#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int n, a[N];
ll k, pref[N];

bool ok(ll op) {
  ll ans = 0;
  for (int i = 0; i <= min(op, 1ll * n - 1); i++) {
    ll sum = pref[n];
    ll rem = op - i;
    ll x = a[1] - rem;
    sum -= rem;
    sum -= pref[n] - pref[n - i];
    sum += 1ll * i * x;
    if (sum <= k) return true;
  }
  return false;
}

void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  sort(a + 1, a + n + 1);

  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + a[i];
  }

  ll l = 0, r = 1e15, ans = -1;
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else l = mid + 1;
  }
  cout << ans << '\n';
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