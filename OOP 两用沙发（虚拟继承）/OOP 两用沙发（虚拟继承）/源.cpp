#include<iostream>
#include<string>
using namespace std;

class Furniture {
protected:
    int quality;
};

class Bed : public Furniture {
public:
    Bed() {
    }

    void sleep() {
        cout << "Sleeping..." << endl;
    }
};

class Sofa : public Furniture {
public:
    Sofa() {
    }
    void WatchTV() {
        cout << "Watching TV." << endl;
    }
};

class SleeperSofa : public Bed, public Sofa {
public:
    SleeperSofa() {
    }
    void FoldOut() {
        cout << "Fold out the sofa." << endl;
    }
};

int main() {
    string type;
    while (getline(cin, type)) {
        size_t start = type.find_first_not_of(" \t");
        if (start == string::npos) {
            break; 
        }
        type = type.substr(start);
        if (type == "Bed") {
            Bed bed;
            bed.sleep();
        }
        else if (type == "Sofa") {
            Sofa sofa;
            sofa.WatchTV();
        }
        else if (type == "SleeperSofa") {
            SleeperSofa sleep;
            sleep.FoldOut();
        }
    }
    return 0;
}