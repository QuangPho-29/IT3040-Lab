#include<bits/stdc++.h>

using namespace std;

//*************************//

/* Ta Quang Pho - 20215450 */

//*************************//

// Cấu trúc để lưu trữ giá trị ai và ki cho mỗi đoạn tường
struct data {
    int ai;
    int ki;

    data(int ai, int ki){
        this->ai = ai;
        this->ki = ki;
    }
};

int n, s, kill_enemy = 0, total_enemy = 0;

// Hàng đợi ưu tiên để lưu trữ các đoạn tường, được sắp xếp theo giá trị nhỏ nhất giữa ai và ki
priority_queue<data, vector<data>, function<bool(data, data)>> Q([](data a, data b) {
    int ra = (a.ai <= a.ki) ? a.ai : a.ki;
    int rb = (b.ai <= b.ki) ? b.ai : b.ki;
    return ra < rb;
});

// Hàm để nhập dữ liệu
void inputData(){
    cin >> n >> s;
    for (int i=0; i<n; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        Q.push(data(tmp1, tmp2));
    }
}

// Hàm để giải quyết bài toán
void solve() {
    // Xử lý các đoạn tường cho đến khi hết quân lính hoặc hàng đợi ưu tiên rỗng
    while (!Q.empty() && s > 0) {
        data inf = Q.top();
        Q.pop();

        if (inf.ai <= inf.ki)
            kill_enemy += inf.ai;
        else {
            int nenemy = inf.ai - inf.ki;
            Q.push(data(nenemy, inf.ki));
            kill_enemy += inf.ki;
        }

        s--;
    }

    // Tính tổng số lượng kẻ thù trong lâu đài
    total_enemy = kill_enemy;
    while (!Q.empty()) {
        total_enemy += Q.top().ai;
        Q.pop();
    }
}

int main(){
    ios_base :: sync_with_stdio (false);
    cin.tie(0); cout.tie(0);

    inputData();

    solve();
    cout << '\n' << "output:" << '\n' << total_enemy - kill_enemy;

    return 0;
}
