#include <iostream>
#include <algorithm>
using namespace std;

class CSet {
private:
    int n;
    int* data;

    // 辅助函数：检查元素是否存在
    bool contains(int value) const {
        for (int i = 0; i < n; ++i)
            if (data[i] == value) return true;
        return false;
    }

    // 辅助函数：排序并去重
    void sortAndUnique() {
        if (n <= 1) return;
        // 冒泡排序
        for (int i = 0; i < n - 1; ++i)
            for (int j = 0; j < n - i - 1; ++j)
                if (data[j] > data[j + 1])
                    swap(data[j], data[j + 1]);
        // 去重
        int newSize = 1;
        for (int i = 1; i < n; ++i) {
            if (data[i] != data[newSize - 1])
                data[newSize++] = data[i];
        }
        n = newSize;
    }

public:
    CSet(int size = 0, const int* elements = nullptr) : n(0), data(nullptr) {
        if (size <= 0) return;
        data = new int[size];
        for (int i = 0; i < size; ++i)
            data[i] = elements[i];
        n = size;
        sortAndUnique();
    }

    // 拷贝构造函数
    CSet(const CSet& other) : n(other.n) {
        data = new int[n];
        for (int i = 0; i < n; ++i)
            data[i] = other.data[i];
    }

    // 析构函数
    ~CSet() {
        delete[] data;
    }

    // 赋值运算符重载
    CSet& operator=(const CSet& other) {
        if (this != &other) {
            delete[] data;
            n = other.n;
            data = new int[n];
            for (int i = 0; i < n; ++i)
                data[i] = other.data[i];
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const CSet& s) {
        if (s.n > 0) {
            os << s.data[0];
            for (int i = 1; i < s.n; ++i)
                os << " " << s.data[i];
        }
        return os;
    }

    CSet operator+(const CSet& other) const {
        // 计算并集大小
        int unionSize = n;
        for (int i = 0; i < other.n; ++i)
            if (!contains(other.data[i]))
                unionSize++;

        int* unionData = new int[unionSize];
        int idx = 0;
        for (int i = 0; i < n; ++i)
            unionData[idx++] = data[i];
        for (int i = 0; i < other.n; ++i)
            if (!contains(other.data[i]))
                unionData[idx++] = other.data[i];

        CSet result(unionSize, unionData);
        delete[] unionData;
        return result;
    }

    CSet operator-(const CSet& other) const {
        // 计算差集大小
        int diffSize = 0;
        for (int i = 0; i < n; ++i)
            if (!other.contains(data[i]))
                diffSize++;

        int* diffData = new int[diffSize];
        int idx = 0;
        for (int i = 0; i < n; ++i)
            if (!other.contains(data[i]))
                diffData[idx++] = data[i];

        CSet result(diffSize, diffData);
        delete[] diffData;
        return result;
    }

    CSet operator*(const CSet& other) const {
        // 计算交集大小
        int intersectSize = 0;
        for (int i = 0; i < n; ++i)
            if (other.contains(data[i]))
                intersectSize++;

        int* intersectData = new int[intersectSize];
        int idx = 0;
        for (int i = 0; i < n; ++i)
            if (other.contains(data[i]))
                intersectData[idx++] = data[i];

        CSet result(intersectSize, intersectData);
        delete[] intersectData;
        return result;
    }
};

int main() {
    int t;
    cin >> t;
    for (int caseNum = 0; caseNum < t; ++caseNum) {
        int n, m;
        cin >> n;
        int* a = new int[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        cin >> m;
        int* b = new int[m];
        for (int i = 0; i < m; ++i)
            cin >> b[i];

        CSet A(n, a);
        CSet B(m, b);
        CSet unionAB = A + B;
        CSet intersectAB = A * B;
        CSet diffAB = A - B;
        CSet diffBA = B - A;
        CSet symmetricDiff = diffAB + diffBA;

        cout << "A:" << A << endl;
        cout << "B:" << B << endl;
        cout << "A+B:" << unionAB << endl;
        cout << "A*B:" << intersectAB << endl;
        cout << "(A-B)+(B-A):" << symmetricDiff << endl;

        delete[] a;
        delete[] b;
        if (caseNum < t - 1) cout << endl;
    }
    return 0;
}