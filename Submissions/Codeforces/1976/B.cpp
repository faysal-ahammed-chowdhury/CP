#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n; cin >> n;
  int m = n + 1;
  int a[n + 1], b[m + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  int dis = 2e9;
  for (int i = 1; i <= n; i++) {
    dis = min(dis, abs(a[i] - b[m]));
    dis = min(dis, abs(b[i] - b[m]));
  }
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    ans += abs(a[i] - b[i]);
    if (b[m] >= a[i] and b[m] <= b[i]) dis = 0;
    if (b[m] <= a[i] and b[m] >= b[i]) dis = 0;
  }
  ans += dis;
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