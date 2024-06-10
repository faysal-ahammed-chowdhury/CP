#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n; cin >> n;
    unordered_map<int ,int> mp;
    for (int i = 0; i < n; i++)
    {
    	int val;
    	cin >> val;
    	mp[val]++;
    }

    double cnt = 0;

    for (auto i : mp) 
    {
    	cnt += (i.second / 2) / 2.0;
    }

    cout << int(cnt) << '\n';
    
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