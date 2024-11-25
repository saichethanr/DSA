#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> extractWords(const string &input) {
    vector<string> words;
    stringstream ss(input);
    string word;

    // Tokenize the string based on spaces
    while (ss >> word) {
        words.push_back(word);
    }

    return words;
}

int main() {
    string input = "This is a sample string to extract words from";
    vector<string> words = extractWords(input);

    cout << "Words extracted from the string are:" << endl;
    for (const string &word : words) {
        cout << word << endl;
    }

    return 0;
}
