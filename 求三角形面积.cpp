#include<stdio.h>
#include<math.h>
int main()
{
	int T;
	double a,b,c;
	double S,area;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%lf %lf %lf",&a,&b,&c);
		S=(a+b+c)/2;
		area=sqrt(S*(S-a)*(S-b)*(S-c));
		printf("%.2f",area);
		if(i!=T-1){
			printf("\n");
		}	
	}
	return 0;
}
