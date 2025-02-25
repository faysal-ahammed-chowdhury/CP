#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int cnt1 = 0, cnt2 = 0;
  for (auto c : s) {
    if (c == '-') cnt1++;
    else cnt2++;
  }

  int cnt3 = cnt1 / 2;
  cnt1 -= cnt3;

  cout << (1ll * cnt1 * cnt2 * cnt3) << '\n';
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