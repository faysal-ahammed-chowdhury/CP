#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int x1 = 12, x2 = 20, x3 = 30;
  set<int> se;
  se.insert(6);
  se.insert(10);
  se.insert(15);
  while (se.size() < n) {
    if (x1 < 10000) {
      se.insert(x1);
      x1 += 6;
    }
    if (x2 < 10000 and se.size() < n) {
      se.insert(x2);
      x2 += 10;
    }
    if (x3 < 10000 and se.size() < n) {
      se.insert(x3);
      x3 += 15;
    }
    if (x1 >= 10000 and x2 >= 10000 and x3 >= 10000) break;
  }
  // cout << se.size() << '\n';
  for (auto x : se) {
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}