#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      int calc = 0, mx = 0, backward = n;
      for(int j = 1; j < i; j++) {
        calc += j * j;
        mx = max(mx, j * j);
      }
      for(int j = i; j <= n; j++) {
        calc += backward * j;
        mx = max(mx, backward * j);
        backward--;
      }
      calc -= mx;
      ans = max(ans, calc);
    }
    cout << ans << '\n';
  }

  return 0;
}