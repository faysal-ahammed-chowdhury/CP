#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, m, k; cin >> n >> m >> k;
  int per = (n + m - 1) / m;
  int baki = n - per;

  if (baki <= k) cout << "NO\n";
  else cout << "YES\n";
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