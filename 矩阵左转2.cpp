#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		
		int **matrix=new int*[a];
		for(int i=0;i<a;i++){
			matrix[i]=new int[b];
		}
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				cin>>matrix[i][j];
			}
		}
		for(int j=b-1;j>=0;j--){
			for(int i=0;i<a;i++){
				cout<<matrix[i][j];
				if(i<a-1){
					cout<<" ";
				}
			}
			cout<<endl;
		}
		for(int i=0;i<a;i++){
			delete[]matrix[i];
		}
		delete[]matrix;
	}
	return 0;
}
