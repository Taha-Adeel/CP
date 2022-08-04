#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    string* arr;
    arr = new string[3*N];
    getline(cin,arr[0]);
    for(int n{0}; n<N; ++n){
        getline(cin, arr[3*n]);
        getline(cin, arr[3*n+1]);
        getline(cin, arr[3*n+2]);
    }
    unordered_map<string, int> freq;
    for(int i=0; i< 3*N; ++i){
        ++freq[arr[i]];
    }
    auto comp= [](const pair<int, int>& p1, const pair<int, int>& p2){
        if(p1.first!=p2.first)
            return p2.first<p1.first;
        else return p2.second<p1.second;
    };
    map<std::pair<int,int>, string, decltype(comp)> Freq(comp);
    for(int i=3*N-1; i>=0; --i){
        if(freq[arr[i]]!=-1){
            Freq.insert({{freq[arr[i]], i}, arr[i]});
            freq[arr[i]]=-1;
        }
    }
    map<pair<int, int>, string>::iterator it;
    int iii{0};
    for (it = Freq.begin(); iii<K && it != Freq.end(); ++it, ++iii) {
        cout << it->second << '\n';
    }
    return 0;
}