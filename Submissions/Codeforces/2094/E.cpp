#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(ll N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(ll &N, int pos) { (N |= (1ll << pos)); }

void solve() {
  int n; cin >> n;
  int a[n + 1], on[32];
  memset(on, 0, sizeof on);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int k = 0; k < 30; k ++) {
      if (CHECK(a[i], k)) {
        on[k]++;
      }
    }
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ll here = 0;
    for (int k = 0; k < 30; k++) {
      int on_k = on[k];
      int off_k = n - on[k];
      if (CHECK(a[i], k)) {
        here += 1ll * off_k * (1ll << k);
      }
      else {
        here += 1ll * on_k * (1ll << k);
      }
    }
    ans = max(ans, here);
  }
  cout << ans << '\n';
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