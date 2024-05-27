#include <iostream>
#include <vector>
using namespace std;

/*
    Ta Quang Pho - 20215450
*/

int main() {
    int n, a;
    cin >> n;

    bool found = false;

    // Nhập danh sách các năm
    while (n--) {
        cin >> a;
        if (((a % 4) == 0 && (a % 100) != 0) || (a % 400 == 0)){
            found = true;
            break;
        }
    }

    // Kiểm tra và hiển thị kết quả
    if (found) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
