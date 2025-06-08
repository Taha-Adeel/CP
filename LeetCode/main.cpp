#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> last;
        int n = s.size(), l = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (!last.count(s[i])) {
                last[s[i]] = -1;
            }
            if (last.count(s[i]) && last[s[i]] >= l) {
                l = last[s[i]] + 1;
            }
            last[s[i]] = i;
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        vector<int> indices_zero;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                indices_zero.push_back(i);
            }
        }

        int l = 0, r = 0, ans = 0, n = nums.size();
        while (r < indices_zero.size()) {
            if (r - l + 1 <= k) {
                ans = max(ans, indices_zero[r] - indices_zero[l] + 1);
                r++;
            } else {
                l++;
            }
        }
        return ans;
    }
};