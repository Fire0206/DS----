#include<iostream>
#include<string>
using namespace std;
class CBook{
public:
	string number;
	string name;
	int sum;
	int able;
	
	CBook(){
		number= "";
		name="";
		sum=0;
		able=0;
	}
	CBook(string a,string b,int c,int d):
		number(a),name(b),sum(c),able(d){}
	void borrow(){
		if(able>=1){
			cout<<name<<" 索取号: "<<number<<endl;
			able-=1;
		}else{
			cout<<name<<" 该书已全部借出"<<endl;
		}
	}
};
int main()
{
	int n,m;
	cin>>n;
	string a;string b;int c;int d;
	CBook *books = new CBook[n];
	for(int i=0;i<n;i++){
		cin>>a>>b>>c>>d;
		books[i]=CBook(a,b,c,d);
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>b;
		for(int j=0;j<n;j++){
			if(books[j].name==b){
				books[j].borrow();
				break;
			}
		}
		if(i==(m-1)){
			cout<<endl;
		}
	}
	
	for(int i=0;i<n;i++){
		cout<<books[i].number<<" "<<books[i].name<<" "
		<<books[i].sum<<" "<<books[i].able<<endl;
	}
	int sum=0;
	int left=0;
	for(int i=0;i<n;i++){
		sum+=books[i].sum-books[i].able;
		left+=books[i].able;
	}
	cout<<"借出图书: "<<sum<<"本  剩余馆藏图书: "<<left<<"本";
	delete[] books;
	return 0;
}
