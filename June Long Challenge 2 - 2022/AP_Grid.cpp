#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort_asc() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	long long sum() {long long sum = 0; for(auto& i: *this) sum += i; return sum;}
	map<T, int> freqs() {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i << ' '; return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
};
void display(bool answer){cout << ((answer)?"Yes":"No");}
#define pY {cout << "Yes"; return;}
#define pN {cout << "No";  return;}

#define FOR(i, n)                for(ll i = 0; i < n; ++i)
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

void solve(){
	ll N, M;
	cin >> N >> M;
	bool m_greater = (M >= N);
	if(M < N)
		swap(M, N);

	ll d1 = 1, d2 = 3, c1 = 2;
	ll a_nm = 1 + c1*(N-1) + (M-1)*(d1 + (M-1)*(d2-d1));
	if(1 + (N+1)*(N-1) + (M-1)*(d1 + (M-1)*(2-d1)) < a_nm){
		d2 = 2;
		c1 = N + 1;
	}
	V<vll> A(N, vll(M));
	FOR(i, N){
		A[i][0] = 1 + c1*i;
		FOR(j, M){
			A[i][j] = A[i][0] + j * (d1 + (i)*(d2-d1));
		}
	}

	if(!m_greater) 
		swap(M, N);
	FOR(i, N){
		FOR(j, M){
			if(m_greater)
				cout << A[i][j] << ' ';
			else
				cout << A[j][i] << ' ';
		}
		cout << nl;
	}
}

int main(){
	int T;
	cin >> T;
	FOR(t, T){
		solve();
	}
	
	return 0;
}