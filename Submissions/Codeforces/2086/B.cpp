#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
int n, k; ll x;


void solve() {
  cin >> n >> k >> x;
  int a[n + 1];
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  ll cnt = (x / sum);
  ll rem = x % sum;

  if (rem == 0) {
    ll ans = (1ll * n * k) - (1ll * n * cnt) + 1;
    cout << max(0ll, ans) << '\n';
    return;
  }

  sum = 0;
  int idx = -1;
  for (int i = n; i >= 1; i--) {
    sum += a[i];
    if (sum >= rem) {
      idx = i;
      break;
    }
  }

  if (idx == -1) {
    cout << 0 << '\n';
  }

  ll ans = (1ll * n * (k - cnt - 1)) + idx;
  cout << max(0ll, ans) << '\n';
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