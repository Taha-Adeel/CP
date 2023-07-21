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
#define display(x) if(x) pY else pN

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define ROF(i, n)            for(int i = (int)n-1; i >= 0; --i)
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

class TrieNode{
public:
	TrieNode* parent = nullptr;
	TrieNode* children[2] = {nullptr, nullptr};
	char c;
	int freq = 0;
	TrieNode(char c = ' '): c(c){}
};


class Trie{
public:
	TrieNode* root = new TrieNode();
	void add(string s){
		TrieNode* curr = root;
		curr->freq++;
		for(auto& c: s){
			if(curr->children[c - '0'] == nullptr){
				curr->children[c - '0'] = new TrieNode(c);
				curr->children[c - '0']->parent = curr;
			}
			curr = curr->children[c - '0'];
			curr->freq++;
		}
	}

	bool remove(string s){
		TrieNode* curr = root;

		for(auto& c: s){
			if(curr->children[c - '0'] == nullptr) return false;
			curr = curr->children[c - '0'];
		}

		TrieNode* parent = curr->parent;
		while(curr != nullptr){
			curr->freq--;
			if(curr->freq == 0){
				parent->children[curr->c - '0'] = nullptr;
				delete curr;
			}
			curr = parent;
			if(curr != nullptr) parent = curr->parent;
		}
		return true;
	}

};

string binary_32(int x){
	return bitset<32>(x).to_string();
}

void solve(){
	int q; cin >> q;

	Trie t;
	t.add(binary_32(0));

	while(q--){
		char op; int x;
		cin >> op >> x;
		if(op == '+'){
			t.add(binary_32(x));
		}
		else if(op == '-'){
			t.remove(binary_32(x));
		}
		else{
			TrieNode* curr = t.root;
			string ans = "";
			for(auto& c: binary_32(x)){
				if(curr->children[(c^'0'^'1') - '0'] != nullptr){
					ans += c^'0'^'1';
					curr = curr->children[(c^'0'^'1') - '0'];
				}
				else{
					ans += c;
					curr = curr->children[c - '0'];
				}
			}

			cout << (stoi(ans, nullptr, 2) ^ x) << nl;
		}
	}
}

int main(){
	FAST;
	solve();
	cout << nl;
	
	return 0;
}