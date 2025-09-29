#include<iostream>
#include<algorithm>
using namespace std;
struct Birth{
	int year;
	int month;
	int day;
};
bool operator<(const Birth& a, const Birth& b) {
    if (a.year != b.year) {
        return a.year < b.year;
    }
    if (a.month != b.month) {
        return a.month < b.month;
    }
    return a.day < b.day;
}
int main()
{
	int t;
	cin>>t;
	Birth *birth =new Birth[t];
	for(int i=0;i<t;i++){
		cin>>birth[i].year>>birth[i].month>>birth[i].day;
	}
	sort(birth,birth+t);
	cout<<birth[1].year<<"-" << birth[1].month << "-" << birth[1].day <<endl;
	delete[] birth;
    return 0;
}
