#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int calculate_ans(vector<int> &p){
    vector<int> lt,rt;
    int n = p.size();
    if(n==1) return 0;
    p.push_back(0);
    for(int i = 0; i < n; i++){
        if(p[i]*2 <= n) lt.push_back(p[i]);
        else rt.push_back(p[i] - n/2);
    }
    int ans = 0;
    ans += calculate_ans(lt);
    ans += calculate_ans(rt);
    vector<int> lt_stack,rt_stack;
    for(int i = n-1; i >= 0; i--){
        if(p[i]*2 <= n){
            while(true){
                if(lt_stack.empty()) break;
                if(p[-lt_stack.back()] < p[i]) lt_stack.pop_back();
                else break;
            }
            int temp;
            if(lt_stack.empty()) temp = -n;
            else temp = lt_stack.back();
            ans += rt_stack.end() - lower_bound(rt_stack.begin(),rt_stack.end(),temp);
            lt_stack.push_back(-i);
        }
        else{
            while(true){
                if(rt_stack.empty()) break;
                if(p[-rt_stack.back()] > p[i]) rt_stack.pop_back();
                else break;
            }
            rt_stack.push_back(-i);
        }
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int &i : p) cin >> i;
    cout << calculate_ans(p) << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::freopen("input.txt", "r", stdin);
    std::freopen("output_brute.txt", "w", stdout);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
