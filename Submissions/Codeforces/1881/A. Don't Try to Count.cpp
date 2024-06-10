#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  string s1, s2; cin >> s1 >> s2;
  int op = 0;
  int old_n = n;
  while (n <= old_n * 5 or n <= m * 5) {
    if (s1.find(s2) != string::npos) {
      cout << op << '\n';
      return;
    }
    s1 += s1;
    op++;
    n *= 2;
  }
  if (s1.find(s2) != string::npos) {
    cout << op << '\n';
    return;
  }
  cout << -1 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}