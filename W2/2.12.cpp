#include <bits/stdc++.h>

//*************************//

/* Ta Quang Pho - 20215450 */

//*************************//

using namespace std;

int main () {
    ios_base :: sync_with_stdio (false);
    cin.tie(0); cout.tie(0);

    vector <pair <int, int>> v;             // Vector v lưu các cặp {khóa, giá trị}

    int key, value;                         // Các biến trung gian để đẩy giá trị vào vector
    while (cin >> key) {                    // Dừng khi gặp EOF
        cin >> value;
        v.push_back({key, value});
    }

    // Hàm sắp xếp với phép so sánh nặc danh
    sort(v.begin(), v.end(), [](const pair <int, int> &a, const pair <int, int> &b) {
        if (a.second == b.second) {     // Nếu 2 phần tử có giá trị bằng nhau
            return a.first > b.first;   // thì ưu tiên khóa lớn hơn
        }
        return a.second > b.second;     // Giá trị lớn hơn đứng trước
    });

    // In ra các phần tử được sắp xếp theo yêu cầu
    for (pair <int, int> item : v) {    // Duyệt các phần tử kiểu pair <int, int> trong vector
        cout << item.first << ' ' << item.second << '\n';   // In (Khóa + ' ' + Giá trị)
    }

    return 0;
}
