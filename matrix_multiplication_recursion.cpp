#include <bits/stdc++.h>
using namespace std;

void multiply(int m1, int n1, int a[10][10], int m2, int n2, int b[10][10], int c[10][10])
{
    static int i = 0, j = 0, k = 0;

    if (i >= m1)
    {
        return;
    }
    else if (i < m1)
    {
        if (j < n2)
        {
            if (k < n1)
            {
                c[i][j] += a[i][k] * b[k][j];
                k++;
                multiply(m1, n1, a, m2, n2, b, c);
            }
            k = 0;
            j++;
            multiply(m1, n1, a, m2, n2, b, c);
        }
        j = 0;
        i++;
        multiply(m1, n1, a, m2, n2, b, c);
    }
}

void display(int m1, int n2, int c[10][10])
{
    int i, j;

    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}

int32_t main()
{
    int a[10][10] = {0}, b[10][10] = {0}, c[10][10] = {0};
    int row1, col1, row2, col2, i, j, k;

    cout << "Enter rows and columns for Matrix A respectively: " << endl;
    cin >> row1 >> col1;

    cout << "Enter rows and columns for Matrix B respectively: " << endl;
    cin >> row2 >> col2;

    if (col1 != row2)
    {
        cout << "Matrix multiplication not possible." << endl;
    }
    else
    {
        cout << "Enter elements in Matrix A:" << endl;
        for (i = 0; i < row1; i++)
            for (j = 0; j < col1; j++)
                cin >> a[i][j];

        cout << "\nEnter elements in Matrix B:" << endl;
        for (i = 0; i < row2; i++)
            for (j = 0; j < col2; j++)
                cin >> b[i][j];

        multiply(row1, col1, a, row2, col2, b, c);
    }
    cout << "On matrix multiplication of A and B the result is:" << endl;
    display(row1, col2, c);
}
