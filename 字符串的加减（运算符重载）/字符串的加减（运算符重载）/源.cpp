#include <iostream>
#include <cstring>
using namespace std;

class str {
	int length;
	char* p;
public:
	str() {
	};
	str(char* s) {
		p = new char[strlen(s) + 1];
		strcpy(p, s);
	}
	str(const str& obj) {
		length = obj.length;
		p = new char[strlen(obj.p) + 1];
		strcpy(p, obj.p);
	}
	~str() {
		if (p != NULL) {
			delete[]p;
		}
	}
	friend str operator+(const str& s1, const str& s2);
	friend str operator-(const str& s1, const str& s2);
	void operator=(const str& obj) {
		strcpy(p, obj.p);
	}
	void show() {
		cout << "length=" << length << " " << p << endl;
	}
};

str operator+(const str& s1, const str& s2) {
	str ans;
	ans.p = new char[strlen(s1.p) + strlen(s2.p) + 1];
	strcpy(ans.p, s1.p);
	strcat(ans.p, s2.p);
	ans.length = strlen(ans.p);
	return ans;
}

str operator-(const str& s1, const str& s2) {
	str ans;
	ans.p = new char[strlen(s1.p) + 1];
	char* q = strstr(s1.p, s2.p);
	char* t = s1.p;
	for (int i = 0; t + i < q; i++) {
		ans.p[i] = s1.p[i];
	}
	ans.length = strlen(ans.p);
	return ans;
}

int main() {
	char a[30];
	char b[30];
	cin.getline(a, 30);
	cin.getline(b, 30);
	str m(a);
	str n(b);
	str ans = m + n;
	ans.show();
	str ans2 = ans - n;
	ans2.show();
	return 0;
}