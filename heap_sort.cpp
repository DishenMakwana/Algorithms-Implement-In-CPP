#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &a, int n, int i)
{
    int lr = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[lr])
        lr = l;

    if (r < n && a[r] > a[lr])
        lr = r;

    if (lr != i)
    {
        swap(a[i], a[lr]);
        heapify(a, n, lr);
    }
}

void built_max_heap(vector<int> &a)
{
    for (int i = a.size() / 2 - 1; i >= 0; i--)
        heapify(a, a.size(), i);
}

void heap_sort(vector<int> &a)
{
    built_max_heap(a);

    for (int i = a.size() - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
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

        heap_sort(a);
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }
    return 0;
}