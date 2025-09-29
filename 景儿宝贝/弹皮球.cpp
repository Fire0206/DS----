#include<stdio.h>
int main()
{
	unsigned long long current = 1;
	unsigned long long sum = 0;
	for (int i = 0; i < 64; i++)
	{	
		current = 1;
		for(int j=0;j<i;j++)
		{
		current = current * 2;	
		}
		sum += current;
	}
	printf("共需要%llu粒麦子\n", sum);
	double volume=(double)sum/1.42e8;
	printf("麦子合需%.2f立方米", volume);

	return 0;
}
