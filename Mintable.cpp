#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
struct Cell {
    int x, y;
};
// 4 huong di chuyen 
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int main() {
    ifstream fin("mintable.inp");
    ofstream fout("mintable.out");

    int N, M, XI, YI, XJ, YJ;
    fin >> N >> M >> XI >> YI >> XJ >> YJ;

    vector<vector<int>> A(N + 1, vector<int>(M + 1));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            fin >> A[i][j];

    vector<vector<int>> dist(N + 1, vector<int>(M + 1, 1e9));
    vector<vector<Cell>> pre(N + 1, vector<Cell>(M + 1, { -1, -1 }));

    queue<Cell> q;
    q.push({ XI, YI });
    dist[XI][YI] = 0;

    while (!q.empty()) {
        Cell u = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = u.x + dx[k];
            int ny = u.y + dy[k];
            if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
            if (A[nx][ny] == A[u.x][u.y]) continue; // khong đi qua o co cung gia tri 
            if (dist[nx][ny] > dist[u.x][u.y] + A[nx][ny]) {
                dist[nx][ny] = dist[u.x][u.y] + A[nx][ny];
                pre[nx][ny] = u;
                q.push({ nx, ny });
            }
        }
    }

    if (dist[XJ][YJ] == 1e9) {
        fout << 1;
        return 0;
    }

    // truy vet duong di ngan nhat 
    vector<Cell> path;
    int x = XJ, y = YJ;
    while (x != -1 && y != -1) {
        path.push_back({ x, y });
        Cell p = pre[x][y];
        x = p.x;
        y = p.y;
    }
    reverse(path.begin(), path.end());

    fout << 2 << " " << dist[XJ][YJ] << "\n";
    for (auto c : path)
        fout << c.x << " " << c.y << "\n";

    fin.close();
    fout.close();
    return 0;
}
