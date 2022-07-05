#include<stdio.h>
#include<stdlib.h>
long *a;
int p=8000,i;int main(void){a=calloc(16000,sizeof(long));
a[p+0]+=8;a[p+1]+=a[p+0]*1;a[p+2]+=a[p+0]*4;a[p+0]=0;a[p+1]+=2;a[p+3]+=1;p+=2;for(;a[p];p+=2){a[p+0]+=-1;a[p+2]+=a[p+0]*1;a[p+0]=1;}a[p+1]+=1;p+=1;for(;a[p];p+=1){a[p+0]+=-1;p+=-3;for(;a[p];p+=-2){a[p+0]+=-1;p+=1;for(;a[p];p+=2){a[p+0]=1;a[p+1]+=2;a[p+4]+=-1;}p+=-1;for(;a[p];p+=-1){}a[p+2]+=6;a[p+0]+=a[p+2]*5;a[p+0]+=2;a[p+2]=1;for(i=0;i<1;i++){putchar(a[p+0]);fflush(stdout);}a[p+0]=0;}for(i=0;i<1;i++){putchar(a[p+1]);fflush(stdout);}a[p+2]+=1;p+=2;for(;a[p];p+=2){}a[p+1]+=1;}return 0;}

