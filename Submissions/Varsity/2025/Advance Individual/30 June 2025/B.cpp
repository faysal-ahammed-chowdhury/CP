#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ok(int len, int k, vector<int> &v) {
  for (int i = 0; i + len - 1 < v.size(); i++) {
    int x = v[i], y = v[i + len - 1];
    int num = y - x + 1;
    if (num - len <= k) return true;
  }
  return false;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k; cin >> n >> m >> k;
  map<int, vector<int>> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp[x].push_back(i);
  }

  int ans = 0;
  for (auto [_, v] : mp) {
    int l = 1, r = v.size(), tmp = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (ok(mid, k, v)) {
        tmp = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    ans = max(ans, tmp);
  }

  cout << ans << '\n';

  return 0;
}