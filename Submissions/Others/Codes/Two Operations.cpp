#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int freq[26];
  memset(freq, 0, sizeof(freq));
  for (auto c : s) {
    freq[c - 'a']++;
  }

  for (int i = 0; i < 25; i++) {
    freq[i + 1] += freq[i] / 2;
    freq[i] %= 2;
  }

  for (int i = 25; i >= 0; i--) {
    for (int j = 1; j <= freq[i]; j++) {
      cout << char(i + 'a');
    }
  }
  cout << '\n';

  return 0;
}