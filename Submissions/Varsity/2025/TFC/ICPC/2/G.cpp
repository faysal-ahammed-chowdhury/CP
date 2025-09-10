#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;

void solve() {
  int n, m; cin >> n >> m;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    int orr = 0;
    for (int j = 1; j <= m; j++) {
      int x; cin >> x;
      orr |= x;
    }
    v.push_back(orr);
  }

  int andd = v[0];
  for (int i = 1; i < (int)v.size(); i++) {
    andd &= v[i];
  }

  if (andd > 0) cout << "YES\n";
  else cout << "NO\n";
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