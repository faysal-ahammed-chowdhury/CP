#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int l = 1, r = n;
  for (int i = 1; i <= n; i++) {
    if (l > r) {
      cout << "NO\n";
      return;
    }
    if (a[l] == i) l++;
    else if (a[r] == i) r--;
    else {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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