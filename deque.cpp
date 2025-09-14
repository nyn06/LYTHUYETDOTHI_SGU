#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    // Khởi tạo deque a với 2 phần tử đều là (-1, "NULL")
    deque<pair<int, string>> a(2, make_pair(-1, string("NULL")));
    deque<pair<int, string>> b;

    // Thêm phần tử vào đầu deque
    a.push_front(make_pair(1, string("Mot")));
    a.push_front(make_pair(2, string("Hai")));

    // Sao chép nội dung của a vào b
    b = a;

    // Duyệt và xuất ra
    while (!b.empty()) {
        pair<int, string> v = b.front();
        b.pop_front();
        cout << "(" << v.first << "," << v.second << ") ";
    }

    return 0;
}
