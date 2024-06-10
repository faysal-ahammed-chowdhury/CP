#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m, a[N];

bool ok(int sz) {
  int taken = 0, cnt = 1;
  for (int i = 1; i <= n; i++) {
    if (taken + a[i] <= sz) {
      taken += a[i];
    }
    else {
      cnt++;
      taken = a[i];
    }
  }
  return cnt <= m;
}

int cs;
void solve() {
  cin >>n >> m;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  int l = mx, r = 1e9, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  cout << "Case " << ++cs << ": " << ans << '\n';
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