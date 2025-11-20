#include <iostream>
#include <vector>
using namespace std;

int n; // so dinh 

struct Edge {
    int u; // dinh dau 
    int v; // dinh cuoi 
};

// 1. Ma tran ke -> danh sach ke 
vector<vector<int>> mtkedske(vector<vector<int>>& A) {
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i][j] == 1) {
                adj[i].push_back(j);
            }
        }
    }
    return adj;
}

// 2. Ma tran ke -> danh sach canh 
vector<Edge> mtkedscanh(vector<vector<int>>& A) {
    vector<Edge> edges;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) { // tranh trung canh (do thi vo huong)
            if (A[i][j] == 1) {
                Edge e;
                e.u = i;
                e.v = j;
                edges.push_back(e);
            }
        }
    }
    return edges;
}

// 3. Danh sach ke -> ma tran ke 
vector<vector<int>> dskemtke(vector<vector<int>>& adj) {
    vector<vector<int>> A(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j : adj[i]) {
            A[i][j] = 1;
        }
    }
    return A;
}

// 4. Danh sach ke -> danh sach canh 
vector<Edge> listToEdge(vector<vector<int>>& adj) {
    vector<Edge> edges;
    for (int i = 1; i <= n; i++) {
        for (int j : adj[i]) {
            if (i < j) { // tranh trung canh vi vo huong
                Edge e;
                e.u = i;
                e.v = j;
                edges.push_back(e);
            }
        }
    }
    return edges;
}

// 5. Danh sach canh -> ma tran ke
vector<vector<int>> dscanhmtke(vector<Edge>& edges) {
    vector<vector<int>> A(n + 1, vector<int>(n + 1, 0));
    for (Edge e : edges) {
        int u = e.u, v = e.v;
        A[u][v] = 1;
        A[v][u] = 1; // vi vo huong 
    }
    return A;
}

// 6. Danh sach canh -> danh sach ke 
vector<vector<int>> edgeToList(vector<Edge>& edges) {
    vector<vector<int>> adj(n + 1);
    for (Edge e : edges) {
        int u = e.u, v = e.v;
        adj[u].push_back(v);
        adj[v].push_back(u); // vi vo huong 
    }
    return adj;
}
