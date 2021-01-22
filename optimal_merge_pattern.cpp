#include <bits/stdc++.h>
using namespace std;
#define int long long int

int minComputation(int size, int files[])
{

	priority_queue<int, vector<int>,
				   greater<int>>
		pq;

	for (int i = 0; i < size; i++)
	{
		pq.push(files[i]);
	}

	int count = 0;

	while (pq.size() > 1)
	{
		int first_smallest = pq.top();
		pq.pop();
		int second_smallest = pq.top();
		pq.pop();

		int temp = first_smallest + second_smallest;

		count += temp;

		// Add back to priority queue
		pq.push(temp);
	}
	return count;
}

int32_t main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << "Minimum Computations -> "
		 << minComputation(n, a);

	return 0;
}