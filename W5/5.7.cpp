#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Ta Quang Pho - 20215450
*/

int main() {
    int n;
    cin >> n;

    int ans = 0, sum = 0;
    // Vòng lặp các test cases
    for (int i = 0; i < n; i++) {
        int k, t;
        cin >> k >> t; // t là loại tiền(xin hay cho)

        // Vòng lặp chạy qua từng nhà
        while (k--) {
            int a;
            cin >> a;

            sum += t * a;
            ans = max(ans, -sum);
        }
    }

    // Hiển thị kết quả
    cout << ans;

    return 0;
}
