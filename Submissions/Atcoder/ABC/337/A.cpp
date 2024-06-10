#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int t = 0, a = 0;
  for (int i = 1; i <= n; i++) {
    int x, y; cin >> x >> y;
    t += x;
    a += y;
  }

  if (a == t) {
    cout << "Draw\n";
  }
  else if (t > a) {
    cout << "Takahashi\n";
  }
  else {
    cout << "Aoki\n";
  }

  return 0;
}