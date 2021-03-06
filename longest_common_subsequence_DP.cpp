#include <bits/stdc++.h>
using namespace std;

void lcs(string x, string y, int m, int n)
{
  int dp[m + 1][n + 1];

  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (i == 0 || j == 0)
      {
        dp[i][j] = 0;
      }
      else if (x[i - 1] == y[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  string s = "";
  int i = m, j = n;

  while (i > 0 && j > 0)
  {
    if (x[i - 1] == y[j - 1])
    {
      s += x[i - 1];
      i--;
      j--;
    }
    else if (dp[i - 1][j] > dp[i][j - 1])
    {
      i--;
    }
    else
    {
      j--;
    }
  }
  reverse(s.begin(), s.end());
  cout << "LCS of " << x << " and " << y << " is : " << s;
}

int32_t main()
{
  string x, y;
  cin >> x >> y;
  /* 
  char X[] = "ABCBDAB"; //row
  char Y[] = "BDCABA";  //column
  */
  int m = x.length();
  int n = y.length();
  lcs(x, y, m, n);
  return 0;
}

/*
  BDCABA
  ABCBDAB
  Ans = BCBA
*/
/* 
  GCGCAATG
  GCCCTAGCG
  Ans = GCCTG
*/