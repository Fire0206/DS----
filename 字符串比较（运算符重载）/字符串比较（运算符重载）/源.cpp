#include<iostream>
#include<cstring>
using namespace std;

class str
{
    char* p;
public:
    str() {};
    str(char* s)
    {
        p = s;
    }
    friend bool operator>(str& a, str& b)
    {
        if (strcmp(a.p, b.p) > 0)
            return true;
        else
            return false;
    }
    friend bool operator<(str& a, str& b)
    {
        if (strcmp(a.p, b.p) < 0)
            return true;
        else
            return false;
    }
    friend bool operator==(str& a, str& b)
    {
        if (strcmp(a.p, b.p) == 0)
            return true;
        else
            return false;
    }
    void show()
    {
        cout << p << endl;
    }
};

int main()
{
    char a[100], b[100], c[100];
    cin.getline(a, 100);
    cin.getline(b, 100);
    cin.getline(c, 100);

    str s1(a), s2(b), s3(c);
    if (s1 > s2)
        s1.show();
    else
        s2.show();

    if (s1 < s3)
        s1.show();
    else
        s3.show();

    if (s2 == s3)
        s2.show();
    else
        s3.show();
    return 0;
}

