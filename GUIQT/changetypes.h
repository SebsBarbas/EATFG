#include <stdio.h>
void passtochar(float num, char* arrayret) {
	int aiddec,cont,i,contdecimas,intdecimas;
	char helper[20];
	float decimas;
	decimas = num - (int)num;
	aiddec = int(num);
	i = 0;
	if(aiddec==0){
		arrayret[0]='0';
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
		while ((decimas - int(decimas)) != 0) {
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
	if(contdecimas>2)
		arrayret[cont+3]='\0';
	else
	  arrayret[cont + contdecimas] = '\0';
	return;
}

float passtofloat(char *c) {
	int pos, longitud,factor,i;
	float decimal=0;
	longitud = 0;
	i = 0;
	while (c[i] != '\0') {
		i++;
		if (*c = '.') {
			pos = i;
		}
	}
	longitud = i;
	factor = 10 * (longitud - pos - 1);
	for (i = 0; i < longitud; i++) {
		if (i != pos) {
			decimal = decimal + (c[i] - '0')*factor;
			factor = factor / 10;
		}
	}

	return decimal;
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

