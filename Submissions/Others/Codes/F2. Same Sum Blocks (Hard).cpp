#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1505;
int n, a[N], pref[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }

  map<int, vector<pair<int, int>>> mp;

  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      int sum = pref[j] - pref[i - 1];
      mp[sum].push_back({j, i});
    }
  }

  int ans = 0, sum = 0;
  for (auto &[_, v] : mp) {
    sort(v.begin(), v.end());
    int last = 0, cnt = 0;
    for (auto [j, i] : v) {
      if (i > last) {
        last = j;
        cnt++;
      }
    }

    if (cnt >= ans) {
      ans = cnt;
      sum = _;
    }
  }

  cout << ans << '\n';
  int last = 0, cnt = 0;
  for (auto [j, i] : mp[sum]) {
    if (i > last) {
      cout << i << ' ' << j << '\n';
      last = j;
      cnt++;
    }
  }

  return 0;
}