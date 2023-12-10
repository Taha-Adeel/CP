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

void solve() {
    int n, q; cin >> n >> q;
    map<int, int> odd, even;
    vi last_nz(n + 1, 0), last(n + 1, -1), pxor(n + 1, 0);
    vi a(n + 1);
    even[0] = 0;
    int cur = 0;
    for(int i=1;i<=n;++i) {
    	cin >> a[i];
    	cur ^= a[i];
    	pxor[i] = cur;
    	if(a[i] == 0) {
    		last_nz[i] = last_nz[i - 1];
    	}
    	else {
    		last_nz[i] = i;
    	}
    	if(i & 1) {
    		if(even.count(cur)) {
    			last[i] = even[cur];
    		}
    		odd[cur] = i;
    	}
    	else {
    		if(odd.count(cur)) {
    			last[i] = odd[cur];
    		}
    		even[cur] = i;
    	}
    }
    while(q--) {
    	int l, r;
    	cin >> l >> r;
    	if(pxor[l - 1] != pxor[r]) {
    		cout << "-1\n";
    	}
    	else if(last_nz[r] < l) {
    		cout << "0\n";
    	}
    	else if(r % 2 == l % 2) {
    		cout << "1\n";
    	}
    	else if(a[l] == 0 or a[r] == 0) {
    		cout << "1\n";
    	}
    	else if(last[r] >= l) {
    		cout << "2\n";
    	}
    	else {
    		cout << "-1\n";
    	}
    }
}

int main() {
    FAST;
    solve();
    cout << nl;
    
    return 0;
}