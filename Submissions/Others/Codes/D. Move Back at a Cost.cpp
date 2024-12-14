#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9, inf = 2e9;
int n, a[N];

void solve() {
  cin >> n;
  priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pq.push({a[i], i, 0});
  }

  int mn = inf, mx_idx = 0;
  while (!pq.empty()) {
    auto [x, i, state] = pq.top(); pq.pop();
    if (i > mx_idx and x <= mn) {
      cout << x << ' ';
      mx_idx = i;
    }
    else if (state == 0) {
      pq.push({x + 1, i, 1});
      mn = min(mn, x + 1);
    }
    else {
      cout << x << ' ';
    }
  }
  cout << '\n';
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