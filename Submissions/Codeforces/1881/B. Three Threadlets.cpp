#include <bits/stdc++.h>
using namespace std;

bool ok(deque<int> dq) {
  int n  = (int) dq.size();
  for (int i = 1; i < n; i++) {
    if (dq[i] != dq[0]) return false;
  }
  return true;
}

void solve() {
  int a, b, c; cin >> a >> b >> c;
  deque<int> dq;
  dq.push_back(a);
  dq.push_back(b);
  dq.push_back(c);
  sort(dq.begin(), dq.end());
  for (int i = 1; i <= 3; i++) {
    if (ok(dq)) {
      cout << "Yes\n";
      return;
    }
    int last = dq.back();
    dq.pop_back();
    int first = dq.front();
    dq.push_back(first);
    dq.push_back(last - first);
    sort(dq.begin(), dq.end());
  }
  if (ok(dq)) {
    cout << "Yes\n";
    return;
  }

  cout << "No\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}