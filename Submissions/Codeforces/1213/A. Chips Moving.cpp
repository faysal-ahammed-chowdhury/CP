#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int even_cnt = 0, odd_cnt = 0;
  for(int i = 1; i <= n; i++) {
    int x; cin >> x;
    if(x & 1) odd_cnt++;
    else even_cnt++;
  }

  cout << min(odd_cnt, even_cnt) << '\n';

  return 0;
}