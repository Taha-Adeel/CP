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
    friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v){out << i << ' ';} return out;}
    friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v){in >> i;} return in;}
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}
#define display(x) if(x) pY else pN

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define ROF(i, n)            for(int i = (int)n-1; i >= 0; --i)
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

void solve(){
    int n; cin >> n;
    vi a(n); cin >> a;


    auto indices = a.indices();
    int ans = 0;
    for(auto& [x, vx]: indices){
        for(auto& [y, vy]: indices){
            if(y < x || vx.size()+vy.size() <= ans) continue;

            int i = 0, j = 0;
            vi seq;
            if(vy[0] < vx[0]) seq.pb(vy[0]), j++;
            while(true){
                // Add x
                while(!seq.empty() && i < vx.size() && seq.back() >= vx[i]) i++;
                if(i != vx.size()) seq.pb(vx[i]), i++;
                else break;
                
                // Add y
                while(j < vy.size() && seq.back() >= vy[j]) j++;
                if(j != vy.size()) seq.pb(vy[j]), j++;
                else break;
            }
            ans = max(ans, (int)seq.size());
        }
    }

    cout << ans;
}

int main(){
    FAST;
    solve();
    cout << nl;
    
    return 0;
}