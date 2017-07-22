#include <iostream>
#include <string>
#include <vector>

namespace strcpp {
  std::vector<std::string> split(std::string input, std::string delimiter, 
    std::vector<std::string>& result = std::vector<std::string>()) {
    size_t counter_position = 0;
    size_t delimiter_position = input.find(delimiter);
    if (delimiter_position != std::string::npos) {
      std::string split_string = input.substr(counter_position, delimiter_position);
      delimiter_position += delimiter.size();
      std::string split_remaining = input.erase(counter_position, delimiter_position);
      result.push_back(split_string);
      std::vector<std::string> result_remaining = split(split_remaining, delimiter, result);
    }
    else {
      result.push_back(input);
    }
    return result;
  }
}