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

  int n, k; cin >> n >> k;
  string s; cin >> s;
  deque<int> dq;
  for(int i = 0; i < k; i++) {
    dq.push_back(i);
  }
  int left = 1;
  for(int i = 0; i < n; i++) {
    if(dq.empty()) {
      break;
    }
    if(left) {
      if(s[i] == 'R') {
        dq.pop_front();
        left = 1;
      } 
      else {
        left = 0;
      }
    }
    else {
      if(s[i] == 'L') {
        dq.pop_front();
        left = 0;
      } 
      else {
        left = 1;
      }
    }
  }

  cout << (int)dq.size() << '\n';
        
  return 0;
}