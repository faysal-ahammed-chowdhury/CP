#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  map<int, ll> mp, freq;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    freq[a[i]]++;
  }
  ll ans = 0;
  for (auto [x, cnt] : freq) {
    ll cur = (1ll * cnt * (cnt - 1)) / 2;
    mp[x] = cur;
    ans += cur;
  }
  for (int i = 1; i <= n; i++) {
    ll cur = ans - mp[a[i]];
    cur += (1ll * (freq[a[i]] - 1) * (freq[a[i]] - 2)) / 2;
    cout << cur << '\n';
  }

  return 0;
}