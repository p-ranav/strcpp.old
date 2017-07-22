#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace strcpp {

  // returns length of input string
  size_t length(std::string input) {
    return input.size();
  }

  // returns true/false if input string contains search string
  bool contains(std::string input, std::string search_string, bool ignore_case = false) {
    bool result = false;
    if (ignore_case) {
      std::transform(input.begin(), input.end(), input.begin(), ::toupper);
      std::transform(search_string.begin(), search_string.end(), search_string.begin(), ::toupper);
    }
    if (input.find(search_string) != std::string::npos) {
      result = true;
    }
    return result;
  }

  // split string based on a delimiter string
  // supports multi-character delimiter
  // returns a vector of substrings after split
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