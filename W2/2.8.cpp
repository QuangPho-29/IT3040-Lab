#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int val1, val2;
    cin >> val1 >> val2;

    // Khởi tạo vector của các vector, mỗi vector con đại diện cho một mảng 1 chiều
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1}, // val1 là một giá trị nhập từ người dùng
        {9, 8, 15},
        {10, val2},     // val2 là một giá trị nhập từ người dùng
    };

    // Sắp xếp các vector con trong vector 'a' theo tổng giá trị của chúng giảm dần
    //*************************//
    /* Ta Quang Pho - 20215450 */

    // Sử dụng hàm sort với hàm so sánh nặc danh
    sort(a.begin(), a.end(), [](const vector<int>& arr1, const vector<int>& arr2) {

        int sum1 = accumulate(arr1.begin(), arr1.end(), 0);

        int sum2 = accumulate(arr2.begin(), arr2.end(), 0);
        // So sánh tổng hai vector để sắp xếp
        return (sum1 > sum2); // Sắp xếp giảm dần
    });

    //*************************//

    for (const auto &v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
