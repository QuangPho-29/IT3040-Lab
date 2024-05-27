#include <bits/stdc++.h>

using namespace std;

//*************************//

/* Ta Quang Pho - 20215450 */

//*************************//

void dfs(vector <list <int>> adj) {
    int n = adj.size(); // Số đỉnh của đồ thị

    stack <int> s;
    // Tạo mảng lưu các đỉnh đã thăm (true  = đã thăm)
    vector <bool> visited (n, false);

    s.push(1);  // Thêm đỉnh 1 vào stack
    while (!s.empty()) {
        int cur = s.top();
        s.pop();

        if (!visited[cur]) {
            visited[cur] = true;    // Đánh dấu đã thăm
            cout << cur << '\n';

            stack <int> tmp;    // Stack trung gian để đảm bảo các giá trị được
                                // push vào stack chính đúng thứ tự
            for (auto it : adj[cur]) {
                if (!visited[it]) {
                    tmp.push(it);
                }
            }

            while (!tmp.empty()) {
                s.push(tmp.top());  // Thêm phần tử vào stack
                tmp.pop();
            }
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n = 7;
    vector< list<int> > adj;
    adj.resize(n + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);

    dfs(adj);

    cout << '\n' << "___________________________________" <<'\n';
    cout << "Ta Quang Pho - 20215450" << '\n';

    return 0;
}
