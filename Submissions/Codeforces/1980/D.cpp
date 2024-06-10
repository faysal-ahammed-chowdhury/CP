#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> v;
  for (int i = 1; i + 1 <= n; i++) {
    v.push_back(__gcd(a[i], a[i + 1]));
  }
  int m = v.size();
  if (is_sorted(v.begin() + 1, v.end()) or is_sorted(v.begin(), v.begin() + m - 1)) {
    cout << "YES\n";
    return;
  }
  int start = -1, end = -1;
  for (int i = 1; i < m; i++) {
    if (v[i] < v[i - 1]) {
      start = i;
      end = i + 2;
      break;
    }
  }
  for (int i = start; i <= end; i++) {
    int idx1 = i - 1, idx2 = i + 1;
    int x = __gcd(a[idx1], a[idx2]);
    int old1 = v[i - 2];
    int old2 = v[i - 1];
    v[i - 2] = x;
    v[i - 1] = x;
    if (is_sorted(v.begin(), v.end())) {
      cout << "YES\n";
      return;
    }
    v[i - 2] = old1;
    v[i - 1] = old2;
  }
  cout << "NO\n";
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