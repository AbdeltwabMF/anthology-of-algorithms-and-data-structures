#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;
int next_greater[N], next_smaller[N], prev_greater[N], prev_smaller[N], ar[N], n;
stack <int> st;

int main() {
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> ar[i];

  for(int i = n; i; --i) { // next greater
    while(st.size() && ar[st.top()] < ar[i])
      st.pop();

    if(st.empty())
      next_greater[i] = -1;
    else
      next_greater[i] = st.top();

    st.push(i);
  }

  st = stack <int> ();
  for(int i = n; i; --i) { // next smaller
    while(st.size() && ar[st.top()] > ar[i])
      st.pop();

    if(st.empty())
      next_smaller[i] = -1;
    else
      next_smaller[i] = st.top();

    st.push(i);
  }

  st = stack <int> ();
  for(int i = 1; i <= n; ++i) { // previous greater
    while(st.size() && ar[st.top()] < ar[i])
      st.pop();

    if(st.empty())
      prev_greater[i] = -1;
    else
      prev_greater[i] = st.top();

    st.push(i);
  }

  st = stack <int> ();
  for(int i = 1; i <= n; ++i) { // previous smaller
    while(st.size() && ar[st.top()] > ar[i])
      st.pop();

    if(st.empty())
      prev_smaller[i] = -1;
    else
      prev_smaller[i] = st.top();

    st.push(i);
  }

  for(int i = 1; i <= n; ++i) cout << next_greater[i] << " \n"[i == n];
  for(int i = 1; i <= n; ++i) cout << next_smaller[i] << " \n"[i == n];
  for(int i = 1; i <= n; ++i) cout << prev_greater[i] << " \n"[i == n];
  for(int i = 1; i <= n; ++i) cout << prev_smaller[i] << " \n"[i == n];
}
