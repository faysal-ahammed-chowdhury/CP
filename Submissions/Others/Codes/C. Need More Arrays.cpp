#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int last = a[1], cnt = 1;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == last) continue;
    if (last + 1 == a[i]) {
      last = a[i];
      cnt++;
    }
    else {
      ans += (cnt + 1) / 2;
      last = a[i];
      cnt = 1;
    }
  }

  ans += (cnt + 1) / 2;
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