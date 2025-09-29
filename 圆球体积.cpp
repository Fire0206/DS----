#include  <stdio.h>
int main()
{
float r,h,C1,Sa,Sb,Va,Vb,PI;
scanf("%f%f",&r,&h);
PI=3.14;
C1=2*PI*r;
Sa=PI*r*r;
Sb=4*PI*r*r;
Va=4*PI*r*r*r/3;
Vb=PI*r*r*h;
printf("C1=%.2f\nSa=%.2f\nSb=%.2f\nVa=%.2f\nVb=%.2f",C1,Sa,Sb,Va,Vb);
return 0;
}
