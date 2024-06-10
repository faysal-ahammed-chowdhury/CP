#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  map<char, int> mp;
  for (int i = 1; i <= n; i++) {
    char c; cin >> c;
    mp[c]++;
  }
  int need = 0;
  for (char c = 'A'; c <= 'G'; c++) {
    int cnt = mp[c];
    if (cnt < m) {
      need += m - cnt;
    }
  }
  cout << need << '\n';
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