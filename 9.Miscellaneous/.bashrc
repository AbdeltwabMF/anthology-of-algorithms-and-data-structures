# compilation flags & debugging flags & gdb for competitive programming
# This shell script in this file is executed by bash when you open the terminal
# Adding these flags and commands to ~/.bashrc

# G++ has many useful warning flags such as

# -Wall enables all warnings. I highly recommend using this flags.
# -Wextra enables extra warnings.
# -Wno-sign-conversion silences sign conversion warnings for code like x < vec.size()
# -Wshadow enables shadowing warnings, so that if you define another variable with the same name in a local scope, you will get a warning.

# Using these flags can save you time debugging silly mistakes like forgetting to return a value in a function or
# doing a comparison like x < vec.size() - 1 where vec.size() - 1 can underflow into SIZE_MAX - 1.

function cp {
    g++ -Wall -Wextra -Wshadow -Og -g -Ofast -std=c++17 -fsanitize=address,undefined -D_GLIBCXX_ASSERTIONS -DDEBUG -ggdb3 -fmax-errors=2 -o $1{,.cpp}
}

# Example cp(Compile):
# abdeltwabmf@ThinkPad: cp main
# by doing this command the file main.cpp has been compiled successfully with all warning

# Debugging is an important part of CP. After all, even tourist gets RTE on his submissions occasionally.

# -g enables basic debug information
# -ggdb3 enables extended debug information such as macros. I suggest using this generally.
# It slows down compilation a little bit, but has no effect on run-time, since it just adds an extra piece of data in the executable that helps
# the debugger map the executable file position to line numbers and other related information.

# -D_GLIBCXX_DEBUG enables out of bounds checking and checks that your comparison operator is irreflexive (comp(a, a) should return false), and
# many other useful things. However, this can slow down your code runtime (and compile time) substantially.

# -D_GLIBCXX_ASSERTIONS enables light-weight debug checks such as out of bounds checking.
# I suggest always using this when compiling locally, as it has negligible runtime and compile-time performance impact.

# -fmax-errors=<n> limits the number of errors displayed to n. This stops the compiler from printing an excessive amount of error messages.

# -DDEBUG is used in my debug macro (see below) to enable debugging. Add this to your compilation flags locally to enable debugging.
# Since this macro is not defined in CodeForces' compilation options, when your code is judged debugging will be disabled.

function db {
    (echo "start <input.in" && cat) | gdb -q $1
}

# Example db(GNU GDB Debugger):
# abdeltwabmf@ThinkPad: db main
# by doing this command the main.cpp will run and reading input from input.in file & the GNU GDB will open in the terminal and ready to go

function dbc {
    gdb --tui -q $1 -ex "run <input.in"
}

# Example dbc(GNU GDB Debugger - split the window into 2 parts the souce code will be on the top and the GDB will be in the buttom):
# abdeltwabmf@ThinkPad: dbc main
# by doing this command the same thing will be happened as the previous command except for splitting the window
