#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1];

  int val = 0;
  bool add = true;
  for (int i = 1; i <= k; i++) {
    if (add) {
      for (int j = i; j <= n; j += k) {
        a[j] = ++val;
      }
    }
    else {
      vector<int> v;
      for (int j = i; j <= n; j += k) {
        v.push_back(j);
      }
      reverse(v.begin(), v.end());
      for (auto x : v) {
        a[x] = ++val;
      }
    }

    add = !add;
  }

  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}