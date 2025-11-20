#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <fstream>
using namespace std;
// cau truc bieu dien hinh tron 
struct Circle {
    double x, y, r;
};

// ham tinh khoang cach giua hai tam tru di tong ban kinh
double dist(const Circle& a, const Circle& b) {
    double d = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    return d - (a.r + b.r);
}

int main() {
    ifstream fin("circle.inp");  
    ofstream fout("circle.out"); 


    int n, S, T;
    fin >> n >> S >> T;

    vector<Circle> c(n + 1);
    for (int i = 1; i <= n; i++)
        fin >> c[i].x >> c[i].y >> c[i].r;

    // xay ds ke
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            double d = dist(c[i], c[j]);
            if (d >= 50 && d <= 60) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // BFS 
    vector<int> pre(n + 1, -1), vis(n + 1, 0);
    queue<int> q;
    q.push(S);
    vis[S] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == T) break;
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                pre[v] = u;
                q.push(v);
            }
        }
    }

    // neu khong co duong di 
    if (!vis[T]) {
        fout << 1;
        return 0;
    }

    // truy vet duong di 
    vector<int> path;
    for (int v = T; v != -1; v = pre[v]) path.push_back(v);
    reverse(path.begin(), path.end());

    fout << 2 << " " << path.size() - 1 << " " << path.size() << "\n";
    for (int i = 0; i < path.size(); i++)
        fout << path[i] << " " << (i + 1 < path.size() ? 1 : 0) << "\n";

    fin.close();
    fout.close();
    return 0;
}

