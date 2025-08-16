#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  if (s == "red") cout << "SSS\n";
  else if (s == "blue") cout << "FFF\n";
  else if (s == "green") cout << "MMM\n";
  else cout << "Unknown\n";
  
  return 0;
}