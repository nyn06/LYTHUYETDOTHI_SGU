#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;   // so dinh va 2 dinh x,y
    cin.ignore();

    vector<vector<int>> dsKe(n + 1);

    // doc ds ke va them 2 canh chieu 
    for (int i = 1; i <= n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int v;
        while (ss >> v) {
            if (v != -1) {
                dsKe[i].push_back(v);
                dsKe[v].push_back(i); //them nguoc lai vi do thi vo huong
            }
        }
    }

    // Sap xep ds ke de BFS duyet theo thu tu tang dan
    for (int i = 1; i <= n; i++) {
        sort(dsKe[i].begin(), dsKe[i].end());
    }

    // BFS
    vector<bool> daTham(n + 1, false);
    vector<int> truoc(n + 1, -1);
    queue<int> q;

    daTham[x] = true;
    q.push(x);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == y) break; // thay y thi dung

        for (int v : dsKe[u]) {
            if (!daTham[v]) {
                daTham[v] = true;
                truoc[v] = u;
                q.push(v);
            }
        }
    }

    // Truy vet nguoc tu y ve x
    if (!daTham[y]) {
        cout << 0 << "\n"; // khong co duong di
        return 0;
    }

    vector<int> duongdi;
    for (int v = y; v != -1; v = truoc[v]) {
        duongdi.push_back(v);
    }
    reverse(duongdi.begin(), duongdi.end());


    cout << duongdi.size() << "\n";
    for (int i = 0; i < duongdi.size(); i++) {
        cout << duongdi[i];
        if (i < duongdi.size() - 1) cout << " ";
    }
    cout << "\n";

    return 0;
}
