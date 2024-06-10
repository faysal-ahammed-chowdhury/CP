#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    string s; cin >> s;
    if(s ==  "()") {
      cout << "NO\n";
      continue;
    }

    int n = s.size();
    bool ok = false;
    for(int i = 0; i < n - 1; i++) {
      if(s[i] == '(' && s[i + 1] == '(') {
        ok = true;
        break;
      }
      if(s[i] == ')' && s[i + 1] == ')') {
        ok = true;
        break;
      }
    }

    cout << "YES\n";
    if(ok) {
      string output = "";
      for(int i = 0; i < n; i++) {
        output += '(';
        output += ')';
      }
      cout << output << '\n';
    }
    else {
      string output = "";
      for(int i = 0; i < n; i++) {
        output += '(';
      }
      for(int i = 0; i < n; i++) {
        output += ')';
      }
      cout << output << '\n';
    }
  }

  return 0;
}