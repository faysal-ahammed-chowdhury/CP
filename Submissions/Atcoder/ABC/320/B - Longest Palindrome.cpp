#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = (int)s.size();

  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
      int tmp_i = i, tmp_j = j;
      bool ok = true;
      while(tmp_i <= tmp_j) {
        if(s[tmp_i] != s[tmp_j]) {
          ok = false;
          break;
        }
        tmp_i++, tmp_j--;
      }
      if(ok) {
        ans = max(ans, j - i + 1);
      }
    }
  }
  cout << ans << '\n';

  return 0;
}