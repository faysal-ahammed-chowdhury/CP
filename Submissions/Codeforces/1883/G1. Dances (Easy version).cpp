#include <bits/stdc++.h>
using namespace std;

const int inf = -1e9;

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n);
  deque<int> b(n);
  a[0] = 1;
  for (int i = 1; i < n; i++) {
    cin >> a[i];
  }
  for (auto &x : b) {
    cin >> x;
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int cnt = 0, i = 0;
  while (!b.empty()) {
    int x = b.front();
    b.pop_front();
    if (x > a[i]) {
      cnt++;
      i++;
    }
  }
  cout << n - cnt << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}