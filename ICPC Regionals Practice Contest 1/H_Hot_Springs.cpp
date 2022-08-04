#include<iostream>
#include<vector>

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
    int n, i, j;
    cin >> n;
    vector<int> arr(n);
    vector<int> result(n);
    for(i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    arr = mergeSort(arr);
    for(i=0, j=n-1; i<n/2; i++, j--)
    {
        result[j] = arr[n-1-i];
        j--;
        result[j] = arr[i];
    }
    if(n % 2 != 0)
    {
        result[j] = arr[i];
    }
    for(i=0; i<n; i++)
    {
        cout << result.at(i) << " ";
    }
    return 0;
}