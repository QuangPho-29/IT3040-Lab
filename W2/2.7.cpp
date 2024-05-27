#include <iostream>

using namespace std;

//# viết hàm arr_sum
//*************************//
/* Ta Quang Pho - 20215450 */

template <typename T>

// Hàm template để tính tổng các phần tử của hai mảng
// T: Kiểu dữ liệu của các phần tử trong mảng (ví dụ: int, double)
// Trả về: Tổng của tất cả phần tử trong cả hai mảng
T arr_sum(T* arr1, int size1, T* arr2, int size2) {
    T sum = 0;

    // Duyệt qua mảng đầu tiên và cộng dồn giá trị vào sum
    for (int i = 0; i < size1; i++) {
        sum += arr1[i];
    }

    // Duyệt qua mảng thứ hai và cộng dồn giá trị vào sum
    for (int i = 0; i < size2; i++) {
        sum += arr2[i];
    }
    return sum;
}

//*************************//

int main() {
    int val;
    cin >> val;

    // Tính toán với mảng các số nguyên
    {
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }

    // Tính toán với mảng các số thực
    {
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }

    return 0;
}
