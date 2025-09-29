#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    cin.ignore();

    vector<vector<int>> dsKe(n + 1);

    // doc ds ke
    for (int i = 1; i <= n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int v;
        while (ss >> v) {
            if (v != -1) {
                dsKe[i].push_back(v);
                dsKe[v].push_back(i); // vo huong
            }
        }
    }

    vector<bool> daTham(n + 1, false);
    vector<int> ketqua;

    stack<int> st;
    st.push(x);
    daTham[x] = true;

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        ketqua.push_back(u);

        for (int v : dsKe[u]) {
            if (!daTham[v]) {
                daTham[v] = true;
                st.push(v);
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
