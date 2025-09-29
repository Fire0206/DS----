#include <iostream>
using namespace std;
int main() {
    const char* months[12] = {"January", "February", "March", "April","May", "June", "July", "August","September", "October", "November", "December"};
    int t;
    cin>>t;
    while(t--){
    	int a;
    	cin>>a;
    	if(a>=1&&a<=12){
    		cout<<months[a-1]<<endl;
		}
		else{
			cout<<"error"<<endl;
		}
	}
	return 0;
}
