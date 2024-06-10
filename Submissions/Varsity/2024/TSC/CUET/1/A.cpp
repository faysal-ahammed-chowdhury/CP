#include <bits/stdc++.h>
using namespace std;

#define int long long

int get(int x) {
  return (x * (x + 1)) / 2;
}

int32_t main() {
  freopen("adjustment.in", "r", stdin);
  freopen("adjustment.out", "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  int r_sum = 0, r_cnt = 0, c_sum = 0, c_cnt = 0;

  set<int> rows, cols;
  while (q--) {
    char c; int x; cin >> c >> x;
    if (c == 'R') {
      if (rows.find(x) != rows.end()) {
        cout << 0 << '\n';
        continue;
      }
      int ans = get(n);
      ans += x * n;
      ans -= c_sum;
      ans -= x * c_cnt;
      r_sum += x;
      r_cnt++;
      cout << ans << '\n';
      rows.insert(x);
    }
    else {
      if (cols.find(x) != cols.end()) {
        cout << 0 << '\n';
        continue;
      }
      int ans = get(n);
      ans += n * x;
      ans -= r_sum;
      ans -= x * r_cnt;
      c_sum += x;
      c_cnt++;
      cout << ans << '\n';
      cols.insert(x);
    }
  }

  return 0;
}