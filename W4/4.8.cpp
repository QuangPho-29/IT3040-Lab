#include <iostream>
#include <map>

using namespace std;

//*************************//

/* Ta Quang Pho - 20215450 */

//*************************//

template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {

    // Tạo một map result là bản sao của tập hợp a
    map<T, double> result = a;

    // Duyệt qua từng phần tử của map b
    for (const pair <T, double> &entry : b) {
        // Giá trị độ thuộc bằng giá trị lớn nhất giữa
        // độ thuộc của phần tử đang xét và giá trị hiện có trong map
        result[entry.first] = max(result[entry.first], entry.second);
    }
    return result;
}

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {
    map<T, double> result;
    map<T, double> b_ = b;

    // Duyệt qua từng phần tử của a
    for (const pair <T, double> &entry : a) {

        // Nếu phần tử cũng xuất hiện trong tập hợp b ít nhất 1 lần
        // Giá trị độ thuộc mới bằng giá trị nhỏ nhất giữa độ thuộc của các phần tử đang xét
        if (b.count(entry.first) > 0) {
            result[entry.first] = min(entry.second, b_[entry.first]);
        }
    }
    return result;
}

template<class T>
void print_fuzzy_set(const map<T, double> &a) {
    cout << "{ ";
    for (const auto &x : a) {
        cout << "(" << x.first << ", " << x.second << ") ";
     }
    cout << "}";
    cout << endl;
}

int main() {
    map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
    map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
    cout << "A = "; print_fuzzy_set(a);
    cout << "B = "; print_fuzzy_set(b);

    map<int, double> c = fuzzy_set_union(a, b);
    map<int, double> d = fuzzy_set_intersection(a, b);
    cout << "Union: "; print_fuzzy_set(c);
    cout << "Intersection: "; print_fuzzy_set(d);

    cout << '\n' << "___________________________________" <<'\n';
    cout << "Ta Quang Pho - 20215450" << '\n';

    return 0;
}
