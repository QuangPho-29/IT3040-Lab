#include <iostream>
#include <fstream>

using namespace std;

int n;

void printC (int* arr, int l, int r) {
    //in ra các phần tử từ l(left) đến r(right) thuộc mảng arr
    for (int i = l; i <= r; i++) {
        cout << arr[i];
    }
    cout << endl;
}

int main() {
    cout << "Ta Quang Pho - 20215450\n____________________________________________________________\n\n";
    ifstream fin("input1.9.txt"); // File "input.txt" là file chứa bộ dữ liệu cho test case
    if (!fin.is_open()) {
        printf("Khong mo duoc tep\n"); // In thông báo nếu không mở được tệp
        return 1;
    }

    int testCase;
    while (fin >> testCase) {
        cout << "Test case = " << testCase << '\n';
        fin >> n;
        cout << "\n" << "n = " << n;
        int arr[n];
        cout << "\n\n" << "Tap cha:" << '\n';
        for (int i = 0; i < n; i++) {
            fin >> arr[i];
            cout << arr[i] << " ";
        }
        cout << "\n\n" << "Danh sach tap con:" << '\n';
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                printC(arr, i, j);
                //cho con chạy chạy lần lượt để in các tập con theo thứ tự yêu cầu
            }
        }

        cout << "____________________________________________________________\n\n";
    }
    cout << "Ta Quang Pho - 20215450";
    return 0;
}
