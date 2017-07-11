//============================================================================
// Name        : 337 - Interpreting Control Sequences.cpp
// Author      : ztrixack
// Copyright   : MIT License
// Description : 337 Interpreting Control Sequences in C++, Ansi-style
// Run Time    : 0.008 seconds
//============================================================================

#include <iostream>
#include <sstream>
#include <cctype>
using namespace std;
#define FRI(i, a, b) for(i = a; i < (int)b; ++i)

int main() {
	int i, j, k, n;
	int count, row, col;
	bool omode;
	string word;
	count = 1;
	while (getline(cin, word) && word != "0") {
		stringstream ss(word);
		ss >> n;
		string terminal[] = {
				"+----------+",
				"|          |",
				"|          |",
				"|          |",
				"|          |",
				"|          |",
				"|          |",
				"|          |",
				"|          |",
				"|          |",
				"|          |",
				"+----------+"
		};
		row = col = omode = 1;
		FRI (i, 0, n) {
			getline(cin, word);
			FRI (j, 0, word.size()) {
				if (word[j] == '^') {
					j++;
					if (word[j] == 'b')			  { col = 1; }
					else if (word[j] == 'c')	{ terminal[row] = "|          |"; }
					else if (word[j] == 'd')	{ if (row < 10) row++; }
					else if (word[j] == 'e')	{ FRI(k, row, 11) terminal[k].replace(col, 1, 1, ' '); }
					else if (word[j] == 'h')	{ row = col = 1; }
					else if (word[j] == 'i')	{ omode = false; }
					else if (word[j] == 'l')	{ if (col > 1)	col--; }
					else if (word[j] == 'o')	{ omode = true; }
					else if (word[j] == 'r')	{ if (col < 10)	col++; }
					else if (word[j] == 'u')	{ if (row > 1)	row--; }
					else if (isdigit(word[j]) && isdigit(word[j + 1])) {
						row = word[j] - '0' + 1;
						col = word[++j] - '0' + 1;
					}
					if (word[j] != '^') continue;
				}

				if (omode) terminal[row].erase(col, 1);
				else terminal[row].erase(10, 1);

				terminal[row].insert(col, 1, word[j]);
				if (col < 10) col++;

			}
		}
		cout << "Case " << count << endl;
		FRI (i, 0, 12) cout << terminal[i] << endl;
		count++;
	}
	return 0;
}
