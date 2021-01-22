#include <bits/stdc++.h>
using namespace std;

int pow(int a, int n)
{
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return pow(a * a, n / 2);
  else
    return a * pow(a * a, n / 2);
}

int32_t main()
{
  int a, n;
  cin >> a >> n;
  cout << pow(a, n) << endl;
  return 0;
}