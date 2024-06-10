#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  map<string, int> mp;
  mp["AE"] = 1;
  mp["EA"] = 1;
  mp["AB"] = 1;
  mp["BA"] = 1;
  mp["AD"] = 2;
  mp["DA"] = 2;
  mp["AC"] = 2;
  mp["CA"] = 2;

  mp["BC"] = 1;
  mp["CB"] = 1;
  mp["BD"] = 2;
  mp["DB"] = 2;
  mp["BE"] = 2;
  mp["EB"] = 2;

  mp["CD"] = 1;
  mp["DC"] = 1;
  mp["CE"] = 2;
  mp["EC"] = 2;

  mp["DE"] = 1;
  mp["ED"] = 1;

  string s, t; cin >> s >> t;
  if (mp[s] == mp[t]) {
    cout << "Yes\n";
  }
  else {
    cout << "No\n";
  }
  

  return 0;
}