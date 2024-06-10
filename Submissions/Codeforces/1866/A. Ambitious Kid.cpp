#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int ans = 1e9;
  for(int i = 1; i <= n; i++) {
    int x; cin >> x;
    ans = min(ans, abs(x - 0));
  }
  cout << ans << '\n';

  return 0;
}