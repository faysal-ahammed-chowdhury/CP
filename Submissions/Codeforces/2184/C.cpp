#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int ans = 100;

void f(int st, int en, int val, int cnt) {
  if (st > val) return;
  if (val >= st and val <= en) {
    ans = min(ans, cnt);
    return;
  }
  // cout << st << ' ' << en << '\n';
  f(st * 2 - 1, en * 2 + 1, val, cnt + 1);
}

void solve() {
  int n, k; cin >> n >> k;
  ans = 100;
  f(k, k, n, 0);
  if (ans == 100) ans = -1;
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