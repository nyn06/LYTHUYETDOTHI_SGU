#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int MAX = 1000;
int n;
int a[MAX][MAX];    // ma tran ke 
int deg[MAX];       // bac dinh 
int visited[MAX];   // dung cho DFS

// DFS ktra lien thong
void dfs(int u) {
    visited[u] = 1;
    for (int v = 1; v <= n; v++) {
        if (a[u][v] > 0 && !visited[v]) {
            dfs(v);
        }
    }
}

// Euler bang de quy 
vector<int> euler;
void Euler(int v) {
    for (int u = 1; u <= n; u++) {
        if (a[v][u] > 0) {
            a[v][u]--;
            a[u][v]--;
            Euler(u);
        }
    }
    euler.push_back(v);
}

int main() {
    ifstream fin("DoThiEuler.inp");
    ofstream fout("DoThiEuler.out");

    fin >> n;
    for (int i = 1; i <= n; i++) {
        deg[i] = 0;
        for (int j = 1; j <= n; j++) {
            fin >> a[i][j];
            if (a[i][j]) deg[i] += a[i][j];
        }
    }

    // tim 1 dinh co bac >0 de bat dau
    int start = -1;
    for (int i = 1; i <= n; i++)
        if (deg[i] > 0) { start = i; break; }

    if (start == -1) { // do thi khong co canh nao 
        fout << 1 << endl;
        fout << 1 << endl;
        return 0;
    }

    // ktra bac chan 
    for (int i = 1; i <= n; i++) {
        if (deg[i] % 2 != 0) {
            fout << 0 << endl;
            return 0;
        }
    }

    // ktra lien thong
    dfs(start);
    for (int i = 1; i <= n; i++) {
        if (deg[i] > 0 && !visited[i]) {
            fout << 0 << endl;
            return 0;
        }
    }

    // co chu trinh Euler
    Euler(start);

    fout << 1 << endl;
    for (int i = euler.size() - 1; i >= 0; i--) {
        fout << euler[i];
        if (i > 0) fout << " ";
    }
    fout << endl;

    fin.close();
    fout.close();
    return 0;
}
