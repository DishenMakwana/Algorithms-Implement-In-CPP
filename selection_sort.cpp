#include <iostream>
using namespace std;

void selection_sort(int a[], int n)
{
    int i, j, minIdx = 0;
    for (i = 0; i < n - 1; i++)
    {
        minIdx = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIdx])
            {
                minIdx = j;
            }
        }
        swap(a[i], a[minIdx]);
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

        selection_sort(a, n);
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }
    return 0;
}