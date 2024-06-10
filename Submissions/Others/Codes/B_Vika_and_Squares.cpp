#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n; cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    }

    ll mn = arr[0];
    for (int i = 0; i < n; i++) {
    	mn = min(mn, arr[i]);
    }

    ll ans = (mn * n);

    int first = 0;
    for (int i = 0; i < n; i++) {
    	if (arr[i] > mn) first++;
    	else break;
    }

    int last = 0;
    for (int i = n - 1; i >= 0; i--) {
    	if (arr[i] > mn) last++;
    	else break;
    }

    int mn2 = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
    	if (arr[i] == mn) {
    		cnt = 0;
    		continue;
    	}

    	cnt++;
    	mn2 = max(mn2, cnt);
    }

    ans += max(first + last, mn2);

    cout << ans << '\n';
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test = 1;
    //cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}