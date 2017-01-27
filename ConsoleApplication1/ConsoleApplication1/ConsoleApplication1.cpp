// ConsoleApplication1.cpp : main project file.

#include "stdafx.h"

using namespace System;
// ConsoleApplication1.cpp : main project file.

#include "stdafx.h"
#include<string.h>
#include<string>
#include<vector>

using namespace System;
using namespace std;

public class SubstringSearch {

public:

	/*
	* Compute temporary array to maintain size of suffix which is same as prefix
	* Time/space complexity is O(size of pattern)
	*/
	int* computeTemporaryArray(char pattern[]) {
		int *lps = (int *)malloc(sizeof(int) *strlen(pattern));
		lps[0] = 0;
		int index = 0;
		for (int i = 1; i < strlen(pattern);) {
			if (pattern[i] == pattern[index]) {
				lps[i] = index + 1;
				index++;
				i++;
			}
			else {
				if (index != 0) {
					index = lps[index - 1];
				}
				else {
					lps[i] = 0;
					i++;
				}
			}
		}
		return lps;
	}

	/*
	* KMP algorithm of pattern matching.
	*/
	vector<int> KMP(char text[], char pattern[]) {
		vector<int> result;
		int *lps = computeTemporaryArray(pattern);
		int i = 0;
		int j = 0;
		while (i < strlen(text)) {
			if (j == strlen(pattern)) {
				result.push_back(i - j + 1);
				j = 0;
			}
			if (text[i] == pattern[j]) {
				i++;
				j++;
			}
			else {
				if (j != 0) {
					j = lps[j - 1];
				}
				else {
					i++;
				}
			}
		}
		return result;
	}

};

int main()
{
	char str[] = "abcxabcdabcdabcy";
	char subString[] = "abc";
	SubstringSearch ss;
	vector<int> result = ss.KMP(str, subString);
	for (int i = 0; i < result.size(); i++) {
		Console::WriteLine("Seachred String found at index: " + result.at(i));
	}
	return 0;
}
