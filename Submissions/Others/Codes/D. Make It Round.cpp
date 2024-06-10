#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    int old_n = n, old_m = m;
    int five_cnt = 0, two_cnt = 0;
    for(int i = 2; i <= 5; i++) {
      while(n % i == 0) {
        if(i == 2) two_cnt++;
        else if(i == 5) five_cnt++;
        n /= i;
      }
    }
    if(n == 2) two_cnt++;
    else if(n == 5) five_cnt++;

    int two_cnt_2 = 0, five_cnt_2 = 0;
    if(two_cnt < five_cnt) {
      int need = five_cnt - two_cnt;
      for(int i = 1; i <= need; i++) {
        if(m < 2) break;
        two_cnt_2++;
        m /= 2;
      }
    }
    else if(five_cnt < two_cnt) {
      int need = two_cnt - five_cnt;
      for(int i = 1; i <= need; i++) {
        if(m < 5) break;
        five_cnt_2++;
        m /= 5;
      }
    }

    while(true) {
      bool ok = false;
      int x = m;
      if(m >= 5) {
        m /= 5;
        five_cnt_2++;
        ok = true;
      }
      if(m >= 2 and ok) {
        m /= 2;
        two_cnt_2++;
      }
      else {
        if(ok) {
          five_cnt_2--;
          m = x;
        }
        break;
      }
    }

    long long ans = 1ll * old_n * pow(2, two_cnt_2) * pow(5, five_cnt_2) * m;
    cout << ans << '\n';
  }

  return 0;
}