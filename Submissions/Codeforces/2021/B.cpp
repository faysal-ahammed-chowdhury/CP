#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x; cin >> n >> x;
  set<int> missing_numbers;
  for (int i = 0; i <= n + 5; i++) {
    missing_numbers.insert(i);
  }

  int cnt[n + 5];
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= n; i++) {
    int val; cin >> val;
    if (val <= n) {
      cnt[val]++;
      missing_numbers.erase(val);
    }
  }

  for (int i = 0; i <= n; i++) {
    // cout << i << ' ' << cnt[i] << '\n';
    if (cnt[i] > 1) {
      if (i + x <= n) {
        cnt[i + x] += cnt[i] - 1;
        cnt[i] = 1;
        missing_numbers.erase(i + x);
      }
    }
  }

  cout << *missing_numbers.begin() << '\n';
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