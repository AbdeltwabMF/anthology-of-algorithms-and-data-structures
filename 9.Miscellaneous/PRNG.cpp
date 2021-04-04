/** pseudo-random number generator | C++xx >= C++11 **/


/** generating |64-bit| random number **/
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());

ll myRand(ll B) {
  return (ull)rngll() % B;
}

/** generating |64-bit| random number in range **/
ll myRand(ll a, ll b) {
  return uniform_int_distribution <ll> (a, b)(rngll);
}

/** generating |32-bit| random number **/
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int myRand(int B) {
  return (unsigned int)rng() % B;
}

/** generating |32-bit| random number in range **/
int myRand(int a, int b) {
  return uniform_int_distribution <int> (a, b)(rng);
}
