#include <iostream>
#include <algorithm>
using namespace std;

/*
    Ta Quang Pho - 20215450
*/

int w, h;
int table[601][601];

void init() {
    // Khởi tạo bảng table với giá trị ban đầu là i * j
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            table[i][j] = i * j;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> w >> h;
    int m;
    cin >> m;
    init();

    // Cập nhật giá trị trong table với các ô đã bị xóa
    for (int i = 0; i < m; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        table[tmp2][tmp1] = 0;
    }

    // Quy hoạch động
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            int minWaste = table[i][j];
            // Cắt ngang
            for (int k = 1; k <= i; k++) {
                minWaste = min(minWaste, table[k][j] + table[i - k][j]);
            }
            // Cắt dọc
            for (int k = 1; k <= j; k++) {
                minWaste = min(minWaste, table[i][k] + table[i][j - k]);
            }
            table[i][j] = minWaste;
        }
    }

    cout << table[h][w] << endl;

    return 0;
}
