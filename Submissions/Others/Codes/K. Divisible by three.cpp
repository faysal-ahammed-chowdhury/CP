#include <bits/stdc++.h>
using namespace std;

void solve() {
  int m; cin >> m;
  int a[m];
  for(int i = 0; i < m; i++) {
    char c; cin >> c;
    a[i] = c - '0';
  }

  for(int i = 1; i < m; i++) {
    a[i] += a[i - 1];
  }

  map<int, int> mp;
  long long ans = 0;
  for(int i = 0; i < m; i++) {
    if(a[i] % 3 == 0) ans++;
    ans += mp[a[i] % 3];
    mp[a[i] % 3]++;
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