#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

const int MAX = 7; // domino tu 0..6
int n;
int a[MAX][MAX];    // luu so canh cua ma tran ke(da do thi)
int deg[MAX];       // bac dinh
int visited[MAX];
vector<pair<int, int>> cycle;

// DFS ktra lien thong
void dfs(int u) {
    visited[u] = 1;
    for (int v = 0; v < MAX; v++) {
        if (a[u][v] > 0 && !visited[v]) dfs(v);
    }
}

// xay chu trinh euler
void Euler(int u) {
    for (int v = 0; v < MAX; v++) {
        while (a[u][v] > 0) {
            a[u][v]--; a[v][u]--;
            Euler(v);
            cycle.push_back({ u,v });
        }
    }
}

int main() {
    ifstream fin("Domino.inp");
    ofstream fout("Domino.out");

    fin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; fin >> x >> y;
        a[x][y]++; a[y][x]++;
        deg[x]++; deg[y]++;
    }

    // tim mot dinh bat dau co bac >0
    int start = -1;
    for (int i = 0; i < MAX; i++) if (deg[i] > 0) { start = i; break; }

    if (start == -1) { // khong co canh nao 
        fout << 1 << "\n";
        return 0;
    }

    // ktra bac chan
    for (int i = 0; i < MAX; i++) {
        if (deg[i] % 2) { fout << 0 << "\n"; return 0; }
    }

    // ktra lien thong
    dfs(start);
    for (int i = 0; i < MAX; i++) {
        if (deg[i] > 0 && !visited[i]) { fout << 0 << "\n"; return 0; }
    }

    // tim chu trinh euler
    Euler(start);

    fout << 1 << "\n";
    for (int i = cycle.size() - 1; i >= 0; i--) {
        fout << "(" << cycle[i].first << "," << cycle[i].second << ") ";
    }
    fout << "\n";

    fin.close(); fout.close();
    return 0;
}
