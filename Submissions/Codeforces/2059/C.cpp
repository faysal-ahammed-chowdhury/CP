#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n; cin >> n;
  int a[n + 1][n + 1];
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
    int sum = 0;
    for (int j = n; j >= 1; j--) {
      if (a[i][j] != 1) break;
      sum++;
    }
    if (sum > 0) v.push_back(sum);
  }

  sort(v.begin(), v.end());
  // for (auto x : v) cout << x << ' '; cout << '\n';
  
  int mex = 1;
  for (int i = 0; i < v.size(); i++) {
    if (mex <= v[i]) mex++;
  }
  cout << min(n, mex) << '\n';
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