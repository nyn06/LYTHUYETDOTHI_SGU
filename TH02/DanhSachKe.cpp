#include <iostream>
#include <sstream>   // de tach so trong 1 dong 
#include <string>
#include <vector>
using namespace std;

#define FI "DANHSACHKE.INP"
#define FO "DANHSACHKE.OUT"

int n;                        // so dinh cua do thi
string s;                     // dung de luu tung dong khi doc
vector<vector<int>> adjlist;  // danh sach ke: moi dinh co 1 vector luu cac dinh ke

void xuly() {
    // doc so dinh
    cin >> n;
    cin.ignore(); // bo ky tu xuong dong con sot lai sau khi nhap n

    adjlist.resize(n + 1); // cap phat bo nho cho n dinh (danh so tu 1 den n)

    // doc danh sach ke cho tung dinh 
    for (int u = 1; u <= n; u++) {
        getline(cin, s);         // doc ca 1 dong 
        stringstream ss(s);      // dua dong vao stringstram de tach so 
        int v;
        while (ss >> v) {        // doc tung so trong dong 
            adjlist[u].push_back(v); // them v vao danh sach ke cua u
        }
    }

    // in so dinh 
    cout << n << endl;
    // in bac cua tung dinh 
    for (int u = 1; u <= n; u++) {
        cout << adjlist[u].size() << endl;
    }
}

int main() {
    xuly();  
    return 0;
}
