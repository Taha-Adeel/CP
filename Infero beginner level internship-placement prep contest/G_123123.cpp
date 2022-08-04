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

struct Char{
	char c;
	int nearest1_l = -1;
	int nearest2_l = -1;
	int nearest3_l = -1;
	int nearest1_r = -1;
	int nearest2_r = -1;
	int nearest3_r = -1;
};

void solve(){
	string _s;
	cin >> _s;

	V<Char> s(_s.size());
	FOR(i, s.size()){
		char c = _s[i];
		s[i].c = c;
		if(c == '1'){
			s[i].nearest1_l = i;
			s[i].nearest2_l = s[max(i-1, 0)].nearest2_l;
			s[i].nearest3_l = s[max(i-1, 0)].nearest3_l;
		}
		else if(c == '2'){
			s[i].nearest2_l = i;
			s[i].nearest1_l = s[max(i-1, 0)].nearest1_l;
			s[i].nearest3_l = s[max(i-1, 0)].nearest3_l;
		}
		else if(c == '3'){
			s[i].nearest3_l = i;
			s[i].nearest2_l = s[max(i-1, 0)].nearest2_l;
			s[i].nearest1_l = s[max(i-1, 0)].nearest1_l;
		}
	}
	FOR_REV(i, s.size()){
		char c = _s[i];
		if(c == '1'){
			s[i].nearest1_r = i;
			s[i].nearest2_r = s[min(i+1, (int)(s.size()-1))].nearest2_r;
			s[i].nearest3_r = s[min(i+1, (int)(s.size()-1))].nearest3_r;
		}
		else if(c == '2'){
			s[i].nearest2_r = i;
			s[i].nearest1_r = s[min(i+1, (int)(s.size()-1))].nearest1_r;
			s[i].nearest3_r = s[min(i+1, (int)(s.size()-1))].nearest3_r;
		}
		else if(c == '3'){
			s[i].nearest3_r = i;
			s[i].nearest2_r = s[min(i+1, (int)(s.size()-1))].nearest2_r;
			s[i].nearest1_r = s[min(i+1, (int)(s.size()-1))].nearest1_r;
		}
	}

	int min_length = INT_MAX;
	FOR(i, s.size()){
		int min_with_c = INT_MAX;
		if(s[i].c == '1'){
			if(s[i].nearest2_l != -1 && s[i].nearest3_r != -1)
				min_with_c = min(min_with_c, s[i].nearest3_r - s[i].nearest2_l + 1);
			if(s[i].nearest2_r != -1 && s[i].nearest3_l != -1)
				min_with_c = min(min_with_c, s[i].nearest2_r - s[i].nearest3_l + 1);
		}
		else if(s[i].c == '2'){
			if(s[i].nearest1_l != -1 && s[i].nearest3_r != -1)
				min_with_c = min(min_with_c, s[i].nearest3_r - s[i].nearest1_l + 1);
			if(s[i].nearest1_r != -1 && s[i].nearest3_l != -1)
				min_with_c = min(min_with_c, s[i].nearest1_r - s[i].nearest3_l + 1);
		}
		else if(s[i].c == '3'){
			if(s[i].nearest1_l != -1 && s[i].nearest2_r != -1)
				min_with_c = min(min_with_c, s[i].nearest2_r - s[i].nearest1_l + 1);
			if(s[i].nearest1_r != -1 && s[i].nearest2_l != -1)
				min_with_c = min(min_with_c, s[i].nearest1_r - s[i].nearest2_l + 1);
		}
		min_length = min(min_length, min_with_c);
	}
	if(min_length == INT_MAX)
		min_length = 0;
	cout << min_length;
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