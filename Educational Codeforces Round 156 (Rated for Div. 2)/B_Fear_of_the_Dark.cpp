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

void solve(){
    int px, py, ax, ay, bx, by; cin >> px >> py >> ax >> ay >> bx >> by;

    double dist_pa = sqrt((px-ax)*(px-ax) + (py-ay)*(py-ay));
    double dist_pb = sqrt((px-bx)*(px-bx) + (py-by)*(py-by));
    double dist_ab = sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
    double dist_p = sqrt(px*px + py*py);
    double dist_a = sqrt(ax*ax + ay*ay);
    double dist_b = sqrt(bx*bx + by*by);

    auto is_good = [&](double r){
        if(dist_a <= r && dist_pa <=r) return true;
        if(dist_b <= r && dist_pb <=r) return true;
        if(r >= dist_ab/2 && (dist_pa <= r || dist_pb <= r) && (dist_a <= r || dist_b <= r)) return true;
        return false;
    };
    double l = 0, r = 1e6, delta = 1e-9;
    while(r-l > delta){
        double m = (l+r)/2;
        if(is_good(m)) r = m;
        else l = m;
    }
    cout << fixed << setprecision(10) << l;
}

int main(){
    int T;
    cin >> T;
    FOR(t, T){
        solve();
        cout << nl;
    }
    
    return 0;
}