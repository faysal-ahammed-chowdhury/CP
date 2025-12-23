#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n, x, y; cin >> n >> x >> y;
  string s; cin >> s;
  s = '.' + s;
  int p[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }

  bool has_one = false, has_zero = false;
  int a[n + 1], b[n + 1];
  int sum1 = 0, sum2 = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      has_zero = true;
      a[i] = 1;
      b[i] = 0;
    }
    else {
      has_one = true;
      b[i] = 1;
      a[i] = 0;
    }

    sum1 += a[i];
    sum2 += b[i];
  }

  int need = 0;
  for (int i = 1; i <= n; i++) {
    int here = a[i] + b[i];
    need += max(0ll, p[i] - here);
  }

  if (sum1 > x or sum2 > y) {
    cout << "NO\n";
    return;
  }

  int cur1 = x - sum1, cur2 = y - sum2;
  if (cur1 > cur2) {
    if (!has_zero) {
      cout << "NO\n";
      return;
    }
  }
  else if (cur2 > cur1) {
    if (!has_one) {
      cout << "NO\n";
      return;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      int need = max(0ll, p[i] - (a[i] + b[i]));
      a[i] += (need + 1) / 2;
      cur1 -= (need + 1) / 2;
    }
    else {
      int need = max(0ll, p[i] - (a[i] + b[i]));
      b[i] += (need + 1) / 2;
      cur2 -= (need + 1) / 2;
    }
  }

  if (cur1 < 0 or cur2 < 0) {
    cout << "NO\n";
    return;
  }

  need = 0;
  for (int i = 1; i <= n; i++) {
    int here = a[i] + b[i];
    need += max(0ll, p[i] - here);
  }

  int available = cur1 + cur2;
  if (need <= available) cout << "YES\n";
  else cout << "NO\n";

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