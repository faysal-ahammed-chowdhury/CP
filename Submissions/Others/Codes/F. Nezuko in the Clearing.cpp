#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int h, d; 

ll get(int n) {
  return (1ll * n * (n + 1)) / 2;
}

bool ok(int stop) {
  int cnt = d / (stop + 1);
  int rem = d % (stop + 1);

  ll need = get(cnt) * (stop + 1);
  need += (cnt + 1) * rem;

  return need < h + stop;
}

void solve() {
  cin >> h >> d;
  int l = 0, r = d, ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }

  ans += d;

  cout << ans << '\n';
  // cout << ok(1) << '\n';
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