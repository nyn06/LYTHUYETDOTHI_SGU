#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

const int MAX = 1001;
int n, m;
vector<int> adj[MAX]; // danh sach ke
int color[MAX];       // luu mau cua moi dinh

int main() {
    ifstream fin("TOMAU.INP");  
    ofstream fout("TOMAU.OUT"); 

    fin >> n >> m; // doc so dinh va so canh

    // doc danh sach canh
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // to mau tung dinh
    for (int u = 1; u <= n; u++) {
        bool usedColor[MAX] = { false }; // danh dau mau da dung boi cac dinh ke
        for (int v : adj[u]) {
            if (color[v] != 0)
                usedColor[color[v]] = true;
        }

        // chon mau nho nhat chua bi dung
        int c = 1;
        while (usedColor[c]) c++;
        color[u] = c;
    }

    // tim so mau lon nhat
    int maxColor = 0;
    for (int i = 1; i <= n; i++)
        if (color[i] > maxColor)
            maxColor = color[i];

    // ghi ket qua ra file
    fout << maxColor << endl;
    for (int c = 1; c <= maxColor; c++) {
        for (int i = 1; i <= n; i++)
            if (color[i] == c)
                fout << i << " ";
        fout << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
