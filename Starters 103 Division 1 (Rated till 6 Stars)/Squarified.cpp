#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
    void sort()			{std::sort(this->begin(), this->end());}
    void sort_dsc() 	{std::sort(this->begin(), this->end(), greater<T>());}
    auto sum() 			{T sum = 0; for(auto& i: *this) sum += i; return sum;}
    auto freqs() 		{map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
    auto indices()		{int n=this->size(); map<T, V<int>> ii; for(int i=0; i<n; i++) ii[(*this)[i]].push_back(i); return ii;}
    auto prefix_sums() 	{int n=this->size(); V<T> ps(n+1,0); for(int i=0; i<n; i++) ps[i+1] = ps[i]+(*this)[i]; return ps;}
    friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i << ' '; return out;}
    friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}
#define display(x) if(x) pY else pN

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define ROF(i, n)                for(int i = (int)n-1; i >= 0; --i)
#define all(v)                   v.begin(), v.end()
#define rall(v)                  v.rbegin(), v.rend()

#define F  first
#define S  second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

#define N 10000

vi primes;
void seive(){
    bitset<N+1> is_prime;
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i*i <= N; ++i)
        if(is_prime[i])
            for(int j = i*i; j <= N; j += i)
                is_prime[j] = 0;
    FOR(i, N+1) if(is_prime[i]) primes.pb(i);
}

int get_square_free_part(int n){
    int ans = 1;
    for(auto& p: primes){
        if(p*p > n) break;
        int cnt = 0;
        while(n%p == 0) n /= p, cnt++;
        if(cnt%2) ans *= p;
    }
    if(n > 1) ans *= n;
    return ans;
}

void solve(){
    int n; cin >> n;
    vi a(n); cin >> a;

    int ans = 0;
    map<int, int> freq;
    FOR(i, n)
        freq[get_square_free_part(a[i])]++;
    
    for(auto& [k, v]: freq) if(k != 1)
        ans = max(ans, v);

    cout << ans;
}

int main(){
    FAST;
    seive();
    int T;
    cin >> T;
    FOR(t, T){
        solve();
        cout << nl;
    }
    
    return 0;
}