#include <bits/stdc++.h>
#include <gmpxx.h> // g++ filename.cpp -lgmpxx -lgmp

using namespace std;

using ll = mpz_class;

constexpr int cnt = 2000; // Change to 1e6 for final submission
set<ll> nums;
vector<int> mod_nums;
vector<int> prefix_sums;
constexpr int MOD = 998244353;

void precompute() {
    ll max = ll(1) << (1 << 15);
    for (ll base = 2; base <= 16; ++base) {
        bool flag = true;
        ll num = 1;
        while (flag) {
            for (int digit = 1; digit < base; digit++) {
                if (digit * num > max) {
                    flag = false;
                    break;
                }
                if (nums.size() < cnt) {
                    nums.insert(digit * num);
                } else if (digit * num < *nums.rbegin()) {
                    nums.erase(*nums.rbegin());
                    nums.insert(digit * num);
                } else {
                    flag = false;
                    break;
                }
            }
            num *= base;
            num += 1;
        }
    }

    for (auto& num : nums) {
        ll mod_num = num % MOD;
        mod_nums.push_back(mod_num.get_si());
    }

    prefix_sums.push_back(0);
    for (auto i: mod_nums) {
        prefix_sums.push_back((prefix_sums.back() + i) % MOD);
    }
}

string to_base_x(int num) {
    // Ascii 35 to 126 represent digits. Ascii 63(?), 92 (\), 127(DEL) are skipped
    int base = 180;
    string res = "";
    while (num) {
        int digit = num % base + 35;
        if(digit >= '?') digit++;
        if(digit >= '\\') digit++;
        if(digit >= 127) digit = -(digit - 126);
        res += char(digit);
        num /= base;
    }
    reverse(res.begin(), res.end());
    while (res.size() < 4) res = char(35) + res;
    return res;
}

void create_file() {
    ofstream fout("Basic_Blooms.cpp");
    fout << 
"#include <bits/stdc++.h>\n\
using namespace std;\n\
\n\
constexpr int MOD = 998244353;\n\
\n\
vector<int> prefix_sums;\n\
string prefix_sums_brute = \""; for (auto i: prefix_sums) fout << to_base_x(i); fout << "\";\n\
\n\
int from_base_x(string num) {\n\
    int base = 180;\n\
    int res = 0;\n\
    for (int i = 0; i < num.size(); ++i) {\n\
        res *= base;\n\
        int digit = num[i];\n\
        if(digit < 0) digit = -digit + 126;\n\
        if(digit >= '?') digit--;\n\
        if(digit >= '\\\\') digit--;\n\
        res += digit - 35;\n\
    }\n\
    return res;\n\
}\n\
\n\
int main() {\n\
    for (int i = 0; i < prefix_sums_brute.size(); i += 4) {\n\
        prefix_sums.push_back(from_base_x(prefix_sums_brute.substr(i, 4)));\n\
    }\n\
    int t;\n\
    cin >> t;\n\
    while (t--) {\n\
        int l, r; cin >> l >> r;\n\
        cout << (prefix_sums[r] - prefix_sums[l - 1] + MOD) % MOD << '\\n';\n\
    }\n\
    return 0;\n\
}";

    fout.close();
}

int main() {
    precompute();
    create_file();
    return 0;
}