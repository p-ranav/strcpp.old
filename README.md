# String Manipulation API for C++

## strcpp::split

```cpp
{
  std::string input = "We are the champions";     // input string
  std::vector<std::string> result;                // result vector

  result = strcpp::split(input, " ");             // result = ["We", "are", "the", "champions"]
  result = strcpp::split(input, " a");            // result = ["We", "re the champions"]
  result = strcpp::split(input, "ions");          // result = ["We are the champ"]

  input = "a, b, c, d, e";
  result = strcpp::split(input, ", ");            // result = ["a", "b", "c", "d", "e"]

  input = "LOGGER::ERROR::Error Message!";
  auto message = strcpp::split(input, "::")[2];   // message = "Error Message!"
}
```

## strcpp::join

```cpp
{
  std::string input = "This. is. not. how. sentences. work.";        // wow such a sentence
  auto split_string = strcpp::split(input, ". ");                    // split using period
  std::string joined_string = strcpp::join(split_string, " ");       // join result of split
  std::string output = strcpp::replace(joined_string, " not", "");   // remove the word 'not'
  std::cout << output << std::endl;                                  // "This is how sentences work."

  input = "Transaction_date, Product, Price, State";                 // some csv data
  split_string = strcpp::split(input, ", ");                         // split using comma
  output = strcpp::join(split_string, "::");                         // join result of split
  std::cout << output << std::endl;                                  // "Transaction_date::Product::Price::State"
}
```

## strcpp::slice

```cpp
{
  std::string input = "Hello World";
  // End index is optional and defaults to end of string
  std::cout << strcpp::slice(input, 0) << std::endl;     // All but the first zero characters  - "Hello World"
  std::cout << strcpp::slice(input, 0, 1) << std::endl;  // Just the first character           - "H"
  std::cout << strcpp::slice(input, 3) << std::endl;     // All but the first three characters - "lo World"
  std::cout << strcpp::slice(input, 0, 5) << std::endl;  // Just the first five characters     - "Hello"
  std::cout << strcpp::slice(input, 3, 8) << std::endl;  // After third till eigth character   - "lo Wo"
  std::cout << strcpp::slice(input, -3) << std::endl;    // Just the last three characters     - "rld"
  std::cout << strcpp::slice(input, 0, -3) << std::endl; // All but the last three characters  - "Hello Wo"
}
```

## strcpp::contains
```cpp
{
  std::string input = "ERROR::Houston, we have a problem!";

  if (strcpp::contains(input, "ERROR"))                                 // containment check - case sensitive
    std::cout << "Input string contains \"ERROR\"" << std::endl;        // check returns true and prints message

  if (strcpp::contains(input, "error::", true))                         // containment check - ignore case
    std::cout << "Input string contains \"error::\"" << std::endl;      // check returns true and prints message

  if (strcpp::contains(input, "PROBLEM"))                               // containment check - ignore case
    std::cout << "Input string contains \"PROBLEM\"\n";
  else
    std::cout << "Input string does not contain \"PROBLEM\"\n";         // check returns false and prints message
}
```

## strcpp::count

```cpp
{
  std::string input = "Hello World!";
  std::cout << strcpp::count(input, "l") << std::endl;                  // prints 3
  std::cout << strcpp::count(input, "llo") << std::endl;                // prints 1
  std::cout << strcpp::count(input, " W") << std::endl;                 // prints 1
  std::cout << strcpp::count(input, " wo") << std::endl;                // prints 0
  std::cout << strcpp::count(input, " wo", true) << std::endl;          // prints 1 - ignores case

  std::string them_spaces = "Count, the number of          spaces";
  std::cout << strcpp::count(them_spaces, " ") << std::endl;            // prints 13
}
```

## strcpp::starts_with

```cpp
{
  std::string input = "What's up with the Quaithe?";
  if (strcpp::starts_with(input, 'W'))
    std::cout << "Input string starts with 'W'\n";                     // check returns true and prints message

  if (strcpp::starts_with(input, 'w', true))
    std::cout << "Input string starts with 'w' - Case is ignored\n";   // check returns true and prints message
}
```

## strcpp::ends_with

```cpp
{
  std::string input = "What's up with the Quaithe?";
  if (strcpp::ends_with(input, '.'))                                   // check returns false
    std::cout << "Input string ends with period\n";

  if (strcpp::ends_with(input, '?'))                                   // check returns true and prints message
    std::cout << "Input string is a question\n";
}
```

## strcpp::repeat

```cpp
{
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

## strcpp::find

```cpp
{
  std::string input = "I scream, you scream, we all scream for icecream!";
  size_t find_index = strcpp::find(input, "you");                            // Index = 10
  std::cout << find_index << std::endl;
}
```

## strcpp::find_first

```cpp
{
  std::string input = "I scream, you scream, we all scream for icecream!";
  size_t find_index = strcpp::find_first(input, "cream");                    // Index = 3
  std::cout << find_index << std::endl;
}
```

## strcpp::find_last

```cpp
{
  std::string input = "I scream, you scream, we all scream for icecream!";
  size_t find_index = strcpp::find_last(input, "cream");                     // Index = 47
  std::cout << find_index << std::endl;
}
```

## strcpp::find_regex

```cpp
{
  std::string log(R"(
        Speed : 366
        Mass  :	 35
        Speed : 378
        Mass  :	 32
        Speed : 400
	Mass  :	 30)");
  std::string regex_string = R"(Speed : \d*)";
  auto results = strcpp::find_regex(log, regex_string);  
  // ["Speed : 366", "Speed : 378", "Speed : 400"]

  std::string file_path = "/home/pranav/dev/FILE_SomeStringOfInterest_EVENT.bash";
  results = strcpp::find_regex(file_path, ".*FILE_(\\w+)_EVENT\\.bash.*");
  // results: ["/home/pranav/dev/FILE_SomeStringOfInterest_EVENT.bash", "SomeStringOfInterest"]
}
```

## strcpp::replace

```cpp
{
  std::string input = "This is a test string.";
  std::cout << strcpp::replace(input, "a test", "an example");  // "This is an example string."
  std::cout << std::endl <<
    strcpp::replace(input, "test", "") << std::endl;            // "This is a string"

  input = "This is a a test string";                            // replace the first occurrence of the letter 'a'
  std::cout << strcpp::replace(input, "a", "", 1) << "\n";      // "This is a test string"

  input = "Peter Piper picked a peck of pickled peppers.";                            
  std::cout << strcpp::replace(input, "p", "T", 2) << "\n";     // "Peter PiTer Ticked a peck of pickled peppers."

  input = "Peter Piper picked a peck of pickled peppers.";
  std::cout << strcpp::replace(input, "P", "T", 2) << "\n";     // "Teter Tiper picked a peck of pickled peppers."
}
```

## strcpp::translate

```cpp
{
  std::string input = "1X444 2X3AB *^$RB (F(QP.";                          // coded input message
  std::map<std::string, std::string> translation_table = {
    { "1X444", "Appetite"},
    { "2X3AB", "comes" },
    { "*^$RB", "with" }, 
    { "(F(QP", "eating" }
  };
  std::string translated = strcpp::translate(input, translation_table);
  std::cout << translated << std::endl;                                    // "Appetite comes with eating."
}
```

## strcpp::trim

```cpp
{
  std::string input = "   Hello World!   ";
  std::cout << strcpp::trim(input) << std::endl;    // "Hello World!"
  std::cout << strcpp::ltrim(input) << std::endl;   // "Hello World!   "
  std::cout << strcpp::rtrim(input) << std::endl;   // "   Hello World!"
}
```

## strcpp::format

```cpp
{
  std::string output = strcpp::format("Roses are {0}, Violets are {1}, Sugar is {2}, And so are {3}!",
                                      { "red", "blue", "sweet", "you" });
  std::cout << output << std::endl; // "Roses are red, Violets are blue, Sugar is sweet, And so are you!"

  std::cout << strcpp::format("{0}!... {0}!", {"Hodor"}) << std::endl; // "Hodor!... Hodor!"
}
```

### strcpp::upper

```cpp
{
  std::string input = "this is some lowercase string";
  std::cout << strcpp::upper(input) << std::endl;               // "THIS IS SOME LOWERCASE STRING"
}
```

## strcpp::is_upper

```cpp
{
  std::string input = "Hello World!";
  if (strcpp::is_upper(input))
    std::cout << "There is at least one upper case character in input" << std::endl;
}
```

## strcpp::lower

```cpp
{
  std::string input = "ACCIDENTALLY ENABLED CAPS LOCK!!!";
  std::cout << strcpp::lower(input) << std::endl;               // "accidentally enabled caps lock!!!"
}
```

## strcpp::is_lower

```cpp
{
  std::string input = "Hello World!";
  input = strcpp::lower(input);
  if (strcpp::is_lower(input))
    std::cout << "All alphabets in the input string are lower case" << std::endl;
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
