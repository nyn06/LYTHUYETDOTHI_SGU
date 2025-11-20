#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000000;

int main() {
    ifstream fin("Floyd.inp");
    ofstream fout("Floyd.out");

    int n, m;
    fin >> n >> m; // n dinh, m canh

    // khoi tao mtran ke
    vector<vector<int>> d(n + 1, vector<int>(n + 1, INF));

    // khoang cach tu i den i=0
    for (int i = 1; i <= n; i++) d[i][i] = 0; // d[i][j] luu khoang cach ngan nhat tam thoi tu dinh i den dinh j 

    // doc cac canh cua do thi (vi la vo huong nen gan 2 chieu)
    for (int i = 0; i < m; i++) {
        int u, v, w;
        fin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w); // dung min tranh TH co nhieu canh song song, chi giu canh co trong so nho nhat
    }

    // Floyd
    for (int k = 1; k <= n; k++) { // k dinh trung gian dang duoc xet
        for (int i = 1; i <= n; i++) { // dinh bat dau 
            for (int j = 1; j <= n; j++) { // dinh ket thuc 
                if (d[i][k] < INF && d[k][j] < INF) // tranh cong vo cuc
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]); // neu di tu i->j qua k ngan hon so voi i->j truc tiep -> cap nhat lai duong di moi ngan hon
            }
        }
    }

    // Xuat 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == INF) fout << 0 << " ";
            else fout << d[i][j] << " ";
        }
        fout << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
