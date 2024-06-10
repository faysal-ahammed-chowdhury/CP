#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n; cin >> n;
    ll arr[] = {9, 90, 900, 9000, 90000, 900000, 9000000, 90000000, 900000000, 9000000000};
    unsigned ll ans = 0;
    int i = 1;
    while (n > 0) {
    	ll mn = n < arr[i - 1] ? n : arr[i - 1];
    	ans += (mn * i);
    	n = n - arr[i - 1];
    	i++;
    }

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