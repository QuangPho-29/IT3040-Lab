#include <iostream>

using namespace std;

//# Viết hàm get_value
//*************************//
/* Ta Quang Pho - 20215450 */

int get_value(int x, int a = 2, int b = 1, int c = 0) {
    return (a*x*x + b*x + c);       // Trả về ax^2+bx+c
}

//*************************//

int main(){
    int x;
    scanf("%d", &x);

    int a = 2; //# giá trị mặc định của a
    int b = 1; //# giá trị mặc định của b
    int c = 0; //# giá trị mặc định của c

    //# Nhập 3 số nguyên a, b, c từ bàn phím
    //*************************//
    /* Ta Quang Pho - 20215450 */

    scanf("%d%d%d", &a, &b, &c);

    //*************************//

    // In ra giá trị 2x^2 + x + 0
    printf("a=2, b=1, c=0: %d\n", get_value(x));

    // In ra giá trị ax^2 + x + 0
    printf("a=%d, b=1, c=0: %d\n", a, get_value(x, a));

    // In ra giá trị ax^2 + bx + 0
    printf("a=%d, b=%d, c=0: %d\n", a, b, get_value(x, a, b));

    // In ra giá trị ax^2 + bx + c
    printf("a=%d, b=%d, c=%d: %d\n", a, b, c, get_value(x, a, b, c));

    return 0;
}
