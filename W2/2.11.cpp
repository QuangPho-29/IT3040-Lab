#include <bits/stdc++.h>

//*************************//

/* Ta Quang Pho - 20215450 */

//*************************//

using namespace std;

int n, m;               // n là bậc của đa thức A, m là bậc của đa thức B
int* a, *b, *result;    // mảng a, b, result lưu lần lược các phần tử của đa thức A, B, tích 2 đa thức

//Hàm khởi tạo các mảng và nhập dữ liệu đầu vào
void input() {
    cin >> n;
    a = new int [n + 1];                // Cấp phát vùng nhớ cho mảng A
    memset(a, 0, (n + 1)*sizeof(int));  // Đặt giá trị các phần tử về 0 tránh vùng nhớ rác
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }

    cin >> m;
    b = new int [m + 1];                // Cấp phát vùng nhớ cho mảng B
    memset(b, 0, (m + 1)*sizeof(int));  // Đặt giá trị các phần tử về 0 tránh vùng nhớ rác
    for (int i = 0; i <= m; i++) {
        cin >> b[i];
    }

    result = new int[n + m];                    // Cấp phát vùng nhớ lưu tích 2 mảng
    memset(result, 0, (n + m)*sizeof(int));     // Đặt giá trị các phần tử về 0 tránh vùng nhớ rác
}

// Hàm nhân 2 đa thức
void multiPoly() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            result[i + j] += a[i] * b[j];       // Cộng dồn các phần tử cùng bậc
        }
    }
}

// Hàm in kết quả
void printResult() {
    int tmp = 0;
    int level = n + m;
    for (int i = 0; i <= level; i++) {
        tmp = tmp ^ result[i];                  // tmp lưu giá trị XOR giữa tất cả các phần tử trong mảng
    }

    cout << tmp;
}

// Hàm thu hồi bộ nhớ đã cấp phát
void deleteAllocated() {
    delete [] a;
    delete [] b;
    delete [] result;
}

int main () {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    multiPoly();
    printResult();
    deleteAllocated();

    cout << '\n' << "Ta Quang Pho - 20215450";

    return 0;
}
