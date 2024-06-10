#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  set<int> se;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      se.insert(i);
      n /= i;
      if (se.size() == 2) break;
    }
  }
  se.insert(n);
  if (se.size() == 3) {
    cout << "Yes\n";
    for (auto i: se) {
      cout << i << ' ';
    }
    cout << '\n';
  }
  else {
    cout << "No\n";
  }
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