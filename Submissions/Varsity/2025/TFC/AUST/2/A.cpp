#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  if (s == "N") cout << "S\n";
  if (s == "S") cout << "N\n";
  if (s == "E") cout << "W\n";
  if (s == "W") cout << "E\n";
  if (s == "SE") cout << "NW\n";
  if (s == "NW") cout << "SE\n";
  if (s == "SW") cout << "NE\n";
  if (s == "NE") cout << "SW\n";

  return 0;
}