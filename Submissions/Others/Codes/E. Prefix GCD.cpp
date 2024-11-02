#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int n, a[N];

void solve() {
  cin >> n;
  int gc = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    gc = __gcd(gc, a[i]);
  }
  for (int i = 1; i <= n; i++) {
    a[i] /= gc;
  }
  long long ans = 0;
  int cur = 0, cnt = 0;
  while (true) {
    ++cnt;
    int mn = 1e9;
    for (int i = 1; i <= n; i++) {
      mn = min(mn, __gcd(cur, a[i]));
    }
    cur = mn;
    ans += cur;
    if (cur == 1) {
      ans += n - cnt;
      break;
    }
  }
  ans *= gc;
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