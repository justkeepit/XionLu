#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <bitset> 
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cctype>
#include <unordered_map>
#include <sstream>

#include <cstdio>
#include <cstdlib>

using namespace std;

void local_test();

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};


