#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <utility>
using namespace std;

typedef pair<int, int> ii; // first trong so canh, second dinh ke 
const int INF = 1000000000;

vector<vector<ii>> adj;
int n, m, s, t, x;

vector<int> dijkstra(int start, vector<int>& pre) {
    vector<int> dist(n + 1, INF); 
    vector<bool> visited(n + 1, false);
    priority_queue<ii, vector<ii>, greater<ii>> pq; // hang doi uu tien 

    dist[start] = 0;
    pq.push(ii(0, start));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;

        for (auto e : adj[u]) {
            int w = e.first;
            int v = e.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w; // dist khoang cach ngan nhat tu start den v
                pre[v] = u; // dinh truoc v tren duong di ngan nhat 
                pq.push(ii(dist[v], v));
            }
        }
    }
    return dist;
}

vector<int> truyvet(int s, int t, vector<int> pre) {
    vector<int> path;
    for (int u = t; u != -1; u = pre[u])
        path.push_back(u);
    reverse(path.begin(), path.end()); // dao nguoc thu tu (vi di tu dich den nguon)
    if (path.front() != s) path.clear(); // khong co duong di->xoa ket qua
    return path;
}

int main() {
    ifstream fin("NganNhatTrungGian.inp");
    ofstream fout("NganNhatTrungGian.out");

    fin >> n >> m >> s >> t >> x; // x dinh trung gian
    adj.assign(n + 1, vector<ii>()); // adj la ds ke, luu tat ca cac canh cua do thi 

    for (int i = 0; i < m; i++) {
        int u, v, w;
        fin >> u >> v >> w;
        adj[u].push_back(ii(w, v)); 
    }

    vector<int> pre1(n + 1, -1), pre2(n + 1, -1);
    vector<int> dist1 = dijkstra(s, pre1);
    vector<int> dist2 = dijkstra(x, pre2);

    if (dist1[x] == INF || dist2[t] == INF) {
        fout << "Khong co duong di\n";
        return 0;
    }

    // truy vet 2 doan duong
    vector<int> path1 = truyvet(s, x, pre1);
    vector<int> path2 = truyvet(x, t, pre2);

    // ghep 2 doan, bo x lap lai
    vector<int> fullPath = path1; // bo bot dinh x trung lap o 2 doan
    for (int i = 1; i < (int)path2.size(); i++)
        fullPath.push_back(path2[i]);

    int totalDist = dist1[x] + dist2[t]; // tong do dai 2 doan 

    fout << fullPath.size() << " " << totalDist << endl;
    for (int i = 0; i < (int)fullPath.size(); i++)
        fout << fullPath[i] << " ";
    fout << endl;

    fin.close();
    fout.close();
    return 0;
}
