#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	cin.ignore();
	while (t--){
		char a[11],b[11],c[11];
		int lenSum=0;
		cin>>a>>b>>c;
		int l[4],r[4];
		for(int i=0;i<3;i++){
			cin>>l[i]>>r[i];
			lenSum+=(r[i]-l[i]+1);
		}
		char *str=new char[lenSum+1];
		char* p = str;
		
		char* ptr1 = a + l[0] - 1;
        for (int j = 0; j < (r[0]-l[0]+1); ++j) {
            *p = *ptr1;
            ++p;
            ++ptr1;
        }
        
        char* ptr2 = b + l[1] - 1;
        for (int j = 0; j < (r[1]-l[1]+1); ++j) {
            *p = *ptr2;
            ++p;
            ++ptr2;
        }
        
        char* ptr3 = c + l[2] - 1;
        for (int j = 0; j < (r[2]-l[2]+1); ++j) {
            *p = *ptr3;
            ++p;
            ++ptr3;
        }
        *p='\0';
        cout<<str<<endl;
        delete[] str;
	}
	return 0;
} 
