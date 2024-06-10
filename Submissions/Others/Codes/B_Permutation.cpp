#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, k; cin >> n >> k;

    n *= 2;

    if(k == 0)
    {
    	for(int i = 1; i <= n; i++) cout << i << ' ';
    	cout << '\n';
    	return;
    }

    int second = 1, first = 1 + k;

    cout << first << ' ' << second << ' ';
    for(int i = 1; i <= n; i++) 
    {
    	if(i ==  first || i == second) continue;
    	cout << i << ' ';
    }
    cout << '\n';
    
}

int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int test = 1;
    //cin >> test;
    while(test--)
    {
        solve();
    }
    return 0;
}