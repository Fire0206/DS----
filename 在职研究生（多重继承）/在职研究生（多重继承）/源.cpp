#include<iostream>
#include<string> 
using namespace std;

class CPeople {
protected:
    string name, gender;
    int age;
public:
    CPeople() {}
    CPeople(string n, string g, int a) :name(n), gender(g), age(a) {}

    void print() {
        
        cout << "Name: " << name << endl;
        cout << "Sex: " << gender << endl;
        cout << "Age: " << age << endl;
    }
};

class CStudent : virtual public CPeople {
protected:
    string id;
    double score;
public:
    CStudent() {}
    CStudent(string n, string g, int a, string i, double s) : CPeople(n, g, a), id(i), score(s) {}
    void print1() {
        cout << "Student:" << endl;
        CPeople::print();
        cout << "No.: " << id << endl;
        cout << "Score: " << score << endl;
    }
};

class CTeacher : virtual public CPeople {
protected:
    string work, dpt;
public:
    CTeacher() {}
    CTeacher(string n, string g, int a, string w, string d) :
        CPeople(n, g, a), work(w), dpt(d) {
    }
    void print2() {
        cout << "Teacher:" << endl;
        CPeople::print();
        cout << "Position: " << work << endl;
        cout << "Department: " << dpt << endl;
    }
};

class CGradOnWork : public CStudent, public CTeacher {
    string direction, tutor;
public:
    CGradOnWork(string n, string g, int a, string i, double s, string w, string d, string dir, string tut) :
        CPeople(n, g, a), CStudent(n, g, a, i, s), CTeacher(n, g, a, w, d), direction(dir), tutor(tut) {
    }
    void print3() {
        cout << "GradOnWork:" << endl;
        CPeople::print();
        cout << "No.: " << id << endl;
        cout << "Score: " << score << endl;
        cout << "Position: " << work << endl;
        cout << "Department: " << dpt << endl;
        cout << "Direction: " << direction << endl;
        cout << "Tutor: " << tutor << endl;
    }
};

int main() {
    string name, gender;
    int age;
    string id;
    double score;
    string work, dpt;
    string direction, tutor;
    cin >> name >> gender >> age >> id >> score >> work >> dpt >> direction >> tutor;
    CPeople people(name, gender, age);
    cout << "People:" << endl;
    people.print();
    cout << endl;
    CStudent student(name, gender, age, id, score);
    student.print1();
    cout << endl;
    CTeacher teacher(name, gender, age, work, dpt);
    teacher.print2();
    cout << endl;
    CGradOnWork grad(name, gender, age, id, score, work, dpt, direction, tutor);
    grad.print3();
    return 0;
}