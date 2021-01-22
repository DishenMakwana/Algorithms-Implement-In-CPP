#include <bits/stdc++.h>
using namespace std;

#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define endl "\n"
#define int long long int

void fibo(int n)
{
  int f[n + 2] = {0};

  f[0] = 0;
  f[1] = 1;

  if (n == 0)
  {
    return;
  }

  if (n >= 1)
  {
    cout << "0 ";
  }

  for (int i = 2; i <= n; i++)
  {
    f[i] = f[i - 1] + f[i - 2];
    cout << f[i] << " ";
  }
  //return f[n];
}

int32_t main()
{
  IOS;
  int n;
  cin >> n;
  fibo(n);
  return 0;
}