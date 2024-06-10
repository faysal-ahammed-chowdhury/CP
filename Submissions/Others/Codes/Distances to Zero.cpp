#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int ans[n + 1];
  for (int i = 1; i <= n; i++) {
    ans[i] = inf;
  }

  int last_idx = inf;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) last_idx = i;
    if (last_idx != inf) {
      ans[i] = min(ans[i], i - last_idx);
    }
  }

  last_idx = inf;
  for (int i = n; i >= 1; i--) {
    if (a[i] == 0) last_idx = i;
    if (last_idx != inf) {
      ans[i] = min(ans[i], last_idx - i);
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';

  return 0;
}