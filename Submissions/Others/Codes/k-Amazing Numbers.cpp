#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9, inf = 1e9;
int a[N], ans[N], n;

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  map<int, int> last, mp;
  for (int i = 1; i <= n; i++) {
    last[a[i]] = 0;
  }
  for (int i = 1; i <= n; i++) {
    mp[a[i]] = max(mp[a[i]], i - last[a[i]]);
    last[a[i]] = i;
  }

  for (int i = 1; i <= n; i++) {
    mp[a[i]] = max(mp[a[i]], (n + 1) - last[a[i]]);
    ans[i] = inf;
  }

  for (auto [x, y] : mp) {
    ans[y] = min(ans[y], x);
  }

  int mn = inf;
  for (int i = 1; i <= n; i++) {
    mn = min(mn, ans[i]);
    if (mn == inf) {
      cout << -1 << ' ';
    }
    else {
      cout << mn << ' ';
    }
  }
  cout << '\n';
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