#include <bits/stdc++.h>
using namespace std;

int cs;
void solve() {
  cout << "Case " << ++cs << ":\n";
  stack<string> back, forward;
  string cur = "http://www.lightoj.com/";
  while (true) {
    string s; cin >> s;
    if (s == "QUIT") break;
    if (s == "VISIT") {
      if (cur != "") back.push(cur);
      string page; cin >> page;
      cur = page;
      cout << cur << '\n';
      while (!forward.empty()) forward.pop();
    }
    else if (s == "BACK") {
      if (back.empty()) cout << "Ignored\n";
      else {
        forward.push(cur);
        cur = back.top();
        cout << cur << '\n';
        back.pop();
      }
    }
    else {
      if (forward.empty()) cout << "Ignored\n";
      else {
        back.push(cur);
        cur = forward.top();
        cout << cur << '\n';
        forward.pop();
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}