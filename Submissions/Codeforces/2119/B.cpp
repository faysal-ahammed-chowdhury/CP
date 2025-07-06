#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n; cin >> n;
  int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  int a[n + 1], sum = 0;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    mx = max(mx, a[i]);
  }

  int tmp1 = (x1 - x2) * (x1 - x2);
  int tmp2 = (y1 - y2) * (y1 - y2);
  int tmp = tmp1 + tmp2;

  if (x1 == x2 and y1 == y2) {
    if (n == 1) {
      cout << "No\n";
      return;
    }
    if (n == 2) {
      if (a[1] == a[2]) cout << "Yes\n";
      else cout << "No\n";
      return;
    }
  }

  if (tmp == (sum * sum)) {
    cout << "Yes\n";
    return;
  }

  if (tmp >= (mx * mx)) {
    if (tmp <= (sum * sum)) cout << "Yes\n";
    else cout << "No\n";
    return;
  }
  else {
    if (tmp >= (((mx + mx) - sum) * ((mx + mx) - sum)) or ((mx + mx) - sum) < 0) cout << "Yes\n";
    else cout << "No\n";
  }
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