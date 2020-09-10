#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> A) {
  const int NUMBERS = 10;
  const int LETTERS = 30;

  bool rooms[ NUMBERS ][ LETTERS ];
  int ans = 0;
  
  for (int i = 0; i < NUMBERS; ++i)
    for (int j = 0; j < LETTERS; ++j)  
      rooms[ i ][ j ] = false;

  for (int i = 0; i < A.size(); ++i)
  {
    int number = A[ i ][ 1 ] - '0';
    int letter = A[ i ][ 2 ] - 'A';
    if( rooms[ number ][ letter ] == false ) {
      rooms[ number ][ letter ] = true;
      ++ans;
    }
  }

  //cerr << "Tip: Use cerr to write debug messages on the output tab.";
  return ans;
}

vector<string> splitAndRemoveQuotes(string s, char sep) {
  vector<string> words;
  string word;
  istringstream wordStream(s);
  while (getline(wordStream, word, sep)) {
    words.push_back(word.substr(1, word.length() - 2));
  }
  return words;
}

int main() {
  // Read from stdin, solve the problem, and write the answer to stdout.
  string input;
  cin >> input;
  string removedBrackets = input.substr(1, input.length() - 2);
  cout << solution(splitAndRemoveQuotes(removedBrackets, ','));
}
