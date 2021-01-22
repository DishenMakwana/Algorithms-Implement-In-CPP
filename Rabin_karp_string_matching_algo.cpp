#include <bits/stdc++.h>
using namespace std;

// commented values are for all type of text
#define d 10 //256
#define q 13 //101
// q is prime number

void search(string path, string txt)
{
    int m = path.length();
    int n = txt.length();
    int i, j;
    int p_hash = 0; // hash value for pattern
    int t_hash = 0; // hash value for txt
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first
    for (i = 0; i < m; i++)
    {
        p_hash = (d * p_hash + path[i]) % q;
        t_hash = (d * t_hash + txt[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= n - m; i++)
    {
        if (p_hash == t_hash)
        {
            for (j = 0; j < m; j++)
            {
                if (txt[i + j] != path[j])
                    break;
            }
            if (j == m)
            {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Calculate hash value for next window of text: Remove leading digit, add trailing digit
        if (i < n - m)
        {
            t_hash = (d * (t_hash - txt[i] * h) + txt[i + m]) % q;

            // We might get negative value of t, converting it to positive
            if (t_hash < 0)
                t_hash = (t_hash + q);
        }
    }
}

int32_t main()
{
    string path, txt;
    //cin >> txt ;
    //cin >> path;
    getline(cin, txt);
    getline(cin, path);
    search(path, txt);
    return 0;
}

/*
AABAACAADAABAAABAA 
AABA

Ans : 
Pattern found at index 0
Pattern found at index 9
Pattern found at index 13
*/