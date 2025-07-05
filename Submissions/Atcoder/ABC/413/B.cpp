#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  set<string> se;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j == i) continue;
      string t = s[i] + s[j];
      se.insert(t);
    }
  }

  cout << se.size() << '\n';

  return 0;
}