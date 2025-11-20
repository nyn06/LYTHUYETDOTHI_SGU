#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define FI "BonChua.inp"
#define FO "BonChua.out"

int n;                             // so dinh 
vector<vector<int>> a;             // ma tran ke
vector<int> bacvao, bacra;         // bac vao, bac ra cua tung dinh 
vector<int> ketqua;                // luu cac dinh bon chua 

// Ham nhap ma tran ke 
void Nhap() {
    ifstream fi(FI);
    fi >> n;
    a.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fi >> a[i][j];  
        }
    }
    fi.close();
}

// ham tinh bacvao bacra cua tung dinh 
void TinhBac() {
    bacvao.assign(n, 0);
    bacra.assign(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                bacra[i]++;   // co cung i -> j
                bacvao[j]++;  // j co cung di vao 
            }
        }
    }
}

// ham tim cac dinh bon chua (chi co cung vao, khong co cung ra)
void TimBonChua() {
    for (int i = 0; i < n; i++) {
        if (bacra[i] == 0 && bacvao[i] > 0) {
            ketqua.push_back(i + 1); // +1 vi dinh danh so tu 1
        }
    }
}

void Xuat() {
    ofstream fo(FO);
    fo << ketqua.size() << endl;   // in so luong bon chua 
    if (!ketqua.empty()) {
        for (int i = 0; i < ketqua.size(); i++) {
            fo << ketqua[i] << " ";
        }
        fo << endl;
    }
    fo.close();
}

int main() {
    Nhap();
    TinhBac();
    TimBonChua();
    Xuat();
    return 0;
}
