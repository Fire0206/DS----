#include <iostream>
using namespace std;

class CRect;

class CPoint {
private:
    int x, y;
public:
    CPoint(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    friend class CRect;
    friend bool isCover(const CRect& r1, const CRect& r2);
};

class CRect {
private:
    CPoint p1, p2;
public:
    CRect(const CPoint& _p1, const CPoint& _p2) : p1(_p1), p2(_p2) {}

    friend bool isCover(const CRect& r1, const CRect& r2);
};

bool isCover(const CRect& r1, const CRect& r2) {
    int r1MinX = min(r1.p1.x, r1.p2.x);
    int r1MaxX = max(r1.p1.x, r1.p2.x);
    int r1MinY = min(r1.p1.y, r1.p2.y);
    int r1MaxY = max(r1.p1.y, r1.p2.y);

    int r2MinX = min(r2.p1.x, r2.p2.x);
    int r2MaxX = max(r2.p1.x, r2.p2.x);
    int r2MinY = min(r2.p1.y, r2.p2.y);
    int r2MaxY = max(r2.p1.y, r2.p2.y);

    if (r1MaxX < r2MinX || r2MaxX < r1MinX ||
        r1MaxY < r2MinY || r2MaxY < r1MinY) {
        return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        CPoint p1(x1, y1);
        CPoint p2(x2, y2);
        CPoint p3(x3, y3);
        CPoint p4(x4, y4);

        CRect r1(p1, p2);
        CRect r2(p3, p4);

        if (isCover(r1, r2)) {
            cout << "overlapped" << endl;
        }
        else {
            cout << "not overlapped" << endl;
        }
    }
    return 0;
}