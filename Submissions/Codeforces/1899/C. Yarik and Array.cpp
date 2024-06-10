#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e18;

void solve() {
  int n; cin >> n;
  int a[n + 1], arr[n + 1];
  memset(arr, 0, sizeof arr);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    arr[i] = abs(a[i]) % 2;
  }

  vector<pair<int, int>> v;
  int start = 1;
  for (int i = 1; i <= n; i++) {
    if (i == n) {
      v.push_back({start, i});
      continue;
    }
    if (arr[i] == arr[i + 1]) {
      v.push_back({start, i});
      start = i + 1;
    }
  }

  int final = -inf;
  for (auto [x, y] : v) {
    vector<int> v;
    v.push_back(0);
    for (int i = x; i <= y; i++) {
      v.push_back(a[i]);
    }
    int sz = v.size();
    for (int i = 1; i < sz; i++) {
      v[i] += v[i - 1];
    }
    int low = 0;
    int ans = -inf;
    for (int i = 1; i < sz; i++) {
      ans = max(ans, v[i] - low);
      low = min(low, v[i]);
    }
    final = max(final, ans);
  }
  cout << final << '\n';
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