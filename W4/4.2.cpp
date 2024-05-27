#include<bits/stdc++.h>

using namespace std;

//*************************//

/* Ta Quang Pho - 20215450 */

//*************************//


// Hàm tính diện tích tam giác biết tọa độ 3 đỉnh
double area(Point a, Point b, Point c) {
    //*************************//
    /* Ta Quang Pho - 20215450 */

        // Lưu các tọa độ
        double x1 = a.first, y1 = a.second;
        double x2 = b.first, y2 = b.second;
        double x3 = c.first, y3 = c.second;

        // Công thức tính diện tích tam giác cho biết tọa độ 3 đỉnh
        double area = 0.5 * abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
        return area;

    //*************************//
}

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie(0); cout.tie(0);

    cout << setprecision(2) << fixed;
    cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;

    return 0;
}
