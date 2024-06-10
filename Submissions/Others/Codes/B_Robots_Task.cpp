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
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int move = 0, curr = 0;

    for(int i = 0; i < n; i++)
    {
    	int got = 0;
    	if(i % 2 == 1)
    	{
    		for(int j = n-1; j >= 0; j--)
	    	{
	    		if(arr[j] != -1 && arr[j] <= curr)
	    		{
	    			arr[j] = -1;
	    			got++;
	    			curr++;
	    		}
	    	}
    	}
    	else 
    	{
    		for(int j = 0; j < n; j++)
	    	{
	    		if(arr[j] != -1 && arr[j] <= curr)
	    		{
	    			arr[j] = -1;
	    			got++;
	    			curr++;
	    		}
	    	}
    	}

    	if(!got) break;
    	else if(i != 0) move++;
    }


    cout << move << '\n';
    
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