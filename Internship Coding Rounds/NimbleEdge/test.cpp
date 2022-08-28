#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int getPosSums(const vector<int>& a){
    int n = a.size();    
    int ans = 0, cur_sum = 0;
    for(int i = 0; i < n; i++){
        cur_sum += a[i];
        if(cur_sum > 0) 
            ans++;
    }
    
    return ans;
}

int maxPosPrefixes(vector<int> a) {
    int n = a.size();
    sort(a.rbegin(), a.rend());
    vector<string> words;
	map<string, long long> freqs;
	for(auto& s: words)
		freqs[s]++;

	long long ans = 0;
	for(auto& f: freqs)
		ans += (f.second * (f.second - 1))/2;
		
    return ans;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    int result = maxPosPrefixes(arr);

    fout << result << "\n";

    fout.close();

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
