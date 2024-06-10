#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 105;
int g[N][N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 1; i <= n; i++) {
    int u, k; cin >> u >> k;
    for(int j = 1; j <= k; j++) {
      int v; cin >> v;
      g[u][v] = 1;
    }
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cout << g[i][j];
      if(j != n) cout << ' ';
    }
    cout << "\n";
  }

  return 0;
}