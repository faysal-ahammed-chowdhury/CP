#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1][n + 1];
  deque<int> dq;
  for (int i = 1; i <= n; i++) {
    dq.push_back(i);
  }
  int idx = n / 2 + 1;
  for (int j = 1; j <= n; j++) {
    a[idx][j] = dq[j - 1];
  }
  for (int i = idx - 1; i >= 1; i--) {
    int top = dq.back();
    dq.pop_back();
    dq.push_front(top);
    for (int j = 1; j <= n; j++) {
      a[i][j] = dq[j - 1];
    }
  }
  dq.clear();
  for (int i = 1; i <= n; i++) {
    dq.push_back(i);
  }
  for (int i = idx + 1; i <= n; i++) {
    int top = dq.front();
    dq.pop_front();
    dq.push_back(top);
    for (int j = 1; j <= n; j++) {
      a[i][j] = dq[j - 1];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
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