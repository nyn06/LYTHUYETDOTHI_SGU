#include <iostream>
using namespace std;

int main() {
    long long N;
    // doc nhieu dong den het file
    while (cin >> N) {
        long long ans = 0;
        while (N > 0) {
            ans += N / 5;
            N /= 5;
        }
        cout << ans << "\n";
    }
    return 0;
}
