#include <bits/stdc++.h>
#include <iomanip>      // std::setw

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
    int n; cin >> n;
    
    if(n <= 2) { cout << -1 << nl; return; }
    else if(n == 3) { 
        cout << "2 3 1 3 2 1 3 2 1" << nl;
        cout << "1 3 3 2 3 2 1 2 1" << nl;
        return;
    }
    else if(n == 4) {
        cout << "1 2 4 3 1 3 4 3 1 2 4 2 3 4 2 1" << nl;
        cout << "2 3 3 2 4 4 2 1 1 2 4 4 3 1 1 3" << nl;
        return;
    }
    else if(n == 5) {
        cout << "1 2 3 5 4 5 4 2 1 3 1 3 5 4 5 3 2 1 2 1 3 4 5 4 2" << nl;
        cout << "1 2 1 1 2 4 5 5 4 4 5 5 5 3 2 2 3 2 4 3 3 4 3 1 1" << nl;
        return;
    }

    vi x, y;
    int cur_x, cur_y;

    V<vi> visited(n, vi(n, 0));

    auto is_valid = [&](pii p) {
        auto [x, y] = p;
        return 1 <= x && x <= n && 1 <= y && y <= n;
    };

    auto move = [&](pii dest) {
        if(!is_valid(dest)) return;
        tie(cur_x, cur_y) = dest;
        x.pb(cur_x), y.pb(cur_y);
        visited[cur_x-1][cur_y-1] = x.size();
    };

    auto move_u = [&](pii dest, int step_x, int step_y, pii lim_x) {
        // Go down
        while(lim_x.first <= cur_x + 2 * step_x && cur_x + 2 * step_x <= lim_x.second)
            move({cur_x + 2 * step_x, cur_y});

        // Make turn
        if(lim_x.first <= cur_x + step_x && cur_x + step_x <= lim_x.second) move({cur_x + step_x, cur_y + step_y});
        else move({cur_x - step_x, cur_y + step_y});
        step_x *= -1;

        // Go up
        while(make_pair(cur_x, cur_y) != dest)
            move({cur_x + 2 * step_x, cur_y});
    };

    auto move_zigzag_hor = [&](pii dest, int step_x, int step_y) {
        while(make_pair(cur_x, cur_y) != dest) {
            move({cur_x + step_x, cur_y + step_y});
            step_x *= -1;
            if(step_y > 0) step_y = (step_y == 1) ? 2 : 1;
            else step_y = (step_y == -1) ? -2 : -1;
        }
    };

    auto move_zigzag_vert = [&](int dest_y, int step_x, int step_y, int dist) {
        bool flip_parity = (dist % 2 != (cur_y == dest_y));
        for(int i = 0; i < dist - 3 * flip_parity; i++) {
            move({cur_x + step_x, cur_y + step_y});
            step_y *= -1;
        }
        if(flip_parity) {
            move({cur_x + 2 * step_x, cur_y});
            move({cur_x - step_x, cur_y + step_y});
        }
    };

    move({1, 1});
    if(n % 3 == 0) {
        // Color 0 (Even num columns)
        while(cur_y != n - 1) { // Cover all C0s using U loops
            move_u({cur_x + 1, cur_y + 1}, 1, 1, {1, n});
            move({cur_x - 1, cur_y + 2}); // Move to start of next U            
        }

        // Color 1 (Even num columns)
        move({4, n}); // Switch from Color 0 to Color 1
        move_u({cur_x - 1, cur_y - 1}, 1, -1, {1, n}); // Traverse all C1 cells in the last 2 columns
        move({cur_x - 1, cur_y + 1}); // Move to missed cell 
        move({cur_x - 1, cur_y - 1}); // Finish last 2 columns
        while(cur_y != 2) { // Cover the remaining C1s
            move({cur_x + 1, cur_y - 2}); // Move to start of next U
            move_u({cur_x - 1, cur_y - 1}, 1, -1, {1, n});
        }

        // Color 2 (Even num columns)
        move({cur_x + 1, cur_y + 2}); // Switch from Color 1 to Color 2
        move_zigzag_hor({1, n}, -1, 2); // Traverse all C2 cells in the first 2 rows
        move({3, n}); // Move to start of the U
        while(cur_y != 4) { // Cover the remaining C2s
            move_u({cur_x + 1, cur_y - 2}, 1, -2, {3, n});
            if(cur_y != 4)
                move({cur_x - 1, cur_y - 1}); // Move to start of next U
        }
        move({cur_x + 1, cur_y - 1}); // Finish last 2 rows
        move_u({4, 1}, 1, -2, {3, n}); // Traverse all C2 cells in the last 2 rows
        move({3, 3}); move({1, 3}); move({2, 1}); // Finish hamiltonian tour
    }
    else if(n % 3 == 1) {
        // Color 0 (Odd num columns)
        move_zigzag_vert(cur_y + 1, 1, 1, n); // Traverse first 2 columns
        if(n % 2 == 1) move({cur_x + 1, cur_y + 2});
        else move({cur_x - 1, cur_y + 2});
        while(cur_y != n) { // Cover all C0s in the middle
            if(n % 2 == 1) {
                move_u({cur_x - 1, cur_y + 1}, -1, 1, {1, n});
                move({cur_x + 1, cur_y + 2});
            } else {
                move_u({cur_x + 1, cur_y + 1}, -1, 1, {1, n});
                move({cur_x - 1, cur_y + 2});
            }
        }
        while(cur_x != 1) // Go up
            move({cur_x - 2, cur_y});

        // Color 2 (Odd num columns)
        move({cur_x + 2, cur_y - 1}); // Switch from Color 0 to Color 2
        move({cur_x - 2, cur_y}); move({cur_x + 1, cur_y + 1}); move({cur_x + 2, cur_y}); // Get missed cells
        move_zigzag_vert(cur_y - 1, 1, -1, n - 3); // Traverse all C2 cells in the last 2 cols
        if(n % 2 == 0) move({cur_x + 1, cur_y - 2});
        else move({cur_x - 1, cur_y - 2});
        while(cur_y != 1) { // Cover all C2s in the middle (Last U smaller)
            if(n % 2 == 0) {
                move_u({cur_x - 1, cur_y - 1}, -1, -1, {1 + (cur_y == 4), n});
                move({cur_x + 1, cur_y - 2});
            }
            else {
                move_u({cur_x + 1, cur_y - 1}, -1, -1, {1 + (cur_y == 4), n});
                move({cur_x - 1, cur_y - 2});
            }
        }
        while(cur_x != 2) // Go up
            move({cur_x - 2, cur_y});
        move({cur_x - 1, cur_y + 2}); // Visit last C2 cell

        // Color 1 (Even num columns)
        move({cur_x + 2, cur_y - 1}); // Switch from Color 2 to Color 1
        while(true) { // Cover all C1s in the middle
            move_u({cur_x + 1, cur_y + 1}, 1, 1, {3, n});
            if(cur_y == n - 1) break;
            move({cur_x - 1, cur_y + 2}); // Move to start of next U
        }
        move({cur_x - 2, cur_y}); // Move to top 2 rows
        move_zigzag_hor({1, 2}, -1, -1); // Traverse all C1 cells in the first 2 rows
    }
    else if(n % 3 == 2) {
        // Color 0 (Even num columns)
        while(cur_y != n) { // Cover all C0s using U loops
            move_u({cur_x + 1, cur_y + 1}, 1, 1, {1, n});
            move({cur_x - 1, cur_y + 2}); // Move to start of next U            
        }

        // Color 2 (Odd num columns)
        move({cur_x - 1, cur_y - 2}); // Switch from Color 0 to Color 2
        move_zigzag_vert(cur_y, 1, 1, n); // Traverse all C2 cells in the last 2 columns
        if(n % 2 == 0) move({cur_x + 1, cur_y - 2});
        else move({cur_x - 1, cur_y - 2});
        while(cur_y != 1) { // Cover all C2s in the middle (Last U smaller)
            if(n % 2 == 0) {
                move_u({cur_x - 1, cur_y - 1}, -1, -1, {1 + (cur_y == 4), n});
                move({cur_x + 1, cur_y - 2});
            } else {
                move_u({cur_x + 1, cur_y - 1}, -1, -1, {1 + (cur_y == 4), n});
                move({cur_x - 1, cur_y - 2});
            }
        }
        while(cur_x != 2) // Go up
            move({cur_x - 2, cur_y});
        move({cur_x - 1, cur_y + 2}); // Visit last C2 cell

        // Color 1 (Odd num columns)
        move({cur_x + 2, cur_y - 1}); // Switch from Color 2 to Color 1
        move_zigzag_vert(cur_y + 1, 1, 1, n - 2); // Traverse all C1 cells in the last 2 columns
        while(cur_y != n - 2) { // Cover all C1s in the middle
            if(n % 2 == 0) {
                move({cur_x - 1, cur_y + 2}); // Move to start of next U
                move_u({cur_x + 1, cur_y + 1}, -1, 1, {3, n});
            } else {
                move({cur_x + 1, cur_y + 2}); // Move to start of next U
                move_u({cur_x - 1, cur_y + 1}, -1, 1, {3, n});
            }
        }
        if(n % 2 == 0) move({cur_x - 1, cur_y + 2}); // Move to start of next U
        else move({cur_x + 1, cur_y + 2});
        while(cur_x != 1) // Go up
            move({cur_x - 2, cur_y});
        move_zigzag_hor({1, 2}, 1, -2); // Traverse all C1 cells in the first 2 rows
    }

    cerr << x.size() << nl;
    for(auto& v: visited) {
        for(auto& i: v)
            cerr << setw(4) << i;
        cerr << nl;
    }

    cout << x << nl;
    cout << y << nl;
}

int main() {
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        solve();
    }
    
    return 0;
}