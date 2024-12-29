#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int n, psum[N], psum2[N];

bool ok(int cnt0) {
  for (int i = 1; i <= n; i++) {
    int here = psum[i - 1] + cnt0;
    int idx = upper_bound(psum + 1, psum + n + 1, here) - psum;
    int cur = psum2[i - 1] + psum2[n] - psum2[idx - 1];
    // cout << i << ' ' << idx - 1 << ' ' << cur << '\n';
    if (cur <= cnt0) {
      // cout << i << ' ' << idx << ' ' << here << '\n';
      return true;
    }
  }
  return false;
}

void solve() {
  string s; cin >> s;
  n = s.size();
  s = '.' + s;
  for (int i = 1; i <= n; i++) {
    psum[i] = psum[i - 1] + (s[i] == '0');
    psum2[i] = psum2[i - 1] + (s[i] == '1');
    // cout << psum[i] << ' ';
  }
  // cout << '\n';
  // auto it = lower_bound(psum + 1, psum + n + 1, 6) - psum;
  // cout << psum[n] << ' ' << it << '\n';

  int l = 0, r = n, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else l = mid + 1;
  }
  cout << ans << '\n';

  // cout << ok(1) << '\n';
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