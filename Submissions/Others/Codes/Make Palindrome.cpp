#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = s.size();

  map<char, int> freq;
  for (auto c : s) {
    freq[c]++;
  }

  vector<char> v;
  for (auto [c, cnt] : freq) {
    if (cnt & 1) {
      v.push_back(c);
    }
  }

  int sz = v.size();
  for (int i = 0, j = sz - 1; i < j; i++, j--) {
    freq[v[i]]++;
    freq[v[j]]--;
  }

  string ans = "";
  for (auto [c, cnt] : freq) {
    int x = cnt / 2;
    for (int i = 1; i <= x; i++) {
      ans += c;
    }
  }

  string rev = ans;
  reverse(rev.begin(), rev.end());
  if (sz & 1) {
    ans += v[sz / 2];
  }
  ans += rev;
  cout << ans << '\n';

  return 0;
}