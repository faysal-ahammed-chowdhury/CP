#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, _; cin >> n >> m >> _;
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    q.push(x);
  }
  int a[m + 1];
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  set<int> se;
  for (int i = 1; i <= m; i++) {
    if (se.find(a[i]) != se.end()) continue;
    int top = q.front();
    q.pop();
    if (a[i] == top) {
      se.insert(top);
    }
    else {
      cout << "TIDAK\n";
      return;
    }
  }
  cout << "YA\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}