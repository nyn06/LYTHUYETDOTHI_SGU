/* Cắt chuỗi theo dấu ngắt từ và đếm tần số */
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int main() {
    char s[] = "Hom nay thu hai. Hom sau thu ba, mot thu tu.";
    map<string, int> tanso;

    // Tách từ theo dấu cách, dấu phẩy, dấu chấm
    char* p = strtok(s, " ,.");
    while (p != NULL) {
        string sub = string(p);
        if (tanso.find(sub) == tanso.end())
            tanso[sub] = 1;   // thêm mới
        else
            tanso[sub]++;     // tăng đếm

        p = strtok(NULL, " ,.");
    }

    // In kết quả đếm tần số
    cout << "== Tan so xuat hien cua cac tu ==" << endl;
    for (map<string, int>::iterator it = tanso.begin(); it != tanso.end(); it++) {
        cout << "[" << it->first << "] xuat hien " << it->second << " lan." << endl;
    }

    // Xoá từ "Hom"
    tanso.erase("Hom");

    // Lấy các phần tử có key nằm trong khoảng [c, s]
    map<string, int>::iterator jLeft = tanso.lower_bound("c");  // >= "c"
    map<string, int>::iterator jRight = tanso.upper_bound("s"); // > "s"
    vector<pair<string, int>> v(jLeft, jRight);

    cout << "\n== Doan con trong map (key tu 'c' den 's') ==" << endl;
    for (size_t i = 0; i < v.size(); i++) {
        cout << "[" << v[i].first << "] xuat hien " << v[i].second << " lan." << endl;
    }

    // Xoá hết phần tử trong map
    if (!tanso.empty())
        tanso.clear();

    return 0;
}
