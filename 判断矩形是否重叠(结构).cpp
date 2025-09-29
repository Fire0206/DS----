#include<iostream>
using namespace std;
struct SPoint{
	int x;
	int y;
};
struct SRect{
	SPoint p1;
	SPoint p2;
};
bool isoverlap(const SRect &rect1,const SRect &rect2){
	int rect1Left = min(rect1.p1.x, rect1.p2.x);
    int rect1Right = max(rect1.p1.x, rect1.p2.x);
    int rect1Top = max(rect1.p1.y, rect1.p2.y);
    int rect1Bottom = min(rect1.p1.y, rect1.p2.y);

    int rect2Left = min(rect2.p1.x, rect2.p2.x);
    int rect2Right = max(rect2.p1.x, rect2.p2.x);
    int rect2Top = max(rect2.p1.y, rect2.p2.y);
    int rect2Bottom = min(rect2.p1.y, rect2.p2.y);

    if (rect1Right < rect2Left || rect1Left > rect2Right || rect1Top < rect2Bottom || rect1Bottom > rect2Top) {
        return false;
    }
    return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		SRect s1;
		SRect s2;
		cin>>s1.p1.x>>s1.p1.y;
		cin>>s1.p2.x>>s1.p2.y;
		cin>>s2.p1.x>>s2.p1.y;
		cin>>s2.p2.x>>s2.p2.y;
		if(isoverlap(s1,s2)){
			cout<<"overlapped"<<endl;
		}
		else{
			cout<<"not overlapped"<<endl;
		}
	}
	return 0;
}
