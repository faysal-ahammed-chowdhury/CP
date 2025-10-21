#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int inf = 1e17;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
    if (i % 2 == 0) a[i] = mx;
  }

  int ans = 0;
  for (int i = 1; i <= n; i += 2) {
    int l = (i - 1 >= 1 ? a[i - 1] : inf);
    int r = (i + 1 <= n ? a[i + 1] : inf);
    int mn = min(l, r);
    if (a[i] >= mn) {
      ans += a[i] - mn + 1;
    } 
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