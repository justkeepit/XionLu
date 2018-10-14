
// Username:peng_peng
// password : Peng0peng

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

using namespace std;


int cal_min_cost(vector<int> & coins, int *parr, int total) {
	int min_index = -1;  //用于索引coins
	int min = 0xffff;
	for (int i = 0; i < coins.size(); i++) {
		int tmp = total - coins[i];
		if (tmp >= 0 && tmp<min) {
			min_index = i;
			min = tmp;
		}
	}
	return min_index;
}



int coinChange(vector<int>& coins, int amount) {
	int *arr = (int *)malloc(sizeof(int)*(amount + 1));
	memset(arr, 0, sizeof(int) * (amount + 1));
	arr[0] = 0;
	for (int i = 1; i < amount + 1; i++) {
		int t = cal_min_cost(coins, arr, i);
		if (t == -1) // 不能被转化
			arr[i] = -1;
		arr[i] = min(arr[i], 1 + arr[i - coins[t]]);
	}
	return arr[amount];
}



int count(int k) {
	if (k < 1) return 0;
	if (k == 1) return 10;
	int res = 1;
	for (int i = 9; i >= (11 - k); --i) {
		res *= i;
	}
	cout << "sssssssss  " << res * 9 << "          ";
	return res * 9;
}

int countNumbersWithUniqueDigits(int n) {
	if (n == 0) return 1;
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		res += count(i);
	}
	return res;
}

/*
Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.

Example 1:
Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.


*/
// https://blog.csdn.net/constantin_/article/details/79575638


int minSteps(int n) {
	int *dp = new int[n + 1];
	memset(dp, 0, sizeof(int)*(n + 1));

	dp[1] = 0;
	for (int i = 2; i < n + 1; i++) {
		dp[i] = (i % 2 == 0 ? (dp[i / 2] + 1) : (dp[i - 1] + 1));
		cout << "        11111111  " << "   <i>       " << i << "      " << dp[i] << "                  " << endl;
	}
	return dp[n];
}

void test3() {
	cout << "           " << minSteps(105) << "             ";
}



void test_1() {
	vector<int> p_int;
	p_int.push_back(83);

	p_int.push_back(186);
	p_int.push_back(408);
	p_int.push_back(419);

	auto num = 6249;
	int ret = coinChange(p_int, num);

	cout << "        " << "     " << ret;



}


void test2() {
	cout << countNumbersWithUniqueDigits(4);
}
void get_memory(char **p, int num) {
	*p = (char *)malloc(sizeof(char)*num);
	memset(p, 0, sizeof(char)*num);
}

char *GetMemory3(int num)
{
	char *p = (char *)malloc(sizeof(char) * num);
	return p;
}


void some_point_test() {

	//char *str[3] = {	// 是一个指针数组  数组的元素是指针 常量指针
	//	"Hello,this is a sample!",
	//	"Hi,good morning.",
	//	"Hello world"
	//};
	//char s[80];
	//strcpy(s, str[0]); //也可写成strcpy(s,*str);  
	//cout <<"1   "<< *(str+1)<<"    ";
	//strcpy(s, str[1]); //也可写成strcpy(s,*(str+1));  
	//cout << "2   " << s << "    ";

	//strcpy(s, str[2]); //也可写成strcpy(s,*(str+2)); 
	//cout << "3   " << s << "    ";

	//int array[10] = { -1,2,3,4,5,6,7,8,9 };
	//int (*ptr)[10] = &array;	    // 这是一个数组指针 指向数组的指针

	//int *base = (int *)ptr;  // ptr + 1 是数组的整个大小的移位;
	//for (int i=0;i<10;i++)
	//{
	//	cout <<"   ptr   "<< *(base+i)<<"  &arr"<< &(array[i])<<endl;
	//	cout << "   ptr   " << *(ptr+i) << "  &arr" << &(array[i]) << endl;

	//}

	/*char a[] = "hello";
	a[0] = 'X';
	cout << a << endl;

	char *p = "world";
	p[0] = 'x';
	cout << p << endl;*/

	//char* str = NULL;
	//get_memory(&str, 100);	// 能不能更改参数要看实参与调用方的关系.不是看实参与形参的类型他们的类型是一样的;
	//strcpy(str, "hello");
	//cout << "str" << str;

	//free(str);

	char *str = NULL;
	str = GetMemory3(100);
	strcpy(str, "hello");
	cout << str << endl;
	free(str);





}


void test_point() {
	some_point_test();
}


int add = 0;

void dfs(vector<vector<int>> &grid, vector<vector<int>>& visited, int i, int j, int *ret, int level) {

	if (i < 0 || j < 0)
		return;
	if (i >= grid.size() || j >= grid[0].size())
		return;
	if (grid[i][j] == 0) {
		//cout << "|||||||||||||||||" <<i<<"   "<<"  "<<j<<"          " << grid[i][j] << "||||||||||||||" << endl;  
		return;


	}
	if (!visited[i][j] == 1) {
		visited[i][j] = 1;
		if (grid[i][j] == 1) {
			add = *ret + 1;
			for (int s = 0; s<level; s++)
			{
				cout << "	";
			}
			cout << " <i,j> " << "<" << i << "," << j << ">" << "         ret        " << add << endl;

			dfs(grid, visited, i, j + 1, &add, level + 1);
			dfs(grid, visited, i - 1, j, &add, level + 1);
			dfs(grid, visited, i + 1, j, &add, level + 1);
			dfs(grid, visited, i, j - 1, &add, level + 1);

		}
	}

}


int maxAreaOfIsland(vector<vector<int>>& grid) {
	auto rows = grid.size();
	auto columns = grid[0].size();
	auto maxNum = -1;
	vector<vector<int> > visited;   // 0 代表没有被访问过
	for (auto i = 0; i < rows; i++) {
		vector<int> temp;
		for (auto j = 0; j<columns; j++)
		{
			temp.push_back(0);
		}
		visited.push_back(temp);
	}
	for (auto i = 0; i < rows; i++) {
		for (auto j = 0; j < columns; j++)
		{
			int tmp = 0;
			//int *p = &tmp;
			dfs(grid, visited, i, j, &tmp, tmp);
			cout << "o" << (tmp) << endl;
			if (add > maxNum) {
				maxNum = add;
			}
		}

	}
	return add;
}



void maxAreaOfIsland_test() {
	vector<int> a_0, a_1, a_2, a_3, a_4, a_5, a_6, a_7;
	a_0.push_back(1);
	a_0.push_back(1);
	a_0.push_back(1);
	a_0.push_back(1);
	a_0.push_back(1);
	a_0.push_back(1);
	a_0.push_back(0);
	a_0.push_back(1);
	a_0.push_back(0);
	a_0.push_back(0);
	a_0.push_back(0);
	a_0.push_back(0);
	a_0.push_back(0);



	a_1.push_back(0);
	a_1.push_back(0);
	a_1.push_back(0);
	a_1.push_back(0);
	a_1.push_back(0);
	a_1.push_back(0);
	a_1.push_back(0);
	a_1.push_back(1);
	a_1.push_back(1);
	a_1.push_back(1);
	a_1.push_back(0);
	a_1.push_back(0);
	a_1.push_back(0);


	a_2.push_back(0);
	a_2.push_back(1);
	a_2.push_back(1);
	a_2.push_back(0);
	a_2.push_back(1);
	a_2.push_back(0);
	a_2.push_back(0);
	a_2.push_back(0);
	a_2.push_back(0);
	a_2.push_back(0);
	a_2.push_back(0);
	a_2.push_back(0);
	a_2.push_back(0);



	a_3.push_back(0);
	a_3.push_back(1);
	a_3.push_back(0);
	a_3.push_back(0);
	a_3.push_back(1);
	a_3.push_back(1);
	a_3.push_back(0);
	a_3.push_back(0);
	a_3.push_back(1);
	a_3.push_back(0);
	a_3.push_back(1);
	a_3.push_back(0);
	a_3.push_back(0);


	a_4.push_back(0);
	a_4.push_back(1);
	a_4.push_back(0);
	a_4.push_back(0);
	a_4.push_back(1);
	a_4.push_back(1);
	a_4.push_back(0);
	a_4.push_back(0);
	a_4.push_back(1);
	a_4.push_back(1);
	a_4.push_back(1);
	a_4.push_back(0);
	a_4.push_back(0);


	a_5.push_back(0);
	a_5.push_back(0);
	a_5.push_back(0);
	a_5.push_back(0);
	a_5.push_back(0);
	a_5.push_back(0);
	a_5.push_back(0);
	a_5.push_back(0);
	a_5.push_back(0);
	a_5.push_back(0);
	a_5.push_back(1);
	a_5.push_back(0);
	a_5.push_back(0);


	a_6.push_back(0);
	a_6.push_back(0);
	a_6.push_back(0);
	a_6.push_back(0);
	a_6.push_back(0);
	a_6.push_back(0);
	a_6.push_back(0);
	a_6.push_back(1);
	a_6.push_back(1);
	a_6.push_back(1);
	a_6.push_back(0);
	a_6.push_back(0);
	a_6.push_back(0);

	a_7.push_back(0);
	a_7.push_back(0);
	a_7.push_back(0);
	a_7.push_back(0);
	a_7.push_back(0);
	a_7.push_back(0);
	a_7.push_back(0);
	a_7.push_back(1);
	a_7.push_back(1);
	a_7.push_back(0);
	a_7.push_back(0);
	a_7.push_back(0);
	a_7.push_back(0);


	vector<vector<int >>  cont;
	cont.push_back(a_0);
	cont.push_back(a_1);
	cont.push_back(a_2);
	cont.push_back(a_3);
	cont.push_back(a_4);
	cont.push_back(a_5);
	cont.push_back(a_6);
	cont.push_back(a_7);


	cout << "eee" << maxAreaOfIsland(cont);

}

string toLowerCase(string str) {
	for (int i = 0; i<str.size(); i++)
	{
		if (str[i] <= 'z'&&str[i] >= 'a') {
			str[i] -= 32;
		}
	}
	return str;
}

int numJewelsInStones(string J, string S) {
	int ret = 0;
	for (int i = 0; i < J.size(); i++) {
		for (int j = 0; j < S.size(); j++) {
			if (J[i] == S[j]) {
				ret++;
			}
		}
	}
	return ret;
}

void test_numJewelsInStones() {
	string J("aA");
	string S("aAAbbbb");
	cout << numJewelsInStones(J, S);
}

void test_toLowerCase() {
	string a(" djfklajfds rtrtY fdfsgjHHHH");
	cout << toLowerCase(a);
}

vector<int> sortArrayByParity(vector<int>& A) {
	int right = A.size() - 1;
	int left = 0;
	while (left <= right)
	{
		if ((A[left] % 2 == 1) && (A[right] % 2 == 0))
		{
			int temp = A[left];
			A[left] = A[right];
			A[right] = temp;
		}
		if (A[left] % 2 == 0) {
			left++;
		}
		if (A[right] % 2 == 1) {
			right--;
		}
	}
	return A;
}
void test_sortArrayByParity() {
	int arr[] = { 3,1,2,4,5 };
	vector<int> A(arr, arr + sizeof(arr) / sizeof(int));
	sortArrayByParity(A);
	for (int i : A) {
		cout << "      " << i << "          ";
	}
}

int uniqueMorseRepresentations(vector<string>& words) {
	string A[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
	set<string>	 morse_Set;
	for (string str : words)
	{
		string tmp;
		for (char i : str) {
			tmp.append(A[i - 'a']);
		}
		morse_Set.insert(tmp);
	}
	return morse_Set.size();

}

void test_uniqueMorseRepresentations() {
	string words[] = { "gin", "zen", "gig", "msg" };
	vector<string> S;
	S.push_back(words[0]);
	S.push_back(words[1]);
	S.push_back(words[2]);
	S.push_back(words[3]);
	cout << "   " << uniqueMorseRepresentations(S) << "       " << endl;
}






struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

int get_maxValue_index(vector<int> &A, int left, int right) {
	int index = left;
	int max = -0xff;
	for (int i = left; i <= right; i++)
	{
		if (max < A[i])
		{
			max = A[i];
			index = i;
		}
	}
	return index;
}

TreeNode* do_hand(vector<int>& nums, int left, int right) {
	if (left > right)
		return NULL;
	//	if (left==right)					// 定义出口
	//	{
	//		return new TreeNode(nums[left]);
	//	}
	int mid = get_maxValue_index(nums, left, right);
	TreeNode *root = new TreeNode(nums[mid]);
	root->left = do_hand(nums, left, mid - 1);	// 这样操作一定会产生left 与right的不同;
	root->right = do_hand(nums, mid + 1, right);
	return root;

}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
	TreeNode *root = do_hand(nums, 0, nums.size() - 1);
	return root;
}

void test_constructMaximumBinaryTree() {
	int arr[] = { 3, 2, 1, 6, 0, 5 };
	vector<int> A(arr, arr + sizeof(arr) / (sizeof(int)));
	constructMaximumBinaryTree(A);
}


bool is_0_tree(TreeNode *root) {
	if (root == NULL)
	{
		return true;
	}
	if (root->left == NULL&&root->right == NULL) {
		return root->val == 0;
	}
	return (root->val == 0) && is_0_tree(root->left) && is_0_tree(root->right);

}

TreeNode* pruneTree(TreeNode* root) {
	if (root == NULL)
	{
		return root;
	}
	if (is_0_tree(root)) {
		return nullptr;
	}
	if (is_0_tree(root->left))
	{
		root->left = nullptr;
	}
	if (is_0_tree(root->right))
	{
		root->right = nullptr;
	}

	TreeNode *left = pruneTree(root->left);
	TreeNode *right = pruneTree(root->right);

	return root;
}


void test_pruneTree() {
	//[1,null,0,0,1]
	TreeNode *root1 = new TreeNode(1);
	TreeNode *root2 = nullptr;
	TreeNode *root3 = new TreeNode(0);
	TreeNode *root4 = new TreeNode(0);
	TreeNode *root5 = new TreeNode(1);
	root1->left = root2;
	root1->right = root3;
	root3->left = root4;
	root3->right = root5;

	TreeNode* ret = pruneTree(root1);


	return;


}

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
	vector<vector<int>> ret;
	int row = A.size();
	int col = A[0].size();

	for (int i = 0; i < row; i++)
	{
		vector<int> a;
		for (int j = 0; j < col; j++)
		{
			a.push_back(0);
		}
		ret.push_back(a);
	}

	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j < col; j++)
		{

			ret[i][j] = (A[i][col - 1 - j] == 1 ? 0 : 1);
			cout << ret[i][j] << "   ";
		}
		cout << endl;
	}
	return ret;
}

void test_flipAndInvertImage() {
	int A[4][4] = { { 1,1,0,0 },{ 1,0,0,1 },{ 0,1,1,1 },{ 1,0,1,0 } };
	vector<vector<int>> ret;

	int row = 4;
	int col = 4;

	for (int i = 0; i < row; i++)
	{
		vector<int> a;
		for (int j = 0; j < col; j++)
		{
			a.push_back(0);
		}
		ret.push_back(a);
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			ret[i][j] = A[i][j];
		}
	}

	flipAndInvertImage(ret);
}

void test_recursion_pass(int &i, int* p)
{
	i = 100;
	//*p = 101;
	p = p + 1;
	*p = 102;
}

int binaryGap(int N) {
	int temp = N;
	int grap = 0;
	int max_grap = 0;
	bool right_1 = false;
	while (temp)
	{
		int temp1 = temp % 2;
		if (temp1 == 1)
		{
			if (!right_1)	     //是否需要更新  
				right_1 = true;
			else
				max_grap = max(max_grap, grap);
			grap = 1;   // 最小的长度是1
		}
		else
		{
			grap++;
		}
		temp /= 2;
	}
	return max_grap;


}

void test_BinaryGap() {
	int n = 22323223;
	cout << binaryGap(n) << "    ";
};


int peakIndexInMountainArray(vector<int>& A) {
	int max = 0;
	int index = -1;
	for (int i = 0; i<A.size(); i++)
	{
		if (A[i] > max) {
			max = A[i];
			index = i;
		}
	}
	return index;
}


void test_peakIndexInMountainArray() {
	vector<int> A;
	A.push_back(0);
	A.push_back(1);
	A.push_back(0);
	cout << "1  " << peakIndexInMountainArray(A);
}



TreeNode* buildTree(int N) {
	if (N == 0)
		return nullptr;
	if (N == 1) {
		return new TreeNode(0);
	}
	int left_ = 0, right_ = N - 1 - left_;

	while (left_<N)
	{
		TreeNode *root = new TreeNode(0);
		TreeNode *left = buildTree(left_);
		TreeNode *right = buildTree(right_);
		root->left = left;
		root->right = right;
		left_++;
		right_ = N - 1 - left_;
		return root;

	}


}

void test_allPossibleFBT() {
	vector <TreeNode *> pp;
	pp.push_back(buildTree(3));
	return;
}
bool myfunction(int i, int j) { return (i<j); }

int smallestRangeI(vector<int>& A, int K) {
	sort(A.begin(), A.end(), myfunction);
	int max = *(--A.end());
	int min = *A.begin();
	if (K > max)
		return 0;
	//if (K < min) {
	//	return max - min;
	//}
	int min_max = max - K;
	int max_max = max + K;
	int min_min = min - K;
	int max_min = min + K;
	if (max_min >= min_max&&max_min <= max_max)
		return 0;
	return min_max - max_min;

}


void test_smallestRangeI() {
	int a[] = { 0,10 };
	vector<int> s(a, a + sizeof(a) / sizeof(int));
	int K = 2;
	smallestRangeI(s, K);
	return;
}



struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

ListNode* middleNode(ListNode* head) {
	if (head == NULL)
	{
		return NULL;
	}
	ListNode *fast;
	fast = head;
	ListNode *slow = head;
	while (fast) {
		if (fast->next)
		{
			fast = fast->next;
			slow = slow->next;
		}
		fast = fast->next;
	}
	return slow;
}

void test_middleNode() {
	// [1, 2, 3, 4, 5]
	ListNode *pa = new ListNode(1);
	ListNode *pb = new ListNode(2);
	ListNode *pc = new ListNode(3);
	ListNode *pd = new ListNode(4);
	ListNode *pe = new ListNode(5);
	ListNode *pf = new ListNode(6);


	pa->next = pb;
	pb->next = pc;
	pc->next = pd;
	pd->next = pe;
	pe->next = pf;
	cout << middleNode(pa)->val;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> ans;
	int m = matrix.size();
	if (m == 0)
		return ans;
	int n = matrix[0].size();

	int K = min(m, n) - 2;
	if (K < 0) {
		if (m == 1)
			return matrix[0];
		if (n == 1) {
			for (int i = 0; i<m; i++)
			{
				ans.push_back(matrix[0][i]);
			}
			return ans;
		}
	}
	vector<vector<int>> ss;
	for (int i = 0; i<m; i++)
	{
		vector<int >t;
		for (int j = 0; j < n; j++) {
			t.push_back(1);
		}
		ss.push_back(t);
	}
	int index_K = 0;
	while (index_K <= K) {
		for (int i = index_K; i<n - index_K - 1; i++)
		{

			if (ss[index_K][i] == 1)
			{
				cout << index_K << "  " << i << "         ";
				cout << "D        $$$$$$          " << matrix[index_K][i] << endl;

				ans.push_back(matrix[index_K][i]);
				ss[index_K][i] = 0;
			}
		}

		for (int i = index_K; i < m - index_K; i++)
		{

			//	ans.push_back(matrix[i][n - 1 - index_K]);
			if (ss[i][n - 1 - index_K] == 1) {

				cout << i << "  " << n - 1 - index_K << "         ";
				cout << "C        $$$$$$          " << matrix[i][n - 1 - index_K] << endl;

				ans.push_back(matrix[i][n - 1 - index_K]);
				ss[i][n - 1 - index_K] = 0;
			}

		}

		for (int i = n - index_K - 1 - 1; i > index_K; i--)
		{

			if (ss[m - 1 - index_K][i] == 1) {

				cout << m - 1 - index_K << "  " << i << "         ";
				cout << "B        $$$$$$          " << matrix[m - 1 - index_K][i] << endl;


				ans.push_back(matrix[m - 1 - index_K][i]);
				ss[m - 1 - index_K][i] = 0;
			}
		}

		for (int i = m - 1 - index_K; i > index_K; i--)
		{

			if (ss[i][index_K] == 1) {

				cout << i << "  " << index_K << "         ";
				cout << "A        $$$$$$          " << matrix[i][index_K] << endl;



				ans.push_back(matrix[i][index_K]);
				ss[i][index_K] = 0;
			}
		}

		index_K++;

	}
	return ans;
}

void test_spiralOrder() {

	int a[] = { 2,  3,  4 };
	int b[] = { 5,  6 , 7 };
	int c[] = { 8,  9 , 10 };
	int d[] = { 11, 12 , 13 };


	vector<int > A(a, a + sizeof(a) / sizeof(int));
	vector<int > B(b, b + sizeof(b) / sizeof(int));
	vector<int > C(c, c + sizeof(c) / sizeof(int));
	vector<int > D(d, d + sizeof(d) / sizeof(int));

	vector <vector<int>> pp;
	pp.push_back(A);
	pp.push_back(B);
	pp.push_back(C);
	pp.push_back(D);

	vector<int> ss = spiralOrder(pp);
	return;
}



TreeNode* searchBST(TreeNode* root, int val) {
	if (root == NULL)
	{
		return root;
	}
	if (root->left == NULL&&root->right == NULL) {
		if (root->val == val)
			return root;
		else
			return NULL;
	}
	if (val < root->val) {
		return searchBST(root->left, val);
	}
	else if (val > root->val) {
		return searchBST(root->right, val);
	}
	else
		return root;

}


void test_searchBST() {
	//void
}

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};



/*void postorder(Node* root, vector<int> &ans) {

if (root == NULL)
{
return;
}
if (root && (root->children.empty())) {
cout << "   1111111      " << root->val;
ans.push_back(root->val);
return;
}

for (int i = 0; i<root->children.size(); i++)
{
postorder(root->children[i], ans);
}
cout << "   222222      " << root->val;

ans.push_back(root->val);
}*/

void test_postorder() {
	Node *p_5 = new Node(5, {});
	Node *p_6 = new Node(6, {});
	vector<Node *>ss;
	ss.push_back(p_5);
	ss.push_back(p_6);
	Node *p_3 = new Node(3, ss);
	Node *p_2 = new Node(2, {});
	Node *p_4 = new Node(4, {});
	vector <Node *>pp;
	pp.push_back(p_3);
	pp.push_back(p_2);
	pp.push_back(p_4);
	Node *p_1 = new Node(1, pp);



	vector<int >tt;
	//	postorder(p_1, tt);
	return;


}





int maxDepth(Node* root) {
	if (root == NULL)
	{
		return 0;
	}
	if (root->children.empty())
		return 1;
	int max = -1;
	for (int i = 0; i<root->children.size(); i++)
	{
		int children_depth = maxDepth(root->children[i]);
		if (children_depth > max) {
			max = children_depth;
		}
	}
	return max + 1;
}


void test_maxDepth() {
	Node *p_5 = new Node(5, {});
	Node *p_6 = new Node(6, {});
	vector<Node *>ss;
	ss.push_back(p_5);
	ss.push_back(p_6);
	Node *p_3 = new Node(3, ss);
	Node *p_2 = new Node(2, {});
	Node *p_4 = new Node(4, {});
	vector <Node *>pp;
	pp.push_back(p_3);
	pp.push_back(p_2);
	pp.push_back(p_4);
	Node *p_1 = new Node(1, pp);



	vector<int >tt;
	int er = maxDepth(p_1);

	return;
}



void preorder(Node* root, vector<int> &ans) {
	if (root == NULL)
	{
		return;
	}

	if (root && (root->children.empty())) {
		cout << "   1111111      " << root->val;
		ans.push_back(root->val);
		return;
	}

	ans.push_back(root->val);


	for (int i = 0; i < root->children.size(); i++)
	{
		preorder(root->children[i], ans);
	}


}


void test_preorder() {
	Node *p_5 = new Node(5, {});
	Node *p_6 = new Node(6, {});
	vector<Node *>ss;
	ss.push_back(p_5);
	ss.push_back(p_6);
	Node *p_3 = new Node(3, ss);
	Node *p_2 = new Node(2, {});
	Node *p_4 = new Node(4, {});
	vector <Node *>pp;
	pp.push_back(p_3);
	pp.push_back(p_2);
	pp.push_back(p_4);
	Node *p_1 = new Node(1, pp);



	vector<int >tt;
	preorder(p_1, tt);

	return;
}


vector<int> pick_odd_char(string A) {
	vector<int> char_dict(26, 0);

	for (int i = 1; i < A.size(); i += 2) {
		char_dict[A[i] - 'a'] = 1;
	}
	return char_dict;
}

vector<int> pick_even_char(string A) {
	vector<int> char_dict(26, 0);
	for (int i = 0; i < A.size(); i += 2) {
		char_dict[A[i] - 'a'] = 1;
	}
	return char_dict;
}

bool Equ(string A, string B) {
	vector<int> odd_A = pick_odd_char(A);
	vector<int> odd_B = pick_odd_char(B);

	vector<int> even_A = pick_even_char(A);
	vector<int> even_B = pick_even_char(B);

	return odd_A == odd_B && even_A == even_B;

}

int numSpecialEquivGroups(vector<string>& A) {
	if (A.empty())
		return 0;
	vector<vector<string>> pp;
	for (int i = 0; i<A.size(); i++)
	{
		vector<string> s;
		s.push_back(A[i]);
		for (int j = i + 1; j<A.size(); j++)
		{
			if (!Equ(A[i], A[j]))
			{
				s.push_back(A[j]);
			}
		}
		pp.push_back(s);
	}

	return pp.size();
}



void test_numSpecialEquivGroups() {
	// 	string A("abcd");
	// 	string B("cdab");
	// 	string C("adcb");
	// 	string D("cbad");
	string A("aa");
	string B("bb");
	string C("ab");
	string D("ba");
	// 	string A("abc");
	// 	string B("acb");
	// 	string C("bac");
	// 	string D("bca");
	// 	string E("cab");
	// 	string F("cba");


	vector<string > pp;
	pp.push_back(A);
	pp.push_back(B);
	pp.push_back(C);
	pp.push_back(D);
	// 	pp.push_back(E);
	// 	pp.push_back(F);
	cout << "111  " << numSpecialEquivGroups(pp);
}


vector<string> uncommonFromSentences(string A, string B) {
	return{};
}

vector<string> split_string_vec(string A) {
	vector<string> ans;
	for (int i = 0; i<A.size(); i++)
	{
		while (A[i] == ' ')
		{
			i++;
			if (i >= A.size())
				break;
		}
		if (i >= A.size())
			break;
		string tmp("");
		while (A[i] != ' ')
		{
			tmp.push_back(A[i]);
			i++;
			if (i >= A.size())
				break;
		}
		if (i >= A.size())
			break;
		if (tmp != "")
			ans.push_back(tmp);

	}
	return ans;
}

void test_uncommonFromSentences() {
	// 	string A("apple apple");
	// 	string B("banana");
	// 	vector<string> aa =  split_string_vec("  q ee eq et q   ");
	// 	set<map<string,int>> sss;
	// 	for (int i=0;i<aa.size();i++)
	// 	{
	// 		sss.insert(aa[i]);
	// 	}
	map<char, int> key_compare;
	key_compare.insert(pair<char, int>('a', 100));
	if (key_compare.count('a')>0)
	{
		//key_compare.erase('a');
		key_compare.insert(pair<char, int>('a', key_compare.count('a') + 1));
	}

	for (auto it = key_compare.begin(); it != key_compare.end(); it++)
	{
		// map的迭代器，可以用 first 访问std::pair的第一个成员(Type1)，second 访问第二个成员 (Type2)
		cout << it->first << ":" << it->second << endl;
	}
	cout << "=================================" << endl;



	return;
}

vector<int> dailyTemperatures(vector<int>& temperatures) {
	vector<int> ans(temperatures.size(), 0);
	for (int i = 0; i<temperatures.size(); i++)
	{
		for (int j = i + 1; j<temperatures.size(); j++)
		{
			if (temperatures[j]>temperatures[i])
			{
				ans[i] = (j - i);
				break;
			}
		}
	}
	return ans;
}

void test_dailyTemperatures() {
	int te[] = { 73, 74, 75, 71, 69, 72, 76, 73 };
	vector<int >ss(te, te + sizeof(te) / sizeof(int));
	vector<int> kk = dailyTemperatures(ss);
	return;
}


int singleNonDuplicate(vector<int>& nums) {
	int front, back;
	front = 0;
	back = 1;
	int index = back;
	while (back<nums.size())
	{
		if (nums[front] == nums[back]) {
			front += 2;
			index += 2;
			back += 2;
		}
		else {
			index += 1;
			if (nums[index] == nums[back])
			{
				return nums[front];
			}

		}
	}
	return nums[nums.size() - 1];
}

void test_singleNonDuplicate() {
	int te[] = { 3,3,7,7,9 };
	vector<int >ss(te, te + sizeof(te) / sizeof(int));
	int kk = singleNonDuplicate(ss);
	return;
}


vector<int> shortestToChar(string S, char C) {
	vector<int> tt;
	vector<int> ans;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == C)
			tt.push_back(i);
	}

	//int index_1 = tt[0];
	int index_1 = -1;
	int index_2 = tt[0];
	bool mid_index = false;
	for (int k = 0, i = 0; k<S.size(); k++)	 // 在两边的只需要使用一个值去判断 在中间的要两个值	默认index_1 <= index_2
	{
		if (S[k] == C && i == 0) // 第一次遇见C	   使用 index_2 判断
		{
			index_1 = index_2;
			index_2 = tt[++i];
			ans.push_back(0);
			cout << S[k] << "   1: " << index_1 << "    _2: " << index_2 << "  k :  " << k << " ans " << ans[k] << endl;
			continue;
		}
		if (S[k] == C && i == tt.size() - 1) // 最后一次遇见C		 使用 index_1 判断
		{
			index_1 = index_2;
			index_2 = 1;
		}


		if (abs(k - index_1)<abs(k - index_2)) // 离index1 近一点
		{
			ans.push_back(k - index_1);
		}

		else {  // 	 离index2 近一点
			ans.push_back(index_2 - k);
		}
		cout << S[k] << "    index_1: " << index_1 << " index_2: " << index_2 << "  k :  " << k << " ans " << ans[k] << endl;


	}
	return ans;
}

void test_shortestToChar() {
	string s("loveleetcode");
	vector<int> hh = shortestToChar(s, 'e');
	return;
}



bool hasAlternatingBits(int n) {

	while (n)
	{
		int A = n % 2;
		int B = n / 2 % 2;
		if (A^B == 0)
			return false;
		n /= 2;
	}
	return true;

}

void test_hasAlternatingBits() {
	cout << "   1   " << hasAlternatingBits(5);
}

int isPrimeNum(int n) {
	if (n < 2)
	{
		//小于2的数即不是合数也不是素数  
		return false;
	}
	for (int i = 2; i < n / 2 + 1; ++i)
	{
		cout << "      iiiiiiii      " << i << endl;
		// 和比它的一半小数相除，如果都除不尽，证明素数  
		if (0 == n % i)
		{
			// 除尽了，合数  
			return false;
		}
	}
	return true; // 都没除尽，素数  
}

int setBitsNum(int i) {
	int ans = 0;
	while (i) {
		int k = i % 2;
		if (k == 1)
			ans++;
		i /= 2;
	}
	return ans;
}

int countPrimeSetBits(int L, int R) {
	int ans = 0;
	for (int i = L; i <= R; i++)
	{
		int k = setBitsNum(i);
		cout << "111111         " << k << endl;

		if (isPrimeNum(k))
		{
			ans++;
		}
	}
	return ans;
}

void test_countPrimeSetBits() {
	cout << "111111";
	cout << " t      111111111111111111111 " << countPrimeSetBits(244, 269);
}



vector<double> averageOfLevels(TreeNode* root) {
	queue<TreeNode *> tree;
	vector<double> ans;
	tree.push(root);
	while (!tree.empty()) {
		int cnt = tree.size();   // 要引进这个变量 这样下面的就不会循环出去了 包含在for循环里面;
		cout << "xxxxxxxx" << cnt << endl;
		double sum = 0;

		for (int i = 0; i<cnt; i++)
		{
			TreeNode *rr = tree.front();
			sum += rr->val;
			tree.pop();
			if (rr->left)
			{
				tree.push(rr->left);
			}
			if (rr->right)
			{
				tree.push(rr->right);
			}
		}
		ans.push_back(sum / cnt);
	}

	return ans;
}

void test_averageOfLevels() {
	TreeNode *root3 = new TreeNode(3);
	TreeNode *root9 = new TreeNode(9);
	TreeNode *root20 = new TreeNode(20);
	TreeNode *root15 = new TreeNode(15);
	TreeNode *root7 = new TreeNode(7);
	root3->left = root9;
	root3->right = root20;
	root20->left = root15;
	root20->right = root7;
	vector<double> gg = averageOfLevels(root3);
}
/*
Input: pre = [1, 2, 4, 5, 3, 6, 7], post = [4, 5, 2, 6, 7, 3, 1]
Output : [1, 2, 3, 4, 5, 6, 7]

*/

TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
	return nullptr;
}

void test_constructFromPrePost() {

}

bool isIncreasing(vector<int >A) {
	for (int i = 0; i<A.size() - 1; i++)
	{
		if (A[i]>A[i + 1])
		{
			return false;
		}
	}
	return true;
}

bool isDecreaing(vector<int >A) {
	for (int i = 0; i < A.size() - 1; i++)
	{
		if (A[i] < A[i + 1])
		{
			return false;
		}
	}
	return true;
}

bool isMonotonic(vector<int>& A) {
	return isDecreaing(A) || isIncreasing(A);
}

void test_isMonotonic() {
	int a[] = { 6,5,4,4 };
	vector<int > ss(a, a + sizeof(a) / sizeof(int));
	cout << " 1111111   " << isMonotonic(ss);
}

bool isPalindromicString(string A) {
	int left = 0;
	int right = A.size() - 1;
	while (left <= right)
	{
		if (A[left] != A[right])
		{
			return false;
		}
		left++;
		right--;
	}
	return true;
}

int countSubstrings(string s) {
	int ans = 0;
	for (int i = 0; i<s.size(); i++)
	{
		for (int j = i; j<s.size(); j++)
		{
			string substring = s.substr(i, j - i + 1);
			cout << " 111  " << substring << endl;
			if (isPalindromicString(substring))
			{
				ans++;
			}
		}
		cout << "  33333  " << endl;
	}
	return ans;
}

void  test_countSubstrings() {
	string a("abc");
	cout << "   2222222   " << countSubstrings(a);
}

double calTriangleArea(double a, double b, double c) {
	double p = (a + b + c) / 2;
	double pp = p*(p - a)*(p - b)*(p - c);
	return sqrt(pp);

}

double cal_dis(double ax, double ay, double bx, double by) {
	return sqrt((ax - bx)*(ax - bx) + (ay - by)*(ay - by));
}

double largestTriangleArea(vector<vector<int>>& points) {
	double ans = 0.0;
	for (int i = 0; i<points.size(); i++)
	{
		for (int j = i + 1; j<points.size(); j++)
		{
			for (int k = j + 1; k<points.size(); k++)
			{
				double ij = cal_dis(points[i][0], points[i][1], points[j][0], points[j][1]);
				double jk = cal_dis(points[j][0], points[j][1], points[k][0], points[k][1]);
				double ki = cal_dis(points[k][0], points[k][1], points[i][0], points[i][1]);
				double	aaaaa = calTriangleArea(ij, jk, ki);
				if (aaaaa>ans)
				{
					ans = aaaaa;
				}

			}
		}
	}

	return ans;
}

void test_largestTriangleArea() {
	int a[] = { 0, 0 };
	int b[] = { 0, 1 };
	int c[] = { 1, 0 };
	int d[] = { 0, 2 };
	int e[] = { 2, 0 };

	vector<int >a_(a, a + sizeof(a) / sizeof(int));
	vector<int >b_(b, b + sizeof(b) / sizeof(int));
	vector<int >c_(c, c + sizeof(a) / sizeof(int));
	vector<int >d_(d, d + sizeof(a) / sizeof(int));
	vector<int >e_(e, e + sizeof(a) / sizeof(int));

	vector<vector<int >>yy;
	yy.push_back(a_);
	yy.push_back(b_);
	yy.push_back(c_);
	yy.push_back(d_);
	yy.push_back(e_);
	cout << "    11111111        " << largestTriangleArea(yy);
}




void letterCasePermutation_helper(string S, int level, vector<string> &ans) {
	if (level == S.size())
	{
		for (int i = 0; i < ans.size(); i++)
		{
			cout << "   111   " << ans[i];
		}
		return;
	}

	if (isalpha(S[level]))
	{
		for (int i = 0; i < 2; i++) {
			string  ss(ans[i]);
			ans[i].push_back(S[level] + ('a' - 'A')*i);
		}
	}
	else {

	}
	letterCasePermutation_helper(S, level + 1, ans);



}




vector<string> letterCasePermutation(string S, int level) {
	return{};
}


void test_letterCasePermutation() {

}




int scoreOfParentheses(string S) {
	stack<char >ss;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == '(') {
			ss.push(S[i]);
		}
		else if (S[i] == ')') {
			ss.push(S[i]);
			char c = ss.top();
			if (c==')')
			{
				ss.pop();
				ss.push('1');
			}
			else if (isdigit(c))
			{
				ss.pop();
				if (ss.top() == '(')
				{
					ss.push((c - '0') * 2 + '0');
				}
				else if (isdigit(ss.top()))
				{
					char d = (ss.top() - '0')*(c - '0') + '0';
					ss.pop();
					ss.push(d);
				}
			}
		}
	}
	while (!ss.empty())
	{
		cout << ss.top();
		ss.pop();
	}
	return 0;
}




void test_scoreOfParentheses() {
	string ss("(()(()))");
	scoreOfParentheses(ss);
}



string frequencySort(string s) {
//unordered_map<char, int> ss;
//for (auto c : s)
//{
//	ss[c]++;
//}
//sort(ss.begin(), ss.end(), [](const pair<char, int> &x, const pair<char, int> &y) -> int {
//	return x.second >= y.second;
//});
	return s;
}
		    

void test_frequencySort() {
//	frequencySort("bbAa");
	return;
}

void test_sttttt()
{
	unordered_map<int, int> iMap;
	iMap[1] = 20;
	iMap[2] = 10;
	iMap[5] = 30;
	iMap[4] = 0;

	vector<pair<int, int>> vtMap;
	for (auto it = iMap.begin(); it != iMap.end(); it++)
		vtMap.push_back(make_pair(it->first, it->second));

	sort(vtMap.begin(), vtMap.end(),
		[](const pair<int, int> &x, const pair<int, int> &y) -> int {
		return x.second < y.second;
	});

	for (auto it = vtMap.begin(); it != vtMap.end(); it++)
		cout << it->first << ':' << it->second << '\n';
	return;

}

void test_sort()
{
	test_sttttt();
}


void backTracking(vector<vector<int>>& permus, vector<int>& curr, vector<bool>& visted, vector<int>& nums) {
	if (curr.size() == nums.size()) {
		permus.push_back(curr);
		return;
	}
	for (int i = 0; i<nums.size(); ++i) {
		if (visted[i] == false) {
			visted[i] = true;
			curr.push_back(nums[i]);
			backTracking(permus, curr, visted, nums);
			// visted[i] = false;
			// curr.pop_back();
		}
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> permus;
	if (nums.size() == 0)  return  permus;
	vector<bool> visted(nums.size(), false);
	vector<int> curr;   //记录当前层的排列
	backTracking(permus, curr, visted, nums);
	return permus;
}



vector<int> ret;

bool is_in(int k) {
	for (int i = 0; i < ret.size(); i++) {
		if (ret[i] == k)
			return true;
	}
	return false;
}

void permute_t(int nums, int level, int i) {
	if (level == nums) {
		for each (int s in ret)
		{
			cout << " " << s;
		}
		cout << endl;
		//return;
	}
	for (int i = 0; i<nums; i++)
	{
		if (!is_in(i))
		{
			ret.push_back(i);
			permute_t(nums, level + 1, i);
		}
		else
		{
			ret.pop_back();
		}
	}
}

void test_backtraceing() {
	vector<int> YY;
	YY.push_back(1);
	YY.push_back(2);
	YY.push_back(3);
	
	//permute_t(3, 0, 0);

	permute(YY);



}

int main() {
	//std::cout << "hello?";
	//test_1();
	//test_point();
	//maxAreaOfIsland_test();

	/*int  y = 10;
	int& s = y;*/
	//int *p = &y;
	//test_recursion_pass(s,&y);
	test_backtraceing();

	//test_BinaryGap();
	//cout << s;
	//test_toLowerCase();
	//test_numJewelsInStones();
	//test_sortArrayByParity();
	//test_uniqueMorseRepresentations();
	//test_constructMaximumBinaryTree();
	//test_flipAndInvertImage();
	//test_pruneTree();
	//test_peakIndexInMountainArray();
	//test_allPossibleFBT();
	//test_smallestRangeI();
	//test_middleNode();
	//test_spiralOrder();
	//test_searchBST();
	//test_postorder();
	//test_maxDepth();
	//test_preorder();
	//test_numSpecialEquivGroups();	   ?
	//test_uncommonFromSentences();    ?
	//test_dailyTemperatures();
	//test_singleNonDuplicate();
	//test_shortestToChar(); ?
	//test_hasAlternatingBits();
	//test_countPrimeSetBits();
	//test_averageOfLevels();
	//test_constructFromPrePost(); ?
	//test_isMonotonic();
	//test_countSubstrings();
	//test_largestTriangleArea();	 
	//test_letterCasePermutation();	 ?
	//test_scoreOfParentheses();		 ?
	//cout << "cbc";
	//test_frequencySort();
	//test_sort();
	return 0;
}







