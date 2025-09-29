#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct Poker
{
    char a[20];
    int color;
    int size;
};
void transfer(Poker *poker)
{
    if(strstr(poker->a,"大王")) poker->color =6;
    if(strstr(poker->a,"小王")) poker->color =5;
    if(strstr(poker->a,"黑桃")) poker->color =4;
    if(strstr(poker->a,"红桃")) poker->color =3;
    if(strstr(poker->a,"梅花")) poker->color =2;
    if(strstr(poker->a,"方块")) poker->color =1;
    if(strstr(poker->a,"A")) poker->size=14; 
    if(strstr(poker->a,"K")) poker->size=13;
    if(strstr(poker->a,"Q")) poker->size=12;
    if(strstr(poker->a,"J")) poker->size=11;
    if(strstr(poker->a,"10")) poker->size=10;
    if(strstr(poker->a,"9")) poker->size=9;
    if(strstr(poker->a,"8")) poker->size=8;
    if(strstr(poker->a,"7")) poker->size=7;
    if(strstr(poker->a,"6")) poker->size=6;
    if(strstr(poker->a,"5")) poker->size=5;
    if(strstr(poker->a,"4")) poker->size=4;
    if(strstr(poker->a,"3")) poker->size=3;
    if(strstr(poker->a,"2")) poker->size=2;
}
bool cmp(Poker p1,Poker p2)
{
    if(p1.color!=p2.color) return p1.color>p2.color;
    if(p1.size!=p2.size) return p1.size>p2.size;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Poker *p=new Poker[n];
        for(int i=0;i<n;i++) 
        {
            cin>>p[i].a;
            transfer(&p[i]);
        }
        sort(p,p+n,cmp);
        for(int i=0;i<n;i++)  
        {
            if(i<n-1) cout<<p[i].a<<" ";
            else cout<<p[i].a<<endl;
        }
        delete[] p;
    }
    return 0;
}    
