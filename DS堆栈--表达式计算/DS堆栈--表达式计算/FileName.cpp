#include "iostream"
#include "string"
#include "cstdlib"
#include "cstring"
#include "iomanip"
#include "stack"
#define OPSETSIZE 7
using namespace std;

char prior[7][7] = { '>','>','<','<','<','>','>',
                    '>','>','<','<','<','>','>',
                    '>','>','>','>','<','>','>',
                    '>','>','>','>','<','>','>',
                    '<','<','<','<','<','=',' ',
                    '>','>','>','>',' ','>','>',
                    '<','<','<','<','<',' ','=' };
double Operator(double a, unsigned char thera, double b) {
    if (thera == '+') {
        return a + b;
    }
    if (thera == '-') {
        return b - a;
    }
    if (thera == '*') {
        return a * b;
    }
    if (thera == '/') {
        return b / a;
    }
}

char opset[OPSETSIZE] = { '+','-','*','/','(',')','#' };
int In(char test, char* testop) {
    for (int i = 0; i < 7; i++) {
        if (test == testop[i]) {
            return 1;
        }
    }
    return 0;
}

char precede(char aop, char bop) {
    int a, b;
    for (int i = 0; i < 7; i++) {
        if (aop == opset[i]) {
            a = i;
        }
        if (bop == opset[i]) {
            b = i;
        }
    }
    return prior[a][b];
}

float evaluateexpression(string myexp) {
    stack<char> optr;
    stack<double> opnd;
    char tempdata[20];
    double data, a, b, r;
    char theta, dr[2];
    char c;
    int i = 0;
    optr.push('#');
    c = myexp[0];
    strcpy_s(tempdata, "\0");
    while (c != '#' || optr.top() != '#') {
        if (!In(c, opset)) {
            dr[0] = c;
            dr[1] = '\0';
            strcat_s(tempdata, dr);
            c = myexp[++i];
            if (In(c, opset)) {
                data = (float)atof(tempdata);
                opnd.push(data);
                strcpy_s(tempdata, "\0");
            }
        }
        else {
            switch (precede(optr.top(), c)) {
            case '<':
                optr.push(c);
                c = myexp[++i];
                break;
            case '=':
                optr.pop();
                c = myexp[++i];
                break;
            case '>':
                theta = optr.top();
                optr.pop();
                a = opnd.top();
                opnd.pop();
                b = opnd.top();
                opnd.pop();
                opnd.push(Operator(a, theta, b));
                break;
            }
        }
    }
    return opnd.top();
}

int main() {
    string exp;
    int t;
    double result;
    cin >> t;
    while (t--) {
        cin >> exp;
        result = evaluateexpression(exp);
        cout << fixed << setprecision(4) << result << endl;
    }
    return 0;
}