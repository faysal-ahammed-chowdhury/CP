#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char c) {
  return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u');
}

void solve() {
  int n; cin >> n;
  string s; cin >> s;

  int last_c = true;
  set<int> se;
  for (int i = 1; i < n; i++) {
    if (is_vowel(s[i])) se.insert(i);
    else if (!is_vowel(s[i]) and last_c) {
      se.erase(--se.end());
      se.insert(i - 1);
    }
    last_c = !is_vowel(s[i]);
  }

  if (!is_vowel(s[n - 1])) se.erase(--se.end());

  for (int i = 0; i < n; i++) {
    cout << s[i];
    if (se.find(i) != se.end() and i != n - 1) cout << '.';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}