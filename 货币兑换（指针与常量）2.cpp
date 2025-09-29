#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	double us = 6.2619;
	double eu = 6.6744;
	double ja = 0.0516;
	double ho = 0.8065;
	int t;
	cin>>t;
	while(t--){
		char type;
		double n;
		cin>>type>>n;
		const double* p = &us;
		if(type=='E') p =&eu;
		else if(type=='Y') p = &ja;
		else if(type=='H') p = &ho;
		cout<<fixed<<setprecision(4)<<n*(*p)<<endl;
	}
	return 0;
}
