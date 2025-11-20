#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define FI "DanhSachCanh.inp"
#define FO "DanhSachCanh.out"

int n, m;                 // n = so dinh, m = so canh
vector<int> deg;          // mang luu bac cac dinh 

// ham doc du lieu tu file 
void Nhap() {
    ifstream fi(FI);
    fi >> n >> m;             // doc so dinh va so canh 
    deg.assign(n + 1, 0);     // khoi tao mang bac, ban dau tat ca = 0

    for (int i = 0; i < m; i++) {
        int u, v;
        fi >> u >> v;         // đọc một cạnh doc mot canh
        deg[u]++;             // bac dinh u +1
        deg[v]++;             // bac dinh v +1 (vi do thi vo huong)
    }

    fi.close();
}

void Xuat() {
    ofstream fo(FO);
    fo << n << "\n";          // dong dau in so dinh 
    for (int i = 1; i <= n; i++) {
        fo << deg[i] << "\n"; // in bac tung dinh 
    }
    fo.close();
}

int main() {
    Nhap();
    Xuat();
    return 0;
}
