#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

int *a;
int n, tmp;

int main(){
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    //#Allocate memory

    //*************************//
    /* Ta Quang Pho - 20215450 */
    a = (int*) malloc (n * sizeof(int));
    //*************************//


    for(int i = 0; i < n; i++)
        scanf("%d", a + i);

    printf("The input array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");

    //#Sort array

    //*************************//
    /* Ta Quang Pho - 20215450 */
    for (int i = 0; i < n - 1; i++) {
        for (int j = i; j < n; j++) {
            if (a[i] > a[j]){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    //*************************//

    printf("The sorted array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");

    delete [] a;
    return 0;
}
