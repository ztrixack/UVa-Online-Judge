//============================================================================
// Name        : 417 - Word Index.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 417 - Word Index in C++, Ansi-style
// Run Time    : 0.000 seconds
//============================================================================

#include <iostream>
#include <string>

using namespace std;

#define FRI(i, a, b)      for(i = a; i < b; ++i)

int main() {
  int i, j;
  int index, length, countX, countY;
  int mapper[30][30] = {0};
  char c, startC;
  string word;

  FRI (i, 0, 27) {
    mapper[i][0] = 1;
    FRI(j, 0, i) {
      mapper[i][j+1] = mapper[i-1][j] + mapper[i-1][j+1];
    }
  }

  while(getline(cin, word)) {
    index = 1;
    length = word.length();

    FRI(i, 1, length) {
      if(word[i] <= word[i - 1]) {
        break;
      }
    }

    if (i != length) {
      cout << 0 << endl;
      continue;
    }

    FRI(i, 0, length) {
      if (i == 0) {
        startC = 'a';
      } else {
        startC = word[i-1] + 1;
        index += mapper[26][i];
      }
      
      countX = length - i - 1;
      FRI(c, startC, word[i]){
        countY = 'z' - c;
        index += mapper[countY][countX];
      }
    }

    cout << index << endl;
  }

  return 0;
}

//============================================================================
// Name        : 417 - Word Index.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 417 - Word Index in C++, Ansi-style
// Run Time    : 0.010 seconds
//============================================================================

// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <queue>
// #include <map>

// using namespace std;

// #define FRI(i, a, b)      for(i = a; i <= b; ++i)

// int main() {
//   int index = 1;
//   char c, startC;
//   string word, newWord;
//   queue<string> wordQueue;
//   map<string, int> wordIndex;
//   map<string, int>::iterator it;

//   wordQueue.push("");

//   while(!wordQueue.empty()) {
//     word = wordQueue.front();
//     wordQueue.pop();
//     startC = word.back() + 1;
//     if (startC == 1) startC = 'a';
//     FRI(c, startC, 'z') {
//       newWord = word + c;
//       wordIndex[newWord] = index++;
      
//       if (newWord.length() == 5) continue;
//       wordQueue.push(newWord);
//     }
//   }

//   while(getline(cin, word)) {
//     it = wordIndex.find(word);
//     if (it != wordIndex.end()) cout << it->second << endl;
//     else cout << 0 << endl;
//   }

//   return 0;
// }
