#include <bits/stdc++.h>

#ifndef cpheader
#define F0R(i,a,b) for (int i = a; i < b; ++i)
#define f0r(i,b) F0R(i,0,b)
#define F0Rd(i,a,b) for (int i = a; i >= b; --i)
typedef long long ll;
typedef std::vector<int> vi;
template <class T, class U>
constexpr bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}
template <typename T, typename U>
constexpr long long powi(T a, U b) {
  long long x = 1;
  f0r(i, b) x*=a;
  return x;
}
#define cpheader
#endif


using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  unsigned long long n, e, other;
  cin >> n >> e;

  // vector<unsigned long long> dp(62, 0);
  // dp[0] = 1;
  // int ex = 7;
  // F0R(k, 0, 16){

  // F0R(j, 1, ex){
  int count = 0;

  F0R(i, 0, n) {
  if (to_string(i).find(to_string(powi(2, e))) != -1) {
      count++;
    }
  } 
  cout << count;

  // }
  // }
  /*F0R(i, 1, 62){
    dp[i] = 2*dp[i-1]-1;
  }
  long long ex = 0;
  f0r(i, 62) {
    cout << "i: " << i << " dp[i]: " << dp[i]+ex << '\n';
    ex+=dp[i];
  }*/
  /*
  string ns = to_string(n), es = to_string(powi(2, e)); 



  if (powi(2, e)*powi(10, ns.length() - es.length()) > n) {
    other = powi(2, max(int(ns.length()-es.length()), 0)-1);
  } else {
    other = 1;
  }
  cout << 4842258985-powi(10, max(int(ns.length()-es.length())-2, 0))*other;

  return 0;
  */
}
