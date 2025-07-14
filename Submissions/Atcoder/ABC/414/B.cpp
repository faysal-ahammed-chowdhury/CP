#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s = "";
  bool ok = true;
  while (n--) {
    char c; int len; cin >> c >> len;
    if (len <= 100) {
      for (int i = 1; i <= len; i++) {
        s += c;
      }
    }
    else {
      ok = false;
    }
  }


  if (ok) {
    if (s.size() <= 100) cout << s << '\n';
    else cout << "Too Long\n";
  }
  else cout << "Too Long\n";

  return 0;
}