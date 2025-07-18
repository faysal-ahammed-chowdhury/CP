#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  string s; cin >> s;
  sort(s.begin(), s.end());
  for (auto c : s) {
    cout << c << '\n';
    return;
  }
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