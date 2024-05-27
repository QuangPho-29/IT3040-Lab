#include <stdio.h>
#include <stdlib.h>

int n;

// Hàm cấp phát bộ nhớ cho ma trận
void allocate_mem(int ***mt){
    *mt = (int**) malloc (n * sizeof(int*)); // Cấp phát một mảng con trỏ (các phần tử đầu tiên của cột 0)
    for (int i = 0; i < n; i++) {
        (*mt)[i] = (int*) malloc (n * sizeof(int)); // Cấp phát bộ nhớ cho từng hàng của ma trận
    }
}

// Hàm nhập ma trận từ tệp và hiển thị ma trận
void input(int **mt, FILE* file){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", (*(mt + i) + j)); // Đọc một số từ tệp và lưu vào ma trận
            printf("%5d ", mt[i][j]); // Hiển thị giá trị đã đọc ra màn hình
        }
        printf("\n"); // Xuống dòng khi hoàn thành một hàng
    }
}

// Hàm tính tổng hai ma trận và hiển thị kết quả
void addMT (int** mt1, int** mt2) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d ", (mt1[i][j] + mt2[i][j])); // In tổng hai phần tử [i][j] của hai ma trận
        }
        printf("\n"); // Xuống dòng khi hoàn thành một hàng
    }
}

// Hàm nhân hai ma trận và hiển thị kết quả
void mulMT (int** mt1, int** mt2) {
    int tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp = 0;
            for (int k = 0; k < n; k++) {
                tmp += mt1[i][k] * mt2[k][j]; // Tính tổng các phép nhân để tính giá trị tại [i][j]
            }
            printf("%5d ", tmp); // In giá trị tích [i][j] của ma trận
        }
        printf("\n"); // Xuống dòng khi hoàn thành một hàng
    }
}

int main() {
    printf("Ta Quang Pho - 20215450\n____________________________________________________________\n\n");
    FILE *file = fopen("input1.10.txt", "r"); // File "input.txt" là file chứa bộ dữ liệu cho test case
    if (file == NULL) {
        printf("Khong mo duoc tep\n"); // In thông báo nếu không mở được tệp
        return 1;
    }

    int testCase;
    while (fscanf(file, "%d", &testCase) != EOF) {
        printf("Test Case = %d\n", testCase);
        int** mt1;
        int** mt2;
        fscanf(file, "%d", &n);
        printf("\nn = %d\n", n); // In giá trị của n
        allocate_mem(&mt1);
        allocate_mem(&mt2);
        printf("\nMa tran thu nhat:\n");
        input(mt1, file);
        printf("\nMa tran thu hai:\n");
        input(mt2, file);
        printf("\nTong hai ma tran:\n");
        addMT(mt1, mt2);
        printf("\nTich hai ma tran:\n");
        mulMT(mt1, mt2);
        printf("____________________________________________________________\n\n");
    }

    fclose(file);

    printf("Ta Quang Pho - 20215450");
    return 0;
}
