#include <iostream>
#include <vector>
#include <string>

bool hasSameDifference(const std::string& str) {
    if (str.length() < 2) return true; // A string with less than 2 characters has uniform differences by default

    int diff = str[1] - str[0]; // Calculate the initial difference
    for (size_t i = 1; i < str.length() - 1; ++i) {
        if (str[i + 1] - str[i] != diff) {
            return false; // If any subsequent difference is not the same, return false
        }
    }
    return true; // If all differences are the same, return true
}

std::string findStringWithDifferentDifference(const std::vector<std::string>& strings) {
    for (size_t i = 0; i < strings.size(); ++i) {
        if (!hasSameDifference(strings[i])) {
            return strings[i]; // Return the string that does not have the same difference
        }
    }
    return ""; // Return an empty string if all strings have the same difference
}

int main() {
    std::vector<std::string> strings = {"ABC", "BCD", "DEG"};
    std::string result = findStringWithDifferentDifference(strings);

    if (!result.empty()) {
        std::cout << "The string with different differences is: " << result << std::endl;
    } else {
        std::cout << "All strings have the same differences." << std::endl;
    }

    return 0;
}
