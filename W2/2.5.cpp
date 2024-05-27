#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip>

using namespace std;

struct Complex {
    double real;
    double imag;
};

Complex operator + (Complex a, Complex b) {
    //*************************//
    /* Ta Quang Pho - 20215450 */

    Complex tmp;
    tmp.real = a.real + b.real; // Tổng phần thực
    tmp.imag = a.imag + b.imag; // Tổng phần ảo
    return tmp;

    //*************************//
}

Complex operator - (Complex a, Complex b) {
    //*************************//
    /* Ta Quang Pho - 20215450 */

    Complex tmp;
    tmp.real = a.real - b.real; // Hiệu phần thực
    tmp.imag = a.imag - b.imag; // Hiệu phần ảo
    return tmp;

    //*************************//
}

Complex operator * (Complex a, Complex b) {
    //*************************//
    /* Ta Quang Pho - 20215450 */

    Complex tmp;
    tmp.real = a.real * b.real - (a.imag * b.imag); // Phần thực của tích
    tmp.imag = a.imag * b.real + b.imag * a.real;   // Phần ảo của tích
    return tmp;

    //*************************//
}

Complex operator / (Complex a, Complex b) {
    //*************************//
    /* Ta Quang Pho - 20215450 */

    Complex tmp;

    // Công thức tính thương của 2 số phức bằng nhân liên hợp
    tmp.real = (a.real * b.real + (a.imag * b.imag)) / (b.real * b.real + b.imag * b.imag);
    tmp.imag = (a.imag * b.real - (a.real * b.imag)) / (b.real * b.real + b.imag * b.imag);
    return tmp;

    //*************************//
}

// Đa năng hóa toán tử << để in ra số phức
ostream& operator << (ostream& out, const Complex &a) {
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}

int main() {
    double real_a, real_b, img_a, img_b;
    cin >> real_a >> img_a;
    cin >> real_b >> img_b;

    Complex a{real_a, img_a};   // Khởi tạo biến phức a
    Complex b{real_b, img_b};   // Khởi tạo biến phức b

    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;

    return 0;
}
