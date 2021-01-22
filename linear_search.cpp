#include <bits/stdc++.h>
using namespace std;

bool linear_search(vector<int> &a, int key)
{
   for (int i = 0; i < a.size(); i++)
   {
      if (a[i] == key)
         return true;
   }
   return false;
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

      bool find = linear_search(a, k);
      if (find)
         cout << "Present" << endl;
      else
         cout << "Not Present" << endl;
   }
   return 0;
}