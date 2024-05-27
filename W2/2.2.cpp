#include <iostream>

using namespace std;

void rotate(int &x, int &y, int &z) {   // Truyền tham chiếu
    //*************************//
    /* Ta Quang Pho - 20215450 */

    int tmp = x;                // Tạo biến trung gian để lưu giá trị x
    x = y;                      // Gán giá trị x = giá trị y
    y = z;                      // Gán giá trị y = giá trị z
    z = tmp;                    // Gán giá trị z = giá trị trung gian
                                // (= giá trị ban đầu của x)

    //*************************//
}

int main() {
    int x, y, z;

    //# Nhập 3 số nguyên
    //*************************//
    /* Ta Quang Pho - 20215450 */

    scanf("%d%d%d", &x, &y, &z);

    //*************************//

    printf("Before: %d, %d, %d\n", x, y, z);

    rotate(x, y, z);            // Gọi hàm rotate

    printf("After: %d, %d, %d\n", x, y, z);

    return 0;
}
