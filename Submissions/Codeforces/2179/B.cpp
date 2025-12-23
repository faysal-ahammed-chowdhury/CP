#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 2; i <= n; i++) {
    ans += abs(a[i] - a[i - 1]);
  }

  int cur1 = 0;
  for (int i = 3; i <= n; i++) {
    cur1 += abs(a[i] - a[i - 1]);
  }
  
  int cur2 = 0;
  for (int i = 2; i < n; i++) {
    cur2 += abs(a[i] - a[i - 1]);
  }

  int tmp = ans;
  for (int i = 2; i < n; i++) {
    int cur = tmp;
    cur -= abs(a[i] - a[i - 1]);
    cur -= abs(a[i] - a[i + 1]);
    cur += abs(a[i + 1] - a[i - 1]);
    ans = min(ans, cur);
  }

  ans = min(ans, cur1);
  ans = min(ans, cur2);

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