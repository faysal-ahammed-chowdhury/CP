#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 2; i < n; i++) {
    if (s[i] == s[i - 1] and s[i] == "sweet") {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";

  return 0;
}