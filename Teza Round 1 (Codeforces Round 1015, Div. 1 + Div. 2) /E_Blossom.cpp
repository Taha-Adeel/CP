#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
    void sort()        { std::sort(this->begin(), this->end()); }
    void sort_dsc()    { std::sort(this->begin(), this->end(), greater<T>()); }
    auto sum()         { T sum = 0; for(auto& i: *this) sum += i; return sum; }
    auto freqs()       { map<T, int> freq; for(auto& i: *this) freq[i]++; return freq; }
    auto indices()     { int n=this->size(); map<T, V<int>> ii; for(int i=0; i<n; i++) ii[(*this)[i]].push_back(i); return ii; }
    auto prefix_sums() { int n=this->size(); V<T> ps(n+1,0); for(int i=0; i<n; i++) ps[i+1] = ps[i]+(*this)[i]; return ps; }
    friend ostream& operator<<(ostream& out, const V<T>& v) { for(auto& i: v) out << i << ' '; return out; }
    friend istream& operator>>(istream& in, V<T>& v)        { for(auto& i: v) in >> i; return in; }
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}
#define display(x) if(x) pY else pN

#define FOR(i, n)     for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)    for(int i = 1; i <= (int)n; ++i)
#define ROF(i, n)     for(int i = (int)n-1; i >= 0; --i)
#define all(v)        v.begin(), v.end()
#define pb push_back

constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

template<int MOD = MOD, int MxN = 100'001>
class Z {
    int val;
public:
    static vector<Z> fact;
    static void init_fact() { fact.resize(MxN); fact[0] = 1; for(int i = 1; i < MxN; ++i) fact[i] = fact[i-1] * i; }
    Z(ll v = 0) : val(v%MOD) { if(val < 0) val += MOD; }

    Z pow(ll e) const { Z res = 1; for(Z b = val; e > 0; b = b*b, e /= 2) if(e & 1) res = res*b; return res; }
    Z inv() const { return pow(MOD-2); }
    static Z nCr(int n, int k) { if(k < 0 || k > n) return 0; if(fact.empty()) init_fact(); return fact[n] / (fact[k] * fact[n-k]); }

    Z operator+(const Z& o) const { return Z(val + o.val); }
    Z operator-(const Z& o) const { return Z(val - o.val); }
    Z operator*(const Z& o) const { return Z((ll)val * o.val); }
    Z operator/(const Z& o) const { return *this * o.inv(); }
    Z operator-() const { return Z(-val); }
    Z operator+=(const Z& o) { return *this = *this + o; }
    Z operator-=(const Z& o) { return *this = *this - o; }
    Z operator*=(const Z& o) { return *this = *this * o; }
    Z operator/=(const Z& o) { return *this = *this / o; }
    bool operator==(const Z& o) const { return val == o.val; }
    bool operator!=(const Z& o) const { return val != o.val; }

    friend istream& operator>>(istream& in, Z& z) { ll v; in >> v; z = Z(v); return in; }
    friend ostream& operator<<(ostream& out, const Z& z) { return out << z.val; }
};
template<int MOD, int MxN>
vector<Z<MOD, MxN>> Z<MOD, MxN>::fact;

int computeMex(const set<int>& S) { int cur = 0; while(S.count(cur)) cur++; return cur; }

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;
    
    V<bool> used(n, false);
    for (int i = 0; i < n; i++){
        if(a[i] != -1){
            used[a[i]] = true;
        }
    }

    vi missingVals;
    for (int v = 0; v < n; v++){
        if(!used[v])
            missingVals.push_back(v);
    }
    int m = missingVals.size();

    vi prefixMissing(n,0);
    for (int i = 0; i < n; i++){
        prefixMissing[i] = (a[i] == -1);
        if(i > 0) prefixMissing[i] += prefixMissing[i-1];
    }

    Z<MOD> ans = 0;
    for (int l = 0; l < n; l++){
        for (int r = l; r < n; r++){
            int t = prefixMissing[r] - (l==0 ? 0 : prefixMissing[l-1]);
            set<int> segFixed;
            for (int i = l; i <= r; i++){
                if(a[i] != -1) segFixed.insert(a[i]);
            }
            Z segSum = 0;
            vi idx(m);
            iota(idx.begin(), idx.end(), 0);

            vi comb;
            function<void(int,int)> gen = [&](int start, int left) {
                if(left == 0){
                    set<int> U = segFixed;
                    for (int x : comb) U.insert(missingVals[x]);
                    int curMex = computeMex(U);
                    segSum += curMex;
                    return;
                }
                for (int i = start; i <= m - left; i++){
                    comb.push_back(i);
                    gen(i+1, left-1);
                    comb.pop_back();
                }
            };
            if(t <= m){
                gen(0, t);
            }
            Z weight = Z<MOD>::fact[t] * Z<MOD>::fact[m-t];
            Z segContribution = segSum * weight;
            ans += segContribution;
        }
    }

    cout << ans;
}

int main() {
    FAST;
    Z<MOD>::init_fact();
    int T; cin >> T;
    FOR(t, T) {
        solve();
        cout << nl;
    }
    
    return 0;
}