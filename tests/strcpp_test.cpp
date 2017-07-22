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
    auto message = strcpp::split(input, "::")[2];   // result = "Error Message!"
  }

  system("PAUSE");
  return 0;
}