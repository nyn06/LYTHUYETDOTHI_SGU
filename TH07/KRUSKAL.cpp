#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// Cau truc canh
struct Edge {
    int u, v, w; // u, v là hai đinh, w là trong so
};

// Mang cha de ktra chu trình
int parent[1001];

// Tim goc cua đinh u
int Find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = Find(parent[u]); // đuong đi nen
}

// Gop hai tap hop
void Union(int u, int v) {
    int pu = Find(u);
    int pv = Find(v);
    if (pu != pv) parent[pu] = pv;
}

int main() {
    ifstream fin("KRUSKAL.INP");
    ofstream fout("KRUSKAL.OUT");

    int n, m;
    fin >> n >> m;

    vector<Edge> edges; // danh sach cac canh
    for (int i = 0; i < m; i++) {
        Edge e;
        fin >> e.u >> e.v >> e.w;
        edges.push_back(e);
    }

    // Sap xep canh theo trọng so tang dan
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
        });

    // Khoi tao DSU
    for (int i = 1; i <= n; i++) parent[i] = i;

    vector<Edge> mst; // ds canh trong cay khung nho nhat
    int total = 0;    // tpng trong so

    for (auto e : edges) {
        if (Find(e.u) != Find(e.v)) { // neu chua cung cây
            Union(e.u, e.v);          // gop hai cay lai
            mst.push_back(e);         // them canh vao ket qua
            total += e.w;
        }
    }

    fout << mst.size() << " " << total << endl;
    for (auto e : mst)
        fout << e.u << " " << e.v << " " << e.w << endl;

    fin.close();
    fout.close();
    return 0;
}
