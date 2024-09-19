#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    ll i = 1;
    while (t--)
    {
        ll A, B, L;
        cin >> A >> B >> L;
        ll X = A*B / gcd(A, B);
        if (L % X != 0) cout << "Case " << i++ << ": impossible" << '\n';
        else
        {
            ll C = L / X;
            ll g = gcd(C, X);
            while (g != 1)
            {
                C *= g;
                X /= g;
                g = gcd(C, X);
            }

            cout << "Case " << i++ << ": " << C << '\n';
        }
    }
}