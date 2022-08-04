#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> mergeSort(vector<int> avector) {

    if (avector.size()>1) {
        int mid = avector.size()/2;
        //C++ Equivalent to using Python Slices
        vector<int> lefthalf(avector.begin(),avector.begin()+mid);
        vector<int> righthalf(avector.begin()+mid,avector.begin()+avector.size());

        lefthalf = mergeSort(lefthalf);
        righthalf = mergeSort(righthalf);

        unsigned i = 0;
        unsigned j = 0;
        unsigned k = 0;
        while (i < lefthalf.size() && j < righthalf.size()) {
            if (lefthalf[i] < righthalf[j]) {
                avector[k]=lefthalf[i];
                i++;
            } else {
                avector[k] = righthalf[j];
                j++;
            }
            k++;
        }

        while (i<lefthalf.size()) {
            avector[k] = lefthalf[i];
            i++;
            k++;
        }

        while (j<righthalf.size()) {
            avector[k]=righthalf[j];
            j++;
            k++;
        }

    }


    return avector;
}
int main()
{
    int X, Y, n, i, a, b, median, result = 0;
    vector<int> x, y, tempy;
    vector<vector<int>> roads;
    cin >> X >> Y;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
        tempy.push_back(b);

    }
    for(i=0; i<X; i++)
    {
        vector<int> temp;
        temp.push_back(-1);
        roads.push_back(temp);
    }
    roads.resize(X);
    for(i=0; i<n; i++)
    {
        roads[x[i]].push_back(y[i]);
    }
    
    for(i=0; i<X; i++)
    {
        roads[i].erase(roads[i].begin());
    }

    tempy = mergeSort(tempy);
    if(n % 2 != 0)
    {
        median = tempy[(n-1)/2];

    } 
    else
    {
        median = tempy[n / 2];
    }
    result = X;
    for(i=0; i<X; i++)
    {
        if(roads[i].size() == 0)
            continue;
        int minimum = *min_element(roads[i].begin(), roads[i].end());
        int maximum = *max_element(roads[i].begin(), roads[i].end());
        if(maximum == minimum)
        {
            result += 2 * abs(minimum - median);
        }
        else if(maximum <= median)
        {
            result += 2 * (median - minimum);

        }
        else if(minimum >= median)
        {
            result += 2 * (maximum - median);
        }
        else
        {
            result += 2 * ((median - minimum) + (maximum - median));
        }
    }
    cout << result-1 << endl;
    return 0;
   
}