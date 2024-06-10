#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x; cin >> n >> x;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int mx_dis = 0;
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    mx_dis = max(mx_dis, abs(a[i] - a[i - 1]));
  }
  mx_dis = max(mx_dis, abs(x - a[n]) * 2);
  cout << mx_dis << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}