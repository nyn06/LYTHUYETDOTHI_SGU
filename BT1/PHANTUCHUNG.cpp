#include <iostream>
#include <vector>
using namespace std;

int main() {
    int nx, ny, nz;
    cin >> nx;
    vector<int> x(nx);
    for (int i = 0; i < nx; i++) cin >> x[i];

    cin >> ny;
    vector<int> y(ny);
    for (int i = 0; i < ny; i++) cin >> y[i];

    cin >> nz;
    vector<int> z(nz);
    for (int i = 0; i < nz; i++) cin >> z[i];

    // mang danh dau (gioi han gia tri <= 10000)
    const int MAXV = 10000;
    vector<int> check1(MAXV + 1, 0), check2(MAXV + 1, 0), check3(MAXV + 1, 0);

    for (int v : x) check1[v] = 1;
    for (int v : y) check2[v] = 1;
    for (int v : z) check3[v] = 1;

    vector<int> common;
    for (int v = 0; v <= MAXV; v++) {
        if (check1[v] && check2[v] && check3[v]) {
            common.push_back(v);
        }
    }

    cout << common.size() << "\n";
    for (int i = 0; i < (int)common.size(); i++) {
        cout << common[i] << " ";
    }

    return 0;
}
