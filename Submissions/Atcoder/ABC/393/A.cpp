#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s1, s2; cin >> s1 >> s2;
  if (s1 == "sick" and s2 == "fine") {
    cout << "2\n";
  }
  else if (s1 == "fine" and s2 == "sick") {
    cout << "3\n";
  }
  else if (s1 == "fine" and s2 == "fine") {
    cout << "4\n";
  }
  else  {
    cout << "1\n";
  }

  return 0;
}