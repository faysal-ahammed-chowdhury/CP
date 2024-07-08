#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 9;
int n, a[4][N];

void solve() {
  cin >> n;
  ll tot = 0;
  for (int i = 1; i <= 3; i++) {
    ll sum = 0;
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      sum += a[i][j];
    }
    tot = sum;
  }
  ll per = (tot + 2) / 3;
  vector<int> v = {1, 2, 3};
  do {
    int j = 1, last = 0;
    bool ok = true;
    pair<int, int> ans[4];
    for (auto i : v) {
      ll sum = 0;
      for (; j <= n and sum < per; j++) {
        sum += a[i][j];
      }
      ans[i] = {last + 1, j - 1};
      last = j - 1;
      ok &= sum >= per;
    }
    if (ok) {
      for (int i = 1; i <= 3; i++) {
        cout << ans[i].first << ' ' << ans[i].second << ' ';
      }
      cout << '\n';
      return;
    }
  } while (next_permutation(v.begin(), v.end()));
  cout << -1 << '\n';
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