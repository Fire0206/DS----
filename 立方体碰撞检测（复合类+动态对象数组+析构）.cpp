#include <iostream>
using namespace std;

class CPoint {
public:
    int x, y, z;
    CPoint(int a = 0, int b = 0, int c = 0) : x(a), y(b), z(c) {} 
    ~CPoint() {}
};

class CCube {
    CPoint* point;
public:
    CCube(CPoint* point1, CPoint* point2) {
        point = new CPoint[2];
        point[0].x = min(point1->x, point2->x);
        point[0].y = min(point1->y, point2->y);
        point[0].z = min(point1->z, point2->z);
        point[1].x = max(point1->x, point2->x);
        point[1].y = max(point1->y, point2->y);
        point[1].z = max(point1->z, point2->z);
    }
    
    int collide(CCube& r) {
        bool xOverlap = !(point[1].x < r.point[0].x || r.point[1].x < point[0].x);
        bool yOverlap = !(point[1].y < r.point[0].y || r.point[1].y < point[0].y);
        bool zOverlap = !(point[1].z < r.point[0].z || r.point[1].z < point[0].z);
        return xOverlap && yOverlap && zOverlap;
    }
    
    ~CCube() {
        delete[] point; 
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        CPoint p[4];
        int x, y, z;
        for (int i = 0; i < 4; i++) {
            cin >> x >> y >> z;
            p[i] = CPoint(x, y, z);
        }
        CCube c1(&p[0], &p[1]); 
        CCube c2(&p[2], &p[3]); 
        if (c1.collide(c2)) {
            cout << "collide" << endl;
        } else {
            cout << "have distance" << endl;
        }
    }
    return 0;
}
