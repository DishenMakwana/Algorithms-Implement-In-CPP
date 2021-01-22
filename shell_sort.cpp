#include <iostream>
using namespace std;

void shell_sort(int a[], int n)
{
  for (int gap = n / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < n; i++)
    {
      int key = a[i], j = i;

      while (j - gap >= 0 && a[j - gap] > key)
      {
        a[j] = a[j - gap];
        j -= gap;
      }
      a[j] = key;
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
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];

    shell_sort(a, n);
    for (int i = 0; i < n; i++)
      cout << a[i] << " ";
  }
  return 0;
}