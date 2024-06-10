#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  map<char, int> first, second, third;
  for(int i = 0; i < n; i += 3) {
    first[s[i]]++;
    if(i + 1 < n) second[s[i + 1]]++;
    if(i + 2 < n) third[s[i + 2]]++;
  }

  map<string, int> mp;
  mp["RGB"] = first['R'] + second['G'] + third['B'];
  mp["RBG"] = first['R'] + second['B'] + third['G'];
  mp["GBR"] = first['G'] + second['B'] + third['R'];
  mp["GRB"] = first['G'] + second['R'] + third['B'];
  mp["BRG"] = first['B'] + second['R'] + third['G'];
  mp["BGR"] = first['B'] + second['G'] + third['R'];

  string str; int mx = 0;
  for(auto i: mp) {
    if(i.second > mx) {
      mx = i.second;
      str = i.first;
    }
  }

  int ans = 0;
  for(int i = 0; i < n; i += 3) {
    string sub = s.substr(i, min(n - i, 3));
    int x = sub.length();
    for(int j = 0; j < x; j++) {
      if(sub[j] != str[j]) ++ans;
    }
  }
  
  cout << ans << '\n';
  int x = n / 3;
  int y = n % 3;
  for(int i = 0; i < x; i++) {
    cout << str;
  }
  for(int i = 0; i < y; i++) {
    cout << str[i];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  while(t--) {
    solve();
  }

  return 0;
}