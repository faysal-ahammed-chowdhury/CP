#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1], b[n + 1];
  int nid = -1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == n) nid = i;
  }

  vector<int> v1, v2;
  map<int, int> mp;
  int half = (n / 2) + 1;
  int start = ((nid & 1) ? 3 : 2), end = ((nid & 1) ? n : n - 1);
  for (int i = start; i <= end; i += 2) {
    v1.push_back(a[i]);
  }
  for (int i = n; i >= half; i--) {
    v2.push_back(i);
  }
  sort(v1.begin(), v1.end());
  for (int i = 0; i < v1.size(); i++) {
    mp[v1[i]] = v2[i];
  }
  v1.clear(), v2.clear();
  start = ((nid & 1) ? 2 : 1), end = n;
  for (int i = start; i <= end; i += 2) {
    v1.push_back(a[i]);
  }
  for (int i = half - 1; i >= 1; i--) {
    v2.push_back(i);
  }
  sort(v1.begin(), v1.end());
  for (int i = 0; i < v1.size(); i++) {
    mp[v1[i]] = v2[i];
  }

  set<int> se;
  for (int i = 1; i <= n; i++) {
    se.insert(i);
  }

  for (int i = 1; i <= n; i++) {
    b[i] = mp[a[i]];
    se.erase(b[i]);
  }

  for (int i = 1; i <= n; i++) {
    if (b[i] == 0) b[i] = *se.begin();
    cout << b[i] << ' ';
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