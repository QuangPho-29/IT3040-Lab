#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//*************************//

/* Ta Quang Pho - 20215450 */

//*************************//

typedef long long ll;

void solve() {
    ll n;
    cin >> n;

    vector<ll> vt(n + 2); // Vector lưu trữ chiều cao của cột chữ nhật
    for (ll i = 1; i <= n; i++) {
        cin >> vt[i];
    }

    stack<ll> st;
    vector<ll> L(n + 2), R(n + 2); // Mảng L và R lưu trữ các chỉ số tương ứng của các cột liên tiếp

    // Tìm chỉ số L[i] cho mỗi cột i
    for (ll i = 0; i <= n + 1; i++) {
        while (!st.empty() && vt[i] < vt[st.top()]) {
            L[st.top()] = i; // Gán chỉ số của cột i vào L[j] khi cột j kết thúc
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty()) {
        st.pop();
    }

    // Tìm chỉ số R[i] cho mỗi cột i
    for (ll i = n + 1; i >= 0; i--) {
        while (!st.empty() && vt[i] < vt[st.top()]) {
            R[st.top()] = i; // Gán chỉ số của cột i vào R[j] khi cột j bắt đầu
            st.pop();
        }
        st.push(i);
    }

    ll maxh = 0;
    for (ll i = 1; i <= n; i++) {

        // Tính diện tích của hình chữ nhật liên tiếp bằng (R[i] - L[i] - 1) * vt[i]
        ll h = (L[i] - R[i] - 1) * vt[i];
        maxh = max(maxh, h); // Cập nhật giá trị lớn nhất của diện tích hình chữ nhật
    }

    cout << maxh << '\n'; // In ra kết quả
}

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}
