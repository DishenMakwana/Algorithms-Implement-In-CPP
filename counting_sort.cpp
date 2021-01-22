#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int> &a)
{
    int max = *max_element(a.begin(), a.end());
    int min = *min_element(a.begin(), a.end());
    int range = max - min + 1;

    vector<int> idx(range), tmp(a.size());

    for (int i = 0; i < a.size(); i++)
        idx[a[i] - min]++;

    for (int i = 1; i < idx.size(); i++)
        idx[i] += idx[i - 1];

    for (int i = a.size() - 1; i >= 0; i--)
    {
        tmp[idx[a[i] - min] - 1] = a[i];
        idx[a[i] - min]--;
    }

    for (int i = 0; i < a.size(); i++)
        a[i] = tmp[i];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        counting_sort(a);
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }
    return 0;
}