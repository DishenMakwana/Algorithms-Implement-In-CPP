#include <bits/stdc++.h>
using namespace std;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define NO_OF_CHARS 256

void computeTransFun(string path, int M, int TF[][NO_OF_CHARS])
{
    int i, lps = 0, x;

    // Fill entries in first row
    for (x = 0; x < NO_OF_CHARS; x++)
        TF[0][x] = 0;
    TF[0][path[0]] = 1;

    // Fill entries in other rows
    for (i = 1; i <= M; i++)
    {
        // Copy values from row at index lps
        for (x = 0; x < NO_OF_CHARS; x++)
            TF[i][x] = TF[lps][x];

        // Update the entry corresponding to this character
        TF[i][path[i]] = i + 1;

        // Update lps for next row to be filled
        if (i < M)
            lps = TF[lps][path[i]];
    }
}

/* Prints all occurrences of pat in txt */
void search(string path, string txt)
{
    int M = path.length();
    int N = txt.length();

    int TF[M + 1][NO_OF_CHARS];

    computeTransFun(path, M, TF);

    // process text over FA.
    int i, j = 0;
    for (i = 0; i < N; i++)
    {
        j = TF[j][txt[i]];
        if (j == M)
        {
            cout << "pattern found at index " << (i - M + 1) << endl;
        }
    }
}

/* Driver code */
int main()
{
    IOS;
    string txt, path;
    cout << "Enter Text and Pattern here : " << endl;
    getline(cin, txt);
    getline(cin, path);
    //cin >> txt >> path;
    search(path, txt);
    return 0;
}

// This is code is contributed by rathbhupendra
/*
Output:
 pattern found at index 0
 pattern found at index 10
 */