#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n; cin >> n;
  ll a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  if (n > 100) {
    cout << "NO\n";
    return;
  }

  map<ll, ll> mp;
  for (int i = 1; i <= n; i++) {
    ll o = 0;
    for (int j = i; j <= n; j++) {
      o |= a[j];
      mp[o]++;
      if (mp[o] > 1) {
        cout << "NO\n";
        return;
      }
    }
  }

  cout << "YES\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}