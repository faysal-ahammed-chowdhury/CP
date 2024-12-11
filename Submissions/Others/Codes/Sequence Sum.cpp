#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n, x, m; cin >> n >> x >> m;

  int tmpn = 1e5 + 10;
  int a[tmpn + 1];
  memset(a, 0, sizeof a);
  
  for (int i = 1; i <= tmpn; i++) {
    a[i] = x;
    x = (1ll * x * x) % m;
  }

  map<int, int> mp;
  int st = -1, en = -1;
  for (int i = 1; i <= tmpn; i++) {
    if (mp.find(a[i]) != mp.end()) {
      st = mp[a[i]], en = i - 1;
      break;
    }
    mp[a[i]] = i;
  }

  if (n < st) {
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += a[i];
    }
    cout << ans << '\n';
    return 0;
  }

  ll ans = 0;
  for (int i = 1; i < st; i++) {
    ans += a[i];
  }

  ll cur = 0;
  for (int i = st; i <= en; i++) {
    cur += a[i];
  }

  int len = en - st + 1;
  n = n - st + 1;

  ll times = n / len;
  ans += times * cur;
  int rem = n % len;

  int i = st;
  while (rem--) {
    ans += a[i];
    i++;
  }
  cout << ans << '\n';

  return 0;
}