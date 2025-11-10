#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

const int MAX = 100;
int n, m;
vector<int> adj[MAX];   // danh sach ke
int color[MAX];         // luu mau hien tai
int bestColor[MAX];     // luu mau tot nhat
int minColor = 1000;    // so mau nho nhat tim duoc

// ham hoan doi 2 bien
void swapInt(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

// sap xep thu tu dinh giam dan theo bac
void sortByDegree(int deg[], int order[]) {
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (deg[i] < deg[j]) {
                swapInt(deg[i], deg[j]);
                swapInt(order[i], order[j]);
            }
        }
    }
}

// kiem tra xem mau c co hop le voi dinh u khong
bool canColor(int u, int c) {
    for (int v : adj[u]) {
        if (color[v] == c)
            return false;
    }
    return true;
}

// thuat toan to mau toi uu (quay lui)
void TryColor(int u, int maxUsed) {
    if (u > n) {
        if (maxUsed < minColor) {
            minColor = maxUsed;
            for (int i = 1; i <= n; i++)
                bestColor[i] = color[i];
        }
        return;
    }

    for (int c = 1; c <= maxUsed + 1; c++) {
        if (canColor(u, c)) {
            color[u] = c;
            if (c < minColor)
                TryColor(u + 1, (c > maxUsed ? c : maxUsed));
            color[u] = 0;
        }
    }
}

// thuat toan to mau tham lam co sap thu tu
void GreedyColor(ofstream& fout) {
    int degree[MAX];
    int order[MAX];

    // tinh bac
    for (int i = 1; i <= n; i++) {
        degree[i] = adj[i].size();
        order[i] = i;
    }

    // sap giam dan theo bac
    sortByDegree(degree, order);

    int colorG[MAX] = { 0 };
    int maxColor = 0;

    // to mau theo thu tu da sap
    for (int k = 1; k <= n; k++) {
        int u = order[k];
        bool used[MAX] = { false };

        for (int v : adj[u]) {
            if (colorG[v] != 0)
                used[colorG[v]] = true;
        }

        int c = 1;
        while (used[c]) c++;

        colorG[u] = c;
        if (c > maxColor)
            maxColor = c;
    }

    fout << "Ket qua to mau tham lam:\n";
    fout << "So mau su dung: " << maxColor << endl;
    for (int c = 1; c <= maxColor; c++) {
        fout << "Mau " << c << ": ";
        for (int i = 1; i <= n; i++)
            if (colorG[i] == c)
                fout << i << " ";
        fout << endl;
    }
}

int main() {
    ifstream fin("TOMAU2.INP");
    ofstream fout("TOMAU2.OUT");

    fin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // goi thuat toan tham lam
    GreedyColor(fout);

    // goi thuat toan toi uu
    for (int i = 1; i <= n; i++) color[i] = 0;
    TryColor(1, 0);

    fout << "\nKet qua to mau toi uu:\n";
    fout << "So mau nho nhat: " << minColor << endl;
    for (int c = 1; c <= minColor; c++) {
        fout << "Mau " << c << ": ";
        for (int i = 1; i <= n; i++)
            if (bestColor[i] == c)
                fout << i << " ";
        fout << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
