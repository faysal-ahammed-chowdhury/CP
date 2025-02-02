#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long n; 
  while (cin >> n) {
    string ans = "none";
    for (int i = 1; ; i++) {
      if (n == 1) break;
      if (i & 1) {
        n = (n + 8) / 9;
        ans = "Stan wins.";
      }
      else {
        n = (n + 1) / 2;
        ans = "Ollie wins.";
      }
    }
    cout << ans << '\n';
  }

  return 0;
}