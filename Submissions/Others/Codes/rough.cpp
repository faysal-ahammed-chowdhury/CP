#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = s.size();
  int mx = 0;
  sort(s.begin(), s.end());
  do {
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (s[i] == s[j]) ans++;
        else {
          for (int k = i; k < j; k++) {
            if (s[k] != s[k + 1] and (s[k] != s[i] or s[k + 1] != s[j])) {
              ans++;
              break;
            }
          }
        }
      }
    }
    cout << ans << ' ' << s << '\n';
    mx = max(ans, mx);
  } while (next_permutation(s.begin(), s.end()));
  cout << mx << '\n';

  return 0;
}