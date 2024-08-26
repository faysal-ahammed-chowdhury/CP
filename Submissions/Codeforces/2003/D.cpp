#include <bits/stdc++.h>
using namespace std;

#define int long long

int get(int n) {
  return (n * (n + 1)) / 2;
}

void solve() {
  int n, m; cin >> n >> m;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    set<int> missing_numbers;
    for (int j = 0; j <= x + 5; j++) {
      missing_numbers.insert(j);
    }
    for (int j = 1; j <= x; j++) {
      int y; cin >> y;
      missing_numbers.erase(y);
    }
    int val = *missing_numbers.begin();
    missing_numbers.erase(missing_numbers.begin());
    mx = max(mx, *missing_numbers.begin());
  }
  if (m < mx) {
    cout << (m + 1) * mx << '\n';
  }
  else {
    int ans = mx * mx;
    ans += get(m) - get(mx - 1);
    cout << ans << '\n';
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