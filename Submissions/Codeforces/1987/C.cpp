#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n; cin >> n;
  int a[n + 2];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
 
  int ans = 0;
  for (int i = n; i >= 1; i--) {
    if (a[i] > ans) {
      ans = a[i];
    }
    else ans++;
  }
  cout << ans << '\n';
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