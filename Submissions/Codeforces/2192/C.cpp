#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9;
int n, h, k, a[N];
int pref[N];
int suff_mx[N];

void solve() {
  cin >> n >> h >> k;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    pref[i] = pref[i - 1] + a[i];
  }

  suff_mx[n + 1] = 0;
  for (int i = n; i >= 1; i--) {
    suff_mx[i] = max(suff_mx[i + 1], a[i]);
  }

  int need = h / sum;
  int ans = need * n;
  if (need > 0) {
    ans += (need - 1) * k;
    if (h % sum) ans += k;
  }

  h -= need * sum;

  if (h == 0) {
    cout << ans << '\n';
    return;
  }

  int mn = 2e9;
  for (int i = 1; i <= n; i++) {
    mn = min(mn, a[i]);
    int x = max(pref[i], pref[i] - mn + suff_mx[i + 1]);
    if (x >= h) {
      cout << ans + i << '\n';
      return;
    }
  }

  assert(false);
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