#include <bits/stdc++.h>
using namespace std;

#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define endl "\n"
#define int long long int

// using dynamic programming
int binomial_coefficient(int n, int k)
{
  int C[n + 1][k + 1]; //dp array

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= min(i, k); j++)
    {
      if (j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
  return C[n][k];

  // pascal's triangle
  /*for(int i=0;i<=n;i++)
    {
       for(int j=0;j<=i;j++)
       {
          cout << C[i][j] << " ";
       }
       cout << endl;
    }*/
}

int32_t main()
{
  IOS;
  int n, k;
  cin >> n >> k;
  int ans = binomial_coefficient(n, k);
  cout << ans << endl;
  return 0;
}

//  using recursion
/*
int binomial_coefficient(int n,int k) 
{
  if(k==0 || k==n)
    return 1;
    
  return binomial_coefficient(n-1,k-1)+binomial_coefficient(n-1,k);
}

int32_t main()
{
  IOS;
  int n,k;
  cin >> n >> k;
  int ans=binomial_coefficient(n,k);
  cout << ans << endl;
  return 0;
}*/
