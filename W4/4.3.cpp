#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//*************************//

/* ta quang pho - 20215450 */

//*************************//

using vector = tuple<double, double, double>;

hàm tính tích có hướng 2 vector
vector cross_product(vector a, vector b) {
    vector multi;
    // tính hoành độ của vector a*b
    get<0>(multi) = get<1>(a) * get<2>(b) - get<2>(a) * get<1>(b);

    // tính tung độ của vector a*b
    get<1>(multi) = get<2>(a) * get<0>(b) - get<0>(a) * get<2>(b);

    // tính cao độ của vector a*b
    get<2>(multi) = get<0>(a) * get<1>(b) - get<1>(a) * get<0>(b);

    return multi;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << setprecision(2) << fixed;
    vector a {1.2, 4, -0.5};
    vector b {1.5, -2, 2.5};

    vector c = cross_product(a, b);
    cout << get<0>(c) << ' ' << get<1>(c) << ' ' << get<2>(c) << '\n';

    cout << '\n' << "___________________________________" <<'\n';
    cout << "ta quang pho - 20215450" << '\n';

    return 0;
}
