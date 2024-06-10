#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char c) {
  return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u');
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = (int) s.size();
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (is_vowel(s[i - 1])) {
      ans += 1ll * i * (n - i + 1);
    }
  }
  cout << ans << '\n';

  return 0;
}