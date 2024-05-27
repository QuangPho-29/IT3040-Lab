#include <iostream>
#include <vector>
using namespace std;

/*
    Ta Quang Pho - 20215450
*/

// Hàm cal dùng để tính điểm chữ dựa trên điểm số
char cal(double a) {
    if (a < 4) return 'F';
    else if (a < 5.5) return 'D';
    else if (a < 7) return 'C';
    else if (a < 8.5) return 'B';
    return 'A';
}

int main() {
    int n;
    cin >> n;

    vector<double> scores(n);

    // Nhập danh sách điểm số
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    int A = 0, B = 0, C = 0, D = 0, F = 0;
    for (double score : scores) {
        char grade = cal(score);

        // Đếm số lượng từng điểm chữ
        switch (grade) {
            case 'A':
                A++;
                break;
            case 'B':
                B++;
                break;
            case 'C':
                C++;
                break;
            case 'D':
                D++;
                break;
            case 'F':
                F++;
                break;
        }
    }

    // Hiển thị kết quả
    cout << A << " " << B << " " << C << " " << D << " " << F;

    return 0;
}
