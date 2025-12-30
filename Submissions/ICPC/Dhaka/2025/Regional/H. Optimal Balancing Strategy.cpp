#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9, MXV = 1e6 + 9;
const ll inf = 1e18;
int spf[MXV];
int n, a[N];
pair<ll, pair<ll, ll>> costs[N];

void spf_sieve() {
  for (int i = 2; i < MXV; i++) {
    spf[i] = i;
  }
  for (int i = 2; i < MXV; i++) {
    if (spf[i] == i) {
      for (int j = i; j < MXV; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}

void solve() {
  int cnt1, cnt2; cin >> n >> cnt1 >> cnt2;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ll cost1 = 0, cost2 = 0;
    int x = a[i];
    while (x > 1) {
      int p = spf[x], ex = 0;
      while (x % p == 0) {
        ex++;
        x /= p;
      }
      if (p == 2) cost1 += 1ll * p * ex;
      else cost2 += 1ll * p * ex;
    }
    costs[i] = {cost1 - cost2, {cost1, cost2}};
  }

  sort(costs + 1, costs + n + 1);

  ll ans = 0;
  for (int i = 1; i <= cnt2; i++) {
    ans += costs[i].second.first;
  }
  int st = n - cnt1 + 1;
  for (int i = st; i <= n; i++) {
    ans += costs[i].second.second;
  }
  for (int i = cnt2 + 1; i < st; i++) {
    ans += min(costs[i].second.first, costs[i].second.second);
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}