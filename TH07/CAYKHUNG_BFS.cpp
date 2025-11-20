#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

// KHAI BAO BIEN TOAN CUC
vector<int> adj[1001];             // ds ke cua do thi (adj[u] chua cac dinh ke voi u)
bool visited[1001];                // mang danh dau dinh da tham hay chua
vector<pair<int, int>> treeEdges;  // luu cac canh thuoc cay khung BFS

// HAM DUYET BFS
void BFS(int start) {
    queue<int> q;                  // hang doi luu cac dinh can duyet
    visited[start] = true;         // danh dau dinh bat dau da tham
    q.push(start);                 // dua dinh bat dau vao hang doi

    while (!q.empty()) {           // lap den khi hang doi rong
        int u = q.front();         // lay phan tu dau hang doi
        q.pop();

        for (int v : adj[u]) {     // duyet cac dinh ke cua u
            if (!visited[v]) {     // neu v chua duoc tham
                visited[v] = true; // danh dau la da tham
                treeEdges.push_back({ u, v }); // them canh (u, v) vao cay khung
                q.push(v);         // dua v vao hang doi de duyet tiep
            }
        }
    }
}

int main() {
    ifstream fin("CAYKHUNG_BFS.INP");   
    ofstream fout("CAYKHUNG_BFS.OUT");  

    int n, m;                           // n: so dinh, m: so canh
    fin >> n >> m;                      

    // NHAP CAC CANH CUA DO THI
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;                  
        adj[u].push_back(v);            // them v vao ds ke cua u
        adj[v].push_back(u);            // them u vao ds ke cua v (do thi vo huong)
    }

    // KHOI TAO MANG VISITED
    for (int i = 1; i <= n; i++) visited[i] = false;

    // DUYET BFS TU DINH 1
    BFS(1);                             // goi ham BFS bat dau tu dinh 1

    // GHI KET QUA RA FILE
    fout << treeEdges.size() << endl;   // in so canh trong cay khung
    for (auto e : treeEdges)
        fout << e.first << " " << e.second << endl;  // in tung canh (u, v)

    fin.close();
    fout.close();
    return 0;
}
    
