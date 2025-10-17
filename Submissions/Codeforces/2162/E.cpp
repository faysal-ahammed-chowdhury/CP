#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1];
  set<int> se;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    se.insert(i);
  }

  for (int i = 1; i <= n; i++) {
    se.erase(a[i]);
  }

  vector<int> v;
  for (auto x : se) {
    v.push_back(x);
  }

  se.clear();
  vector<int> v2;
  for (int i = n; i >= 1; i--) {
    if (se.find(a[i]) == se.end()) {
      se.insert(a[i]);
      v2.push_back(a[i]);
    }
    if (v2.size() == 3) break;
  }

  reverse(v2.begin(), v2.end());
  for (auto x : v2) {
    v.push_back(x);
  }

  int j = 0;
  for (int i = 1; i <= k; i++) {
    cout << v[j] << ' ';
    j++;
    if (j == v.size()) j = 0;
  }
  cout << '\n';
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