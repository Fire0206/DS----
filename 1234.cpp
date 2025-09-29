#include<iostream>
using namespace std;
double calculateAverage(int *arr,int n){
	double sum=0;
	int *ptr=arr;
	for(int i=0;i<n;i++){
		sum+=*ptr;
		ptr++;
	}
	return sum / static_cast<double>(n);
}
char maxChar(char* arr,int n){
	char max=*arr;
	char* ptr=arr+1;
	for(int i=0;i<n;i++){
		if(*ptr>max){
			max=*ptr;
		}
		ptr++;
	}
	return max;
}
float minNum(float* arr,int n){
	float min=*arr;
	float*ptr=arr+1;
	for(int i=0;i<n;i++){
		if(*ptr<min){
			min=*ptr;
		}
		ptr++;
	}
	return min;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		char type;
		int n;
		cin>>type>>n;
		switch(type){
			case'I':
				int *arr1 = new int[n];
				int *ptr1 =arr1;
				for(int i=0;i<n;i++){
					cin>>*ptr1;
					ptr1++;
				}
				double average=calculateAverage(arr1,n);
				cout<<average<<endl;
				delete[] arr1;
				break;
			case'C':
				char *arr2 = new char[n];
				char *ptr2 =arr2;
				for(int i=0;i<n;i++){
					cin>>*ptr2;
					ptr2++;
				}
				char max=maxChar(arr2,n);
				cout<<max<<endl;
				delete[] arr2;
				break;
			case'F':
				float* arr3 = new float[n];
				float* ptr3 =arr3;
				for(int i=0;i<n;i++){
					cin>>*ptr3;
					ptr3++;
				}
				float min=minNum(arr3,n);
				cout<<min<<endl;
				delete[] arr3;
				break;
		}
	}
	return 0;
} 
