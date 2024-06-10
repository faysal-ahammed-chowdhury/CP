#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1], b[n + 1];
  priority_queue<int> pq;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pq.push(a[i]);
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  int need = 0;
  for (int i = 1; i <= n; i++) {
    need += a[i] > b[i];
  }

  if (need == 0) {
    cout << 0 << '\n';
    return;
  }

  for (int i = 1; i <= n; i++) {
    pq.pop();
    pq.push(1);
    priority_queue<int> tmp;
    bool ok = true;
    for (int j = n; j >= 1; j--) {
      int top = pq.top();
      pq.pop();
      ok &= top <= b[j];
      tmp.push(top);
    }
    if (ok) {
      cout << i << '\n';
      return;
    }

    while (!tmp.empty()) {
      pq.push(tmp.top());
      tmp.pop();
    }
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