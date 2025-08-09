#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n, k; cin >> n >> k;
  pair<int, int> a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].second;
    if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
    ans += a[i].second - a[i].first;

    // cout << a[i].first << ' ' << a[i].second << '\n';
  }

  sort(a + 1, a + n + 1);

  int extra = 2e9, mx = -2e9;
  for (int i = 1; i <= n; i++) {
    if (mx >= a[i].first) {
      extra = 0;
    }
    else {
      extra = min(extra, a[i].first - mx);
    }
    mx = max(mx, a[i].second);
  }

  // cout << extra << '\n';
  assert(extra >= 0);

  ans += extra * 2;
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