#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll x; cin >> x;
  map<ll, int> pf;
  ll tmp = x;
  for (int i = 2; 1ll * i * i <= x; i++) {
    while (tmp % i == 0) {
      pf[i]++;
      tmp /= i;
    }
  }
  if (tmp > 1) pf[tmp]++;

  vector<ll> v;
  for (auto [p, pw] : pf) {
    v.push_back(pow(p, pw));
  }
  int n = v.size();

  ll ans = 1e18;
  for (int mask = 0; mask < (1 << n); mask++) {
    ll first = 1, second = 1;
    for (int i = 0; i < n; i++) {
      if (CHECK(mask, i)) {
        first *= v[i];
      }
      else {
        second *= v[i];
      }
    }
    ans = min(ans, max(first, second));
  }
  cout << x / ans << ' ' << ans << '\n';

  return 0;
}