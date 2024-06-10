#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

// You can just output "0 0 n".

void solve()
{
    int n, idx;
    cin >> n;

    if (n == 0)
        cout << "0 0 0\n";
    else if (n == 1)
        cout << "0 0 1\n";

    else if (n == 2)
        cout << 0 << " " << 1 << " " << 1 << endl;
    else
    {
        vector<int> fib;
        fib.push_back(0);
        fib.push_back(1);

        int i = 2;
        while (true)
        {
            fib.push_back(fib[i - 1] + fib[i - 2]);
            if (fib[i] == n)
                break;
            i++;
        }
        cout << fib[i - 4] << " " << fib[i - 3] << " " << fib[i - 1] << endl;
    }
}

int main()
{
    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
