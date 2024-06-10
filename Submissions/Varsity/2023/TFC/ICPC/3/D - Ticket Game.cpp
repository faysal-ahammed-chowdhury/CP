#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s; cin >> s;
  int option1 = 0, option2 = 0, sum1 = 0, sum2 = 0;
  for(int i = 0; i < n; i++) {
    if((i + 1) <= (n / 2)) {
      if(s[i] == '?') {
        option1++;
      }
      else {
        sum1 += s[i] - '0';
      }
    }
    else {
      if(s[i] == '?') {
        option2++;
      }
      else {
        sum2 += s[i] - '0';
      }
    }
  }

  int diff = sum1 - sum2;
  int need = (option2 - option1) / 2;
  if(diff == 9 * need) {
    cout << "Bicarp\n";
  }
  else {
    cout << "Monocarp\n";
  }

  return 0;
}