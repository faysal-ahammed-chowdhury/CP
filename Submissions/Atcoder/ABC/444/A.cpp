#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  sort(s.begin(), s.end());

  if (s[0] == s[2]) cout << "Yes\n";
  else cout << "No\n";

  return 0;
}