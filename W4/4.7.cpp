#include <bits/stdc++.h>

using namespace std;

//*************************//

/* Ta Quang Pho - 20215450 */

//*************************//

template<class T>
set<T> set_union(const set<T> &a, const set<T> &b) {
    set<T> result = a;  // Đặt tập kết quả bằng tập a

    for (T it: b) { // Duyệt và thêm các phần tử trong tập b
        result.insert(it);  // Set sẽ tự động không cập nhật các giá trị đã có
    }

    return result;
}

template<class T>
set<T> set_intersection(const set<T> &a, const set<T> &b) {
    set<T> result;

    // Duyệt qua các phần tử của set a
    for (const T &element : a) {

        // Nếu trong set b có ít nhất một element đang xét, thêm vào tập hợp result
        if (b.count(element) > 0) {
            result.insert(element);
        }
    }
    return result;
}

template<class T>
void print_set(const set<T> &a) {
    for (const T &x : a) {
        cout << x << ' ';
    }
    cout << endl;
}

int main() {
    set<int> a = {1, 2, 3, 5, 7};
    set<int> b = {2, 4, 5, 6, 9};
    set<int> c = set_union(a, b);
    set<int> d = set_intersection(a, b);

    cout << "Union: "; print_set(c);
    cout << "Intersection: "; print_set(d);

    cout << '\n' << "___________________________________" <<'\n';
    cout << "Ta Quang Pho - 20215450" << '\n';

    return 0;
}
