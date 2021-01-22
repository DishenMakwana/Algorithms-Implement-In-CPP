#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll multiply(ll x, ll y, ll n)
{
  if (n == 1)
    return x * y;

  n = n / 2;

  ll divider = pow(10, n);

  ll al = x / divider;
  ll ar = x % divider;
  ll bl = y / divider;
  ll br = y % divider;

  ll q = multiply(ar, br, n);
  ll r = multiply(ar + al, br + bl, n);
  ll p = multiply(al, bl, n);

  //cout << p << " " << q << " " << r << endl;

  return q + ((r - p - q) * pow(10, n)) + (p * pow(10, 2 * n));
}

int main()
{
  ll a, b, n;
  cin >> n >> a >> b;
  cout << multiply(a, b, n) << endl;
  return 0;
}
