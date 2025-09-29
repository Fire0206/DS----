#include<stdio.h>
int main()
{
	char a;
	int b;
	scanf("%c %d",&a,&b);
	switch(a){
		case'A':
		case'a':	
		printf("ºÚÌÒ");break; 
		case'B':
		case'b':	
		printf("ºìÌÒ");break;
		case'C':
		case'c':	
		printf("Ã·»¨");break;
		case'D':
		case'd':	
		printf("·½¿é");break; 
	}
	if(b==1){
		printf("A");
	}
	else if(b>1&&b<11){
		printf("%d",b);
	}
	else if(b==11){
		printf("J");
	}
	else if(b==12){
		printf("Q");
	}
	else if(b==13){
		printf("K");
	}
	return 0;
 } 
//ÊäÈë Êä³ö
//D 2 ·½¿é2
//a 1 ºÚÌÒA
//b 11 ºìÌÒJ
//C 12 Ã·»¨Q 
