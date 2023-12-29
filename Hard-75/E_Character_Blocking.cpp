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
    string s1, s2; cin >> s1 >> s2;
    int t, q; cin >> t >> q;

    int blocked_cnt = 0, equal_cnt = 0, n = s1.size();
    FOR(i, n) 
        equal_cnt += (s1[i] == s2[i]);

    queue<pii> blocked_pos;
    FOR(cur_time, q) {
        // Check if any blocked position is unblocked
        while(!blocked_pos.empty() && blocked_pos.front().first == cur_time) {
            int pos = blocked_pos.front().second;
            blocked_pos.pop();

            if(s1[pos] == s2[pos]) equal_cnt++;
            blocked_cnt--;
        }

        int type; cin >> type;
        if(type == 1) { // Block the given position
            int pos; cin >> pos; --pos;

            if(s1[pos] == s2[pos]) equal_cnt--;
            blocked_pos.push({cur_time + t, pos});
            blocked_cnt++;  
        }
        else if(type == 2) { // Swap the given positions
            int i1, pos1, i2, pos2; cin >> i1 >> pos1 >> i2 >> pos2; pos1--; pos2--;

            if(s1[pos1] == s2[pos1]) equal_cnt--;
            if(s1[pos2] == s2[pos2]) equal_cnt--;
            if(i1 == i2) {
                if(i1 == 1) swap(s1[pos1], s1[pos2]);
                else swap(s2[pos1], s2[pos2]);
            }
            else {
                if(i1 == 1) swap(s1[pos1], s2[pos2]);
                else swap(s2[pos1], s1[pos2]);
            }
            if(s1[pos1] == s2[pos1]) equal_cnt++;
            if(s1[pos2] == s2[pos2]) equal_cnt++;
        }
        else if(type == 3) { // Check if the unblocked positions are equal
            if(n - blocked_cnt == equal_cnt) cout << "YES" << nl;
            else cout << "NO" << nl;
        }
    }
}

int main() {
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        solve();
    }
    
    return 0;
}