#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, int wt[], int val[], int n)
{

  int dp[n + 1][W + 1];

  for (int i = 0; i < n + 1; i++)
  {
    for (int j = 0; j < W + 1; j++)
    {
      if (i == 0 || j == 0)
        dp[i][j] = 0;

      else if (wt[i - 1] <= j)
        dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);

      else
        dp[i][j] = dp[i - 1][j];
    }
  }

  /* display the dp array
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=W;j++)
    {
       cout << dp[i][j] << " ";
    }
    cout << endl;
  }*/

  cout << "Including Weights : ";

  int w = W, res = dp[n][W];

  for (int i = n; i > 0 && res > 0; i--)
  {
    if (res != dp[i - 1][w])
    {
      cout << wt[i - 1] << " ";
      res = res - val[i - 1];
      w = w - wt[i - 1];
    }
    else
      continue;
  }
  cout << endl;

  return dp[n][W];
}

int32_t main()
{
  int n, W;
  cin >> n >> W;
  int val[n] = {0}, wt[n] = {0};
  for (int i = 0; i < n; i++)
    cin >> val[i];

  for (int i = 0; i < n; i++)
    cin >> wt[i];

  int ans = knapsack(W, wt, val, n);
  cout << "cost = " << ans << endl;
  return 0;
}
/*
6 10
7 5 2 1 3 4
10 2 4 5 1 3

Ans :
Including Weights : 3 1 4 2 
cost = 14
*/