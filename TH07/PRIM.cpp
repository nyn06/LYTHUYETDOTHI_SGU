#include <iostream>
using namespace std;

const int MAX = 1001;
const int INF = 1000000000; // gia tri vo cung lon
int a[MAX][MAX];            // ma tran trong so
bool used[MAX];             // danh dau dinh da chon vao cay
int d[MAX];                 // khoang cach nho nhat tu cay den dinh v
int trace[MAX];             // luu dinh truoc do trong cay
int n, m;                   // so dinh va so canh

int main() {
    cout << "Nhap so dinh va so canh: ";
    cin >> n >> m;

    // khoi tao ma tran trong so
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = 0;

    // nhap danh sach canh
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = a[v][u] = w; // do thi vo huong
    }

    // khoi tao ban dau
    for (int i = 1; i <= n; i++) {
        used[i] = false;
        d[i] = INF;    // tat ca khoang cach ban dau la vo cung
        trace[i] = -1; // chua co dinh truoc do
    }

    // bat dau tu dinh 1
    d[1] = 0;
    int total = 0; // tong trong so cua cay khung

    // lap n lan de chon n dinh
    for (int i = 1; i <= n; i++) {
        int u = -1, minD = INF;

        // tim dinh u chua duoc chon co d[u] nho nhat
        for (int j = 1; j <= n; j++) {
            if (!used[j] && d[j] < minD) {
                minD = d[j];
                u = j;
            }
        }

        if (u == -1) break; // do thi khong lien thong
        used[u] = true;

        // neu khong phai dinh bat dau thi cong them trong so vao tong
        if (trace[u] != -1)
            total += a[u][trace[u]];

        // cap nhat khoang cach den cac dinh chua chon
        for (int v = 1; v <= n; v++) {
            if (a[u][v] && !used[v] && a[u][v] < d[v]) {
                d[v] = a[u][v];
                trace[v] = u;
            }
        }
    }

    // in ket qua
    cout << n - 1 << " " << total << endl;
    for (int v = 2; v <= n; v++)
        cout << trace[v] << " " << v << " " << a[trace[v]][v] << endl;

    return 0;
}
