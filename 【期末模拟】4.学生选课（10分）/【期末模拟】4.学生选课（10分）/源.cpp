#include<iostream>
#include<string>

using namespace std;

class Institude {
protected:
	string Insname;
public:
	Institude() {}
	Institude(string n) : Insname(n) {}
	string getInsname() const {
		return Insname;
	}
};

class Student : virtual public Institude {
protected:
	string Stuname, id;
public:
	Student() {}
	Student(string n, string na, string i) : Institude(n), Stuname(na), id(i) {}
	string getId() const {
		return id;
	}
	string getStuname() const {
		return Stuname;
	}
};

class Course : virtual public Institude {
protected:
	string Couname, number, time;
	int score;
public:
	Course() {}
	Course(string n, string na, string num, string t, int s) : Institude(n), Couname(na), number(num), time(t), score(s) {}
	string getNumber() const {
		return number;
	}
	string getTime() const {
		return time;
	}
	string getCoursename() const {
		return Couname;
	}
	int getScore() const {
		return score;
	}
};

class Student_Course : public Student, public Course {
protected:
	bool position;
	string CourseInsname;

public:
	Student_Course() : position(false) {}
	Student_Course(Student& s, Course& c) :
		Institude(s.getInsname()), 
		Student(s),
		Course(c),
		CourseInsname(c.getInsname()),
		position(false) {
	}

	string getCourseInsname() const {
		return CourseInsname;
	}

	bool getPosition() const {
		return position;
	}

	void print() const {
		if (position) {
			cout << Student::getInsname() << "," << getStuname() << ","
				<< getCoursename() << "," << getScore() << ","
				<< getTime() << endl;
		}
	}
	void set(bool a) {
		position = a;
	}
};

class Administration {
	Student_Course** s;
	int len;
public:
	Administration(Student_Course** stu, int l) : s(stu), len(l) {}

	void process() {
		for (int i = 0; i < len; i++) {
			if (s[i]->getInsname() != s[i]->getCourseInsname()) {
				continue;
			}

			bool conflict = false;
			for (int j = 0; j < i; j++) {
				if (s[j]->getPosition() && s[i]->getId() == s[j]->getId() && s[i]->getTime() == s[j]->getTime()) {
					conflict = true;
					break;
				}
			}
			if (!conflict) {
				s[i]->set(true);
			}
		}
	}

	void output() const {
		for (int i = 0; i < len; i++) {
			s[i]->print();
		}
	}

	~Administration() {
		for (int i = 0; i < len; i++) {
			delete s[i];
		}
		delete[] s;
	}
};

int main() {
	int t1, t2, t3;
	string Insname;

	cin >> t1;
	Student* students = new Student[t1];
	for (int i = 0; i < t1; i++) {
		string Insname, Stuname, id;
		cin >> Insname >> id >> Stuname;
		students[i] = Student(Insname, Stuname, id);
	}

	cin >> t2;
	Course* courses = new Course[t2];
	for (int i = 0; i < t2; i++) {
		string Couname, number, time;
		int score;
		cin >> Insname >> number >> Couname >> score >> time;
		courses[i] = Course(Insname, Couname, number, time, score);
	}

	cin >> t3;
	Student_Course** sc = new Student_Course * [t3];
	for (int i = 0; i < t3; i++) {
		string sid, cid;
		cin >> sid >> cid;
		Student* sp = nullptr;
		Course* cp = nullptr;
		for (int j = 0; j < t1; j++) {
			if (students[j].getId() == sid) {
				sp = &students[j];
				break;
			}
		}
		for (int j = 0; j < t2; j++) {
			if (courses[j].getNumber() == cid) {
				cp = &courses[j];
				break;
			}
		}
		if (sp != nullptr && cp != nullptr) {
			sc[i] = new Student_Course(*sp, *cp);
		}
		else {
			sc[i] = new Student_Course();
		}
	}

	Administration ad(sc, t3);
	ad.process();
	ad.output();

	delete[] students;
	delete[] courses;

	return 0;
}