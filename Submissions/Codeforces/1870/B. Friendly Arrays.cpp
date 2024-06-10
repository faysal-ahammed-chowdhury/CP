#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

void solve() {
  int n, m; cin >> n >> m;
  int a[n], b[m];
  int ans1 = 0, ans2 = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    ans1 ^= a[i];
  }
  int on = 0;
  for(int i = 0; i < m; i++) {
    cin >> b[i];
    on |= b[i];
  }

  for(int i = 0; i < n; i++) {
    ans2 ^= a[i] | on;
  }

  cout << min(ans1, ans2) << ' ' << max(ans1, ans2) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}