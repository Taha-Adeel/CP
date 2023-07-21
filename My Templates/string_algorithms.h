#include <string>
#include <vector>
#include <map>

using namespace std;
using vi = vector<int>;

/* String Searching Algorithms */

// Knuth-Morris-Pratt Algorithm. 
// Returns pi_s s.t pi_s[i] = largest k < i s.t s[0...(k-1)] == s[(i-(k-1))...i]
vi kmp_algo(string& s) {
	int n = s.size();
	vi pi_s(n, 0);
	for(int i = 1, j = 0; i < n; i++) {
		while(j > 0 && s[j] != s[i])
			j = pi_s[j - 1];

		if(s[i] == s[j]) j++;
		pi_s[i] = j;
	}
	return pi_s;
}

// Returns z s.t z[i] = largest  k < n s.t s[0...(k-1)] == s[(i)...(i+(k-1))]
vi z_function(string& s) {
	int n = s.size();
	vi z(n, 0);
	for(int i = 1, l = 0, r = 0; i < n; ++i){
		if(i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while(i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if(i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}

vi z_function_trivial(string& s) {
	int n = s.size();
	vi z(n, 0);
	for(int i = 1; i < n; ++i)
		while(i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
	return z;
}


class TrieNode{
public:
	TrieNode* parent = nullptr;
	map<char, TrieNode*> children;
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
			if(curr->children.count(c)==0){
				curr->children[c] = new TrieNode(c);
				curr->children[c]->parent = curr;
			}
			curr = curr->children[c];
			curr->freq++;
		}
	}

	bool remove(string s){
		TrieNode* curr = root;
		
		for(auto& c: s){
			if(curr->children.count(c)==0) return false;
			curr = curr->children[c];
		}

		TrieNode* parent = curr->parent;
		while(curr != nullptr){
			curr->freq--;
			if(curr->freq == 0){
				parent->children.erase(curr->c);
				delete curr;
			}
			curr = parent;
			if(curr != nullptr) parent = curr->parent;
		}
		return true;
	}
};
