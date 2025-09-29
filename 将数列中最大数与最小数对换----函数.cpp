#include<stdio.h>
void in(int numbers[]);
void exchange(int numbers[]);
void out(int numbers[]);
int main()
{
	int numbers[10];
	in(numbers);
	exchange(numbers);
	out(numbers);
	return 0;
}
void in(int numbers[]){
	for(int i=0;i<10;i++){
		scanf("%d",&numbers[i]);
	}
}
void out(int numbers[]){
	for(int i=0;i<10;i++){
		printf("%d ",numbers[i]);
	}
}
void exchange(int numbers[]){
	int max=0;
	int min=0;
	for(int i=1;i<10;i++){
		if(numbers[i]<numbers[min]){
			min=i;		
		}
		if(numbers[i]>numbers[max]){
			max=i;		
		}
	}
	int temp=numbers[0];
	numbers[0]=numbers[min];
	numbers[min]=temp;
	if(max==0){
		max=min;
	}
	temp=numbers[9];
	numbers[9]=numbers[max];
	numbers[max]=temp;
}
