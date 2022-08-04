#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for(int i = 0;; i++){
            char c = 'A';
            for(auto& str: strs){
                if(i >= str.length())
                    return str.substr(0, i);
                if(c == 'A')
                    c = str[i];
                if(str[i] != c)
                    return str.substr(0, i);
            }
        }
    }
};