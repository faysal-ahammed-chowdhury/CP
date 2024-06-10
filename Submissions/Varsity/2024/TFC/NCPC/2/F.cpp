#include <bits/stdc++.h>
using namespace std;

int str_to_int(string s) {
  int ans = 0;
  for (auto c : s) {
    ans = ans * 10 + (c - '0');
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int now = 1;
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    string s; cin >> s;
    if (s == "mumble") {
      now++;
      continue;
    }
    int x = str_to_int(s);
    if (x != now) ok = false;
    now++;
  }

  if (ok) {
    cout << "makes sense\n";
  }
  else {
    cout << "something is fishy\n";
  }

  return 0;
}