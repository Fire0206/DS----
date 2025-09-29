#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class CDate{
public:
    int year, month, day;

    CDate(int y,int m,int d):year(y),month(m),day(d)
    {}

    bool check(){
        if(year < 1 || month <1 || month > 12 || day < 1) return false;
        int monthdays[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(isLeap()) monthdays[1]=29;
        return day <= monthdays[month - 1];
    }

    bool isLeap(){
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    void print(){
        cout << year << "年" <<month<<"月"<<day<<"日 "; 
    }
};

class CStudentID
{
private:

    char *p_id, *p_name; //身份证号码，姓名
    CDate birthday; //出生日期
    int registered; //登记否

    bool isIdFormat(const char *id){
        int len = strlen(id);
        if(len!= 15 && len != 18) return false;
        for(int i=0;i<len;i++){
            if (i == 17 && (id[i] == 'X' || id[i] == 'x')) continue;
            if (!isdigit(id[i])) return false;
        }
        return true; 
    }

    bool isIdDateMatch(const char* id) {
        int len = strlen(id);
        int idYear, idMonth, idDay;
        if (len == 15) {
            idYear = 1900 + (id[6] - '0') * 10 + (id[7] - '0');
            idMonth = (id[8] - '0') * 10 + (id[9] - '0');
            idDay = (id[10] - '0') * 10 + (id[11] - '0');
        } else {
            idYear = (id[6] - '0') * 1000 + (id[7] - '0') * 100 + (id[8] - '0') * 10 + (id[9] - '0');
            idMonth = (id[10] - '0') * 10 + (id[11] - '0');
            idDay = (id[12] - '0') * 10 + (id[13] - '0');
        }
        return idYear == birthday.year && idMonth == birthday.month && idDay == birthday.day;
    }

    bool isCheckDigitValid(const char* id) {
        if (strlen(id) != 18) return true;
        return id[17] == calculateCheckDigit(id);
    }

    char calculateCheckDigit(const char* id17) {
        int weights[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
        char checkDigits[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
        int sum = 0;
        for (int i = 0; i < 17; ++i) {
            sum += (id17[i] - '0') * weights[i];
        }
        int temp = sum % 11;
        return checkDigits[temp];
    }

public:

    CStudentID(char *p_idval, char *p_nameval, CDate &day):birthday(day){
        if(!day.check() || !isIdFormat(p_idval) || !isIdDateMatch(p_idval)){
            cout<<p_nameval << " illegal id"<<endl;
            registered = 0;
            p_id = NULL;
            p_name = NULL;
            return;
        }

        if (strlen(p_idval) == 18 && !isCheckDigitValid(p_idval)) {
            cout << p_nameval << " illegal id" <<endl;
            registered = 0;
            p_id = NULL;
            p_name = NULL;
            return;
        }
        p_id = new char[strlen(p_idval) + 1];
        strcpy(p_id, p_idval);
        p_name = new char[strlen(p_nameval) + 1];
        strcpy(p_name, p_nameval);
        registered = 1;
        cout << p_name << " ";
        birthday.print();
        cout << p_id << endl;
    }

    CStudentID(const CStudentID &r) : birthday(r.birthday) {
        if (strlen(r.p_id) == 15) {
            p_id = new char[19];
            strncpy(p_id, r.p_id, 6);
            p_id[6] = '1';
            p_id[7] = '9';
            strncpy(p_id + 8, r.p_id + 6, 9);
            p_id[17] = calculateCheckDigit(p_id);
            p_id[18] = '\0';
        } else {
            p_id = new char[strlen(r.p_id) + 1];
            strcpy(p_id, r.p_id);
        }
        p_name = new char[strlen(r.p_name) + 1];
        strcpy(p_name, r.p_name);
        registered = r.registered;
        if (registered) {
            cout << p_name << " ";
            birthday.print();
            cout << p_id << endl;
        }
    }

    bool checked() { 
        return registered; 
    }

    ~CStudentID(){
        delete[] p_id;
        delete[] p_name;
    }

};

int main()
{
    int t;
    cin>>t;
    while(t--){
        int y,m,d;
        char name[100];
        char id[100];
        cin>>y>>m>>d;
        CDate day(y,m,d);
        cin>>name>>id;
        CStudentID s(id,name,day);
        if(s.checked()){
            CStudentID s_copy(s);
        }
    }
    return 0;
}
