#include <bits/stdc++.h>
using namespace std;

void find_min_max(int arr[], int l, int h, int &min, int &max)
{
  if (l == h)
  {
    if (max < arr[l])
      max = arr[l];

    if (min > arr[h])
      min = arr[h];

    return;
  }

  if (h - l == 1)
  {
    if (arr[l] < arr[h])
    {
      if (min > arr[l])
        min = arr[l];

      if (max < arr[h])
        max = arr[h];
    }
    else
    {
      if (min > arr[h])
        min = arr[h];

      if (max < arr[l])
        max = arr[l];
    }
    return;
  }

  int m = (l + h) / 2;

  find_min_max(arr, l, m, min, max);
  find_min_max(arr, m + 1, h, min, max);
}

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int max = INT_MIN, min = INT_MAX;

  find_min_max(arr, 0, n - 1, min, max);

  cout << "max = " << max << "\nmin = " << min << endl;
  return 0;
}

/*#include<bits/stdc++.h> 
using namespace std; 
  
void min_max(int a[],int n)
{
   int mx=a[0],mn=a[0]; 
   for (int i=0;i<n;i++)
   {
      if(mn>a[i])
        mn=a[i]; 
      if(mx<a[i]) 
        mx=a[i]; 
   }
   cout << "max = " << mx << "\nmin = " << mn << endl;
}
  
int main() 
{ 
    int n;
    cin >> n; 
    int a[n];
    for(int i=0;i<n;i++)
    {
       cin >> a[i];
    }
    min_max(a,n);
    return 0; 
}*/