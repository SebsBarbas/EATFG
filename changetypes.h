#include <stdio.h>
void passtochar(float num, char* arrayret) {
	int aiddec,cont,i,contdecimas,intdecimas;
	char helper[20];
	float decimas;
	//Two cases, the number is less than 0 or bigger than 0
	if(num<0){
		num=0-num;
		
		decimas = num - (int)num;
	aiddec = (int)num;
	i = 0;
	if(aiddec==0){
		arrayret[0]='0';
		cont=1;
	}
	else{/*Without the else it worked okay, but it was added to save time and make it more presentable, it can be erased*/
	while (aiddec != 0) {
		helper[20 - i - 1]='0'+(aiddec)%10;
		aiddec = aiddec / 10;
		i++;
	}
	for (cont = 0; cont < i; cont++) {
		arrayret[cont] = helper[20 - i + cont]; /*Hay que mirar esto un poco mejor*/
	}
	}
	if (decimas != 0) {
		arrayret[cont] = '.';
		cont++;
		contdecimas = 0;
		while ((decimas - (int)decimas) != 0) {
			decimas = decimas * 10;
			contdecimas++;
		}
		intdecimas = decimas;
		for (i = 0; i < contdecimas; i++) {
			helper[20 - 1 - i] = '0' + intdecimas % 10;
			arrayret[cont + contdecimas-1 - i] = helper[20 - 1 - i];
			intdecimas = intdecimas / 10;
		}
	}
	else{
		contdecimas=0;
	}
	if(contdecimas>0)
		arrayret[cont+1]='\0';
	else
	  arrayret[cont] = '\0';
	for(i=cont+1;i>=0;i--){
		arrayret[i+1]=arrayret[i];
	}
	arrayret[0]='-';	
	arrayret[cont+2]='\0';	
	
	}
	
	
	else{
	decimas = num - (int)num;
	aiddec = (int)num;
	i = 0;
	if(aiddec==0){
		arrayret[0]='0';
		cont=1;
	}
	else{/*Without the else it worked okay, but it was added to save time and make it more presentable, it can be erased*/
	while (aiddec != 0) {
		helper[20 - i - 1]='0'+(aiddec)%10;
		aiddec = aiddec / 10;
		i++;
	}
	for (cont = 0; cont < i; cont++) {
		arrayret[cont] = helper[20 - i + cont]; /*Hay que mirar esto un poco mejor*/
	}
	}
	if (decimas != 0) {
		arrayret[cont] = '.';
		cont++;
		contdecimas = 0;
		while ((decimas - (int)decimas) != 0) {
			decimas = decimas * 10;
			contdecimas++;
		}
		intdecimas = decimas;
		for (i = 0; i < contdecimas; i++) {
			helper[20 - 1 - i] = '0' + intdecimas % 10;
			arrayret[cont + contdecimas-1 - i] = helper[20 - 1 - i];
			intdecimas = intdecimas / 10;
		}
	}
	else{
		contdecimas=0;
	}
	if(contdecimas>0)
		arrayret[cont+1]='\0';
	else
	  arrayret[cont] = '\0';
  }
  
	return;
}

void passtocharpos(float num, char *arrayret){
	
	int aiddec,cont,i,contdecimas,intdecimas;
	char helper[20];
	float decimas;
	//Two cases, the number is less than 0 or bigger than 0
	if(num<0){
		num=0-num;
		
		decimas = num - (int)num;
	aiddec = (int)num;
	i = 0;
	if(aiddec==0){
		arrayret[0]='0';
		cont=1;
	}
	else{/*Without the else it worked okay, but it was added to save time and make it more presentable, it can be erased*/
	while (aiddec != 0) {
		helper[20 - i - 1]='0'+(aiddec)%10;
		aiddec = aiddec / 10;
		i++;
	}
	for (cont = 0; cont < i; cont++) {
		arrayret[cont+1] = helper[20 - i + cont]; /*Hay que mirar esto un poco mejor*/
	}
	}
	if (decimas != 0) {
		arrayret[cont] = '.';
		cont++;
		contdecimas = 0;
		while ((decimas - (int)decimas) != 0) {
			decimas = decimas * 10;
			contdecimas++;
		}
		intdecimas = decimas;
		for (i = 0; i < contdecimas; i++) {
			helper[20 - 1 - i] = '0' + intdecimas % 10;
			arrayret[cont + contdecimas- i] = helper[20 - 1 - i];
			intdecimas = intdecimas / 10;
		}
	}
	else{
		contdecimas=0;
	}
	if(contdecimas>3)
		arrayret[cont+5]='\0';
	else
	  arrayret[cont+contdecimas+1] = '\0';
}
	
	else{
	decimas = num - (int)num;
	aiddec = (int)num;
	i = 0;
	if(aiddec==0){
		arrayret[0]='0';
		cont=1;
	}
	else{/*Without the else it worked okay, but it was added to save time and make it more presentable, it can be erased*/
	while (aiddec != 0) {
		helper[20 - i - 1]='0'+(aiddec)%10;
		aiddec = aiddec / 10;
		i++;
	}
	for (cont = 0; cont < i; cont++) {
		arrayret[cont] = helper[20 - i + cont]; /*Hay que mirar esto un poco mejor*/
	}
	}
	if (decimas != 0) {
		arrayret[cont] = '.';
		cont++;
		contdecimas = 0;
		while ((decimas - (int)decimas) != 0) {
			decimas = decimas * 10;
			contdecimas++;
		}
		intdecimas = decimas;
		for (i = 0; i < contdecimas; i++) {
			helper[20 - 1 - i] = '0' + intdecimas % 10;
			arrayret[cont + contdecimas-1 - i] = helper[20 - 1 - i];
			intdecimas = intdecimas / 10;
		}
	}
	else{
		contdecimas=0;
	}
	if(contdecimas>3)
		arrayret[cont+4]='\0';
	else
	  arrayret[cont+contdecimas] = '\0';
  }
  
	return;
}

float passtofloat(char *c) {
	int pos, longitud,factor,i;
	float decimal=0;
	longitud = 0;
	i = 0;
	while (c[i] != '\0') {
		i++;
		if (c[i] = '.') {
			pos = i;
		}
	}
	longitud = i-1;
	factor = 1;
	for(int j=0;j<pos-1;j++){
		factor=factor*10;
	}
	for (i = 0; i <= longitud; i++) {
		if (i != pos) {
			decimal = decimal + (c[i] - '0')*factor;
			factor = factor / 10;
		}
	}

	return decimal;
}

void passtocharpress(float num, char *arrayret){
	int i,longitud,j;
    char helper[8];
    int aid;
    aid=num;
    if(aid==0){
        arrayret[0]='0';
		arrayret[1] = '\0';
    }
    else{
        i=0;
        j=0;
        while(aid){
            helper[8 - i - 1]='0'+(aid)%10;
            aid = aid / 10;
            i++;
        }
        longitud=i;
        aid=num;
    for (j = 0; j < i; j++)
		arrayret[j] = helper[8 - i + j];
    }
	arrayret[j] = '\0';
    return;
	
}


void passfromint(int num, char *arrayret){
    int aid,i,longitud,j;
    aid=num;
    char helper[5];
    if(aid==0){
        arrayret[0]='0';
		arrayret[1] = '\0';
    }
    else{
        i=0;
        j=0;
        while(aid){
            helper[5 - i - 1]='0'+(aid)%10;
            aid = aid / 10;
            i++;
        }
        longitud=i;
        aid=num;
    for (j = 0; j < i; j++)
		arrayret[j] = helper[5 - i + j];
    }
	arrayret[j] = '\0';
    return;
}

