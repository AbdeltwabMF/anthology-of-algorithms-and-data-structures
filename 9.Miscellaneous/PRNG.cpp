/** pseudo-random number generator | C++xx >= C++11 **/

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

T myRand(T a, T b) {
  return uniform_int_distribution <T> (a, b)(rng);
}
