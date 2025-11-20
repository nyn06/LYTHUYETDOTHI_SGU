#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <utility>
using namespace std;

typedef pair<int, int> ii;      // khoang cach: int dau, dinh ke: int sau
const int INF = 1000000000;

int main() {
    ifstream fin("Dijkstra.inp");
    ofstream fout("Dijkstra.out");

    int n, m, s, t;
    fin >> n >> m >> s >> t; // n: dinh, m: canh, s va t: dinh bat dau va dinh ket thuc

    vector<vector<ii>> adj(n + 1); // adj[u] chua cac cap (w, v)
    for (int i = 0; i < m; i++) {
        int u, v, w;
        fin >> u >> v >> w;
        adj[u].push_back(ii(w, v));
    }

    vector<int> dist(n + 1, INF);
    vector<int> pre(n + 1, -1);
    vector<bool> visited(n + 1, false);

    // Hang doi uu tien: phan tu dau tien co gia tri dist nho nhat
    priority_queue<ii, vector<ii>, greater<ii>> pq;

    dist[s] = 0;
    pq.push(ii(0, s));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto e : adj[u]) {
            int w = e.first;
            int v = e.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pre[v] = u;
                pq.push(ii(dist[v], v));
            }
        }
    }

    if (dist[t] == INF) {
        fout << "Khong co duong di\n";
        return 0;
    }

    // Truy vet duong di 
    vector<int> path;
    for (int u = t; u != -1; u = pre[u])
        path.push_back(u);
    reverse(path.begin(), path.end()); // dao lai thu tu (vi truy nguoc tu dich->nguon)

    fout << path.size() << " " << dist[t] << endl;
    for (int i = 0; i < (int)path.size(); i++)
        fout << path[i] << " ";
    fout << endl;

    fin.close();
    fout.close();
    return 0;
}

