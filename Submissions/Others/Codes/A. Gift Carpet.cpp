#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    char a[n][m];
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    string need = "vika";
    int curr = 0;
    for(int j = 0; j < m; j++) {
      for(int i = 0; i < n; i++) {
        if(a[i][j] == need[curr]) {
          curr++;
          break;
        }
      }
    }
    if(curr >= 4) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }

  return 0;
}