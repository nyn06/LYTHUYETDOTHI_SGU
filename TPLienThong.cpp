#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<vector<int>> dsKe(n + 1);

    // doc ds ke, them canh 2 chieu
    for (int i = 1; i <= n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int v;
        while (ss >> v) {
            if (v != -1) {
                dsKe[i].push_back(v);
                dsKe[v].push_back(i);
            }
        }
    }

    vector<bool> daTham(n + 1, false);
    vector<vector<int>> cacTPLT;

    // duyet qua cac dinh 
    for (int i = 1; i <= n; i++) {
        if (!daTham[i]) {
            vector<int> thanhphan;
            queue<int> q;
            daTham[i] = true;
            q.push(i);

            while (!q.empty()) {
                int u = q.front(); q.pop();
                thanhphan.push_back(u);

                for (int v : dsKe[u]) {
                    if (!daTham[v]) {
                        daTham[v] = true;
                        q.push(v);
                    }
                }
            }
            sort(thanhphan.begin(), thanhphan.end());
            cacTPLT.push_back(thanhphan);
        }
    }
    cout << cacTPLT.size() << "\n";
    for (auto& tp : cacTPLT) {
        for (int i = 0; i < tp.size(); i++) {
            cout << tp[i];
            if (i < tp.size() - 1) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
