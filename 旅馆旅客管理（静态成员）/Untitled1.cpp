#include <iostream>
#include <cstring>
using namespace std;

class Customer {
private:
    static int TotalCustNum;
    static int Rent;
    static int Year;
    int CustID;
    char* CustName;
public:
    Customer() {
        CustID = TotalCustNum + 1;
        CustName = NULL;
    }
    Customer(const char* name) {
        CustID = TotalCustNum + 1;
        if (name) {
            CustName = new char[strlen(name) + 1];
            strcpy(CustName, name);
        }
        else {
            CustName = NULL;
        }
        Rent += 150;
        TotalCustNum++;
    }
    ~Customer() {
        delete[] CustName;
    }
    static void changeYear(int r) {
        Year = r;
    }
    void Display() {
        cout << CustName << " " << Year << "000" << CustID << " " << TotalCustNum << " " << Rent << endl;
    }
};

int Customer::TotalCustNum = 0;
int Customer::Rent = 0;
int Customer::Year = 2014;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int year;
        char name[100];
        cin >> year;
        Customer::changeYear(year);
        while (true) {
            cin >> name;
            if (strcmp(name, "0") == 0) {
                break;
            }
            Customer cus(name);
            cus.Display();
            
        }
    }
    return 0;
}
