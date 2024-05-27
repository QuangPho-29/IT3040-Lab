#include <iostream>
#include <queue>
#include <climits>

using namespace std;

//*************************//

/* Ta Quang Pho - 20215450 */

//*************************//

vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) {
    int n = adj.size();

    // Khởi tạo khoảng cách ban đầu là vô cùng cho tất cả các đỉnh
    vector<int> distance(n, INT_MAX);
    distance[0] = 0;  // Khoảng cách từ đỉnh xuất phát đến chính nó là 0

    // Sử dụng priority_queue với đỉnh có khoảng cách nhỏ nhất đến đỉnh xuất phát
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push(make_pair(0, 0));  // Đặt đỉnh xuất phát vào priority_queue

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        // Nếu khoảng cách hiện tại từ đỉnh xuất phát đến u đã được cập nhật
        // thì bỏ qua các bước xét tiếp theo
        if (dist_u > distance[u]) {
            continue;
        }

        // Duyệt qua các đỉnh kề của u
        for (const auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // Nếu có đường đi từ đỉnh xuất phát tới v ngắn hơn
            // thì cập nhật khoảng cách và đưa v vào priority_queue
            if (dist_u + weight < distance[v]) {
                distance[v] = dist_u + weight;
                pq.push(make_pair(distance[v], v));
            }
        }
    }

    return distance;
}

int main() {
    int n = 9;
    vector< vector< pair<int, int> > > adj(n);
    auto add_edge = [&adj] (int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    add_edge(0, 1, 4);
    add_edge(0, 7, 8);
    add_edge(1, 7, 11);
    add_edge(1, 2, 8);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);

    vector<int> distance = dijkstra(adj);
    for (int i = 0; i < distance.size(); ++i) {
        cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
    }

    cout << '\n' << "___________________________________" <<'\n';
    cout << "Ta Quang Pho - 20215450" << '\n';

    return 0;
}
