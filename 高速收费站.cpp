#include<iostream>
#include<string>
using namespace std;

class CTollBooth{
public:
    int charge = 0;
    int uncharge = 0;
    int sum = 0;

    void payingcar(char type){
        switch(type) { 
            case 'S': {  
                uncharge += 1;
                break;
            }
            case 'C': {
                charge += 1;
                sum += 5;
                break;
            }
            case 'V': {
                charge += 1;
                sum += 8;
                break;
            }
        }
    }

    void display(){
        cout << charge << " " << uncharge << " " << sum << endl;
    }
};

int main()
{
    int t;
    char type;
    cin >> t;
    CTollBooth booth;
    while(t--){
        cin >> type;
        booth.payingcar(type);
        booth.display();
    }
    return 0;
}
