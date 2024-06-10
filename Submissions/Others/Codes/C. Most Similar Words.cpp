#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    string s[n];
    for(int i = 0; i < n; i++) {
      cin >> s[i];
    }
    int ans = INT_MAX;
    for(int i = 0; i < n; i++) {
      for(int j = i + 1; j < n; j++) {
        int diff = 0;
        for(int k = 0; k < m; k++) {
          diff += abs(s[j][k] - s[i][k]);
        }
        ans = min(ans, diff);
      }
    }
    cout << ans << '\n';
  }

  return 0;
}