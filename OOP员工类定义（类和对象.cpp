#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    string id;
    string department;
    string position;
    string gender;
    string phone;

public:
    void setName(const string& n) {
        name = n;
    }
    string getName() const {
        return name;
    }
    void setId(const string& i) {
        id = i;
    }
    string getId() const {
        return id;
    }
    void setDepartment(const string& d) {
        department = d;
    }
    string getDepartment() const {
        return department;
    }
    void setPosition(const string& p) {
        position = p;
    }
    string getPosition() const {
        return position;
    }
    void setGender(const string& g) {
        gender = g;
    }
    string getGender() const {
        return gender;
    }
    void setPhone(const string& ph) {
        phone = ph;
    }
    string getPhone() const {
        return phone;
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        Employee emp;
        string name, id, department, position, gender, phone;
        cin >> name >> id >> department >> position >> gender >> phone;

        emp.setName(name);
        emp.setId(id);
        emp.setDepartment(department);
        emp.setPosition(position);
        emp.setGender(gender);
        emp.setPhone(phone);

        cout << emp.getName() << " " << emp.getId() << " " << emp.getDepartment() << " "
             << emp.getPosition() << " " << emp.getGender() << " " << emp.getPhone() << endl;
    }

    return 0;
}    
