#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
map<string, int> mp;
int weekend1 = 1, weekend2 = 2;

int before_x_day(int x) {
  x = ((x % 7) + 7) % 7;
  return x == 0 ? 7 : x;
}

int next_renewe(int x) {
  x = (x + 2) % 7;
  return x == 0 ? 7 : x;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  mp["Sat"] = 1;
  mp["Sun"] = 2;
  mp["Mon"] = 3;
  mp["Tue"] = 4;
  mp["Wed"] = 5;
  mp["Thu"] = 6;
  mp["Fri"] = 7;

  int ans = INT_MAX;

  string today; cin >> today;
  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;

    if(x == 30) {
      if(today == "Sat") {
        cout << "2\n";
      }
      else if(today == "Sun") {
        cout << "1\n";
      }
      else {
        cout << "0\n";
      }
      return 0;
    }

    int last_renewe = before_x_day(mp[today] - x);
    int gone = 0;
    while(true) {
      int next = next_renewe(last_renewe);
      if(next == weekend1) {
        if(gone + 30 + 2 <= x) {
          gone += 32;
          last_renewe = 3;
        }
        else {
          break;
        }
      }
      else if(next == weekend2) {
        if(gone + 30 + 1 <= x) {
          gone += 31;
          last_renewe = 3;
        }
        else {
          break;
        }
      }
      else {
        if(gone + 30 <= x) {
          gone += 30;
          last_renewe = next;
        }
        else {
          break;
        }
      }
    }
    int last_renewe_day = before_x_day(mp[today] - (x - gone));
    int this_month = 0;
    if(next_renewe(last_renewe_day) == weekend1) this_month = 32;
    else if(next_renewe(last_renewe_day) == weekend2) this_month = 31;
    else this_month = 30;
    int val = this_month - (x - gone);
    ans = min(ans, val);
  }
  cout << ans << '\n';

  // cout << before_x_day(mp["Fri"]-31);



  return 0;
}