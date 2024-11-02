#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
set<int> se;
bool dp[N][N];
vector<pair<int, int>> ans;

void f(int a, int b) {
  if (dp[a][b] == true) return;
  dp[a][b] = true;
  cout << "? " << a << ' ' << b << endl;
  int x; cin >> x;
  if (x == a or x == b) {
    ans.push_back({a, b});
    se.erase(a);
    se.erase(b);
    return;
  }
  f(a, x);
  f(x, b);
}

void solve() {
  int n; cin >> n;
  se.clear();
  ans.clear();
  memset(dp, 0, sizeof dp);
  for (int i = 1; i <= n; i++) {
    if (i > 1) se.insert(i);
  }
  while (!se.empty()) {
    f(1, *se.begin());
  }
  // assert(ans.size() == n - 1);
  cout << "! ";
  for (auto [u, v] : ans) cout << u << ' ' << v << ' ';
  cout << endl;
}

int32_t main() {

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}