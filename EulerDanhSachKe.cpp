#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX = 1000;
int n, m;
vector<int> adj[MAX];  // ds ke
int deg[MAX];
bool visited[MAX];

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v);
    }
}

int main() {
    ifstream fin("EulerDanhSachKe.inp");
    ofstream fout("EulerDanhSachKe.out");

    fin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }

    // ktra bac chan
    for (int i = 1; i <= n; i++) {
        if (deg[i] % 2 != 0) {
            fout << 0 << "\n";
            return 0;
        }
    }

    // tim dinh bat dau co bac lon hon 0
    int start = -1;
    for (int i = 1; i <= n; i++) if (deg[i] > 0) { start = i; break; }
    if (start == -1) { // do thi rong
        fout << 1 << "\n1\n";
        return 0;
    }

    // ktra lien thong
    dfs(start);
    for (int i = 1; i <= n; i++) {
        if (deg[i] > 0 && !visited[i]) {
            fout << 0 << "\n";
            return 0;
        }
    }

    // Hierholzer ko de quy 
    stack<int> st;
    vector<int> cycle;
    st.push(start);

    while (!st.empty()) {
        int u = st.top();
        if (!adj[u].empty()) {
            int v = adj[u].back();
            adj[u].pop_back();
            auto it = find(adj[v].begin(), adj[v].end(), u);
            if (it != adj[v].end()) adj[v].erase(it);
            st.push(v);
        }
        else {
            cycle.push_back(u);
            st.pop();
        }
    }

    fout << 1 << "\n";
    for (int i = cycle.size() - 1; i >= 0; i--) {
        fout << cycle[i] << (i ? ' ' : '\n');
    }

    fin.close();
    fout.close();
    return 0;
}
