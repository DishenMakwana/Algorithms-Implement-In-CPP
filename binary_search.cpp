#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &a, int l, int r, int key)
{
    if (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (a[mid] == key)
            return 1;

        if (a[mid] > key)
            return binary_search(a, l, mid - 1, key);
        else
            return binary_search(a, mid + 1, r, key);
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());
        int find = binary_search(a, 0, a.size(), k);
        if (find)
            cout << "Present" << endl;
        else
            cout << "Not Present" << endl;
    }
    return 0;
}