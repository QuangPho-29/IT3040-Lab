#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <iostream>

using namespace std;

// Giới hạn đầu vào cho hàm sigmoid
const int LIMIT = 100;
// Số lượng giá trị tính trước để tối ưu hàm sigmoid
const int NUM_ITER = 100000;
// Tổng số lượng giá trị đầu vào để kiểm tra
const int NUM_INPUTS = NUM_ITER * 100;

// Hàm sigmoid chậm - tính theo công thức chuẩn
double sigmoid_slow(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// Mảng chứa các giá trị đầu vào để kiểm tra
double x[NUM_INPUTS];

// Hàm chuẩn bị các giá trị đầu vào ngẫu nhiên
void prepare_input() {
    const int PRECISION = 1000000; // Độ chính xác cho việc sinh số
    const double RANGE = LIMIT / 20.0;
    for (int i = 0; i < NUM_INPUTS; ++i) {
        x[i] = RANGE * (rand() % PRECISION - rand() % PRECISION) / PRECISION;
    }
}

// Con trỏ toàn cục để  trỏ tới vùng lưu trữ các giá trị sigmoid
// đã được tính trước
double *y;
// Khoảng cách giữa hai giá trị liên tiếp được tính trước
double delta = 2.0 * LIMIT / NUM_ITER;

// Hàm tính trước các giá trị của hàm sigmoid
void precalc() {
    // Cấp phát bộ nhớ cho mảng y
    y = new double[NUM_ITER];
    // Tính toán và lưu trữ các giá trị sigmoid đã được tính trước
    for (int i = 0; i < NUM_ITER; i++)
        y[i] = sigmoid_slow(delta * i - LIMIT);
}

// Hàm sigmoid nhanh - sử dụng phép nội suy tuyến tính
double sigmoid_fast(double x) {
    // Nếu x nằm ngoài phạm vi đã được tính trước, trả về giá trị biên
    if (x < -LIMIT) return 0;
    if (x > LIMIT) return 1;
    // Tính chỉ số tương ứng trong mảng y
    int n = (x + LIMIT) / delta;
    // Tính giá trị sigmoid nhanh thông qua nội suy tuyến tính
    return y[n] + (x + LIMIT - n * delta) * (y[n + 1] - y[n]) / delta;
}

// Hàm đo hiệu suất của hàm tính sigmoid
double benchmark(double (*calc)(double), vector<double> &result) {
    const int NUM_TEST = 20; // Số TEST CASE

    double taken = 0;
    result = vector<double>();
    result.reserve(NUM_ITER);

    int input_id = 0;
    clock_t start = clock();
    for (int t = 0; t < NUM_TEST; ++t) {
        double sum = 0;
        for (int i = 0; i < NUM_ITER; ++i) {
            double v = fabs(calc(x[input_id]));
            sum += v;
            if (t == 0) result.push_back(v);
            if ((++input_id) == NUM_INPUTS) input_id = 0;
        }
    }
    clock_t finish = clock();
    taken = (double)(finish - start);
    return taken;
}

// Hàm kiểm tra tính chính xác của hai hàm tính sigmoid
bool is_correct(const vector<double> &a, const vector<double> &b) {
    const double EPS = 1e-6; // Sai số cho phép khi so sánh

    if (a.size() != b.size()) return false;
    for (int i = 0; i < (int)a.size(); ++i) {
        if (fabs(a[i] - b[i]) > EPS) {
            return false;
        }
    }
    return true;
}

int main() {
    // Chuẩn bị dữ liệu đầu vào
    prepare_input();
    // Tính toán trước các giá trị sigmoid
    precalc();

    vector<double> a, b;
    double slow = benchmark(sigmoid_slow, a);
    double fast = benchmark(sigmoid_fast, b);

    double xval;
    scanf("%lf", &xval);
    printf("%.2f \n", sigmoid_fast(xval));

    if (is_correct(a, b) && !(slow / fast > 1.3)) {
        cout << "Correct answer! Your code is faster at least 30%!" << endl;
    } else {
        printf("Wrong answer or your code is not fast enough!\n");
    }

    // Giải phóng bộ nhớ đã cấp phát cho y
    delete[] y;

    return 0;
}
