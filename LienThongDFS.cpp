#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int n, x;
vector<vector<int>> dsKe;
vector<bool> daTham;
vector<int> ketqua;

void DFS(int u) {
    daTham[u] = true;
    ketqua.push_back(u);
    for (int v : dsKe[u]) {
        if (!daTham[v]) {
            DFS(v);
        }
    }
}

int main() {
    cin >> n >> x;
    cin.ignore();

    dsKe.assign(n + 1, {});
    for (int i = 1; i <= n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int v;
        while (ss >> v) {
            if (v != -1) {
                dsKe[i].push_back(v);
                dsKe[v].push_back(i); // vô hướng
            }
        }
    }

    daTham.assign(n + 1, false);
    DFS(x);

    cout << ketqua.size() << "\n";
    for (int i = 0; i < ketqua.size(); i++) {
        cout << ketqua[i];
        if (i < ketqua.size() - 1) cout << " ";
    }
    cout << "\n";

    return 0;
}
