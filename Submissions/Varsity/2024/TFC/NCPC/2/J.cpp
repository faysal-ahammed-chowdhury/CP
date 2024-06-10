#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char c) {
  return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'y');
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s; cin >> s;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    bool flag = is_vowel(s[i]);
    while (i <= n and is_vowel(s[i]) == flag) {
      i++;
    }
    if (i < n) {
      cnt++;
    }
  }

  cout << cnt << '\n';

  return 0;
}