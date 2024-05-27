#include <iostream>

using namespace std;

int cube(int x) {
    //# trả về lập phương của x
    //*************************//
    /* Ta Quang Pho - 20215450 */

    return (x*x*x);             // x^3

    //*************************//

}

//# viết hàm tính lập phương của một số kiểu double
double cube(double x) {
    //# trả về lập phương của x
    //*************************//
    /* Ta Quang Pho - 20215450 */

    return (x*x*x);             // x^3

    //*************************//

}

int main() {
    int n;
    double f;
    scanf("%d %lf", &n, &f);

    // Hàm cube với tham số truyền vào kiểu int và trả về kết quả kiểu
    // int được gọi
    printf("Int: %d\n", cube(n));

    // Hàm cube với tham số truyền vào kiểu double và trả về kết quả kiểu
    // double được gọi
    printf("Double: %.2lf\n", cube(f));

    return 0;
}
