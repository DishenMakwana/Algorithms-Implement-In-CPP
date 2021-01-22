#include <bits/stdc++.h>
using namespace std;
#define IOS                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);

void compute_LPS_arr(string path, int m, int lps[])
{
	int len = 0;
	lps[0] = 0;

	int i = 1;
	while (i < m)
	{
		if (path[i] == path[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			if (len != 0)
			{
				len = lps[len - 1];
			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
	/*cout << "Pia Array : ";
	for(int i=0;i<m;i++)
	{
		cout << lps[i] << " ";
	}
	cout<<endl;*/
}

void KMP_search(string txt, string path)
{
	int m = path.length();
	int n = txt.length();

	int lps[m]; // pai array
	compute_LPS_arr(path, m, lps);

	int i = 0; // index for txt[]
	int j = 0; // index for pat[]

	while (i < n)
	{
		if (path[j] == txt[i])
		{
			j++;
			i++;
		}

		if (j == m)
		{
			printf("Found pattern at index %d ", i - j);
			j = lps[j - 1];
		}
		// mismatch after j matches
		else if (i < n && path[j] != txt[i])
		{
			// Do not match lps[0..lps[j-1]] characters,
			// they will match anyway
			if (j != 0)
				j = lps[j - 1];
			else
				i++;
		}
	}
}

int32_t main()
{
	IOS;
	string txt, path;
	cout << "Enter Text and Pattern here : " << endl;
	getline(cin, txt);
	getline(cin, path);
	//cin >> txt >> path;
	KMP_search(txt, path);
	return 0;
}

/*
ABABDABACDABABCABAB 
ABABCABAB
Ans : Found pattern at index 10
*/
