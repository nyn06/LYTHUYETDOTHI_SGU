#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int MAXN = 1000;
int n;
int a[MAXN][MAXN];       // mtran ke
int x[MAXN];             // Hamilton
vector<bool> visited;    // danh dau dinh da dung 
bool found = false;

ofstream fout("Hamilton.out");

void PrintCycle() {
    fout << 1 << "\n";
    for (int i = 1; i <= n; i++) fout << x[i] << " ";
    fout << x[1] << "\n";    // quay lai dinh dau de thanh chu trinh
}

void Hamilton(int i) {
    if (found) return; // chi can tim 1 chu trinh 
    for (int j = 1; j <= n; j++) {
        if (a[x[i - 1]][j] && !visited[j]) {
            x[i] = j;
            visited[j] = true;
            if (i == n) {
                if (a[x[i]][x[1]]) { // noi ve lai dinh dau 
                    PrintCycle();
                    found = true;
                    return;
                }
            }
            else Hamilton(i + 1);
            visited[j] = false;
        }
    }
}

int main() {
    ifstream fin("Hamilton.inp");
    fin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fin >> a[i][j];
    fin.close();

    visited.assign(n + 1, false);
    x[1] = 1; // chon dinh 1 lam xuat phat
    visited[1] = true;

    Hamilton(2);

    if (!found) fout << 0 << "\n";

    fout.close();
    return 0;
}
