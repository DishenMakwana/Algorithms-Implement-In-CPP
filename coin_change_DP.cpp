#include <bits/stdc++.h>
using namespace std;

int coin_change(vector<int> &coins, int amt)
{
   vector<int> dp(amt + 1, amt + 1);
   dp[0] = 0;

   for (int i = 1; i <= amt; i++)
   {
      for (int j = 0; j < coins.size(); j++)
      {
         if (i >= coins[j])
         {
            dp[i] = min(dp[i], dp[i - coins[j]] + 1);
         }
      }
   }
   return dp[amt] > amt ? -1 : dp[amt];
}

int32_t main()
{
   int amt = 0, n;

   cin >> n >> amt;
   vector<int> coins(n, 0);

   for (int i = 0; i < n; i++)
   {
      cin >> coins[i];
   }

   int ans = coin_change(coins, amt);
   cout << "Minimum coins = " << ans << endl;

   return 0;
}