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
    pair<int,int> arr[n];
    for(int i = 0; i < n; i++) 
    {
    	int x, y; cin >> x >> y;
    	arr[i] = {x, y};
    }

    if(n == 1) 
    {
    	cout << "-1\n";
    	return;
    }

	bool isPossible = false;
	int x1 = arr[0].first, y1 = arr[0].second;
	int x2 = 1005, y2 = 1005;

	for(int i = 0; i < n; i++)
	{
		if(arr[i].first != x1)
		{
			x2 = arr[i].first;
		}
		if(arr[i].second != y1)
		{
			y2 = arr[i].second;
		}
	}

	isPossible = x2 != 1005 && y2 != 1005;

	if(!isPossible)
	{
    	cout << "-1\n";
    	return;
    }

    int xD, yD;

    xD = abs(x1 - x2);
    yD = abs(y1 - y2);

    int area = xD * yD;
    cout << area << '\n';
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