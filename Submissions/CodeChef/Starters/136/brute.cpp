#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n = 8, k = 3;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    a[i] = i;
  }

  map<int, int> mp;
  set<int> se;

  do {
    int sum = 0;
    for (int j = 1; j + k - 1 <= n; j++) {
      int mx = 0;
      for (int i = j; i <= j + k - 1; i++) {
        mx = max(mx, a[i]);
      }
      sum += mx;
    }
    mp[sum]++;
    if (sum == 73) {
      for (int i = 1; i <= n; i++) {
        // cout << a[i] << ' ';
        if (a[i] == 8) {
          se.insert(i);
        }
      }
      // cout << '\n';
    }
  } while (next_permutation(a + 1, a + n + 1));

  for (auto x : se) cout << x << ' '; cout << '\n';
  for (auto [sum, cnt] : mp) {
    cout << sum << ' ' << cnt << '\n';
  }

  return 0;
}