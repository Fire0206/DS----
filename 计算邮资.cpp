#include<stdio.h>
int main()
{int g,a,fee;
scanf("%d %c",&g,&a);
if(g<=1000){
	fee=8;
}
else{
	fee=8+((g-1000)/500+1)*4;
 } 
if(a=='y'){
	fee+=5;
}
printf("%d",fee);
return 0;
}
