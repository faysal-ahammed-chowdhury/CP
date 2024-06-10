#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) {
      a[i] = i;
    }

    int ans = 0;
    do {
      int mx = 0, calc = 0;
      for(int i = 1; i <= n; i++) {
        calc += a[i] * i;
        mx = max(mx, a[i] * i);
      }
      if(calc - mx == 152) {
        for(int i = 1; i <= n; i++) {
          cout << a[i] << ' ';
        }
        cout << '\n';
      }
      ans = max(ans, calc - mx);

    } while(next_permutation(a + 1, a + 1 + n));
    cout << ans << '\n';
  }

  return 0;
}