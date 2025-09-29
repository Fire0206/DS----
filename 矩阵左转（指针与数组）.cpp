#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int a[2][3];
		for(int i=0;i<2;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}			
		}
		for (int j = 2; j >= 0; --j) {
	        for (int i = 0; i < 2; ++i) {
	            int* ptr = &a[0][0] + i * 3 + j;
	            cout << *ptr<<" ";
	        }
	    	cout<<endl;
		}
	}
	return 0;
}
