#include <stdio.h>
int main(){
    int a[7]= {13, -355, 235, 47, 67, 943, 1222};
    printf("address of first five elements in memory.\n");
    for (int i=0; i<5;i++)  printf("             a[%d]",i);
    printf("\n");

    //*************************//
    /* Ta Quang Pho - 20215450 */
    for (int i = 0; i < 5; i++) {
        printf(" %p", a + i);
    }
    //*************************//
    printf("\nTa Quang Pho - 20215450");

    return 0;
}
