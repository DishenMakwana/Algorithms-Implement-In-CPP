#include <bits/stdc++.h>
#define pb push_back
#define int long long int
using namespace std;

int32_t main()
{
    vector<int> a(5, 0);
    int i = 0;
    while (i < a.size() and a[i] == 1)
    {
        a[i] = 0;
        i++;

        // for(int i=0;i<a.size();i++)
        // {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
    }
    if (i < a.size())
    {
        a[i] = 1;
    }

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}