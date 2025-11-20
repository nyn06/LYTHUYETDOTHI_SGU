#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <utility>
using namespace std;

typedef pair<int, int> ii;
const int INF = 1000000000;

int main() {
    ifstream fin("DijkstraPriorityQueue.inp");
    ofstream fout("DijkstraPriorityQueue.out");

    int n, m, s, t;
    fin >> n >> m >> s >> t; // n dinh, m canh, s dinh xuat phat, t dinh dich

    vector<vector<ii>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        fin >> u >> v >> w;
        adj[u].push_back(ii(w, v)); // adj[u] luu tat ca cac dinh ke voi u, moi phan tu la cap (w,v)
    }

    vector<int> dist(n + 1, INF); // dist[v] khoang cach ngan nhat tu s den v (ban dau gan vo cung)
    vector<int> pre(n + 1, -1); // pre[v] dinh dung truoc v trong duong di ngan nhat 
    vector<bool> visited(n + 1, false); // visited[v] danh dau dinh v da duoc duyet hay chua 

    priority_queue<ii, vector<ii>, greater<ii>> pq; // hang doi uu tien 
    dist[s] = 0;
    pq.push(ii(0, s));

    while (!pq.empty()) {
        int u = pq.top().second; // lay dinh co khoang cach nho nhat trong hang doi u 
        pq.pop();
        if (visited[u]) continue; // neu u duoc xu ly -> bo qua 
        visited[u] = true;

        for (auto e : adj[u]) {
            int w = e.first;
            int v = e.second;
            if (dist[v] > dist[u] + w) { // tim duoc duong di ngan hon 
                dist[v] = dist[u] + w; // cap nhat
                pre[v] = u; // luu lai 
                pq.push(ii(dist[v], v)); // xet tiep 
            }
        }
    }

    if (dist[t] == INF) {
        fout << "Khong co duong di\n";
        return 0;
    }

    vector<int> path;
    for (int u = t; u != -1; u = pre[u])
        path.push_back(u);
    reverse(path.begin(), path.end());

    fout << path.size() << " " << dist[t] << endl;
    for (int i = 0; i < (int)path.size(); i++)
        fout << path[i] << " ";
    fout << endl;

    fin.close();
    fout.close();
    return 0;
}
