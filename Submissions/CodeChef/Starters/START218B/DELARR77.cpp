#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 105;
int n, a[N], pref[N];
pair<int, int> c[N];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> c[i].first;
    c[i].second = i;
  }
  sort(c + 1, c + n + 1);

  int ans = 0, lim = n;
  for (int i = 1; i <= n; i++) {
    auto [mn, idx] = c[i];
    if (idx > lim) continue;
    ans += mn * (pref[lim] - pref[idx - 1]);
    lim = idx - 1;
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