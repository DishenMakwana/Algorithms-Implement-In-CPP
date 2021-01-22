
#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << fib(i) << " ";
    }
    cout << endl;
    return 0;
}

/*#include<bits/stdc++.h> 
using namespace std; 
  
void fibo(int n) 
{ 
    int a=0,b=1,c=0; 
    if(n==1)
    {
      cout << "0" << endl;
      return;
    }
    while(n--)
    {
       cout << c << " ";
       c = a+b;
       a=b;
       b=c;
    }
} 
  
int main() 
{ 
    int n;
    cin >> n; 
    fibo(n);
    cout << endl;
    return 0; 
}*/