// 5. Longest Palindromic Substring.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cstring>
# include <Algorithm>

using namespace std;


char s_new[30];
int p[30];

int Manacher(string s) {
	int len = 0;
	s_new[len++] = '$';
	s_new[len++] = '#';

	for (int i = 0; i < s.length; i++) {
		s_new[len++] = s[i];
		s_new[len++] = '#';
	}
	s_new[len] = '\0';
	
	int mx = 0;
	int max_len = -1;
	int id = 0;
	
	for (int i = 1; i < len; i++) {
		if (i < mx)
			p[i] = min(p[2 * id - i], mx - i);
		else
			p[i] = 1;

		while (s_new[i - p[i]] == s_new[i + p[i]])
			p[i]++;

		if (mx < i + p[i]) {
			id = i;
			mx = i + p[i];
		}

		max_len = max(max_len, p[i] - 1);
	}

	return max_len;
	
	
}

int main() {
	int max_len = 0;
	string s = "cabaef";
	
	max_len = Manacher(s);
	cout << "max_len:" << max_len << endl;
	return 0;
}

