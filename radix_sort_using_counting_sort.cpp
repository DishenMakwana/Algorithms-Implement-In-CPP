#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int> &a, int exp)
{
    vector<int> idx(10, 0), tmp(a.size());

    for (int i = 0; i < a.size(); i++)
        idx[(a[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        idx[i] += idx[i - 1];

    for (int i = a.size() - 1; i >= 0; i--)
    {
        tmp[idx[(a[i] / exp) % 10] - 1] = a[i];
        idx[(a[i] / exp) % 10]--;
    }

    for (int i = 0; i < a.size(); i++)
        a[i] = tmp[i];

    // check how sorting working
    /*for(int i=0; i < a.size(); i++) 
            cout << a[i] << " ";
    cout << endl;*/
}

//only for natural numbers(except negative)
void radix_sort(vector<int> &a)
{
    int max = *max_element(a.begin(), a.end());
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort(a, exp);
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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        radix_sort(a);
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }
    return 0;
}