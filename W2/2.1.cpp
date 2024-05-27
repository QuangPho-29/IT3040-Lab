#include <stdio.h>
#include <math.h>

float get_hypotenuse(float x, float y) {
    //*************************//
    /* Ta Quang Pho - 20215450 */

    return (sqrt(x*x + y*y));   // Theo định lý Pytago

    //*************************//
}

int main(){
    float x, y;
    scanf("%f%f", &x, &y);

    float z = get_hypotenuse(x, y); // Gán giá trị của cạnh huyền
                                    // ứng với 2 cạnh góc vuông là x và y
                                    // cho biến z
    printf("z = %.2f\n", z);

    return 0;
}
