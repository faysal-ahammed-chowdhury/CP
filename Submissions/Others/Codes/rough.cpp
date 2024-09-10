#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int a, b, q, lc, x;

int __lcm(int a, int b) {
  return (1ll * a * b) / __gcd(a, b);
}

ll get(ll r) {
  ll ans = 0;
  ll cnt = r / lc, rem = r % lc;
  ans += cnt * x;
  for (int i = r - rem + 1; i <= r; i++) {
    if (((i % a) % b) != ((i % b) % a)) ans++;
  }
  return ans;
}

void solve() {
  cin >> a >> b >> q;
  lc = __lcm(a, b);
  x = 0;
  for (int i = 1; i <= lc; i++) {
    if (((i % a) % b) != ((i % b) % a)) x++;
  }
  ll l = 1, r = 64; ;
  ll cur = get(r) - get(l - 1);
  cout << lc << ' ';
  cout << cur << ' ';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}