#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void reverseArray(int arr[],int a,int b)
{
    while(a<b){
        swap(arr[a],arr[b]);
        a++;
        b--;
    }
}
int main(){
    int m,n;
    cin>>n>>m;
    int *arr=new int[10];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(m>n){
        m%=n;
    }
    reverseArray(arr,0,n-1);
    reverseArray(arr,0,m-1);
    reverseArray(arr,m,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i];
        if(i!=n-1){
            cout<<" ";
        }
    }
    delete[] arr;
    return 0;
}
