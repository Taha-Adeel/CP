#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getNumberOfDays' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY debts as parameter.
 */
 
#define MxN 100001
#define k 22

int sparse_table[MxN][k];
int lg[MxN];

void init_sparsetable(vector<int>& a){
    int n = a.size();
    for(int i = 0; i < n; i++)
        sparse_table[i][0] = a[i];
    
    for(int j = 1; j < lg[n] + 1; j++)
        for(int i = 0; i + (1<<j) <= n; i++)
            sparse_table[i][j] = min(sparse_table[i][j-1], sparse_table[i + (1<<(j-1))][j-1]);
}

int get_min(int l, int r){
    int j = lg[r - l + 1];
    int mn = min(sparse_table[1][j], sparse_table[r - (1<<j) + 1][j]);
    
    return mn;
}

int getNumberOfDays(vector<int> debts) {
    int n = debts.size();
	// for(int i = 0; i < )
    
    // Precompute log values;
    lg[1] = 0;
    for(int i = 2; i <= n; i++)
        lg[i] = lg[i/2] + 1;
    
    init_sparsetable(debts);
    
    int ans = 0;
    int cur_i = 0;
    while(cur_i < n){
        int l = cur_i+1, r = n-1;
        while(l < r){
            int m = (l+r)/2;
            if(get_min(l, m) <= debts[cur_i])
                r = m;
            else if(get_min(m+1, r) <= debts[cur_i])
                l = m+1;
            else
                l = n;
        }
        ans = max(ans, l - cur_i - 1);
        cur_i = l;
    }
    
    return ans;
}

int main()
{
    string debts_count_temp;
    getline(cin, debts_count_temp);

    int debts_count = stoi(ltrim(rtrim(debts_count_temp)));

    vector<int> debts(debts_count);

    for (int i = 0; i < debts_count; i++) {
        cin >> debts[i];
    }

    int result = getNumberOfDays(debts);

    cout << result << "\n";


    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
