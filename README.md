# String Manipulation Header-only Library for C++

## Split that String!

```cpp
#include <strcpp.h>

int main() {

  // Splitting std::string
  {
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
  }

  return 0;
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
