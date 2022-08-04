#include <bits/stdc++.h>

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
struct event{
	int time;
	int time_other;
	int index;
	bool start;

	friend bool operator<(const event& e1, const event& e2){return e1.time != e2.time ? e1.time < e2.time : e1.start > e2.start;}
};


void solve(){
	int n;
	cin >> n;
	V<event> e(2*n);
	FOR(i, n){
		cin >> e[2*i].time >> e[2*i+1].time;
		e[2*i].time_other = e[2*i+1].time;	e[2*i + 1].time_other = e[2*i].time;
		e[2*i].start = true; 				e[2*i + 1].start = false;
		e[2*i].index = i; 					e[2*i + 1].index = i;
	}

	e.sort_asc();
	vi rooms(n);
	stack<int> free_rooms;
	int cur_occupied = 0;
	FOR(i, 2*n){
		if(e[i].start){
			cur_occupied++;
			if(free_rooms.empty())
				free_rooms.push(cur_occupied);
			
			rooms[e[i].index] = free_rooms.top();
			free_rooms.pop();
		}
		else{
			cur_occupied--;
			free_rooms.push(rooms[e[i].index]);
		}
	}
	int k = *max_element(rooms.begin(), rooms.end());
	cout << k << nl;
	cout << rooms;
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}