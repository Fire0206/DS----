#include<iostream>
#include<string>
using namespace std;
struct student{
    string name;
    string id;
    int score;
};
int main(){
    int n;
    cin>>n;
    student maxstudent;
    student minstudent;
    maxstudent.score=-1;
    minstudent.score=101;
    for(int i=0;i<n;i++){
        student currentStudent;
        cin>>currentStudent.name>>currentStudent.id>>currentStudent.score;
        if(currentStudent.score>maxstudent.score){
            maxstudent=currentStudent;
        }
        if(currentStudent.score<minstudent.score){
            minstudent=currentStudent;
        }
    }
    cout<<maxstudent.name<<" "<<maxstudent.id<<endl;
    cout<<minstudent.name<<" "<<minstudent.id<<endl;
    return 0;
}
