#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//*************************//

/* Ta Quang Pho - 20215450 */

//*************************//

// In các phần tử trong vector
void print_vector(const vector<int> &a) {
    for (int v : a) {   // Duyệt các phần tử trong a (không phải 1 iterator)
        cout << v << ' ';
    }
    cout << '\n';
}

// Xóa các phần tử chẵn trong vector
void delete_even(vector<int> &a) {
    int index = 0;

    // Vòng lặp duyệt các phần tử trong vector,
    // nếu chẵn thì cập nhật phần tử thứ index
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] % 2 != 0) {
            a[index++] = a[i];
        }
    }

    a.resize(index);    // Đặt lại kích thước vector (xóa phần sau index)
}

// Sắp xếp vector giảm dần
void sort_decrease(vector<int> &a) {

    //Bubble sort
    for (int i = 0; i < (int)a.size() - 1; i++) {
        for (int j = i + 1; j < (int)a.size(); j++) {
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}


// Trộn hai vector (đã được sắp xếp) thành một vector mới, sắp xếp giảm dần
vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    vector<int> outp;
    int i = 0, j = 0;

    // Duyệt đến khi 1 trong 2 vector hết phần tử
    while (i < (int)a.size() && j < (int)b.size()) {
        // So sánh 2 phần tử của 2 vector để thêm theo thứ tự giảm dần
        if (a[i] > b[j]) {
            outp.push_back(a[i]);
            i++;
        } else {
            outp.push_back(b[j]);
            j++;
        }
    }


    // Thêm phần dư của vector a
    while (i < (int)a.size()) {
        outp.push_back(a[i]);
        i++;
    }

    // thêm phần dư của vector b
    while (j < (int)b.size()) {
        outp.push_back(b[j]);
        j++;
    }

    return outp;
}


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m, n, u;
    vector<int> a, b;   // Khởi tạo 2 vector

    // Nhập 2 vector
    cin >> m >> n;
    for (int i = 0; i < m; i++){
        cin >> u;
        a.push_back(u);
    }

    for (int i = 0; i < n; i++){
        cin >> u;
        b.push_back(u);
    }

    // xóa phần tử chẵn của a
    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    // Xóa phần tử lẻ của a
    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    // Sắp xếp giảm dần các phần tử của vector a
    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    // Sắp xếp giảm dần các phần tử của vector b
    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    // Trộn 2 vector
    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

//    cout << "___________________________________" <<'\n';
//    cout << "Ta Quang Pho - 20215450" << '\n';

    return 0;
}
