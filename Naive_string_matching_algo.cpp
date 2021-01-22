#include <bits/stdc++.h>
using namespace std;

void search(string path, string txt)
{
    int m = path.length();
    int n = txt.length();

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (txt[i + j] != path[j])
            {
                break;
            }
        }
        if (j == m)
        {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main()
{
    string txt, path;
    cin >> txt >> path;
    search(path, txt);
    return 0;
}

/*
AABAACAADAABAAABAA AABA

Ans : 
Pattern found at index 0
Pattern found at index 9
Pattern found at index 13
*/