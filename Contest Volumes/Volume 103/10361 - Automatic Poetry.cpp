//============================================================================
// Name        : 10361 - Automatic.cpp
// Author      : ztrixack
// Copyright   : MIT
// Description : 110361 Automatic in C++, Ansi-style
// Run Time    : 0.008 seconds
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main () {
	int number;
	int n, fst, sec;
	string word, word1, word2;
	string s2, s3, s4, s5;
	cin >> number;
	for (int i = 0; i < number; i++) {
		word.clear();
		cin >> word1;
		getline(cin, word);
		word1 += word;
		n = word1.length();
		fst = word1.find("<");
		word1.erase(fst, 1);
		sec = word1.find(">");
		word1.erase(sec, 1);
		s2.assign(word1, fst, sec - fst);
		fst = word1.find("<");
		word1.erase(fst, 1);
		s3.assign(word1, sec, fst - sec);
		sec = word1.find(">");
		word1.erase(sec, 1);
		s4.assign(word1, fst, sec - fst);
		s5.assign(word1, sec, n - sec);
		cout << word1 << endl;
		word.clear();

		cin >> word2;
		getline(cin, word);
		word2 += word;
		fst = word2.find("...");
		word2.erase(fst, 3);
		word2.insert(fst, s5);
		word2.insert(fst, s2);
		word2.insert(fst, s3);
		word2.insert(fst, s4);
		cout << word2 << endl;
	}

}
