#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// KHAI BAO BIEN TOAN CUC
vector<int> adj[1001];             // ds ke cua do thi (adj[u] chua cac dinh ke voi u)
bool visited[1001];                // mang danh dau dinh da tham hay chua
vector<pair<int, int>> treeEdges;  // luu cac canh thuoc cay khung DFS

// HAM DUYET DFS
void DFS(int u) {
    visited[u] = true;             // danh dau dinh u da tham

    for (int v : adj[u]) {         // duyet qua tat ca dinh ke v cua u
        if (!visited[v]) {         // neu v chua duoc tham
            treeEdges.push_back({ u, v }); // them canh (u, v) vao danh sach cay khung
            DFS(v);                // goi de quy tiep tuc duyet tu dinh v
        }
    }
}

int main() {
    ifstream fin("CAYKHUNG_DFS.INP");  
    ofstream fout("CAYKHUNG_DFS.OUT");  

    int n, m;                           // n: so dinh, m: so canh
    fin >> n >> m;                      // doc n va m tu file
    // NHAP CAC CANH CUA DO THI
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;                  // doc mot canh (u, v)
        adj[u].push_back(v);            // them v vao ds ke cua u
        adj[v].push_back(u);            // them u vao ds ke cua v (do thi vo huong)
    }
    // DUYET DFS TU DINH 1
    DFS(1);                             // goi ham DFS bat dau tu dinh 1

    fout << treeEdges.size() << endl;   // in so luong canh trong cay khung
    for (auto e : treeEdges)
        fout << e.first << " " << e.second << endl;  // in tung canh (u, v)
    fin.close();
    fout.close();

    return 0;
}
