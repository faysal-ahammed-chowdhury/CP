#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string time; cin >> time;
  int hh = stoi(time.substr(0, 2));
  int mm = stoi(time.substr(3, 2));
  int minutes; cin >> minutes;
  int hrs = (minutes / 60) % 24;
  minutes %= 60;
  hh += hrs;
  hh %= 24;
  mm += minutes;
  if (mm >= 60) {
    hh++;
    hh %= 24;
    mm -= 60;
  }
  if (hh < 10) cout << '0';
  cout << hh << ':';
  if (mm < 10) cout << '0';
  cout << mm << '\n';

  return 0;
}