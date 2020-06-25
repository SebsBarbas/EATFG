#ifndef ADDSTRINGS2_H_INCLUDED
#define ADDSTRINGS2_H_INCLUDED
#include <stdio.h>
void addstringsGUIv2(char *to_send, char *skin_prof, char *peri_prof, char *ef_yel_ver, char *ef_inter_ver, char *ef_yel_el, char *ef_inter_el, char *freq){
    int i=0,j=0;
    while(skin_prof[j]!='\0'){
        to_send[i]=skin_prof[j];
        i++;
        j++;
    }
    to_send[i]=' ';
    i++;
    j=0;
    while(peri_prof[j]!='\0'){
        to_send[i]=peri_prof[j];
        i++;
        j++;
    }
    to_send[i]=' ';
    i++;
    j=0;
    while(ef_yel_ver[j]!='\0'){
        to_send[i]=ef_yel_ver[j];
        i++;
        j++;
    }
    to_send[i]=' ';
    i++;
    j=0;
    while(ef_inter_ver[j]!='\0'){
        to_send[i]=ef_inter_ver[j];
        i++;
        j++;
    }
    to_send[i]=' ';
    i++;
    j=0;
    while(ef_yel_el[j]!='\0'){
        to_send[i]=ef_yel_el[j];
        i++;
        j++;
    }
    to_send[i]=' ';
    i++;
    j=0;
    while(ef_inter_el[j]!='\0'){
        to_send[i]=ef_inter_el[j];
        i++;
        j++;
    }
    to_send[i]=' ';
    i++;
    j=0;
    while(freq[j]!='\0'){
		to_send[i]=freq[j];
		i++;
		j++;
	}

while(i<36){
      to_send[i]=' ';
      i++;
      }
      to_send[36]='\0';
return;

}

void addstringsADCv2(char *to_send, char *press1, char *press2, char *pos){
    int i=0,j=0;
    while(press1[j]!='\0'){
		if((press1[j]>='0' && press1[j]<='9') || press1[j]=='.' || press1[j]=='-'){ 
        to_send[i]=press1[j];
	}
	else{
		to_send[i]='0';
	}
        i++;
        j++;
    }
    to_send[i]=' ';
    i++;
    j=0;
    while(press2[j]!='\0'){
		if((press2[j]>='0' && press2[j]<='9') || press2[j]=='.' || press2[j]=='-'){ 
        to_send[i]=press2[j];
	}
	else{
		to_send[i]='0';
	}
        i++;
        j++;
    }
    to_send[i]=' ';
    i++;
    j=0;
    while(pos[j]!='\0'){
		if((pos[j]>='0' && pos[j]<='9') || pos[j]=='.' || pos[j]=='-'){ 
        to_send[i]=pos[j];
	}
	else{
		to_send[i]='0';
	}
        i++;
        j++;
    }
    to_send[i]=' ';
    i++;
    j=0;
    while(i<27){
      to_send[i]=' ';
      i++;
      }
    to_send[27]='\0';
}

void separatestringsGUIv2(char *to_send, char *skin_prof, char *peri_prof, char *ef_yel_ver, char *ef_inter_ver, char *ef_yel_el, char *ef_inter_el, char *freq){
int i=0,flag=0,j=0;
while(to_send[i]!='\0'){
        j=0;
    while(to_send[i]!=' ' && to_send[i]!='\0'){
            switch(flag){
            case 0: skin_prof[j]=to_send[i]; break;
            case 1:peri_prof[j]=to_send[i]; break;
            case 2: ef_yel_ver[j]=to_send[i]; break;
            case 3: ef_inter_ver[j]=to_send[i]; break;
            case 4: ef_yel_el[j]=to_send[i]; break;
            case 5: ef_inter_el[j]=to_send[i]; break;
            case 6: freq[j]=to_send[i]; break;
            default: break;
            }
            j++;
            switch(flag){
            case 0: skin_prof[j]='\0'; break;
            case 1:peri_prof[j]='\0'; break;
            case 2: ef_yel_ver[j]='\0'; break;
            case 3: ef_inter_ver[j]='\0'; break;
            case 4: ef_yel_el[j]='\0'; break;
            case 5: ef_inter_el[j]='\0'; break;
            case 6: freq[j]='\0'; break;
            default: break;
            }
            i++;
    }
    flag++;
    if(to_send[i]!='\0')
        i++;
}
}

void separatestringsADCv2(char *to_send, char *press1, char *press2, char *pos){
int i=0,flag=0,j=0;
while(to_send[i]!='\0'){
        j=0;
    while(to_send[i]!=' ' && to_send[i]!='\0'){
            switch(flag){
            case 0: press1[j]=to_send[i]; break;
            case 1:press2[j]=to_send[i]; break;
            case 2: pos[j]=to_send[i]; break;
            default: break;
            }
            j++;
            switch(flag){
            case 0: press1[j]='\0'; break;
            case 1:press2[j]='\0'; break;
            case 2: pos[j]='\0'; break;
            default: break;
            }
            i++;
    }
    flag++;
    if(to_send[i]!='\0')
        i++;
}
}


#endif // ADDSTRINGS2_H_INCLUDED
