#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
   int i = low - 1;
   int pivot = arr[high];

   for (int j = low; j < high; j++)
   {
      if (arr[j] < pivot)
      {
         i++;
         swap(arr[i], arr[j]);
      }
   }
   swap(arr[i + 1], arr[high]);
   return i + 1;
}

void quick_sort(int arr[], int low, int high)
{
   if (low < high)
   {
      int p = partition(arr, low, high);

      quick_sort(arr, low, p - 1);
      quick_sort(arr, p + 1, high);
   }

   // for (int i = 0; i < 9; i++)
   //    cout << arr[i] << " ";
   // cout << endl;
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

      quick_sort(a, 0, n - 1);
      for (int i = 0; i < n; i++)
         cout << a[i] << " ";
   }
   return 0;
}