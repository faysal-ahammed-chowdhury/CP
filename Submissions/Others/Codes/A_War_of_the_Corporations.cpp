#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string s1, s2; cin >> s1 >> s2;

    int cnt = 0;

    int lim = s1.length() - s2.length() + 1;
    for (int i = 0; i < lim; i++)
    {
        if (s1[i] == s2[0])
        {
            string s3 = s1.substr(i, s2.length());
            if (s3 == s2)
            {
                s1[i + s2.length() - 1] = '#';
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
    
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test = 1;
    //cin >> test;
    while(test--)
    {
        solve();
    }
    return 0;
}