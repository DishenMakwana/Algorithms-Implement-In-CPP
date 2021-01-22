#include <bits/stdc++.h>
using namespace std;

void multiply(int a[10][10], int b[10][10], int c[10][10], int row1, int col2)
{
  int p1 = a[0][0] * (b[0][1] - b[1][1]);
  int p2 = (a[0][0] + a[0][1]) * b[1][1];
  int p3 = (a[1][0] + a[1][1]) * b[0][0];
  int p4 = a[1][1] * (b[1][0] - b[0][0]);
  int p5 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
  int p6 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);
  int p7 = (a[0][0] - a[1][0]) * (b[0][0] + b[0][1]);

  c[0][0] = p5 + p4 - p2 + p6;
  c[0][1] = p1 + p2;
  c[1][0] = p3 + p4;
  c[1][1] = p1 + p5 - p3 - p7;

  cout << "\n After multiplication \n";
  for (int i = 0; i < row1; i++)
  {
    cout << endl;
    for (int j = 0; j < col2; j++)
      cout << c[i][j] << " ";
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

    multiply(a, b, c, row1, col2);
  }
}
