#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class box {
private:
    string num;
    int length;
    int width;
    int height;
    int volume;
public:
    box() {}
    box(string tn, int tl, int tw, int th) {
        num = tn;
        length = tl;
        width = tw;
        height = th;
        volume = tl * tw * th;
    }
    int operator-(box& b) {
        if (length >= b.length && width >= b.width && height >= b.height) return b.volume;
        else if (length < b.length && width < b.width && height < b.height) return volume;
        return 0;
    }
    string getnum() {
        return num;
    }
}B[100];

int main() {
    int t;
    cin >> t;
    string n1, n2;
    for (int i = 0; i < t; i++) {
        string tn;
        int tl, tw, th;
        cin >> tn >> tl >> tw >> th;
        box tmp(tn, tl, tw, th);
        B[i] = tmp;
    }
    int maxx = -1;
    for (int i = 0; i < t; i++) {
        for (int j = i + 1; j < t; j++) {
            int overflow1 = B[i] - B[j];
            if (overflow1 > maxx) {
                maxx = overflow1;
                n1 = B[i].getnum();
                n2 = B[j].getnum();
            }
            int overflow2 = B[j] - B[i];
            if (overflow2 > maxx) {
                maxx = overflow2;
                n1 = B[j].getnum();
                n2 = B[i].getnum();
            }
        }
    }
    cout << n2 << "盒子放入" << n1 << "盒子溢出的水最多，为" << maxx << "。" << endl;
    return 0;
}