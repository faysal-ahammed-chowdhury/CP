#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n = 2;
  vector<vector<int>> v(2, vector<int>(2));
  v[0][0] = 2;
  v[0][1] = 3;
  v[1][0] = 1;
  v[1][1] = 4;
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << v[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}