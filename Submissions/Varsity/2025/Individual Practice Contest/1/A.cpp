#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s1, s2, s3; cin >> s1 >> s2 >> s3;
  string a = s3, b = s2, c = s1;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  reverse(c.begin(), c.end());

  if (a == s1 and b == s2 and c == s3) cout << "YES\n";
  else cout << "NO\n"; 

  return 0;
}