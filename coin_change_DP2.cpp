// using 2D array
#include <bits/stdc++.h>
using namespace std;

int coin_change(vector<int> &coins, int amt)
{
   vector<vector<int>> dp(coins.size(), vector<int>(amt + 1, 0));

   for (int i = 0; i < coins.size(); i++)
   {
      dp[i][0] = 0;
      for (int j = 1; j <= amt; j++)
      {
         if (i == 0 && j < coins[i])
         {
            dp[i][j] = INT_MAX;
         }
         if (i == 0)
         {
            dp[i][j] = 1 + dp[0][j - coins[0]];
         }
         else if (j < coins[i])
         {
            dp[i][j] = dp[i - 1][j];
         }
         else
         {
            dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i]]);
         }
      }
   }
   /*for(int i=0;i<coins.size();i++)
   {
      for(int j=0;j<=amt;j++)
      {
         cout << dp[i][j] << " ";
      }
      cout << endl;
   }*/
   return dp[coins.size() - 1][amt];
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

// using 1D array
/*
#include <bits/stdc++.h>
using namespace std;

int coin_change(vector<int>& coins, int amt) 
{
   vector<int> dp(amt+1, amt+1);
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
   int amt=0,n;
   
   cin >> n >> amt; 
   vector<int> coins(n,0);
   
   for(int i=0;i<n;i++)
   {
     cin >> coins[i];
   }
   
   int ans=coin_change(coins,amt);
   cout << "Minimum coins = " << ans << endl;
   
   return 0;
}*/