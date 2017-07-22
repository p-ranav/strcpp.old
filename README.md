# String Manipulation Header-only Library for C++

## Split an input string using a delimiter string

```cpp
#include <strcpp.h>

int main() {

  std::string input = "We are the champions";     // input string
  std::vector<std::string> result;                // result vector

  result = strcpp::split(input, " ");             // result = ["We", "are", "the", "champions"]
  result = strcpp::split(input, " a");            // result = ["We", "re the champions"]
  result = strcpp::split(input, "ions");          // result = ["We are the champ"]

  input = "a,b,c,d,e";
  result = strcpp::split(input, ",");             // result = ["a", "b", "c", "d", "e"]

  input = "a, b, c, d, e";
  result = strcpp::split(input, ", ");            // result = ["a", "b", "c", "d", "e"]

  input = "LOGGER::ERROR::Error Message!";
  auto message = strcpp::split(input, "::")[2];   // message = "Error Message!"

  auto length = strcpp::length(message);          // length = 14

  return 0;
}
```

## Slice an input string like in Python

```cpp
#include <strcpp.h>

int main() {
  std::string input = "Hello World";
  // End index is optional and defaults to end of string
  std::cout << strcpp::slice(input, 0) << std::endl;     // All but the first zero characters  - "Hello World"
  std::cout << strcpp::slice(input, 0, 1) << std::endl;  // Just the first character           - "H"
  std::cout << strcpp::slice(input, 3) << std::endl;     // All but the first three characters - "lo World"
  std::cout << strcpp::slice(input, 0, 5) << std::endl;  // Just the first five characters     - "Hello"
  std::cout << strcpp::slice(input, 3, 8) << std::endl;  // After third till eigth character   - "lo Wo"
  std::cout << strcpp::slice(input, -3) << std::endl;    // Just the last three characters     - "rld"
  std::cout << strcpp::slice(input, 0, -3) << std::endl; // All but the last three characters  - "Hello Wo"
  return 0;
}
```

## Check if an input string contains sub-string

```cpp
#include <strcpp.h>

int main() {

  std::string input = "ERROR::Houston, we have a problem!";

  if (strcpp::contains(input, "ERROR")) {                               // containment check - case sensitive
    std::cout << "Input string contains \"ERROR\"" << std::endl;        // check returns true and prints message
  }

  if (strcpp::contains(input, "error::", true)) {                       // containment check - ignore case
    std::cout << "Input string contains \"error::\"" << std::endl;      // check returns true and prints message
  }

  if (strcpp::contains(input, "PROBLEM")) {                             // containment check - ignore case
    std::cout << "Input string contains \"PROBLEM\"\n";
  }
  else {
    std::cout << "Input string does not contain \"PROBLEM\"\n";         // check returns false and prints message
  }

  return 0;
}
```

## Count number of times an input string contains a sub-string

```cpp
#include <strcpp.h>

int main() {
  std::string input = "Hello World!";
  std::cout << strcpp::count(input, "l") << std::endl;          // prints 3
  std::cout << strcpp::count(input, "llo") << std::endl;        // prints 1
  std::cout << strcpp::count(input, " W") << std::endl;         // prints 1
  std::cout << strcpp::count(input, " wo") << std::endl;        // prints 0
  std::cout << strcpp::count(input, " wo", true) << std::endl;  // prints 1 - ignores case


  std::string them_spaces = "Count, the number of          spaces";
  std::cout << strcpp::count(them_spaces, " ") << std::endl;    // prints 13
  return 0;
}
```

## Check if an input string starts with or ends with some character

```cpp
#include <strcpp.h>

int main() {
  std::string input = "What's up with the Quaithe?";

  if (strcpp::starts_with(input, 'W')) {
    std::cout << "Input string starts with 'W'\n";                     // check returns true and prints message
  }

  if (strcpp::starts_with(input, 'w', true)) {
    std::cout << "Input string starts with 'w' - Case is ignored\n";   // check returns true and prints message
  }

  if (strcpp::ends_with(input, '.')) {                                 // check returns false
    std::cout << "Input string ends with period\n";
  }

  if (strcpp::ends_with(input, '?')) {                                 // check returns true and prints message
    std::cout << "Input string is a question\n";
  }
  return 0;
}
```

## Repeat input string some number of times and optionally with a connector string

```cpp
#include <strcpp.h>

int main() {
  std::string input = "Ha";
  std::cout << strcpp::repeat(input, 5) << std::endl;           // "HaHaHaHaHa"
  std::cout << strcpp::repeat(input, 5, " ") << std::endl;      // "Ha Ha Ha Ha Ha"

  input = "Ch";
  auto result = strcpp::repeat(
                  strcpp::repeat(input, 2, "ooo!"), 
                3, " ");
  std::cout << result << std::endl;                             // "Chooo!Chooo! Chooo!Chooo! Chooo!Chooo!"
}
```

## LICENSE

Copyright (c) 2017 Pranav Srinivas Kumar <pranav.srinivas.kumar@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
