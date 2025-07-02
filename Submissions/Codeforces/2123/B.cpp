#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, j, k; cin >> n >> j >> k;
  int a[n + 1];
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }

  if (a[j] == mx or k >= 2) {
    cout << "YES\n";
    return;
  } 

  cout << "NO\n";
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