#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int a, b, q, lc, x; 

int __lcm(int a, int b) {
  return (1ll * a * b) / __gcd(a, b);
}

ll get(ll n) {
  ll ans = 1ll * (n / lc) * x;
  ll rem = n % lc;
  rem = max(rem, 1ll * max(a, b) - 1);
  ans += rem - max(a, b) + 1;
  // cout << n << ' ' << rem << '\n';
  return ans;
}

void solve() {
  cin >> a >> b >> q;
  lc = __lcm(a, b);
  x = lc - max(a, b);
  while (q--) {
    ll l, r; cin >> l >> r;
    ll cur = get(r) - get(l - 1);
    cout << cur << ' ';
  }
  cout << '\n';
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