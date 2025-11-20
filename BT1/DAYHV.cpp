#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<int> check(N + 1, 0); // check[i] = 1 neu so i da xuat hien
    bool ok = true;

    for (int i = 0; i < N; i++) {
        if (a[i] < 1 || a[i] > N) {
            ok = false; // ngoai pham vi
            break;
        }
        if (check[a[i]] == 1) {
            ok = false; // trung so
            break;
        }
        check[a[i]] = 1; // danh dau da gap
    }

    if (ok) cout << "YES";
    else cout << "NO";

    return 0;
}
