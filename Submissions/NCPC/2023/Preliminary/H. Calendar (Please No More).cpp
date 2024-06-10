#include <bits/stdc++.h>
using namespace std;

int months[15];
map<string, int> mp;

bool is_leap_year(int y) {
  return (y % 400 == 0) or (y % 4 == 0 and y % 100 != 0);
}

void solve() {
  string s, d; cin >> s >> d;
  string date_s = s.substr(0, 2);
  string month_s = s.substr(3, 2);
  string year_s = s.substr(6, 4);
  int date = atoi(date_s.c_str());
  int month = atoi(month_s.c_str());
  int year = atoi(year_s.c_str());

  if (is_leap_year(year)) {
    months[2] = 29;
  }
  else {
    months[2] = 28;
  }

  map<int, vector<int>> mp2;

  int this_day = mp[d];
  int cur = this_day;
  for (int i = date; i >= 1; i--) {
    mp2[cur].push_back(i);
    cur--;
    if (cur < 0) cur += 7;
  }
  cur = (this_day + 1) % 7;
  for (int i = date + 1; i <= months[month]; i++) {
    mp2[cur].push_back(i);
    cur++;
    if (cur >= 7) cur %= 7;
  }
  for (auto &[x, y] : mp2) {
    sort(y.rbegin(), y.rend());
  }

  cout << "|---------------------------|\n";
  cout << "|Sun|Mon|Tue|Wed|Thu|Fri|Sat|\n";
  cout << "|---------------------------|\n";

  int ans[10][10];

  int last = 0;
  for (int i = 1; i <= 5; i++) {
    for (int j = 0; j <= 6; j++) {
      int get = 0;
      if (!mp2[j].empty()) {
        get = mp2[j].back();
      }
      if (last == get - 1 and get != 0) {
        last = get;
        ans[i][j] = get;
        mp2[j].pop_back();
      }
      else {
        ans[i][j] = 0;
      }
    }
  }

  int rem = months[month] - last;

  for (int i = 0; i < rem; i++) {
    ans[1][i] = ++last;
  }

  for (int i = 1; i <= 5; i++) {
    cout << '|';
    for (int j = 0; j <= 6; j++) {
      if (ans[i][j] == 0) {
        cout << " - |";
      }
      else {
        if (ans[i][j] >= 10) {
          cout << " ";
        }
        else {
          cout << "  ";
        }
        cout << ans[i][j] << '|';
      }
    }
    cout << '\n';
    cout << "|---------------------------|\n";
  }

  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  mp["Sun"] = 0;
  mp["Mon"] = 1;
  mp["Tue"] = 2;
  mp["Wed"] = 3;
  mp["Thu"] = 4;
  mp["Fri"] = 5;
  mp["Sat"] = 6;

  months[1] = 31;
  months[2] = 28;
  months[3] = 31;
  months[4] = 30;
  months[5] = 31;
  months[6] = 30;
  months[7] = 31;
  months[8] = 31;
  months[9] = 30;
  months[10] = 31;
  months[11] = 30;
  months[12] = 31;

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}