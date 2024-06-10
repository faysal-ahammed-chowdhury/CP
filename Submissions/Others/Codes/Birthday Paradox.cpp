#include <bits/stdc++.h>
using namespace std;

int cs;
void solve() {
  int n; cin >> n;
  double probability = 1.0;
  int j = n, ans = 0;
  while (1.0 - probability < 0.5) {
    probability *= ((n - ans) / (1.0 * n));
    ans++;
  }
  cout << "Case " << ++cs << ": " << --ans << '\n';
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