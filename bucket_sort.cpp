#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<double> &a)
{
    double key = 0;
    int j;
    for (int i = 1; i < a.size(); i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void bucket_sort(vector<double> &a)
{
    vector<double> b[a.size()]; // array of vectors

    for (int i = 0; i < a.size(); i++)
    {
        int t = a.size() * a[i]; // index
        b[t].push_back(a[i]);
    }

    for (int i = 0; i < a.size(); i++)
    {
        //sort(b[i].begin(),b[i].end());
        insertion_sort(b[i]);
    }

    int k = 0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            a[k++] = b[i][j];
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<double> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        bucket_sort(a);
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }
    return 0;
}