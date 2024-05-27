#include <bits/stdc++.h>

using namespace std;

//*************************//
/* Ta Quang Pho - 20215450 */

int n, tmp;

// Cấu trúc node là 1 phần tử của danh sách liên kết
struct Node {
    int val;
    Node* nextNode; // Trỏ tới phần tử tiếp theo trong danh sách

    Node(int value) { // Constructor/ hàm khởi tạo
        val = value;
        nextNode = nullptr;
    }
};

// Cấu trúc danh sách liên kết đơn
struct List {
    Node* root; // Node đầu tiên của danh sách
    Node* last; // Node cuối cùng của danh sách

    List(int value) {   // Hàm khởi tạo / Constructor
        root = new Node(value);
        last = root;
    }

    // Hàm thêm vào cuối danh sách (thay đổi phần tử cuối)
    void push_back_list(int value) {
        Node* curNode = new Node(value); // Tạo node mới với giá trị được thêm
        last->nextNode = curNode;   // Nối phần tử vừa tạo vào cuối danh sách
        last = curNode; // Cập nhật phần tử cuối cùng
    }

    // Hàm thêm vào đầu danh sách (thay đổi phần tử đầu tiên)
    void push_front_list(int value) {
        Node* curNode = new Node(value);    // Tạo node mới với giá trị được thêm
        curNode->nextNode = root;   // Nối vào đầu danh sách
        root = curNode; // Cập nhật phần tử đầu tiên của danh sách
    }

    // Hàm in danh sách liên kết đơn
    void print_list() {
        Node* i = root; // Tạo 1 biến chạy i kiểu con trỏ Node
        while(i != nullptr) {
            cout << ' ' << i->val;
            i = i->nextNode;    // Chuyển đến phần tử tiếp theo
        }
    }

    // Hàm đảo ngược danh sách
    void reversed_list() {
        Node* curNode = root;   // Biến chạy
        Node* prev = nullptr;   // Lưu node trước biến chạy
        Node* next = nullptr;   // Lưu node sau biến chạy

        Node* new_last = root;  // Lưu node đầu tiên để cập nhật node cuối
                                // của danh sách sau khi đảo ngược

        // Vòng lặp hoán đổi 3 con trỏ curNode, prev và next
        while(curNode != nullptr) {
            next = curNode->nextNode;
            curNode->nextNode = prev;
            prev = curNode;
            curNode = next;
        }

        // Cập nhật các giá trị đầu và cuối
        root = prev;
        new_last -> nextNode = nullptr;
        last = new_last;
    }
};

List* l;    // Khai báo con trỏ List toàn cục

// Hàm nhập dữ liệu
void input() {
    cin >> n;
    cin >> tmp;

    l = new List(tmp);
    for(int i = 1; i < n; i++) {
        cin >> tmp;
        l->push_front_list(tmp); // Thêm phần tử vào đầu danh sách
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();

    cout << "Original list:";
    l->print_list();

    cout << '\n';

    l->reversed_list(); // Đảo ngược danh sách
    cout << "Reversed list:";
    l->print_list();

    return 0;
}

//*************************//
