#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

#define ll long long

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t, cs = 0; cin >> t;
  while(t--) {
    cout << "Case " << ++cs << ": ";
    ll n, k; cin >> n >> k;
    long long ans = 0, mx = 0;
    for(int i = 1; i <= n; i++) {
      int x; cin >> x;
      mx = max(mx, 1ll * x);
      ans += x;
    }
    ans += ((k - 1) * mx);
    cout << ans << '\n';
  }

  return 0;
}