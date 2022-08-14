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
 
#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define FOR_RANGE(i, start, end) for(int i = start; i != end; i += (start<end) ? 1 : -1)
#define FOR_REV(i, n)            for(int i = (int)n-1; i >= 0; --i)
#define all(v)                   v.begin(), v.end()
 
#define x  first
#define y  second
#define E  0.00001
#define pb push_back
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using ld  = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pld = pair<ld,ld>;
using vi  = V<int>;
using vll = V<ll>;
 
/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/
 
ld get_slope(pll p1, pll p2){
	if(p1.x == p2.x)
		return INT_MAX;
	return (ld)(p2.y - p1.y)/(ld)(p2.x - p1.x);
}
 
ld get_c(pll p, ld m){
	if(abs(m - INT_MAX) <= E)
		return INT_MAX;
	return p.y - m * p.x;
}
 
bool in_between(ld a, ld b, ld c){
	return b + E >= min(a, c) && b - E <= max(a, c);
}
 
bool point_in_between(pld a, pld b, pld c){
	return in_between(a.x, b.x, c.x) && in_between(a.y, b.y, c.y);
}
 
bool intersect(ld a, ld b, ld c, ld d){
	return min(c, d) <= max(a, b) && max(c, d) >= min(a, b);
}
 
void solve(){
	V<pll> p(4);
	FOR(i, 4)
		cin >> p[i].x >> p[i].y;
	
	ld m1, m2, c1, c2, xi, yi;
	m1 = get_slope(p[0], p[1]);
	m2 = get_slope(p[2], p[3]);
	c1 = get_c(p[0], m1);
	c2 = get_c(p[2], m2);
	if(m1 == m2){
		if(c1 == c2){
			if(m1 == INT_MAX) {if(p[0].x == p[2].x && intersect(p[0].y, p[1].y, p[2].y, p[3].y))
				pY}
			else if(intersect(p[0].x, p[1].x, p[2].x, p[3].x))
				pY
		}
		pN
	}
 
	if(abs(m1 - INT_MAX) <= E){
		xi = p[0].x;
		yi = m2 * xi + c2;
	}
	else if(abs(m2 - INT_MAX) <= E){
		xi = p[2].x;
		yi = m1 * xi + c1;
	}
	else{
		xi = (c2 - c1)/(m1 - m2);
		yi = m1 * xi + c1;
	}
	pld pi = {xi, yi};
 
	if(point_in_between(p[0], pi, p[1]) && point_in_between(p[2], pi, p[3]))
		pY
	else
		pN	
}
 
int main(){
	FAST;
	int T;
	cin >> T;
	FOR(t, T){
		solve();
		cout << nl;
	}
	
	return 0;
}