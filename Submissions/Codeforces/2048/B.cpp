#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  set<int> se;
  for (int i = 1; i <= n; i++) {
    se.insert(i);
  }
  int ans[n + 1];
  memset(ans, -1, sizeof ans);

  int i = 1, cnt = 1;;
  while (i <= n) {
    for (int j = 1; j < k and i <= n; j++, i++) {}
    if (i > n) break;
    ans[i++] = cnt;
    se.erase(cnt);
    cnt++;
  }

  for (int i = 1; i <= n; i++) {
    if (ans[i] == -1) {
      ans[i] = *se.begin();
      se.erase(se.begin());
      // cout << se.size() << '\n';
    }
    cout << ans[i] << ' ';
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