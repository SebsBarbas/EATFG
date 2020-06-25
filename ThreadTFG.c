#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h> 
#include <time.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include "ADS1256_DAC8532_lib.h"
#include "addstrings2.h"
#include "changetypes.h"
#include "ReadWriteSock.h"
#include "Socket.h"
int ppres1[2];
int ppres2[2];
int ppos[2];
int pservo[2];

void *UDPProtocol(){
    struct sockaddr_in Directionwrite;
	int Descriptor,aux;
	struct sockaddr_in Recv;
	int RecvAddrSize=sizeof(Recv);
	char SendDataADC[28];
	char press1[8];
	char press2[8];
	char pos[8];
	char cservo[6];
	struct timespec start,stop; // Enlever apres les tests
	int l=0;
	double secs=0;
	
	Directionwrite.sin_family = AF_INET;
	Directionwrite.sin_addr.s_addr=inet_addr("192.168.1.108");
	Directionwrite.sin_port = htons(59216);
	do{
	    Descriptor = socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		printf("\n El socket vale %d", Descriptor);
		}
		while(Descriptor==-1);
		do{
			printf("\n Llego2");
		    aux=connect(Descriptor, (struct sockaddr *)&Directionwrite, sizeof (Directionwrite));
		}
		while(aux==-1);
				while(1){
					clock_gettime(CLOCK_REALTIME, &start);
					read(ppres1[0],press1,8);
					read(ppres2[0],press2,8);
					read(ppos[0],pos,8);
					addstringsADCv2(SendDataADC,press1,press2,pos);
					writeSocket(Descriptor,SendDataADC,strlen(SendDataADC));
					int b=recvfrom(Descriptor, cservo,5,0,(struct sockaddr *) &Recv, &RecvAddrSize);
					cservo[4]='\0';
					write(pservo[1],cservo,4);
					//printf("\n %d", b);
					clock_gettime(CLOCK_REALTIME,&stop);
					secs=secs+(((double)stop.tv_sec*1000+(double)(stop.tv_nsec/1000000)-((double)start.tv_sec*1000+(double)start.tv_nsec/1000000)));
					l++;
					}
		//(secs=(((double)stop.tv_sec+(double)(stop.tv_nsec/1000000000)-((double)start.tv_sec+(double)start.tv_nsec/1000000000))/250);
        printf("\n %.16g milliseconds", secs/250);
        printf("\n Fin");
}

void *ADCProgram(){
	int cuenta=0;
    float servo=0;
    struct timespec start,stop;
	float pressure1=0;
	float position=0;
	float pressure2=0;
	char press1[8];
	char press2[8];
	char pos[8];
	char cservo[6]="0.00";
	int32_t adc[8];
	int ch_num_tru=3;
	while(1){
	    while((ADS1256_Scan()==0));
	
		for(cuenta=0;cuenta<3;cuenta++){
			adc[cuenta] = ADS1256_GetAdc(cuenta);
			adc[cuenta] = (adc[cuenta] * 100) / 167;
				switch(cuenta){
				case 0:
						position=adc[cuenta];         //Le capteur de position aura avant un circuit electronique pour ajuster la tension mésuré. La tension lu sera 1/4 de la tension réel 
						position=position/1000000;      //Maintenant on a la tension qu'on désire en volts
						position=(position-2,5);        //La conversion entre la position et la tension est de V=s*pos+t avec t=-2.5 et s=0; On a la position en cm, si on travaille entre 0 et 5V
						position=position/100;        
						passtocharpos(position,pos);
						
						write(ppos[1],pos,8);
						 break;   //We multiply the ADC value of our position sensor by 4 beacuse we are going to have an electronical circuit that is going to amplify our signal by a factor of 0.25 so it can be read by our Rpi  
				
				case 1:                                        //Le capteur pression fait un conversion du type V=m*p+V0   Avec V0=0.533 et m=0,4
						pressure1=adc[cuenta];               //
						pressure1=pressure1/1000000;         //On a le voltage en Volts 
						pressure1=(pressure1-0.533)/0.4;     //Maintenant on a la pression en bar
						pressure1=pressure1*100000;
						if(pressure1<0)
						   pressure1=0;
						passtocharpress(pressure1,press1);
						fflush(stdin);
						
						write(ppres1[1],press1,8);
						break;     //The pressure sensors do not need to be amplified i order to be read, thay are only going to have a filter to reduce the amount of noise read
						
				case 2:
					pressure2=adc[cuenta];
					pressure2=pressure2/1000000;
					pressure2=(pressure2-0.533)/0.4;        //Pareille la
					pressure2=pressure2*100000;
					if(pressure2<0)
					   pressure2=0;
					passtocharpress(pressure2,press2);
					
				
					write(ppres2[1],press2,8);
					 break;
	
				default:
				   printf("\n No deberia estar aqui");
					}
				}
				cuenta=0; 
				
				//Falta hacer el DA
				read(pservo[0],cservo,5);
				cservo[5]='\0';
				servo=atof(cservo);
				servo=(servo/4)+2.5;
				if(servo<0 || servo>4.5)
				   servo=2;
				//servo=passtofloat(cservo);
				//Error con la funcion passtofloat
				Write_DAC8552(0x30, Voltage_Convert(5.0,servo)); 
				
		}
   bcm2835_spi_end();
   bcm2835_close(); 
   printf("Me pare");
}

int main(){
int rc1,rc2,rc3;
pthread_t thread1, thread2, thread3;
pipe(ppres1);
pipe(ppres2);
pipe(ppos);
pipe(pservo);
bcm2835_init();
bcm2835_spi_begin();
bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_LSBFIRST );      // The default
bcm2835_spi_setDataMode(BCM2835_SPI_MODE1);                   // The default
bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_8); // Cambiado
bcm2835_gpio_fsel(SPICS, BCM2835_GPIO_FSEL_OUTP);//
bcm2835_gpio_write(SPICS, HIGH);//Why do we need it??
bcm2835_gpio_fsel(DRDY, BCM2835_GPIO_FSEL_INPT);
bcm2835_gpio_set_pud(DRDY, BCM2835_GPIO_PUD_UP); 
		
ADS1256_CfgADC(ADS1256_GAIN_1, ADS1256_2000SPS);

ADS1256_StartScan(0);
if(fork()){
execl("./GUIQT", (char *) NULL);    //Quand on execute l'interface graphique les autres threads ne fonctionnent pasm il faut tester comment resoudre ça
}

else{
if((rc1=pthread_create(&thread1, NULL, &UDPProtocol, NULL))){
    printf("Thread creation failed %d\n", rc1);
    }
if((rc2=pthread_create(&thread2, NULL, &ADCProgram, NULL))){
    printf("Thread creation failed %d\n", rc2);
   } 
  
//Wait for all the threads
  pthread_join(thread1,NULL);
  pthread_join(thread2, NULL);
}
  wait(NULL);
  return 0;
 }  
