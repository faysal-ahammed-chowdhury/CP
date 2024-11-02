#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int n, a[N];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int start = 0, end = 0;
  vector<pair<int, int>> v;
  for (int i = 1; i <= n; i++) {
    if (a[i] > a[i - 1]) {
      if (start != 0) v.push_back(make_pair(start, end));
      start = a[i];
      end = a[i];
    }
    else {
      end = a[i];
    }
  }
  if (start != 0) v.push_back(make_pair(start, end));
  int ans = 0, mx = 0;
  set<int> se;
  for (auto [x, y] : v) {
    if (y > mx) {
      se.insert(x);
    }
    else {
      int max_here = -1;
      vector<int> vec;
      auto itt = se.upper_bound(y);
      for (auto it = itt; it != se.end(); it++) {
        int val = *it;
        max_here = max(max_here, val);
        vec.push_back(val);
      }
      for (auto val : vec) {
        se.erase(val);
      }
      if (max_here != -1) {
        max_here = max(max_here, x);
        se.insert(max_here);
      }
    }
    mx = max(mx, x);
  }
  cout << se.size() << '\n';
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