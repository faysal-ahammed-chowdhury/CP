#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  int a[n + 1][m + 1];
  int pref[n + 1][m + 1];
  int one = 0;
  memset(pref, 0, sizeof pref);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      one += a[i][j] == 1;
      pref[i][j] = pref[i][j - 1] + a[i][j];
    }
  }

  int need = one / 2;
  int j = 1;
  vector<char> ans;
  for (int i = 1; i <= n; i++) {
    while (j <= m and pref[i][m] - pref[i][j - 1] > need) {
      ans.push_back('R');
      j++;
    }
    // cout << i << ' ' << j - 1 << ' ' << need << ' ' << pref[i][m] - pref[i][j - 1] << '\n';
    need -= pref[i][m] - pref[i][j - 1];
    ans.push_back('D');
  }

  while (j <= m) {
    ans.push_back('R');
    j++;
  }

  assert(ans.size() == (n + m));
  cout << (1ll * (one / 2) * (one - (one / 2))) << '\n';
  for (auto c : ans) cout << c; cout << '\n';
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