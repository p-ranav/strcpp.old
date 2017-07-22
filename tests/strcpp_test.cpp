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

void contains_test() {
  std::string input = "ERROR::Houston, we have a problem!";

  if (strcpp::contains(input, "ERROR")) {               // containment check - case sensitive
    std::cout << "We have a problem!" << std::endl;
  }

  if (strcpp::contains(input, "error::", true)) {       // containment check - ignore case
    std::cout << "We have a problem!" << std::endl;
  }

  if (strcpp::contains(input, "PROBLEM", true)) {       // containment check - ignore case
    std::cout << "Message contains problem" << std::endl;
  }
}

int main() {
  split_test();
  contains_test();

  system("PAUSE");
  return 0;
}