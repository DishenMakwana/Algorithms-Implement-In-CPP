#include <bits/stdc++.h>
using namespace std;

void parenthesis(int i, int j, int n, int *s, char &name)
{
    if (i == j)
    {
        cout << name++;
        return;
    }
    cout << "(";

    parenthesis(i, *((s + i * n) + j), n, s, name);
    parenthesis(*((s + i * n) + j) + 1, j, n, s, name);
    cout << ")";
}

void matrix_chain_multiplication(int a[], int n)
{
    int m[n][n];
    int s[n][n];

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int val = m[i][k] + m[k + 1][j] + a[i - 1] * a[k] * a[j];
                if (val < m[i][j])
                {
                    m[i][j] = val;
                    s[i][j] = k;
                }
            }
        }
    }
    char name = 'A';
    cout << "Optimal Cost is : " << m[1][n - 1];
    cout << "\nOptimal Parenthesization is : ";
    parenthesis(1, n - 1, n, (int *)s, name);
}

int32_t main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    matrix_chain_multiplication(a, n);
    return 0;
}