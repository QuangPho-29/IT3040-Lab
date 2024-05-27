#include<bits/stdc++.h>

using namespace std;

//*************************//

/* Ta Quang Pho - 20215450 */

//*************************//

const int N = 10000;

// Mảng chứa các văn bản, mỗi văn bản là một vector các từ
vector<string> doc[N];

// Mảng lưu số lần xuất hiện của từng từ trong từng văn bản
map<string, int> f[N];

// Map lưu số văn bản chứa mỗi từ
map<string, int> df;

// Mảng lưu giá trị lớn nhất của số lần xuất hiện của từng từ trong từng văn bản, biến n lưu số văn bản
int maxf[N], n;

 // Hàm tính TF
double TF(string t, int d){
    if (f[d][t] == 0) return 0;
    return 0.5 + 0.5 * f[d][t] / maxf[d];     // Tính giá trị TF của từ t trong văn bản d
}


// Hàm tính IDF
double IDF(string t){
    return log2(1.0 * n / df[t]);     // Tính giá trị IDF của từ t
}


// Hàm tính điểm số
double score(string t, int d){
    if (df.count(t) == 0) return 0;
    return TF(t, d) * IDF(t);     // Tính điểm số của từ t trong văn bản d
}

int main(){
    ios_base :: sync_with_stdio (false);
    cin.tie(0); cout.tie(0);

    cin >> n;     // Nhập số văn bản
    for (int i = 0; i < n; i++){
        string t;
        cin >> t;
        string w;
        map<string, int> d_f;

        for (char c : t){
            if (c != ',') w.push_back(c);
            else {
                d_f[w]++;

                // Cập nhật số lần xuất hiện của từ t và số văn bản chứa từ t
                if(d_f[w] == 1) df[w]++;
                doc[i].push_back(w);
                f[i][w]++;
                w = "";
                continue;
            }
        }
        d_f[w]++;
        if (d_f[w] == 1) df[w]++;
        doc[i].push_back(w);
        f[i][w]++;

        for (auto it : f[i]){

            // Tìm giá trị lớn nhất của số lần xuất hiện của từng từ trong văn bản i
            maxf[i] = max(maxf[i], it.second);
        }
    }

    int q;
    cin >> q;     // Nhập số truy vấn
    while (q--){
        vector<string> query;
        string t;
        cin >> t;
        string w;

        for (char c : t){
            if(c != ',') w.push_back(c);
            else{
                query.push_back(w);
                w = "";
                continue;
            }
        }

        query.push_back(w);
        double temp_score = -1e9;
        int document = 0;
        int d = 0;
        while (d < n){
            double total_score = 0;

            for(string t : query){
                total_score += score(t, d);     // Tính tổng điểm số của từng từ trong truy vấn đối với văn bản d
            }
            d++;

            if (total_score > temp_score){
                temp_score = total_score;
                document = d;
            }
        }
        cout << document << '\n';     // In ra chỉ số của văn bản khớp với truy vấn
    }
}
