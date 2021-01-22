#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int a[], int n, int b[])
{
  for (int i = 0; i < n; i++)
  {
    int sp = 0;
    for (int j = 0; j < n - i - 1; j++)
    {
      if (a[j] > a[j + 1])
      {
        swap(a[j], a[j + 1]);
        swap(b[j], b[j + 1]);
        sp++;
      }
    }
    if (sp == 0)
    {
      break;
    }
  }

  for (int i = 0; i < n; i++)
    cout << b[i] << " "; //starting time
  cout << endl;
  for (int i = 0; i < n; i++)
    cout << a[i] << " "; //ending time
  cout << endl;
}

void activity_selector(int s[], int f[], int n)
{
  int i = 0, j;

  printf("Following activities are selected \n");

  cout << i + 1 << " ";

  for (j = 1; j < n; j++)
  {
    if (s[j] >= f[i])
    {
      cout << j + 1 << " ";
      i = j;
    }
  }
}

int32_t main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int s[n], f[n];
    for (int i = 0; i < n; i++)
      cin >> s[i];
    for (int i = 0; i < n; i++)
      cin >> f[i];
    bubble_sort(f, n, s);
    activity_selector(s, f, n);
  }
  return 0;
}