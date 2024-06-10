#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  int col[n + 1];
  int ans[n + 1];
  col[1] = 0, ans[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (s[i - 1] > s[i]) {
      col[i] = !col[i - 1];
      ans[i] = col[i];
      char key = s[i];
      int key_col = col[i];
      int j = i - 1;
      while (j >= 1 and s[j] > key) {
        if (col[j] != key_col) {
          col[j + 1] = col[j];
          s[j + 1] = s[j];
          j--;
        }
        else {
          cout << "NO\n";
          return 0;
        }
      }
      s[j + 1] = key;
      col[j + 1] = key_col;
    }
    else {
      col[i] = col[i - 1];
      ans[i] = col[i];
    }
  }

  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    cout << ans[i];
  }
  cout << '\n';

  return 0;
}