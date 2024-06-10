#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  set<int> se;
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    se.insert(x);
  }
  se.erase(--se.end());
  cout << *(--se.end()) << '\n';

  return 0;
}