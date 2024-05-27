#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

//*************************//

/* Ta Quang Pho - 20215450 */

//*************************//

void bfs(vector< list<int> > adj) {
    int n = adj.size(); // Số đỉnh của đồ thị

    queue <int> q;  // Khởi tạo hàng đợi
    vector <bool> visited (n, false);   // Mảng đánh dấu các đỉnh đã thăm

    q.push(1);  // Thêm phần tử đầu tiên vào hàng đợi
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (!visited[cur]) {
            visited[cur] = true;    // Đánh dấu là đã thăm
            cout << cur << '\n';

            queue <int> tmp;    // Hàng đợi trung gian để đảm vào các đỉnh được
                                // thêm vào hàng đợi đúng thứ tự
            for (auto it : adj[cur]) {
                if (!visited[it]) {
                    tmp.push(it);
                }
            }

            while (!tmp.empty()) {
                q.push(tmp.front());
                tmp.pop();
            }
        }
    }
}

int main () {
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

    bfs(adj);

    cout << '\n' << "___________________________________" <<'\n';
    cout << "Ta Quang Pho - 20215450" << '\n';

    return 0;
}
