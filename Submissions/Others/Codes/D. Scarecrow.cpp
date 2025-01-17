#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, k, l; cin >> n >> k >> l;
  k *= 2, l *= 2;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] *= 2;
  }
  int time = a[1], me = k;
  for (int i = 2; i <= n; i++) {
    if (me >= l) break;
    if (a[i] >= me) {
      int cur = a[i] - time;
      cur = max(cur, me);
      if (cur > me) {
        int d = cur - me;
        int here = (d + 1) / 2;
        time += here;
        me += here;
        me += k;
      }
      else if (cur == me) me += k;
    }
    else {
      int cur = a[i] + time;
      cur = min(cur, me);
      if (me - cur <= k) me = cur + k;
    }
  }
  int x = 0;
  if (me < l) x = (l - me);
  cout << time + x << '\n';
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