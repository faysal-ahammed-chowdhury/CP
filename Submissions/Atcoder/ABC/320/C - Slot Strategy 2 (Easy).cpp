#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int inf = 1e9;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m; cin >> m;
  string s1, s2, s3; cin >> s1 >> s2 >> s3;
  s1 = 'a' + s1;
  s2 = 'a' + s2;
  s3 = 'a' + s3;
  int ans = inf;
  for(int i = 0; i <= 100; i++) {
    for(int j = 0; j <= 200; j++) {
      if(i == j) continue;
      for(int k = 0; k <= 300; k++) {
        if(j == k || i == k) continue;
        if(s1[(i % m) + 1] == s2[(j % m) + 1] && s2[(j % m) + 1] == s3[(k % m) + 1]) {
          ans = min(ans, max(i, max(j, k)));
        }
      }
    }
  }

  cout << (ans == inf ? -1 : ans) << '\n';

  return 0;
}