#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  stack<int> odd, even;
  for (int i = 1; i <= n * n; i += 2) {
    odd.push(i);
  }
  for (int i = 2; i <= n * n; i += 2) {
    even.push(i);
  }

  int a[n + 1][n + 1];
  memset(a, 0, sizeof a);
  int x = 1, lim = (n + 1) / 2;
  for (int i = 1; i <= n; i++) {
    int start = (n - x) / 2;
    for (int j = 1; j <= x; j++) {
      a[i][start + j] = 1;
    }
    if (i < lim) x += 2;
    else x -= 2;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int &x = a[i][j];
      if (x & 1) {
        x = odd.top();
        odd.pop();
      }
      else {
        x = even.top();
        even.pop();
      }
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';

  return 0;
}