#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int odd = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    odd += x & 1;
  }

  if (!(odd & 1)) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }

  return 0;
}