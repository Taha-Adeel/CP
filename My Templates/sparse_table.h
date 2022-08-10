#include <bits/stdc++.h>
using namespace std;

class SparseTable{
	vector<vector<int>> sparse_table;
	vector<int> lg; // Precomputed values of floor(log2(i))

public:
	SparseTable(vector<int>& arr){
		int n = arr.size();

		// Precompute log values
		lg.reserve(n + 1);
		lg[1] = 0;
		for (int i = 2; i <= n; i++)
			lg[i] = lg[i/2] + 1;

		// Initialize the sparse table
		int k = lg[n] + 1;
		sparse_table = vector<vector<int>>(n, vector<int>(k));
		for(int i = 0; i < n; i++)
			sparse_table[i][0] = arr[i];
		
		// Populate the sparse table
		for(int j = 1; j < k; j++)
			for(int i = 0; i + (1 << j) <= n; i++)
				sparse_table[i][j] = min(sparse_table[i][j-1], sparse_table[i + (1 << (j - 1))][j - 1]);
	}

	int query(int l, int r){
		int j = lg[r - l + 1];
		int value = min(sparse_table[l][j], sparse_table[r - (1 << j) + 1][j]);

		return value;
	}
};