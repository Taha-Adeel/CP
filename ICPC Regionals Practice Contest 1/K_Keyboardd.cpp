#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    string s, t;
    getline(cin, s);
    getline(cin, t);
    vector<char> sticky;
    int flag;
    for(int i=0, j=0; i<s.size(); i++, j++)
    {
        flag = 0;
        if(s[i] != s[i+1] && t[j] == t[j+1])
        {
            j++;
            for(int k=0; k<sticky.size(); k++)
            {
                if(sticky[k] == s[i])
                {
                    flag = 1;
                }
            }
            if(flag == 0)
            {
                sticky.push_back(s[i]);
            }
        }
    }
    for(int i=0; i<sticky.size(); i++)
    {
        cout << sticky.at(i);
    }
    return 0;
}