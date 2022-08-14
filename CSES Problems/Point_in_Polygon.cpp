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
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v){out << i << ' ';} return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v){in >> i;} return in;}
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define FOR_RANGE(i, start, end) for(int i = start; i != end; i += (start<end) ? 1 : -1)
#define FOR_REV(i, n)            for(int i = (int)n-1; i >= 0; --i)
#define all(v)                   v.begin(), v.end()

#define x first
#define y second
#define pb push_back
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

int intersects(int x, double y, pll& p1, pll& p2){
	if(p1.y == p2.y){
		if(p1.y == y){
			if(x >= min(p1.x, p2.x) && x <= max(p1.x, p2.x))
				return -1;
		}
		return 0;
	}

	double xi = (p2.x - p1.x) * (y - p1.y)/(double)(p2.y - p1.y) + p1.x;
	if((xi >= min(p1.x, p2.x) && xi <= max(p1.x, p2.x)) && (y >= min(p1.y, p2.y) && y <= max(p1.y, p2.y)) && (xi >= x)){
		if(xi == x)
			return -1;
		if((xi == p2.x && y == p2.y))
			return 2;
		return 1;
	}
	return 0;
}

void solve(){
	int n, m;
	cin >> n >> m;
	V<pll> p(n);
	FOR(i, n)
		cin >> p[i].x >> p[i].y;

	FOR(_, m){
		int x, y;
		cin >> x >> y;
		int edges_intersected = 0;
		bool on_boundary = false;
		FOR(i, n){
			int temp = intersects(x, y, p[i], p[(i+1)%n]);
			if(temp == -1){
				cout << "BOUNDARY" << nl;
				on_boundary = true;
				break;
			}
			if(temp == 2){
				double e = 1e-6;
				if(p[(i+1)%n].y == p[(i+2)%n].y)
					temp = max(intersects(x, y+e, p[i], p[(i+1)%n]) + intersects(x, y + e, p[(i+2)%n], p[(i+3)%n]), intersects(x, y-e, p[i], p[(i+1)%n]) + intersects(x, y-e, p[(i+2)%n], p[(i+3)%n])) - 1;
				else
					temp = max(intersects(x, y+e, p[i], p[(i+1)%n]) + intersects(x, y + e, p[(i+1)%n], p[(i+2)%n]), intersects(x, y-e, p[i], p[(i+1)%n]) + intersects(x, y-e, p[(i+1)%n], p[(i+2)%n])) - 1;

			}
			edges_intersected += temp;
		}
		if(!on_boundary){
			if(edges_intersected % 2)
				cout << "INSIDE" << nl; 
			else
				cout << "OUTSIDE" << nl; 
		}
	}
}

int main(){
	FAST;
	solve();
	cout << nl;
	
	return 0;
}