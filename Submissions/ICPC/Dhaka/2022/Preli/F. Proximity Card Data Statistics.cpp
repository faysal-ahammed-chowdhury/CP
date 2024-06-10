#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

struct node {
  string time;
  string blood;
  int year;
};

string cmp(string s1, string s2) {
  int year1 = atoi(s1.substr(6, 9).c_str());
  int year2 = atoi(s2.substr(6, 4).c_str());
  if(year1 > year2) return s1;
  if(year2 > year1) return s2;
  int month1 = atoi(s1.substr(3, 2).c_str());
  int month2 = atoi(s2.substr(3, 2).c_str());
  if(month1 > month2) return s1;
  if(month2 > month1) return s2;
  int date1 = atoi(s1.substr(0, 2).c_str());
  int date2 = atoi(s2.substr(0, 2).c_str());
  if(date1 > date2) return s1;
  if(date2 > date1) return s2;
  int hour1 = atoi(s1.substr(11, 2).c_str());
  int hour2 = atoi(s2.substr(11, 2).c_str());
  if(hour1 > hour2) return s1;
  if(hour2 > hour1) return s2;
  int min1 = atoi(s1.substr(14, 2).c_str());
  int min2 = atoi(s2.substr(14, 2).c_str());
  if(min1 > min2) return s1;
  if(min2 > min1) return s2;
  int sec1 = atoi(s1.substr(17, 2).c_str());
  int sec2 = atoi(s2.substr(17, 2).c_str());
  if(sec1 > sec2) return s1;
  if(sec2 > sec1) return s2;
  return s1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  map<string, node> mp;
  for(int i = 1; i <= n; i++) {
    string time, mail, birth, blood; cin >> time >> mail >> birth >> blood;
    int year = atoi(birth.substr(6).c_str());
    if(mp.find(mail) == mp.end()) {
      mp[mail] = {time, blood, year};
    }
    else {
      string ans = cmp(mp[mail].time, time);
      if(ans == time) {
        mp[mail] = {time, blood, year};
      }
    }
  }

  map<string, int> blood_cnt;
  map<int, int> birth_year_cnt;
  blood_cnt["A+"] = 0;
  blood_cnt["A-"] = 0;
  blood_cnt["AB+"] = 0;
  blood_cnt["AB-"] = 0;
  blood_cnt["B+"] = 0;
  blood_cnt["B-"] = 0;
  blood_cnt["O+"] = 0;
  blood_cnt["O-"] = 0;
  for(auto i: mp) {
    blood_cnt[i.second.blood]++;
    birth_year_cnt[i.second.year]++;
  }
  for(auto i: blood_cnt) {
    cout << i.first << ' ' << i.second << '\n';
  }
  for(auto i: birth_year_cnt) {
    cout << i.first << ' ' << i.second << '\n';
  }



  return 0;
}