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

// Structure to store
// 4 values that are to be stored
// in the nodes
struct node {
    ll sum, prefixsum, suffixsum, maxsum;
};

// array to store the segment tree
node tree[4 * 5 * 100000];

// function to build the tree
void build(vector<ll>& arr, int low, int high, int index)
{
    // the leaf node
    if (low == high) {
        tree[index].sum = arr[low];
        tree[index].prefixsum = arr[low];
        tree[index].suffixsum = arr[low];
        tree[index].maxsum = arr[low];
    }
    else {
        int mid = (low + high) / 2;

        // left subtree
        build(arr, low, mid, 2 * index + 1);

        // right subtree
        build(arr, mid + 1, high, 2 * index + 2);

        // parent node's sum is the summation
        // of left and right child
        tree[index].sum = tree[2 * index + 1].sum
                          + tree[2 * index + 2].sum;

        // parent node's prefix sum will be equivalent
        // to maximum of left child's prefix sum or left
        // child sum + right child prefix sum.
        tree[index].prefixsum
            = max(tree[2 * index + 1].prefixsum,
                  tree[2 * index + 1].sum
                      + tree[2 * index + 2].prefixsum);

        // parent node's suffix sum will be equal to right
        // child suffix sum or right child sum + suffix
        // sum of left child
        tree[index].suffixsum
            = max(tree[2 * index + 2].suffixsum,
                  tree[2 * index + 2].sum
                      + tree[2 * index + 1].suffixsum);

        // maximum will be the maximum of prefix, suffix of
        // parent or maximum of left child or right child
        // and summation of left child's suffix and right
        // child's prefix.
        tree[index].maxsum
            = max(tree[index].prefixsum,
                  max(tree[index].suffixsum,
                      max(tree[2 * index + 1].maxsum,
                          max(tree[2 * index + 2].maxsum,
                              tree[2 * index + 1].suffixsum
                                  + tree[2 * index + 2]
                                        .prefixsum))));
    }
}

// function to return answer to  every type-1 query
node query(vector<ll>& arr, int index, int low, int high, int l,
           int r)
{
    // initially all the values are INT_MIN
    node result;
    result.sum = result.prefixsum = result.suffixsum
        = result.maxsum = INT_MIN;

    // range does not lies in this subtree
    if (r < low || high < l)
        return result;

    // complete overlap of range
    if (l <= low && high <= r)
        return tree[index];

    int mid = (low + high) / 2;

    // right subtree
    if (l > mid)
        return query(arr, 2 * index + 2, mid + 1, high, l,
                     r);

    // left subtree
    if (r <= mid)
        return query(arr, 2 * index + 1, low, mid, l, r);

    node left = query(arr, 2 * index + 1, low, mid, l, r);
    node right
        = query(arr, 2 * index + 2, mid + 1, high, l, r);

    // finding the maximum and returning it
    result.sum = left.sum + right.sum;
    result.prefixsum
        = max(left.prefixsum, left.sum + right.prefixsum);

    result.suffixsum
        = max(right.suffixsum, right.sum + left.suffixsum);
    result.maxsum = max(
        result.prefixsum,
        max(result.suffixsum,
            max(left.maxsum,
                max(right.maxsum,
                    left.suffixsum + right.prefixsum))));

    return result;
}

ll f(int l, int r, vector<ll>& arr){
	return max(0LL, query(arr, 0, 0, arr.size()-1, l, r).maxsum);
}

void solve(){
	ll n;
	cin >> n;
	string s;
	cin >> s;

	vll seq(n);
	FOR(i, n)
		if(s[i] == '1') seq[i] = 1;
		else seq[i] = INT_MIN;
	build(seq, 0, n - 1, 0);

    // FOR(i, n) for(int j = i; j < n; j++) cout << i << ' ' << j << ' ' << f(i, j, seq) << nl;

	ll ans = 0;
	FOR(i, n){
		int cur_k = f(i, n-1, seq);

		while(cur_k > 0){
			// Perform binary search on the increasing function f to find the smallest index j such that f(i, j) == cur_k
            int l = i, r = n-1;
            while(l < r){
                int mid = (l + r) / 2;
                if(f(i, mid, seq) >= cur_k) r = mid;
                else l = mid + 1;
            }
            int j = l;
            cout << i << ' ' << cur_k << ' ' << j << ' ' << f(i, j, seq) << nl;
            cur_k--;
		}
	}
	cout << ans;
}

int main(){
	int T = 1;
	// cin >> T;
	FOR(t, T){
		solve();
		cout << nl;
	}
	
	return 0;
}