#include <iostream>
#include <string>
using namespace std;
class IDCard {
private:
    string oldID;
    string newID;
    char checkNum() {
        int weights[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
        string nums = "10X98765432";
        int S = 0;
        for (int i = 0; i < 17; i++) {
            S += (newID[i] - '0') * weights[i];
        }
        int Y = S % 11;
        return nums[Y];
    }
    void expandID() {
        newID = oldID.substr(0, 6) + "19" + oldID.substr(6);
        newID += checkNum();
    }

public:
    IDCard(){
    	oldID=" ";
    	newID=" ";
	}
    IDCard(const string& id){
    	oldID=id;
        cout << "construct ID=" << oldID << endl;
        expandID();
    }
    ~IDCard() {
        cout << "destruct ID=" << newID.substr(newID.length() - 4) << endl;
    }
    string getExpandedID() const {
        return newID;
    }
};

int main() {
    int t;
    cin >> t; 
    cin.ignore();
    for (int i = 0; i < t; i++) {
        string id;
        getline(cin, id);
        IDCard card(id);
        cout << "upgrade ID=" << card.getExpandedID() << endl;
    }
    return 0;
}    
