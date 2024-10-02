#include <bits/stdc++.h>
using namespace std;

int get_price(string &s) {
  int ans = 0;
  for (auto c : s) {
    ans += (c - 'a' + 1);
  }
  return ans;
}

int get_price(char c) {
  return (c - 'a' + 1);
}

void solve() {
  string s; cin >> s;
  int p; cin >> p;
  int n = s.size();
  int price = get_price(s);
  string t = s;
  sort(t.begin(), t.end());
  map<char, int> mp;
  while (price > p) {
    char c = t.back(); t.pop_back();
    mp[c]++;
    price -= get_price(c);
  }
  for (auto c : s) {
    if (mp[c] > 0) {
      mp[c]--;
      continue;
    }
    cout << c;
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}