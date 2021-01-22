#include <bits/stdc++.h>
using namespace std;

void make_change(int n)
{
   const int c[] = {100, 25, 10, 5, 1};
   int sum = 0, i = 0, cntCoins = 0;
   while (sum != n)
   {
      if (sum + c[i] <= n)
      {
         cntCoins++;
         sum += c[i];
      }
      else
      {
         i++;
      }
   }
   cout << "Total Coins = " << cntCoins << endl;
}

int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      make_change(n);
   }
   return 0;
}