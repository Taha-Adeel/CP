#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
    void sort()            {std::sort(this->begin(), this->end());}
    void sort_dsc()     {std::sort(this->begin(), this->end(), greater<T>());}
    auto sum()             {T sum = 0; for(auto& i: *this) sum += i; return sum;}
    auto freqs()         {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
    auto indices()        {int n=this->size(); map<T, V<int>> ii; for(int i=0; i<n; i++) ii[(*this)[i]].push_back(i); return ii;}
    auto prefix_sums()     {int n=this->size(); V<T> ps(n+1,0); for(int i=0; i<n; i++) ps[i+1] = ps[i]+(*this)[i]; return ps;}
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

ll get_closest_palindrome(ll x){
    string s = to_string(x);
    int n = s.size();

    string left = s.substr(0, n/2);
    string right = s.substr((n+1)/2);

    string rev_left = left;
    reverse(all(rev_left));
    
    string left_copy = left;
    if(n%2) left_copy += s[n/2];
    ll ans1 = stoll(left + rev_left);

    // Add one to middle digit
    left_copy = left;
    int i = n/2 - 1;
    while(i >= 0 && left[i] == '9'){
        left_copy[i] = '0';
        i--;
    }
    if(i >= 0) left_copy[i]++;
    else left_copy = "1" + left_copy;

    rev_left = left_copy; reverse(all(rev_left));
    if(n%2) left_copy += "0";
    ll ans2 = stoll(left_copy + rev_left);

    // Subtract one from middle digit
    left_copy = left;
    i = n/2 - 1;
    while(i >= 0 && left[i] == '0'){
        left_copy[i] = '9';
        i--;
    }
    if(i >= 0) left_copy[i]--;
    else left_copy = "0";

    rev_left = left_copy; reverse(all(rev_left));
    if(n%2) left_copy += "9";
    ll ans3 = stoll(left_copy + rev_left);

    return min({ans1, ans2, ans3}, [&](ll a, ll b){return abs(a-x) < abs(b-x);});
}

void solve(){
    ll n; cin >> n;

    cout << n << ' ' << get_closest_palindrome(n) << nl;
}

int main(){
    int T;
    cin >> T;
    FOR(t, T){
        solve();
    }
    
    return 0;
}