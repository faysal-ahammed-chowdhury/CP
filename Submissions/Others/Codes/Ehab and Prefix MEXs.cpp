#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<int> a(n), b(n);
  for (auto &x : a) cin >> x;
  for (int i = 0; i < n; i++) {
    if (a[i] > i + 1) {
      cout << -1 << '\n';
      return 0;
    }
  }
  int last = -1;
  set<int> se;
  for (int i = 0; i < n; i++) {
    if (i == 0 or a[i] == a[i - 1]) {
      if (i == 0 and a[i] == 1) b[i] = 0;
      else {
        b[i] = -1;
        se.insert(i);
      }
      last = a[i];
      continue;
    }
    b[i] = last;
    int from = last + 1, to = a[i] - 1;
    for (int x = from; x <= to; x++) {
      if (!se.empty()) {
        int first = *se.begin();
        se.erase(se.begin());
        b[first] = x;
      }
    }
    last = a[i];
  }
  for (auto x : b) cout << (x == -1 ? (int)1e6 : x) << ' '; cout << '\n';

  return 0;
}