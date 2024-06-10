#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    char a, b;
    int freq[26];
    for (int i = 0; i < 26; i++)
    {
        freq[i] = i + 'a';
    }

    while (m--)
    {
        cin >> a >> b;
        for (int i = 0; i < 26; i++)
        {
            if (char(freq[i]) == a)
                freq[i] = b;
            else if (char(freq[i]) == b)
                freq[i] = a;
        }
    }

    for (auto i : s)
    {
        cout << char(freq[i - 'a']);
    }
    cout << endl;
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
