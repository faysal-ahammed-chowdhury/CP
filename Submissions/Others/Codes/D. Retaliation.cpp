#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 2e9;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  int diff = inf;
  bool no = false;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i > 1) {
      if (i == 2) {
        diff = a[i] - a[i - 1];
        continue;
      }
      if (diff != a[i] - a[i - 1]) {
        no = true;
      }
    }
  }

  if (no) {
    cout << "NO\n";
    return;
  }

  if (diff == 0 and a[1] == 0) {
    cout << "YES\n";
    return;
  }

  if (diff < 0) reverse(a + 1, a + n + 1);
  diff = abs(diff);

  int extra = a[1] - diff;

  if (extra >= 0 and extra % (n + 1) == 0) cout << "YES\n";
  else cout << "NO\n";
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