#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9, inf = 1e9, K = 20;
int n, a[N], pref[N], pref_min[N], suff_max[N];

int f(int med) {
  pref_min[0] = 0;
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + (a[i] < med ? -1 : 1);
    pref_min[i] = min(pref_min[i - 1], pref[i]);
  }
  suff_max[n] = pref[n];
  for (int i = n - 1; i >= 1; i--) {
    suff_max[i] = max(suff_max[i + 1], pref[i]);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int mn = pref_min[i - 1];
    int mx = suff_max[i];
    if (mn <= mx) ans = max(ans, med - a[i]);
  }

  return ans;
}

void solve() {
  cin >> n;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }

  int ans = 0;
  for (int i = 1; i <= 100; i++) {
    ans = max(ans, f(i));
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