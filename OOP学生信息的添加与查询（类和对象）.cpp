#include <iostream>
#include <iomanip>
#include <map>
#include <string>

using namespace std;

class Student {
public:
    string id;
    string name;
    string birthday;
    double score;
    Student(string id = "", string name = "", string birthday = "", double score = 0.0)
        : id(id), name(name), birthday(birthday), score(score) {}

    bool operator<(const Student& other) const {
        return id < other.id;
    }
};

string formatBirthday(const string& birthday) {
    string formatted = birthday;
    size_t pos1 = formatted.find('-');
    size_t pos2 = formatted.find('-', pos1 + 1);

    if (pos1 != string::npos && pos1 + 2 < formatted.length() && formatted[pos1 + 1] == '0') {
        formatted.erase(pos1 + 1, 1); 
        pos2--; 
    }
    if (pos2 != string::npos && pos2 + 2 < formatted.length() && formatted[pos2 + 1] == '0') {
        formatted.erase(pos2 + 1, 1); 
    }
    for (size_t i = 0; i < formatted.length(); ++i) {
        if (formatted[i] == '-') {
            formatted[i] = '_';
        }
    }

    return formatted;
}

int main() {
    int N;
    cin >> N;
    map<string, Student> students;

    for (int i = 0; i < N; ++i) {
        string id, name, birthday;
        double score;
        cin >> id >> name >> birthday >> score;
        students[id] = Student(id, name, birthday, score);
    }

    map<string, Student>::iterator it;
    for (it = students.begin(); it != students.end(); ++it) {
        const Student& student = it->second;
        string formattedBirthday = formatBirthday(student.birthday);
        cout << "id:" << student.id << " "
             << "name:" << student.name << " "
             << "birthday:" << formattedBirthday << " "
             << "score:" << fixed << setprecision(1) << student.score << endl;
    }

    return 0;
}
