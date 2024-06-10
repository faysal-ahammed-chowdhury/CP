#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k; cin >> n >> m >> k;
  int a[n + 1][m + 1];
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  priority_queue<int> pq;
  long long ans = 0;
  int op = m - k + 1;
  for(int j = m; j > 0; j--) {
    for(int i = 1; i <= n; i++) {
      pq.push(a[i][j]);
    }
    if(j <= op) {
      ans += pq.top();
      pq.pop();
    }
  }

  cout << ans << '\n';

  return 0;
}