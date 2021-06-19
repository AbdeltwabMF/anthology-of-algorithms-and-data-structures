#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

using i128 = __int128_t;
using i64 = int64_t;
using i32 = int32_t;
using i16 = int16_t;
using i8 = int8_t;

using u128 = __uint128_t;
using u64 = uint64_t;
using u32 = uint32_t;
using u16 = uint16_t;
using u8 = uint8_t;

void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

/** 64-bit signed int Generator
 **/
i64 int64(i64 a, i64 b) {
  return uniform_int_distribution <i64> (a, b)(rng);
}

/** Customize your Generator depending on the input
 **/
void gen () {
  ofstream cout("input.in");
  i32 t = 2;
  cout << t << endl;

  while (t--) {
    i32 n = int64(1, 100), m = int64(1, 100);
    cout << n << " " << m << endl;
    
    while (m--) {
      i32 u = int64(1, n), v = int64(1, n), c = int64(1, 4);
      cout << u << " " << v << " " << c << endl;
    }
  }
}

i32 main (i32 arg, char* args[]) {
  fast();
  
  i32 tc = 0;
  i32 limit = 100;
  if(arg != 3) return 0;
  
  string flags = "g++ -Wall -Wextra -Wshadow -Og -g -Ofast -std=c++17 -D_GLIBCXX_ASSERTIONS -DDEBUG -ggdb3 -fsanitize=address,undefined -fmax-errors=2 -o "; 
  string ex = ".cpp", bf, oz, pr;

  bf = flags + args[1] + " " + args[1] + ex; 
  oz = flags + args[2] + " " + args[2] + ex; 
  char bff[bf.size() + 1];
  char ozz[oz.size() + 1];
  strcpy(bff, bf.c_str());
  strcpy(ozz, oz.c_str());

  // compile command
  system(bff);
  system(ozz);

  ex = ".out";
  pr = "./";
  bf = pr + args[1] + " < input.in > " + args[1] + ex;
  oz = pr + args[2] + " < input.in > " + args[2] + ex;
  strcpy(bff, bf.c_str());
  strcpy(ozz, oz.c_str());

  while (++tc <= limit) {
    gen();
    cerr << tc << endl;
    // run command
    system(bff);
    system(ozz);

    ifstream brute_forces("brute_force.out");
    ifstream optimizes("optimized.out");

    string brute_force, optimized;
    getline(brute_forces, brute_force, (char)EOF);
    getline(optimizes, optimized, (char)EOF);

    if(brute_force != optimized) {
      cerr << "Wrong Answer ❌" << endl;
      break;
    } else if (tc == limit) {
      cout << "Accepted insha'a Allah ✅" << endl;
    }
  }
}
