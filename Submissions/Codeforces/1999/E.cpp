#include <bits/stdc++.h>
using namespace std;

#define int long long 

int f(int x) {
  int ans = 0;
  while (x) {
    ans++;
    x /= 3;
  }
  return ans;
}

void solve() {
  int l, r; cin >> l >> r;
  int pw = f(l);
  int ans = pw + pw;
  l++;
  int cur = 1, old = 1, need = 1;
  while (true) {
    old = cur;
    cur *= 3;
    if (cur > r) break;
    if (cur < l) {
      need++;
      continue;
    }
    old = max(old, l);
    int cnt = cur - old;
    ans += cnt * need;
    need++;
  }
  old = max(old, l);
  int cnt = r - old + 1;
  ans += cnt * need;
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