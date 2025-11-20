#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

int n, x, y, z;
vector<vector<int>> dsKe;

int demTPLT(int boX = -1, int boY = -1, int boDinh = -1) {
    vector<bool> daTham(n + 1, false);
    int soTP = 0;

    for (int i = 1; i <= n; i++) {
        if (!daTham[i] && i != boDinh) {
            soTP++;
            queue<int> q;
            q.push(i);
            daTham[i] = true;

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : dsKe[u]) {
                    // bỏ cạnh (boX,boY) và (boY,boX)
                    if ((u == boX && v == boY) || (u == boY && v == boX)) continue;
                    // bỏ đỉnh boDinh
                    if (v == boDinh) continue;

                    if (!daTham[v]) {
                        daTham[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    return soTP;
}

int main() {
    cin >> n >> x >> y >> z;
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
                dsKe[v].push_back(i);
            }
        }
    }

    int soTP1 = demTPLT();
    int soTP2 = demTPLT(x, y, -1);

    if (soTP2 > soTP1) cout << "canh cau\n";
    else cout << "khong la canh cau\n";

    soTP2 = demTPLT(-1, -1, z);
    if (soTP2 > soTP1) cout << "dinh khop\n";
    else cout << "khong la dinh khop\n";

    return 0;
}

