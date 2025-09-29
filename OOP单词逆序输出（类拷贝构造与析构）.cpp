#include<iostream>
#include<algorithm>
#include<cstring>
#include<cctype>
using namespace std;
class STR{
private:
	char *s;
	void backward(char *t1,char *t2){
		while(t1<t2){
			swap(*t1,*t2);
			t1++;
			t2--;
		}
	}
public:
	STR(char *t){
		cout<<"constructing..."<<endl;
		s=new char[strlen(t)+1];
		strcpy(s,t);
	}
	STR(const STR& obj){
		cout<<"copy constructing..."<<endl;
		s=new char[strlen(obj.s)+1];
		strcpy(s,obj.s);
	}
	void fun() {
        char *start = s;
        char *end = s;
        while (*end) {
            if (isalpha(*end)) {
                end++;
            } else {
                if (start < end) {
                    backward(start, end - 1);
                }
                start = end + 1;
                end = start;
            }
        }
        if (start < end) {
            backward(start, end - 1);
        }
    }
	void print(){
		cout<<s;
	}
	~STR(){
		cout<<"delete space..."<<endl;
		delete[] s;
	}
};
int main(){
	char input[1000];
	cin.getline(input,sizeof(input));
	STR obj(input);
	STR obj2(obj);
	obj.print();
	cout<<" can be tranformed to ";
	obj2.fun();
	obj2.print();
	cout<<endl;
	return 0;
}
