#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  for(int i = 0; i < n; i++) {
    if(s[i] != 'W') {
      bool ok = false;
      if(i != 0 && s[i - 1] != 'W') {
        ok = true;
      }
      if(i != n - 1 && s[i + 1] != 'W') {
        ok = true;
      }
      if(!ok) {
        cout << "NO\n";
        return;
      }
    }
  }

  vector<string> v;
  string sub = "";
  for(int i = 0; i < n; i++) {
    if(s[i] == 'W' && sub != "") {
      v.push_back(sub);
      sub = "";
    }
    else if(s[i] != 'W') {
      sub += s[i];
    }
  }
  if(sub != "") {
    v.push_back(sub);
  }


  for(auto i: v) {
    map<char, int> mp;
    for(auto j: i) {
      mp[j]++;
    }
    if(mp.size() != 2) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}