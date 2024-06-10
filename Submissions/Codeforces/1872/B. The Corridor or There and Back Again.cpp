#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int ans = 1e9;
    for(int i = 1; i <= n; i++) {
      int a, b; cin >> a >> b;
      int go = ((b - 1) / 2) + a;
      ans = min(ans, go);
    }
    cout << ans << '\n';
  }

  return 0;
}