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

  int t, o; cin >> t >> o;
  if(t == o) {
    cout << "even even seven EIeven.\n";
  }
  else if(t > o) {
    cout << "orz teralem is the king!\n";
  }
  else {
    cout << "orz overflowker is the king!\n";
  }
        
  return 0;
}