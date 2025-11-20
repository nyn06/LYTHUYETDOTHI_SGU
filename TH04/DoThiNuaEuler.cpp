#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int MAX = 1000;
int n;
int a[MAX][MAX];      // mtran ke do thi vo huong
int degv[MAX];        // bac dinh 
int vis[MAX];         // DFS lien thong 
vector<int> path;     // chu trinh euler

void dfs(int u) {
    vis[u] = 1;
    for (int v = 1; v <= n; ++v)
        if (a[u][v] > 0 && !vis[v]) dfs(v);
}

// ap dung cho ca duong di (2 dinh le) lan chu trinh (0 dinh le)
void euler(int v) {
    for (int u = 1; u <= n; ++u) {
        while (a[v][u] > 0) {          // neu la do thi don thi 0/1 van an toan cho da canh 
            a[v][u]--; a[u][v]--;
            euler(u);
        }
    }
    path.push_back(v);
}

int main() {
    ifstream fin("DoThiNuaEuler.inp");
    ofstream fout("DoThiNuaEuler.out");
    if (!fin) return 0;

    fin >> n;
    for (int i = 1; i <= n; ++i) {
        degv[i] = 0;
        for (int j = 1; j <= n; ++j) {
            fin >> a[i][j];
            if (a[i][j]) degv[i] += a[i][j];
        }
    }

    // tim mot dinh co bac >0
    int start_any = -1;
    for (int i = 1; i <= n; ++i) if (degv[i] > 0) { start_any = i; break; }

    // khong co canh nao 
    if (start_any == -1) {
        fout << 1 << "\n1\n";
        return 0;
    }

    // dem so dinh bac le
    vector<int> odd;
    for (int i = 1; i <= n; ++i) if (degv[i] % 2) odd.push_back(i);

    // ktra lien thong (bo dinh bac 0)
    dfs(start_any);
    for (int i = 1; i <= n; ++i) {
        if (degv[i] > 0 && !vis[i]) {  // co dinh co canh nhung khong toi duoc
            fout << 0 << "\n";
            return 0;
        }
    }

    // chap nhan 2 dinh le, neu 0 dinh le van ok(vi co duong di la chu trinh)
    if (!(odd.size() == 2 || odd.size() == 0)) {
        fout << 0 << "\n";
        return 0;
    }

    // neu co 2 dinh le -> bat dau o odd[0], neu 0 -> bat ky dinh co bac >0
    int start = (odd.size() == 2 ? odd[0] : start_any);

    euler(start);

    fout << 1 << "\n";
    for (int i = (int)path.size() - 1; i >= 0; --i) {
        fout << path[i] << (i ? ' ' : '\n');
    }

    fin.close(); fout.close();
    return 0;
}
