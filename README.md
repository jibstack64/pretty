# pretty

[![License: MIT](https://img.shields.io/badge/license-MIT-orange.svg)](https://opensource.org/licenses/MIT)
![Downloads](https://img.shields.io/github/downloads/jibstack64/pretty/total)
[![Version](https://img.shields.io/badge/version-v0.1-success)](https://github.com/jibstack64/pretty/releases)

#### A simple, lightweight unix console-colouring library for C++, all in one header file!

### Colours
![C++ map of colours](https://user-images.githubusercontent.com/107510599/198850914-5631c86c-7748-4c89-a16b-4acc00f12730.png)

*Includes the large majority of ANSI colour escape sequences. If any are missing, feel free to [create an issue](https://github.com/jibstack64/pretty/issues).*

### Use
> A list of colour names can be found below **Colours**, or, alternatively, just at the top of the `pretty.hpp` header file.

Pretty goes under the `pty` namespace.

Pretty adds the reset escape sequence automically, meaning no more boilerplate `CLR + str + RESET`!

Say you wanted to go basic, a hello world script, for example:
```cpp
#include <iostream>
// include pretty from whatever directory you store your includes in
#include "pretty.hpp"

int main() {
    std::cout << pty::paint("Hello world!", "green") << std::endl;
    // simple as that!
}
```
Or maybe you are working on a deadline project, and need a reusable set of sequences to avoid typing `pty::paint(...)` repeatedly:
```cpp
// here we create the colour set, providing it as many different values as we need
pty::ColourSet clSet({"green", "bold"});
// using this colour set is easy and efficient
std::cout << clSet.apply("This is much faster!") << std::endl;
```
The `paint` function can also be used in the same way as the `ColourSet` constructor.
```cpp
std::cout << pty::paint("I love C++!", {"yellow", "dim"}) << std::endl;

// alternatively with an array
std::vector<std::string> clrs = {"yellow", "bluebg", "underlined"};
std::cout << pty::paint("I love C!", clrs) << std::endl;
```
Need to save coloured text for later, or maybe remove ANSI sequences from a string?
```cpp
std::string coloured = pty::paint("I'll need this later!", {"blue", "yellowbg"});

// use the 'normal(...)' function to "normalise" a string (remove ANSI escape sequences)
std::cout << pty::normal(coloured) << std::endl;
// output will be plain, uncoloured text
```

### Testing
`pretty_tests.cpp` contains code for testing and checking the functionality of changes made in `pretty.hpp`. This is to be updated and used to verify every major addition to `pretty.hpp`.

### Future changes
- [x] `dim`, `bold` and `normal` functions for dimming, brightening and removing escape codes from text.
  
