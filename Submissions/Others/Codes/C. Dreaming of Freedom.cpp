#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    if(n == 1) {
      cout << "YES\n";
    }
    else {
      int val = -1;
      for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
          val = i; 
          break;
        }
      }
      if(n > 1 && val == -1) val = n;
      if(val <= m) {
        cout << "NO\n";
      }
      else {
        cout << "YES\n";
      }
    }
  }

  return 0;
}