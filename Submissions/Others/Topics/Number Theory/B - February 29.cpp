#include <bits/stdc++.h>
using namespace std;

int leap_year_till(int n) {
  int ans = n / 4;
  ans -= n / 100;
  ans += n / 400;
  return ans;
}

bool is_leaf_year(int year) {
  return (year % 4 == 0 & year % 100 != 0) || year % 400 == 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t, cs = 0; cin >> t;
  while(t--) {
    string month1, month2; cin >> month1;
    int day1, day2; cin >> day1;
    char c; cin >> c;
    int year1, year2; cin >> year1;
    cin >> month2 >> day2 >> c >> year2;
    
    int cnt = leap_year_till(year2) - leap_year_till(year1 - 1);
    if(is_leaf_year(year1) && month1 != "January" && month1 != "February") {
      cnt--;
    }
    if(is_leaf_year(year2) && month2 == "January") {
      cnt--;
    }
    else if(is_leaf_year(year2) && month2 == "February" && day2 < 29) {
      cnt--;
    }
    cout << "Case " << ++cs << ": ";
    cout << cnt << '\n';
  }

  return 0;
}