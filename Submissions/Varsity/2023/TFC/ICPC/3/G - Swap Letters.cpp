#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s1, s2; cin >> s1 >> s2;
  int a_cnt_1 = 0, b_cnt_1 = 0, a_cnt_2 = 0, b_cnt_2 = 0;
  deque<int> pos1, pos2, pos3, pos4;
  for(int i = 0; i < n; i++) {
    if(s1[i] == s2[i]) continue;
    if(s1[i] == 'a') {
      a_cnt_1++;
      pos1.push_back(i);
    }
    else {
      b_cnt_1++;
      pos3.push_back(i);
    }
  }

  for(int i = 0; i < n; i++) {
    if(s1[i] == s2[i]) continue;
    if(s2[i] == 'a') {
      a_cnt_2++;
      pos4.push_back(i);
    }
    else {
      b_cnt_2++;
      pos2.push_back(i);
    }
  }

  if((a_cnt_1 + a_cnt_2) % 2 != 0 or (b_cnt_1 + b_cnt_2) % 2 != 0) {
    cout << -1 << '\n';
    return 0;
  }

  // cout << a_cnt_1 << '\n';
  // cout << a_cnt_2 << '\n';
  // cout << b_cnt_1 << '\n';
  // cout << b_cnt_2 << '\n';

  int cnt1 = (a_cnt_1 / 2) + (b_cnt_1 / 2);
  int cnt2 =  (a_cnt_1 % 2) + (b_cnt_1 % 2);
  int ans = cnt1 + cnt2;
  cout << ans << '\n';

  for(int i = 1; i <= a_cnt_1 / 2; i++) {
    int top1 = pos1.front();
    pos1.pop_front(), pos1.pop_front();
    pos2.pop_front();
    int top2 = pos2.front();
    pos2.pop_front();

    cout << ++top1 << ' ' << ++top2 << '\n';
  }
  for(int i = 1; i <= b_cnt_1 / 2; i++) {
    int top1 = pos3.front();
    pos3.pop_front(), pos3.pop_front();
    pos4.pop_front();
    int top2 = pos4.front();
    pos4.pop_front();

    cout << ++top1 << ' ' << ++top2 << '\n';
  }

  while(true) {
    if(cnt2 == 0) break;
    cnt2 -= 2;
    int top1 = pos1.front();
    top1++;
    pos1.pop_front();

    int top2 = pos2.front();
    top2++;
    pos2.pop_front();

    cout << top1 << ' ' << top2 << '\n';

    top1 = pos3.front();
    pos3.pop_front();
    top1++;
    cout << top2 << ' ' << top1 << '\n';
  }

  return 0;
}