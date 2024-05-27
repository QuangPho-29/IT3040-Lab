#include <iostream>
using namespace std;
#include <string.h>
#include <stack>

/*
    Ta Quang Pho - 20215450
*/

// Hàm kiếm tra xem xâu nhập vào có thỏa mãn hay không
int par(string str){
    int a = str.length();
    stack<char> S;
    char x, y;
    for (int i=0; i<a; i++){
        x = str[i];
        // Nếu ký tự là dấu ngoặc mở, đẩy nó vào ngăn xếp
        if (x == '(' || x == '[' || x == '{'){
            S.push(x);
        }
        else {
            // Nếu ký tự là dấu ngoặc đóng, kiểm tra xem nó có khớp với đầu ngăn xếp không
            if (x == ')') {
                // Nếu ngăn xếp rỗng, xâu không thỏa mãn
                if (S.size() == 0) return 0;
                // Nếu đầu ngăn xếp là dấu ngoặc mở cùng loại, lấy nó ra khỏi ngăn xếp
                if (S.top() == '('){
                    S.pop();
                }
                // Nếu không, xâu không thỏa mãn
                else return 0;
            }
            else if (x == ']') {
                if (S.top() == '['){
                    S.pop();
                }
                else return 0;
            }
            else if (x == '}') {
                if (S.top() == '{'){
                    S.pop();
                }
                else return 0;
            }
        }
    }
    // Nếu ngăn xếp không rỗng ở cuối cùng, xâu không thỏa mãn
    if (S.size() != 0){
        return 0;
    }
    // Nếu không, xâu thỏa mãn
    else return 1;
}

int main(){
    int n;
    string str;

    // Đọc số lượng trường hợp kiểm tra
    cin >> n;
    for(int i=0; i<n; i++){
        // Đọc từng trường hợp kiểm tra và kiểm tra xem nó có đúng không
        cin >> str;
        cout << par(str) << endl;
    }

    return 0;
}
