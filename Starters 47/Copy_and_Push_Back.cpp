#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort_asc() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	long long sum() {long long sum = 0; for(auto& i: *this) sum += i; return sum;}
	map<T, int> freqs() {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	map<T, vector<int>> indices() {map<T, vector<int>> index; for(int i=0; i<this->size(); i++) index[this->at(i)].push_back(i); return index;}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i << ' '; return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
};
void display(bool answer){cout << ((answer)?"YES":"NO");}
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}

#define FOR(i, n)                for(int i = 0; i < n; ++i)
#define FOR1(i, n)               for(int i = 1; i < n; ++i)
#define FOR_RANGE(i, start, end) for(int i = start; i != end; i += (start<end) ? 1 : -1)
#define FOR_REV(i, n)            for(int i = n-1; i >= 0; --i)

#define f  first
#define s  second
#define pb push_back
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

// void construct(string& S, const string& A, bool did_op_1){
// 	if(good == true)
// 		return;
// 	if(S.length() >= A.size() && S.compare(A) == 0){
// 		good = true;
// 		return;
// 	}

// 	if(S.size() <= A.size()/2 && S.compare(A.substr(S.size(), S.size())) == 0){
// 		S += S;
// 		construct(S, A, false);
// 		S.erase(S.size()/2);
// 	}
// 	if(!did_op_1){
// 		S += A[S.length()];
// 		construct(S, A, true);
// 		S.erase(S.size() - 1);
// 	}
// }

void solve(){
	int N;
	cin >> N;
	string A;
	cin >> A;
	bool did_op_1 = false;
	while(A.size() > 0){
		if(A.size()%2 == 0){
			if(A.substr(0, A.size()/2).compare(A.substr(A.size()/2)) != 0)
				pN
			did_op_1 = false;
			A.erase(A.size()/2);
		}
		else{
			if(did_op_1 || A.substr(0, A.size()/2).compare(A.substr(A.size()/2, A.size()/2)) != 0)
				pN
			// did_op_1 = true;
			A.erase(A.size()/2);
		}
	}
	pY
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