#include <iostream>
#include <cmath>
using namespace std;

struct SPoint {
    double x;
    double y;
};

struct SLine {
    SPoint p1;
    SPoint p2;
};

double f(SPoint p1, SPoint p2, SPoint p) {
    return (p.x - p1.x) * (p2.y - p1.y) - (p2.x - p1.x) * (p.y - p1.y);
}

bool isPointOnSegment(SPoint p, SLine seg) {
    const double epsilon = 1e-8;
    double minX = min(seg.p1.x, seg.p2.x);
    double maxX = max(seg.p1.x, seg.p2.x);
    double minY = min(seg.p1.y, seg.p2.y);
    double maxY = max(seg.p1.y, seg.p2.y);
    
    if (p.x < minX - epsilon || p.x > maxX + epsilon) return false;
    if (p.y < minY - epsilon || p.y > maxY + epsilon) return false;
    return true;
}

bool isIntersect(SLine line1, SLine line2) {
    double f1 = f(line1.p1, line1.p2, line2.p1);
    double f2 = f(line1.p1, line1.p2, line2.p2);
    double g1 = f(line2.p1, line2.p2, line1.p1);
    double g2 = f(line2.p1, line2.p2, line1.p2);
    
    if ((f1 * f2 < 0) && (g1 * g2 < 0)) return true;
    
    const double epsilon = 1e-8;
    if ((abs(f1) < epsilon && isPointOnSegment(line2.p1, line1)) ||
        (abs(f2) < epsilon && isPointOnSegment(line2.p2, line1)) ||
        (abs(g1) < epsilon && isPointOnSegment(line1.p1, line2)) ||
        (abs(g2) < epsilon && isPointOnSegment(line1.p2, line2))) {
        return true;
    }
    
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        SLine line1, line2;
        cin >> line1.p1.x >> line1.p1.y >> line1.p2.x >> line1.p2.y;
        cin >> line2.p1.x >> line2.p1.y >> line2.p2.x >> line2.p2.y;
        cout << (isIntersect(line1, line2) ? "intersect" : "disjoint") << endl;
    }
    return 0;
}
