#include <iostream>
#include <string>
#include <map>

using namespace std;

//*************************//

/* Ta Quang Pho - 20215450 */

//*************************//

int countSpecialSubstring(string str) {
    int n = str.length();
    int res = 0;
    int slg0 = 0, slg1 = 0;
    map<int, int> m;

    for (int i = 0; i < n; i++) {
        if (str[i] == '0')
            slg0++;
        else
            slg1++;

        int tmp = slg1 - slg0;

        if (tmp == 0)
            res++;  // Tăng kết quả nếu số lượng 0 và 1 bằng nhau
        res += m[tmp];  // Cộng thêm số lượng xâu con đã tạo trước đó với số lượng 0 và 1 bằng nhau
        m[tmp]++;  // Cập nhật số lượng xâu con mới với số lượng 0 và 1 bằng nhau
    }

    return res;
}

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie(0); cout.tie(0);

    string str;
    cin >> str;

    cout << countSpecialSubstring(str) << endl;

    return 0;
}
