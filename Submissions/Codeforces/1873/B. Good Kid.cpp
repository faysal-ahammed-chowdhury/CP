#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

void solve() {
  int n; cin >> n;
  int a[n];
  int mn = 100;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    mn = min(mn, a[i]);
  }
  for(int i = 0; i < n; i++) {
    if(a[i] == mn) {
      a[i]++;
      break;
    }
  }

  int ans = 1;
  for(int i = 0; i < n; i++) {
    ans *= a[i];
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}