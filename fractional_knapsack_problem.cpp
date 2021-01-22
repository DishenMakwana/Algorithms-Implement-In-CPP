#include <bits/stdc++.h>
using namespace std;

double fractional_knapsack(int W, int w[], int v[], int n)
{
    double ratio[n];
    for (int i = 0; i < n; i++)
    {
        ratio[i] = (double)v[i] / w[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                double temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                int tmp = w[j];
                w[j] = w[i];
                w[i] = tmp;

                tmp = v[j];
                v[j] = v[i];
                v[i] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << "  " << w[i] << " : " << ratio[i] << endl;
    }

    int curWeight = 0;
    double finalvalue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (curWeight + w[i] <= W)
        {
            curWeight += w[i];
            finalvalue += v[i];
        }
        else
        {
            int remain = W - curWeight;
            finalvalue += v[i] * ((double)remain / w[i]);
            break;
        }
    }
    return finalvalue;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, W;
        cin >> n >> W;
        int w[n], v[n];
        for (int i = 0; i < n; i++)
            cin >> w[i];
        for (int i = 0; i < n; i++)
            cin >> v[i];
        double cost = fractional_knapsack(W, w, v, n);
        cout << "Total cost = " << cost << endl;
    }
}