#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  pair<int, int> a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].second;
  }
  sort(a + 1, a + n + 1);
  int calorie = a[k].first;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    if (a[i].first <= calorie) {
      v.push_back(a[i].second);
    }
  }
  sort(v.rbegin(), v.rend());
  long long happiness = 0;
  for (int i = 0; i < k; i++) {
    happiness += v[i];
  }
  cout << calorie << ' ' << happiness << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("icecream.in", "r", stdin);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}