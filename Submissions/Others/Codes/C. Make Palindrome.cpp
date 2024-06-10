#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  map<char, int> mp;
  for (auto c : s) {
    mp[c]++;
  }
  vector<char> v;
  for (auto [c, cnt] : mp) {
    if (cnt & 1) v.push_back(c);
  }
  sort(v.begin(), v.end());
  int len = v.size();
  int x = len / 2;
  if (len & 1) {
    x++;
  }
  for (int i = x; i < len; i++) {
    mp[v[i]]--;
    mp[v[i - x]]++;
  }

  bool has_odd = false;
  char odd_char;
  if (len & 1) {
    has_odd = true;
    odd_char = v[len / 2];
  }

  string final = "";
  for (auto [c, cnt] : mp) {
    int x = cnt / 2;
    for (int i = 1; i <= x; i++) {
      final += c;
    }
  }

  string rev = "";
  int n = final.length();
  for (int i = n - 1; i >= 0; i--) {
    rev += final[i];
  }
  if (has_odd) {
    final += odd_char;
  }
  final += rev;
  cout << final << '\n';

  return 0;
}