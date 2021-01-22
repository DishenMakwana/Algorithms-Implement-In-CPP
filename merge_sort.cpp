#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = a[l + i];

    for (int j = 0; j < n2; j++)
        right[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = right[j];
        j++;
        k++;
    }

    /*for(int l=0;l<sizeof(a);l++)
    {
       cout << a[l] << " ";
    }
    cout << endl;*/
}

void merge_sort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);

        merge(a, l, m, r);
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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        merge_sort(a, 0, n);
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }
    return 0;
}