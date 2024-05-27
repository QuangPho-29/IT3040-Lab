#include <bits/stdc++.h>
#define N 101

//*************************//

/* Ta Quang Pho - 20215450 */

//*************************//

using namespace std;

struct bigNum {
    char sign; // Lưu dấu của số lớn (1 : dương, 0 : âm)
    char num[N]; // Mảng lưu số lớn

    // Hàm khởi tạo mặc định (giá trị = 0)
    bigNum() {
        sign = '1'; // Mặc định dấu dương
        for (int i = 0; i < N; i++)
            num[i] = '0';   // Số lớn  = 0
    }

    // Khởi tạo số lớn từ 1 string thứ tự ngược
    bigNum(string& str) {
        int len = str.length(); // Lấy độ dài xâu
        for (int i = N - 1; i >= N - len + 1; --i) {
            num[i] = str[len - N + i];  // Lưu theo thứ tự ngược
        }
        for (int i = 0; i <= N - len; i++) {
            num[i] = '0';               // Các phần tử còn lại = 0
        }
        sign = str[0];  // Dấu là phần tử đầu tiên của mảng
    }

    // Hàm nhân 10 (sử dụng cho việc dịch phép nhân)
    void multiply10(bigNum& val, int level) {
        for (int i = 0; i < N - level; i++) {
            val.num[i] = val.num[i + level];    // Dịch sang trái level phần tử
        }
        for (int i = N - level; i < N; i++) {
            val.num[i] = '0';                   // Còn lại = 0
        }
    }

    // Đa năng hóa toán tử + cho cấu trúc bigNum
    bigNum operator+(const bigNum& operand) const {
        bigNum result;  // Tạo giá trị result = 0
        int carry = 0;  // Biến nhớ
        for (int i = N - 1; i >= 0; --i) {
            int sum = (num[i] - '0') + (operand.num[i] - '0') + carry;
            // num là mảng lưu giá trị toán hạng thứ 1
            // operand là toán hạng thứ 2
            result.num[i] = sum % 10 + '0';     // Lưu kết quả
            carry = sum / 10;                   // Tăng biến nhớ
        }
        return result;
    }

    // Đa năng hóa toán tử - cho cấu trúc bigNum
    bigNum operator-(const bigNum& operand) const {
        bigNum result;  // Tạo giá trị result = 0
        int borrow = 0; // Biến nhớ
        for (int i = N - 1; i >= 0; --i) {
            int x = num[i] - '0', y = operand.num[i] - '0';
            // num là mảng lưu giá trị toán hạng thứ 1
            // operand là toán hạng thứ 2
            if (x >= y + borrow) {  // Nếu số bị trừ > số trừ + nhớ => trừ bình thường
                result.num[i] = x - (y + borrow) + '0';
                borrow = 0;
            } else {
                result.num[i] = (x + 10) - (y + borrow) + '0';
                // Ngược lại, tăng số bị trừ thêm 10 và tăng biến nhớ thêm 1
                borrow = 1;
            }
        }
        return result;
    }

    // Đa năng hóa toán tử * với số nguyên dương
    bigNum operator*(int y) const {
        bigNum result; // Tạo giá trị result = 0
        result.sign = sign; // Dấu không đổi
        int carry = 0;  // Biến nhớ
        for (int i = N - 1; i >= 0; --i) {
            int x = num[i] - '0';   // num là mảng lưu giá trị toán hạng
            int part = x * y + carry;   // y là số nguyên cần nhân thêm
            result.num[i] = part % 10 + '0';
            carry = part / 10;
        }
        return result;
    }

    // Đa năng hóa toán tử * với 1 bigNum
    bigNum operator*(const bigNum& operand) {
        bigNum result;  // Tạo giá trị result = 0;
        for (int i = N - 1; i >= 0; --i) {
            int x = operand.num[i] - '0';
            bigNum temp = (*this) * x; // nhân số hiện tại với x
            multiply10(temp, N - i - 1); // dịch trái N - i - 1 đơn vị
            result = result + temp; // Cộng dồn số lớn vào kết quả
        }
        result.sign = '1' - ((sign - '0') ^ (operand.sign - '0')) + '0';    // Xét dấu của kết quả
        return result;
    }

    // Đa năng hóa toán tử > với bigNum
    bool operator>(const bigNum& operand) const {
        for (int i = 0; i < N; i++) {           // duyệt từ hàng cao -> thấp (VD từ trăm -> chục -> đơn vị)
            if (num[i] == operand.num[i])
                continue;
            else if (num[i] > operand.num[i])   // trả về true ngay khi tìm được phần tử đầu tiên lớn hơn
                return true;
            else
                return false;
        }
        return false;
    }
};

// Ghi đè toán tử << cho việc in dữ liệu
ostream& operator<<(ostream& stream, const bigNum& val) {   // Làm việc với ostream (luồng output)
    stream << val.sign; // In ra dấu
    int i = 0;
    while (i < N && val.num[i] == '0')  // Vòng lặp để tăng i đến chỗ cần tăng giá trị
        i++;
    for (i; i < N; i++) {
        stream << val.num[i];   // In ra từng ký tự trong số lớn
    }
    return stream;  // TRả về luồng output
}

// Overloading the input stream operator for bigNum
istream& operator>>(istream& stream, bigNum& val) {     // Làm việc với istream (luồng input)
    string temp;
    stream >> temp; // Nhập vào 1 string
    val = bigNum(temp); // Khởi tạo bigNum với xâu temp được truyền vào
    return stream;  // Trả về luồng input
}

int main () {
    ios_base :: sync_with_stdio (false);
    cin.tie(0); cout.tie(0);

    bigNum n, m;
    cin >> n;
    cin >> m;
    bigNum a = n * m, b = n * 3, c = m * 4, result;

    // Kiểm tra dấu để có được result = n*m - 3*n
    if (a.sign == '1') {
        if (b.sign == '1') {
            if (a > b) {
                result = a - b;
            } else {
                result = b - a;
                a.sign = '0';
            }
        } else {
            result = a + b;
        }
    } else {
        if (b.sign == '1') {
            result = a + b;
            result.sign = '0';
        } else {
            if (a > b) {
                result = a - b;
                result.sign = '0';
            } else {
                result = b - a;
            }
        }
    }

    //  Kiểm tra dấu để có được result = n*m - 3*n + 4*m
    if (result.sign == '1') {
        if (c.sign == '1') {
            result = result + c;
        } else {
            if (result > c) {
                result = result - c;
            } else {
                result = c - result;
                result.sign = '0';
            }
        }
    } else {
        if (c.sign == '0') {
            result = result + c;
            result.sign = '0';
        } else {
            if (c > result) {
                result = c - result;
            } else {
                result = result - c;
                result.sign = '0';
            }
        }
    }

    cout << result;

    return 0;
}
