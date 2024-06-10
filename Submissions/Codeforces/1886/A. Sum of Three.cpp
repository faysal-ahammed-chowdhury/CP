#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  if (n <= 6 or n == 9) {
    cout << "No\n";
    return;
  }
  n--;
  for (int i = 2; i <= n; i++) {
    int another = n - i;
    if (i % 3 != 0 and another % 3 != 0 and another != i) {
      if (i != 1 and another != 1) {
        cout << "Yes\n";
        cout << 1 << ' ' << i << ' ' << another << '\n';
        return;
      }
    }
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