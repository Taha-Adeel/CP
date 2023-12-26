#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> ii;

struct node{
	int s, e, m;
	long long val = 0; long long lazy = 0;
	node *l, *r;
	
	node(int S, int E){
		s = S, e = E, m = (s+e)/2;
		if(s != e){
			l = new node(s, m);
			r = new node(m+1, e);
		}
	}
	
	void apply(long long L){
		val += L;
		lazy += L;
	}
	void push(){
		if(s == e) return;
		l->apply(lazy);
		r->apply(lazy);
		lazy = 0;
	}
	
	void update(int S, int E, long long L){
		push();
		if(s == S && E == e){
			apply(L);
			return;
		}
		else if(E <= m) l->update(S, E, L);
		else if(S >= m+1) r->update(S, E, L);
		else l->update(S, m, L), r->update(m+1, E, L);
		val = min(l->val, r->val);
	}
	
	long long query(int S, int E){
		push();
		if(s == S && E == e) return val;
		else if(E <= m) return l->query(S, E);
		else if(S >= m+1) return r->query(S, E);
		else return min(l->query(S, m), r->query(m+1, E));
	}
} *root;	


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	ii arr[n];
	for(int i = 0;i < n;i++){
		cin >> arr[i].first;
		arr[i].second = i;
	}
	
	sort(arr,arr+n);
	reverse(arr,arr+n);
	int ans = 0;
	root = new node(0, n-1);
	for(int i = 0;i < n;i++){
		int pos = arr[i].second;
		long long x = arr[i].first;
		
		if(x + root->query(pos,n-1) >= 0){
			ans++;
			root->update(pos,n-1,x);
		}
	}
	
	cout << ans;
}