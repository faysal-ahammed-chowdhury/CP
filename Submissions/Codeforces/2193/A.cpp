#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, s, x; cin >> n >> s >> x;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    int tmp; cin >> tmp;
    sum += tmp;
  }

  int need = s - sum;
  if (need >= 0 and need % x == 0) cout << "YES\n";
  else cout << "NO\n";
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