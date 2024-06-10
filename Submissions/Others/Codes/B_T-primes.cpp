#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

const ll N = 1000006;

int isPrime[N];

void sieve()
{
    for (int i = 2; i < N; i++)
        isPrime[i] = 1;

    int limit(sqrt(N + 1));
    for (int i = 2; i < limit; i++)
    {
        if (isPrime[i])
            for (int j = i + i; j < N; j += i)
            {
                isPrime[j] = false;
            }
    }
}

void solve()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    sieve();

    ll n, val;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        ll sq = sqrt(val);
        if (sq * sq == val && isPrime[sq])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
