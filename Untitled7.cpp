#include<iostream>
#include<string>
using namespace std;
int main() {
	struct Student{
		string name;
		string id;
		int score;
	}
	int n;
	cin>>n;
	
	while(n--){
		struct Student currentStudent;
		cin>>currentStudent.name>>currentStudent.id>>currentStudent.score;
		
	}
}

