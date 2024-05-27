#include <iostream>

using namespace std;

void print(int n) {
    printf("n=%d\n", n);
}

int mul3plus1(int n) {
    return n * 3 + 1;
}

int div2(int n) {
    return n / 2;
}

// khai báo các tham số cho các con trỏ hàm odd, even và output
void simulate(int n, int (*odd)(int n), int (*even)(int n), void (*output)(int n))  {
                    // Con trỏ tới hàm  // Con trỏ tới hàm  // Con trỏ tới hàm
                    // có tham số truyền// có tham số truyền// có tham số truyền
                    // vào kiểu int trả // vào kiểu int trả // vào kiểu int trả
                    // về kiểu int      // về kiểu int      // về kiểu void

    (*output)(n); // Gọi hàm được trỏ bởi con trỏ output
    if (n == 1) return;
    if (n % 2 == 0) {
        n = (*even)(n); // Nếu chẵn, gọi hàm được trỏ bởi con trỏ even
    } else {
        n = (*odd)(n);  // Nếu lẻ, gọi hàm được trỏ bởi con trỏ odd
    }
    simulate(n, odd, even, output);
}

int main() {
    int (*odd)(int) = NULL;
    int (*even)(int) = NULL;

    //*************************//
    /* Ta Quang Pho - 20215450 */

    odd = &mul3plus1;           // Gán địa chỉ hàm mul3plus1 cho odd
    even = &div2;               // Gán địa chỉ hàm div2 cho even

    //*************************//
    /* Ta Quang Pho - 20215450 */

    int n;
    scanf("%d", &n);
    simulate(n, odd, even, print);

    return 0;
}
