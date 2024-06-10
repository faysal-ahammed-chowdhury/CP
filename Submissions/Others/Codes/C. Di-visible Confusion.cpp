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
      cin >> a[i];
    }
    bool ans = true;
    for(int i = 1; i <= min(21, n); i++) {
      bool ok = false;
      for(int j = 1; j <= i; j++) {
        if(a[i] % (j + 1) != 0) {
          ok = true;
          break;
        }
      }
      if(!ok) {
        ans = false;
        break;
      }
    }
    cout << (ans ? "YES\n" : "NO\n");
  }

  return 0;
}