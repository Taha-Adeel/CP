#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

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
#define F first
#define S second

constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

struct num{
	int val;
	int other;
	int index;
	bool start;
	num(){}
	num(int _val, int _other, int _index, bool _start): val(_val), other(_other), index(_index), start(_start){}
	friend bool operator<(const num& n1, const num& n2){return n1.val != n2.val ? n1.val < n2.val : n1.other > n2.other;}
	friend bool operator>(const num& n1, const num& n2){return n1.val != n2.val ? n1.val > n2.val : n1.other < n2.other;}
};
using ordered_set = tree<num, null_type, less<num>, rb_tree_tag, tree_order_statistics_node_update>;
 
void solve(){
	int n; cin >> n;
	V<num> nums(2*n);
	V<pii> lr(n);
	FOR(i, n){
		cin >> lr[i].F >> lr[i].S;
		nums[2 * i].val = lr[i].F;
		nums[2 * i].other = lr[i].S;
		nums[2 * i + 1].val = lr[i].S;
		nums[2 * i + 1].other = lr[i].F;
		nums[2 * i].start = true;
		nums[2 * i + 1].start = false;
		nums[2 * i].index = i;
		nums[2 * i + 1].index = i;
	}
 
	nums.sort();
	ordered_set finished;
	vll contain(n);
	FOR(i, 2*n){
		if(!nums[i].start) {
			num l = num(nums[i].other, nums[i].val, nums[i].index, true);
			finished.insert(l);
			contain[nums[i].index] = finished.size() - finished.order_of_key(l) - 1;
		}
	}
 
	cout << contain.sum();
}

int main() {
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        solve();
        cout << nl;
    }
    
    return 0;
}