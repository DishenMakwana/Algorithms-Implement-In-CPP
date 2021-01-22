#include <bits/stdc++.h>
using namespace std;
long long steps = 0;
void towerOfHanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        steps++;
        cout << "Move disk 1 from rod " << from << " to rod " << to << endl;
        return;
    }

    towerOfHanoi(n - 1, from, aux, to);
    steps++;
    cout << "Move disk " << n << " from rod " << from << " to rod " << to << endl;
    towerOfHanoi(n - 1, aux, to, from);
}

int32_t main()
{
    int n;
    cin >> n;
    towerOfHanoi(n, '1', '2', '3');       // A - Source , C - Destination , B - Auxiliary
    cout << "Steps -> " << steps << endl; // (2^n)-1
    return 0;
}