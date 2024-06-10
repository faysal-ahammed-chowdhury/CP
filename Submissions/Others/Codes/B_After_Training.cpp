#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n, m; cin >> n >> m;

	unordered_map<int,int> mp;

	int mid = (m+1) / 2;
	int i = mid - 1; 
	int j = mid + 1;
	int last = 0;
	mp[++last] = mid;
	
	if(m % 2 == 1)
	{
		while(i > 0 || j <= m)
		{
			if(i > 0)
			{
				mp[++last] = i;
				i--;
			}
			if(j <= m)
			{
				mp[++last] = j;
				j++;
			}
		}
	}
	else 
	{
		while(i > 0 || j <= m)
		{
			if(j <= m)
			{
				mp[++last] = j;
				j++;
			}
			if(i > 0)
			{
				mp[++last] = i;
				i--;
			}
		}
	}


    for(int i = 1; i <= n; i++)
    {
    	int num = i % m;
    	if (num == 0) num = m;
    	cout << mp[num] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    ll test=1;
	//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}