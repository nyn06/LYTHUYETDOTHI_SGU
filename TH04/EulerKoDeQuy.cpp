#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
using namespace std;

const int MAX = 1000;
int n;
int a[MAX][MAX];   // mtran ke
int deg[MAX];      // bac dinh

int main() {
    ifstream fin("EulerKoDeQuy.inp");
    ofstream fout("EulerKoDeQuy.out");

    fin >> n;
    for (int i = 1; i <= n; i++) {
        deg[i] = 0;
        for (int j = 1; j <= n; j++) {
            fin >> a[i][j];
            if (a[i][j]) deg[i] += a[i][j];
        }
    }

    // ktra Euler: moi dinh deu bac chan
    for (int i = 1; i <= n; i++) {
        if (deg[i] % 2 != 0) {
            fout << 0 << "\n";
            return 0;
        }
    }

    // chon dinh bat dau
    int start = 1;
    while (start <= n && deg[start] == 0) start++;
    if (start > n) { // khong co canh nao 
        fout << 1 << "\n1\n";
        return 0;
    }

    stack<int> st;
    vector<int> cycle;
    st.push(start);

    while (!st.empty()) {
        int u = st.top();
        int v;
        for (v = 1; v <= n; v++) {
            if (a[u][v] > 0) break;
        }
        if (v <= n) {
            // di qua canh u-v
            st.push(v);
            a[u][v]--;
            a[v][u]--;
        }
        else {
            // khong co canh, lay ra
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
