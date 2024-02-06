#include <bits/stdc++.h>
#include <gmpxx.h> // Compile with -lgmpxx -lgmp

using namespace std;

using ll = mpz_class;
constexpr int MOD = 998244353;
constexpr int N = 1'000'000;

array<int, N> nums;
array<int, N + 1> prefix_sums;

struct Num {
    ll value;
    ll base_value;
    int mod_value;
    int mod_base_value;
    int base;
    int digit;

    Num(int base): base(base), digit(1), value(1), base_value(1), mod_value(1), mod_base_value(1) {}

    Num& operator++() {
        digit++;
        value += base_value;
        (mod_value += mod_base_value) %= MOD;
        if (digit == base) {
            digit = 1;
            value += 1;
            base_value = value;
            (mod_value += 1) %= MOD;
            mod_base_value = mod_value;
        }

        return *this;
    }

    bool operator>(const Num& other) const {
        return value > other.value;
    }
};

void precompute() {
    ll prev_num = 0;
    priority_queue<Num, vector<Num>, greater<Num>> pq;
    for (int base = 2; base <= 16; ++base) {
        pq.emplace(base);
    }

    for (int i = 0; i < N; ++i) {
        auto num = pq.top(); pq.pop();
        if(num.value > prev_num) {
            nums[i] = num.mod_value;
            prev_num = num.value;
        } else {
            --i;
        }
        ++num;
        pq.push(num);
    }

    prefix_sums[0] = 0;
    for (int i = 0; i < N; ++i) {
        prefix_sums[i + 1] = (prefix_sums[i] + nums[i]) % MOD;
    }
}

int main() {
    precompute();
    int t;
    cin >> t;
    while (t--) {
        int l, r; cin >> l >> r;
        cout << (prefix_sums[r] - prefix_sums[l - 1] + MOD) % MOD << '\n';
    }
    return 0;
}