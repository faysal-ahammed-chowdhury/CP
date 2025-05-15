#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct CRT {
  ll egcd(ll a, ll b, ll& x, ll& y) {
    if (!b) {y = 0, x = 1; return a;}
    ll g = egcd(b, a % b, y, x);
    y -= ((a / b) * x);
    return g;
  }
  ll inv(ll a, ll m) {
    ll x, y;
    egcd(a, m, x, y);
    return (x + m) % m;
  }
  ll chinese_remainder(vector <ll> ar, vector <ll> mods) {
    ll x, y, res = 0, M = 1;
    for (int i = 0; i < ar.size(); i++) M *= mods[i];
    for (int i = 0; i < ar.size(); i++) {
      x = M / mods[i], y = inv(x, mods[i]);
      res = (res + (((x * ar[i]) % M) * y)) % M;
    }
    return res;
  }
} crt;

int cs;
void solve() {
  int n; cin >> n;
  vector<ll> rems, mods;
  for (int i = 1; i <= n; i++) {
    int p, r; cin >> p >> r;
    rems.push_back(r);
    mods.push_back(p);
  }

  ll ans = crt.chinese_remainder(rems, mods);
  cout << "Case " << ++cs << ": ";
  bool ok = true;
  for (int i = 0; i < n; i++) {
    ok &= ans % mods[i] == rems[i];
  }
  if (ok) cout << ans << '\n';
  else cout << "Impossible\n";
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