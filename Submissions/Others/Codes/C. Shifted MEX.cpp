#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int cnt = 0, ans = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i] == a[i - 1]) continue;
    if (a[i] == a[i - 1] + 1) cnt++;
    else {
      ans = max(ans, cnt + 1);
      cnt = 0;
    }
  }
  ans = max(ans, cnt + 1);
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