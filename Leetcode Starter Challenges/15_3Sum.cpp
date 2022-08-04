#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k){
        vector<pair<int,int>> rows(mat.size());
        for(int i = 0; i < mat.size(); i++){
            int j = 0;
            while(mat[i][j] && j < mat[i].size())
                j++;
            rows[i] = {j, i};
        }
        sort(rows.begin(), rows.end());
        vector<int> ans(k);
        for(int i = 0; i < k; i++){
            ans[i] = rows[i].second;
        }
        return ans;
    }
};

int main(){
	Solution sol;

	vector<vector<int>> input = {{1,0,0,0},{1,1,1,1},{1,0,0,0},{1,0,0,0}};
    sol.kWeakestRows(input, 2);
}