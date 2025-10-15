#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  n += n;
  int ans[n];
  memset(ans, -1, sizeof ans);
  vector<int> v;
  v.push_back(1);
  for (int i = 2; i <= n; i++) {
    v.push_back(i);
    cout << "? " << v.size() << ' ';
    for (auto x : v) {
      cout << x << ' ';
    }
    cout << endl;
    int mad; cin >> mad;
    if (mad != 0) {
      v.pop_back();
      ans[i] = mad;
    }
  }

  v.clear();
  v.push_back(n);

  for (int i = n - 1; i >= 1; i--) {
    v.push_back(i);
    if (ans[i] != -1) continue;
    cout << "? " << v.size() << ' ';
    for (auto x : v) {
      cout << x << ' ';
    }
    cout << endl;
    int mad; cin >> mad;
    if (mad != 0) {
      v.pop_back();
      ans[i] = mad;
    }
  }

  cout << "! ";
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;
}

int32_t main() {

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}