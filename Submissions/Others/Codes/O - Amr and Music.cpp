#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  pair<int, int> a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a + 1, a + n + 1);

  vector<int> ans;
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    if (tot + a[i].first > k) break;
    tot += a[i].first;
    ans.push_back(a[i].second);
  }

  cout << ans.size() << '\n';
  for (auto x : ans) {
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}