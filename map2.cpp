#include <iostream>
#include <map>
using namespace std;

struct T {
    int x, y, z;
    T() { }
    T(int a, int b, int c) : x(a), y(b), z(c) {}

    // So sánh mặc định: tăng dần theo x, rồi y, rồi z
    bool operator<(const T& t) const {
        if (x != t.x) return x < t.x;
        if (y != t.y) return y < t.y;
        return z < t.z;
    }
};

// Comparator riêng (cũng theo thứ tự tăng dần)
struct MyComp {
    bool operator()(const T& a, const T& b) const {
        if (a.x != b.x) return a.x < b.x;
        if (a.y != b.y) return a.y < b.y;
        return a.z < b.z;
    }
};

int main() {
    map<T, int> m1;
    m1[T(1, 2, 3)] = 1;
    m1[T(3, 3, 1)] = 2;
    m1[T(1, 2, 1)] = 3;
    m1[T(2, 2, 1)] = 4;

    cout << "== Map m1 (mac dinh operator<) ==" << endl;
    for (auto& p : m1) {
        cout << "{x=" << p.first.x
            << " y=" << p.first.y
            << " z=" << p.first.z
            << "} -> " << p.second << endl;
    }

    // Tạo map m2 với comparator riêng
    map<T, int, MyComp> m2(m1.begin(), m1.end());

    cout << "\n== Map m2 (voi MyComp) ==" << endl;
    for (auto& p : m2) {
        cout << "{x=" << p.first.x
            << " y=" << p.first.y
            << " z=" << p.first.z
            << "} -> " << p.second << endl;
    }

    return 0;
}
