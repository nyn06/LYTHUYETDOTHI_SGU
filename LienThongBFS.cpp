#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;      // so dinh va dinh bat dau 
    cin.ignore();       // bo ky tu xuong dong con sot

    vector<vector<int>> dsKe(n + 1);

    // doc ds ke
    for (int i = 1; i <= n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int v;
        while (ss >> v) {
            dsKe[i].push_back(v);
        }
    }

    // BFS
    vector<bool> daTham(n + 1, false);
    queue<int> hangdoi;
    vector<int> ketqua;

    daTham[x] = true;
    hangdoi.push(x);

    while (!hangdoi.empty()) {
        int u = hangdoi.front();
        hangdoi.pop();
        ketqua.push_back(u);

        for (int v : dsKe[u]) {
            if (!daTham[v]) {
                daTham[v] = true;
                hangdoi.push(v);
            }
        }
    }
    cout << ketqua.size() << "\n";
    for (int i = 0; i < ketqua.size(); i++) {
        cout << ketqua[i];
        if (i < ketqua.size() - 1) cout << " ";
    }
    cout << "\n";

    return 0;
}
