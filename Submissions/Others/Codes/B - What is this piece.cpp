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
  deque<int> fonts_neg, fonts_pos, color_neg, color_pos;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    if(x < 0) {
      fonts_neg.push_back(x);
    }
    else {
      fonts_pos.push_back(x);
    }
  }
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    if(x < 0) {
      color_neg.push_back(x);
    }
    else {
      color_pos.push_back(x);
    }
  }


  return 0;
}