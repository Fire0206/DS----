#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

struct Term {
    int coef;  
    int exp;   
    Term* next;
    Term(int c, int e) : coef(c), exp(e), next(nullptr) {}
};

void insertTerm(Term*& head, int coef, int exp) {
    Term* newNode = new Term(coef, exp);
    if (!head) {
        head = newNode;
        return;
    }
    Term* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = newNode;
}

void printPoly(Term* head) {
    vector<string> parts;
    Term* cur = head;
    while (cur) {
        if (cur->coef != 0) {
            string term;
            stringstream ss;

            // 系数
            if (cur->coef < 0) {
                ss.str(""); ss.clear();
                ss << cur->coef;
                term += "(" + ss.str() + ")";
            }
            else {
                ss.str(""); ss.clear();
                ss << cur->coef;
                term += ss.str();
            }

            // 指数
            if (cur->exp != 0) {
                term += "x^";
                if (cur->exp < 0) {
                    ss.str(""); ss.clear();
                    ss << cur->exp;
                    term += "(" + ss.str() + ")";
                }
                else {
                    ss.str(""); ss.clear();
                    ss << cur->exp;
                    term += ss.str();
                }
            }

            parts.push_back(term);
        }
        cur = cur->next;
    }

    // 拼接输出
    for (size_t i = 0; i < parts.size(); i++) {
        if (i > 0) cout << " + ";
        cout << parts[i];
    }
    cout << endl;
}



Term* addPoly(Term* p1, Term* p2) {
    map<int, int> mp;  
    for (Term* cur = p1; cur; cur = cur->next) {
        mp[cur->exp] += cur->coef;
    }
    for (Term* cur = p2; cur; cur = cur->next) {
        mp[cur->exp] += cur->coef;
    }

    vector<pair<int, int>> terms;
    for (auto& it : mp) {
        if (it.second != 0) terms.push_back({ it.first, it.second });
    }
    sort(terms.begin(), terms.end());

    Term* res = nullptr;
    for (auto& t : terms) {
        insertTerm(res, t.second, t.first);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        Term* p1 = nullptr;
        Term* p2 = nullptr;

        cin >> n;
        for (int i = 0; i < n; i++) {
            int c, e;
            cin >> c >> e;
            insertTerm(p1, c, e);
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            int c, e;
            cin >> c >> e;
            insertTerm(p2, c, e);
        }

        printPoly(p1);
        printPoly(p2);

        Term* res = addPoly(p1, p2);
        printPoly(res);
        cout << endl;
    }
    return 0;
}
