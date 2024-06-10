#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int even_idx, odd_idx, even_cnt = 0, odd_cnt = 0;
  for(int i = 1; i <= n; i++) {
    int x; cin >> x;
    if(x & 1) {
      odd_cnt++;
      odd_idx = i;
    }
    else {
      even_cnt++;
      even_idx = i;
    }
  }
  if(odd_cnt == 1) {
    cout << odd_idx << '\n';
  }
  else {
    cout << even_idx << '\n';
  }
        
  return 0;
}