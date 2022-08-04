#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort_asc() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	long long sum() {long long sum = 0; for(auto& i: *this) sum += i; return sum;}
	map<T, int> freqs() {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	map<T, vector<int>> indices() {map<T, vector<int>> index; for(int i=0; i<this->size(); i++) index[this->at(i)].push_back(i); return index;}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v){out << i << ' ';} return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v){in >> i;} return in;}
};
void display(bool answer){cout << ((answer)?"Yes":"No");}
#define pY {cout << "Yes"; return;}
#define pN {cout << "No";  return;}

#define FOR(i, n)                for(int i = 0; i < n; ++i)
#define FOR1(i, n)               for(int i = 1; i < n; ++i)
#define FOR_RANGE(i, start, end) for(int i = start; i != end; i += (start<end) ? 1 : -1)
#define FOR_REV(i, n)            for(int i = n-1; i >= 0; --i)

#define F  first
#define S  second
#define pb push_back
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
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
	int n;
	cin >> n;
	V<num> nums(2*n);
	V<pii> xy(n);
	FOR(i, n){
		cin >> xy[i].F >> xy[i].S;
		nums[2*i].val = xy[i].F;
		nums[2*i].other = xy[i].S;
		nums[2*i + 1].val = xy[i].S;
		nums[2*i + 1].other = xy[i].F;
		nums[2*i].start = true;
		nums[2*i + 1].start = false;
		nums[2*i].index = i;
		nums[2*i + 1].index = i;
	}

	nums.sort_asc();
	ordered_set cur_ranges, finished;
	vi contain(n), contained_by(n);
	FOR(i, 2*n){
		if(nums[i].start)
			cur_ranges.insert(nums[i]);
		else{
			num l = num(nums[i].other, nums[i].val, nums[i].index, true);

			finished.insert(l);
			contain[nums[i].index] = finished.size() - finished.order_of_key(l) - 1;
			contained_by[nums[i].index] = cur_ranges.order_of_key(l);
			cur_ranges.erase(l);
		}
	}

	cout << contain << nl << contained_by;
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}