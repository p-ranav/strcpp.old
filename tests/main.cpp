#include <strcpp.h>

void split_test() {
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

void slice_test() {
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

void contains_test() {
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

}

int main() {
  split_test();
  slice_test();
  contains_test();
  system("PAUSE");
  return 0;
}