#include <bits/stdc++.h>
using namespace std;

void job_scheduling(int id[], int deadline[], int profit[], int n)
{
  int result[n] = {0};
  bool slot[n] = {false};
  int total_profit = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = min(n, deadline[i]) - 1; j >= 0; j--)
    {
      if (!slot[j])
      {
        result[j] = i;
        slot[j] = true;
        total_profit += profit[i];
        break;
      }
    }
  }

  for (int i = 0; i < n; i++)
    if (slot[i])
      cout << id[result[i]] << " ";
  cout << endl
       << "Total profit = " << total_profit << endl;
}

void sort(int id[], int deadline[], int profit[], int n)
{
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = n - 1; j > n - i; j--)
    {
      if (profit[j] > profit[j - 1])
      {
        swap(profit[j], profit[j - 1]);
        swap(id[j], id[j - 1]);
        swap(deadline[j], deadline[j - 1]);
      }
    }
  }

  /*cout << "      id -> ";
    for(int i=0;i<n;i++)
      cout << id[i] << " ";
    cout << endl << "deadline -> ";
    for(int i=0;i<n;i++)
      cout << deadline[i] << " ";
    cout << endl << "  profit -> ";
    for(int i=0;i<n;i++)
      cout << profit[i] << " ";
    cout << endl;*/
}

int32_t main()
{
  int n;
  cin >> n;
  int id[n] = {0}, deadline[n] = {0}, profit[n] = {0};

  // input method 1
  for (int i = 0; i < n; i++)
  {
    int Id, Deadline, Profit;
    cin >> Id >> Deadline >> Profit;
    id[i] = Id;
    deadline[i] = Deadline;
    profit[i] = Profit;
  }

  // input method 2
  /*for(int i=0;i<n;i++)
     cin >> id[i];
   for(int i=0;i<n;i++)
     cin >> deadline[i];
   for(int i=0;i<n;i++)
     cin >> profit[i];*/

  sort(id, deadline, profit, n); // sort base on profit's descending order
  job_scheduling(id, deadline, profit, n);
  return 0;
}

/*
5
1 2 60
2 1 100
3 3 20
4 2 40
5 1 20
ans : 2 1 3
total profit = 180
*/