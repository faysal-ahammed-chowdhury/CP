#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9, inf = 2e9;
int n, m;
int a[N], b[N], pref[N], suff[N];

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];

  for (int i = 0; i <= m + 2; i++) pref[i] = suff[i] = inf;

  for (int i = 1, j = 1; i <= n and j <= m; i++) {
    if (a[i] >= b[j]) {
      pref[j] = i;
      j++;
    }
  }

  for (int i = n, j = m; i >= 1 and j >= 1; i--) {
    if (a[i] >= b[j]) {
      suff[j] = i;
      j--;
    }
  }

  if (pref[m] < inf) {
    cout << 0 << '\n';
    return;
  }

  int ans = inf;
  for (int i = 1; i <= m; i++) {
    int l = 0;
    if (i - 1 >= 1) l = pref[i - 1];
    int r = n + 5;
    if (i + 1 <= m) r = suff[i + 1];
    // cout << i << ' ' << l << ' ' << r << '\n';
    if (l < r and max(l, r) < inf) ans = min(ans, b[i]);
  }
  cout << (ans >= inf ? -1 : ans) << '\n';
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