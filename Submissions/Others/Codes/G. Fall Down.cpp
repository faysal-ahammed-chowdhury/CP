#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  char a[n + 1][m + 1];
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  for(int i = n; i >= 1; i--) {
    for(int j = 1; j <= m; j++) {
      if(a[i][j] != '*') continue;
      int max_k = i;
      for(int k = i + 1; k <= n; k++) {
        if(a[k][j] == '.') {
          max_k = k;
        }
        else {
          break;
        }
      }
      if(max_k != i) {
        a[max_k][j] = a[i][j];
        a[i][j] = '.';
      }
    }
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cout << a[i][j];
    }
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}