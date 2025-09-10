#include <iostream>
#include <vector>
using namespace std;

// Ham kiem tra so nguyen to
bool snt(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

// Ham tinh so mu cua p trong N!
int demsomu(int N, int p) {
    int cnt = 0;
    while (N > 0) {
        N /= p;
        cnt += N;
    }
    return cnt;
}

int main() {
    int N;
    while (cin >> N) { // doc nhieu test
        vector<int> result;
        for (int p = 2; p <= N; p++) {
            if (snt(p)) {
                int e = demsomu(N, p);
                result.push_back(e);
            }
        }
        // in ket qua
        for (int i = 0; i < (int)result.size(); i++) {
            cout << result[i];
            if (i + 1 < (int)result.size()) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
