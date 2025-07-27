#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int l = 1, r = n;
  int cur = 0;
  while (l < r) {
    int mn = min(a[l], a[r]);
    int mx = max(a[l], a[r]);

    if (cur) {
      if (mn == a[l]) {
        cout << "LR";
      }
      else {
        cout << "RL";
      }
    }
    else {
      if (mx == a[l]) {
        cout << "LR";
      }
      else {
        cout << "RL";
      }
    }

    cur ^= 1;
    l++, r--;
  }
  if (l == r) {
    cout << "L";
  }
  cout << '\n';
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