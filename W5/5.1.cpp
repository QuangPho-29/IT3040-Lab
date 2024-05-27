#include <stdio.h>

/*
    Ta Quang Pho - 20215450
*/

int x[100], mark[100], n;

void print(){
    for (int i = 1; i <= n; ++i) printf("%d ", x[i]);
    printf("\n"); // Sửa "print" thành "printf"
}

void process(int i) {
    if (i > n){
        print(); // Sửa "printf" thành "print"
        return;
    }
    for (int j = 1; j <= n; ++j)
        if (!mark[j]){
            mark[j] = 1;
            x[i] = j;
            process(i+1);
            mark[j] = 0;
        }
}

int main() {
    n = 5;
    process(1);
    return 0;
}
