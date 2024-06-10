#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

bool is_uppercase(string s) {
  for(auto i: s) {
    if(islower(i)) return false;
  }
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  string last = s.substr(1, s.length() - 1);
  bool last_upper = is_uppercase(last);
  if((islower(s[0]) && last_upper) || is_uppercase(s)) {
    for(auto i: s) {
      if(islower(i)) {
        cout << (char)toupper(i);
      }
      else {
        cout << (char)tolower(i);
      }
    }
    cout << '\n';
  }
  else {
    cout << s << '\n';
  }
        
  return 0;
}