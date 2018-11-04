
// Username:peng_peng
// password : Peng0peng

#include "head.h"

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

int maxAreaOfIsland(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i_row, int j_column)
{

	int ret = 0;
	if (i_row<0 || i_row>=grid.size())
	{
		return 0;
	}
	if (j_column < 0 || j_column>=grid[0].size())
	{
		return 0;
	}

	cout <<" "<< grid[i_row][j_column];
	if (i_row==grid.size()-1&&j_column==grid[0].size()-1)
	{
		cout << endl << endl;
	}

	if (!visited[i_row][j_column]&&grid[i_row][j_column])
	{
	    visited[i_row][j_column] = true;	
		
			int a = maxAreaOfIsland(grid, visited, i_row - 1, j_column);
		
		
			int b = maxAreaOfIsland(grid, visited, i_row + 1, j_column);
			
		
		     int c = maxAreaOfIsland(grid, visited, i_row, j_column - 1);
		
		
			 int d = maxAreaOfIsland(grid, visited, i_row, j_column + 1);
			
		ret += 1;
		ret += (a + b + c + d);
	}

	return ret;
}

void test_maxAreaOfIsland()
{
	int A[8][13] = {
		{ 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
		{ 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0 },
		{ 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 }
	};




		//int a[8][13] = {
		//	{ 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 },
		//	{ 20, 21, 22, 23, 24 ,25 ,26, 27, 28, 29 ,30 ,31, 32 },
		//	{ 30, 31, 32, 33, 34 ,35 ,36, 37, 38, 39 ,40 ,41, 42 },
		//	{ 40, 41, 42, 43, 44 ,45 ,46, 47, 48, 49 ,50 ,51, 52 },
		//	{ 50, 51, 52, 53, 54 ,55 ,56, 57, 58, 59 ,60 ,61, 62 },
		//	{ 60, 61, 62, 63, 64 ,65 ,66, 67, 68, 69 ,70 ,71, 72 },
		//	{ 70, 71, 72, 73, 74 ,75 ,76, 77, 78, 79 ,80 ,81, 82 },
		//	{ 80, 81, 82, 83, 84 ,85 ,86, 87, 88, 89 ,90 ,91, 92 },
		//};


	/*int A[4][4] = {
		{ 10, 11, 12, 13, },
		{ 20, 21, 22, 23, },
		{ 30, 31, 32, 33, },
		{ 40, 41, 42, 43, },
	};*/


	


	vector<vector<int >	>grid;
	vector<vector<bool> >visited;

	for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
	{
		vector<int > tt;
		vector<bool> kk;
		for (int j = 0; j < sizeof(A[i]) / sizeof(int); j++)
		{

			tt.push_back(A[i][j]);
			kk.push_back(false);

		}
		grid.push_back(tt);
		visited.push_back(kk);
	}
	int ans = 0;


	int m = grid.size();
	int n = grid[0].size();

	int maxValue = 0;
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			maxValue = max(maxValue, maxAreaOfIsland(grid, visited, 0, 0));

		}
	}





	return ;

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


void letterCasePermutation_helper(string S, int level, vector<string> &ans,string &curr) {
	if (S.size() == curr.size())
	{
		ans.push_back(curr);
		cout << "  111  " << curr<<endl;
		return;
	}

	if (isalpha(S[level]))
	{
		for (int i = 0; i < 2; i++) {
			curr.append(string(1, char(('A' - 'a')*i + S[level])));
			letterCasePermutation_helper(S, level + 1, ans,curr);
			curr.pop_back();			
		}
	}
	else {
			curr.append(string(1, S[level]));
			letterCasePermutation_helper(S, level + 1, ans, curr);
			curr.pop_back();	
	}

}

string upper_char(string S)
{
	string ans;
	for (auto c : S)
	{
		if (isupper(c))
		{
			ans.push_back('a' - 'A' + c);
		}
		else
		{
			ans.push_back(c);
		}
	}
	return ans;
}


vector<string> letterCasePermutation(string S) {
	vector<string >ss;
	string ttttttt;
	S = upper_char(S);
	letterCasePermutation_helper(S, 0, ss,ttttttt);
	return ss;
}


void test_letterCasePermutation() {
	letterCasePermutation("CaadD");
	return;
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
	unordered_map<char, int> ss;
	for (auto c : s)
	{
		ss[c]++;
	}
//	sort(ss.begin(), ss.end(), [](pair<char, int> &x,  pair<char, int> &y) -> int {
//		return x.second >= y.second;
//	});
	return s;
}
		    

void test_frequencySort() {
	frequencySort("bbAa");
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

void countArrangement_help(vector<vector<int>> &con, vector<int>& curr, vector<bool>&visited, int level,int N,int & cnt)
{
	if (curr.size()==N-1)
	{
		cnt++;
		return;
	}
	for (int i=1;i<N;i++)
	{
		if (!visited[i]&&(i%level==0||level%i==0))
		{
			visited[i] = true;
			curr.push_back(i);
			countArrangement_help(con, curr, visited, level + 1, N,cnt);
			curr.pop_back();
			visited[i] = false;
		}
	}

}

int countArrangement(int N) {
	vector<int> ss;
	int level = 1;
	vector<vector<int> >con;
	vector<bool> visited(N+1, false);
	int cnt = 0;
	countArrangement_help(con,ss,visited,level,N+1,cnt);
	return cnt;
}

void test_countArrangement()
{
	int c = countArrangement(6);
	cout << "     1111111  " << c;
}

void generateParenthesis_helper(int n,vector<string>&ans,string &ss,int level,int left,int right)
{
	if (n==ss.size())
	{
		if (left==right)	  // if 只能在中间不能和上一个if条件等价起来.
		{
			ans.push_back(ss);
		}
		
		return;
	}

	if(right>left)	  
	{
		return;
	}
	

	if(level!=0)
	{
		ss.push_back(')');
		generateParenthesis_helper(n, ans, ss, level + 1,left,right+1);
		ss.pop_back();
	}
	if (level!=n-1)
	{
		ss.push_back('(');
		generateParenthesis_helper(n, ans, ss, level + 1,left+1,right);
		ss.pop_back();
	}
}

vector<string> generateParenthesis()
{
	int N = 12;
	vector<string> ans;
	string str;
	int level = 0;
	generateParenthesis_helper(N, ans, str, level,0,0);

	return ans;
}

/*
vector<vector<int>> combinationSum3(int k, int n) {

}



void test_combinationSum3()
{

}


 */

bool stoneGame(vector<int> stone)
{
	vector<int> ret(0, stone.size() / 2);
	for (int i=0;i<stone.size();i++)
	{
		
	}
	return false;
}

void test_stoneGame() {
	int t[] = { 5,3,5,5 };
	vector<int> ss(t , t+sizeof(t)/sizeof(int));

//	bool ret = stoneGame();
	
}

vector<vector<int>> handler_vector_duplicates(vector<vector<int>>& in)
{
	vector<vector<int>> out;
	if (in.size() == 0)
		return out;
	sort(in[0].begin(), in[0].end());
	out.push_back(in[0]);
	for (int i=0;i<in.size()-1;i++)
	{
	  sort(in[i+1].begin(), in[i+1].end());
	  if (in[i]!=in[i+1])
	  {
		  out.push_back(in[i+1]);
	  }
	}
	return out;
}


void combinationSum_helper(vector<vector<int>> & YY, vector<int>& candidates, int target, int start, vector<int>& curr, int& sum)
{

	if (sum == target)
	{
		YY.push_back(curr);
		return;
	}
	if (sum>target)
	{
		return;
	}

	for (int i = start; i<candidates.size(); i++)
	{
		sum += candidates[i];
		curr.push_back(candidates[i]);
		combinationSum_helper(YY, candidates, target, i, curr, sum);
		curr.pop_back();
		sum -= candidates[i];
	}
}
void test_combinationSum()
{

//int a[] = { 2,3,3 };
//int b[] = { 3,2,3 };
//int c[] = { 3,3,2 };
//
//vector<int> y1(a, a + sizeof(a) / sizeof(int));
//vector<int> y2(b, b + sizeof(b) / sizeof(int));
//vector<int> y3(c, c + sizeof(c) / sizeof(int));
//
//vector<vector<int>> sss;
//sss.push_back(y1);
//sss.push_back(y2);
//sss.push_back(y3);
	int stt[] = { 2,3,5 };
	vector<int> candidates(stt,stt+sizeof(stt)/sizeof(int));
	
	int target = 7;
	vector<vector<int>> YY;
	vector<int> curr;
	int sum = 0;
	combinationSum_helper(YY,candidates, target,0,curr,sum);
	
	return;
}
void combinationSum2_helper(vector<vector<int>> & YY, vector<int>& candidates, int target, vector<int>& curr, int& sum, vector<bool>& visited,int lastValue)
{
//	sort(candidates.begin(), candidates.end());
	if (sum == target)
	{
		YY.push_back(curr);
		return;
	}
	if (sum>target)
	{
		return;
	}
 
    for (int i = 0; i<candidates.size(); i++)
	{
		if (candidates[i]==lastValue)
		{
			continue;
		}
		if (!visited[i])
		{
			visited[i] = true;
			sum += candidates[i];
			curr.push_back(candidates[i]);
			combinationSum2_helper(YY, candidates, target, curr, sum, visited, candidates[i]);
			curr.pop_back();
			sum -= candidates[i];
			visited[i] = false;

		}

	}
   
}

void test_combinationSum2()
{
	int stt[] = { 1,1,6 };
	vector<int> candidates(stt, stt + sizeof(stt) / sizeof(int));

	int target = 8;
	vector<vector<int>> YY;
	vector<int> curr;
	int sum = 0;
	sort(candidates.begin(), candidates.end());


	vector<bool> visited(candidates.size(), false);
	combinationSum2_helper(YY, candidates, target, curr, sum,visited,-1);

	return;
}


void backTracking(vector<vector<int>>& permus, vector<int>& curr, vector<bool>& visted, vector<int>& nums) {
	if (curr.size() == nums.size()) {
		permus.push_back(curr);
		return;
	}
	for (auto i = 0; i<nums.size(); ++i) {
		if (!visted[i]) {
			visted[i] = true;
			curr.push_back(nums[i]);
			backTracking(permus, curr, visted, nums);
			//这两步很重要的,恢复成原来的样子,这就是回溯法的要点.
			visted[i] = false;
			curr.pop_back();	   
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
			ret.pop_back();
		}
		
	}
}

void test_backtraceing() {
	vector<int> YY;
	YY.push_back(1);
	YY.push_back(2);
	YY.push_back(3);
	
	permute_t(12, 0, 0);

	//permute(YY);



}





TreeNode* subtreeWithAllDeepest(TreeNode* root) {
	if (!root)
	{
		return nullptr;
	}
	
}

void test_subtreeWithAllDeepest()
{
	
}




int minimumDeleteSum1(string s1, string s2) 
{
	int m = s1.size();
	int n = s2.size();

	vector<vector<int>> dp(m,vector<int>(n, 0));

	if (s1[0]!=s2[0])
	{
		dp[0][0] = s1[0] + s2[0];
	}
	else
	{
		dp[0][0] = 0;
	}

	for (int i=1;i<m;i++)
	{
		if (s2[0]!=s1[i])
		{
			dp[i][0] = dp[i - 1][0] + s1[i];
		}
		else
		{
			dp[i][0] = dp[i - 1][0];
		}
	}

	for (int j = 1; j<n; j++)
	{
		if (s1[0] != s2[j])
		{
			dp[0][j] = dp[0][j-1] + s2[j];
		}
		else
		{
			dp[0][j] = dp[0][j-1];
		}
	}

	for (int i=1;i<m;i++)
	{
		for (int j=1;j<n;j++)
		{
			if (s1[i]==s2[j])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = min(dp[i - 1][j] + s1[i], dp[i][j - 1] + s2[j]);
			}
		}
	}

	return dp[m - 1][n - 1];


}


int minimumDeleteSum2(string s1, string s2)
{
	int m = s1.size();
	int n = s2.size();

	vector<vector<int>> dp((m+1), vector<int>((n+1), 0));

	dp[0][0] = 0;
	
	for (int i = 1; i<=m; i++)
	{	
		dp[i][0] = dp[i - 1][0] + s1[i-1];
		cout << dp[i][0] << endl;
	}

	for (int j = 1; j<=n; j++)
	{
		
		dp[0][j] = dp[0][j - 1] + s2[j-1];
		cout << dp[0][j] << endl;

	}

	for (int i = 1; i<=m; i++)
	{
		for (int j = 1; j<=n; j++)
		{
			if (s1[i-1] == s2[j-1])
			{
				dp[i][j] = dp[i-1][j-1];
				cout << dp[i][j] << endl;
			}
			else
			{
				dp[i][j] = min(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1]);
				cout << dp[i][j] <<s1[i-1]<<s2[j-1]<< endl;
			}
		}
	}

	return dp[m][n];


}

void test_minimumDeleteSum()
{
	string S1 = "delete";
	string S2 = "leet";
	int ans = minimumDeleteSum2(S1, S2);

	return;
}

int minMoves2(vector<int>& nums) 
{
	sort(nums.begin(), nums.end());
	int median = nums[nums.size() / 2];
	int ans = 0;
	for (int i=0;i<nums.size();i++)
	{
		ans += abs(nums[i] - median);
	}

	return  ans;
}

void test_minMoves2()
{
	
}


int minMoves(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int smallest = nums[0];
	int ans = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		ans += abs(nums[i] - smallest);
	}
	return ans;
}

void test_minMoves()
{
	
}

vector<int> productExceptSelf(vector<int>& nums) 
{
	int s = nums.size();
	vector<int>right(s, 1);
	vector<int>left(s, 1);

	left[0] = nums[0];
	for (int i=1;i<s;i++)
	{
		left[i] = left[i-1]*nums[i];
	}


	right[s-1] = nums[s - 1];
	for (int j=s-2;j>=0;j--)
	{
		right[j] = nums[j] * right[j+1];
	}

	
	vector<int> ans(s, 1);
	ans[0] = right[1];
	ans[s - 1] = left[s-2];
	for (int k=1;k<s-1;k++)
	{

		ans[k] = right[k+1] * left[k-1];
	}
	return ans;


}

void test_productExceptSelf()
{
	int s[] = {  2, 3, 4, 5 };
	vector<int>gg(s, s + sizeof(s) / sizeof(int));
	vector<int>kk = productExceptSelf(gg);
	return;

}

/*
 *
 * 使用异或  求不带进位的和
 * 使用与操作 计算进位
 *
 *
 */

int getSum(int a, int b) 
{
	if (b==0)
	{
		return a;
	}

	int sum = a^b;
	int carry = (a&b) << 1;
	return getSum(sum, carry);
}

void test_getSum()
{
	
}

string trans_int(string AA)
{
	string rr =  "0153429786" ;
	string ans;
	for (int i=0;i<AA.size();i++)
	{
		if (AA[i]=='3'||AA[i]=='4'||AA[i]=='7')
		{
			return AA;
		}
		cout << AA[i] - '0';
		ans+=rr[AA[i]-'0'];
	}
	return ans;
}



int rotatedDigits(int N) {
	int ans = 0;
	for (int i=0;i<=N;i++)
	{
		char buff[33];
		
		string src = _itoa(i, buff, 10);
		string dst = trans_int(src);
		if (src!=dst)
		{
			ans++;
		}

		cout << "src   " << src << "   dst    " << dst <<"    "<<ans <<endl;

	}
	return ans;
}


void test_rotatedDigits()
{
	int aaa = rotatedDigits(230);
	cout << aaa;
}



class MagicDictionary {
public:
	set<string> dd;
	/** Initialize your data structure here. */
	MagicDictionary() {

	}

	/** Build a dictionary through a list of words */
	void buildDict(vector<string> dict) {
		for (size_t i=0;i<dict.size();i++)
		{
			dd.insert(dict[i]);
		}
	}

	bool dis_word_2_word_one_char(const string AA, const string BB)
	{
		int ans = 0;
		if (AA.size()!=BB.size())
		{
			return false;
		}

		int cnt = 0;
		for (size_t k = 0; k < AA.size(); k++)
		{
			if (AA[k]!=BB[k])
			{
				cnt++;
			}
		}
		return cnt == 1;
	}


	/** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
	bool search(string word) {
		auto it = dd.begin();
		for (;it!=dd.end();++it)
		{
			 if(dis_word_2_word_one_char(*it,word))
			 {
				 return true;
			 }
		}
		return false;

	}
};

void test_MagicDictionary()
{
	vector<string>sss({ "hello","leetcode" });
	MagicDictionary *obj = new MagicDictionary();
	obj->buildDict(sss);
	cout<<"   11   "<<obj->search("helle");

}


  // 根据链表去找vector的元素 (出现了(找不到的情况/结束)就++1) 只有找到头  	 


bool find_ele(int val,vector<int >& G)
{
	for (int i=0;i<G.size();i++)
	{
		if (val==G[i])
		{
			return true;
		}
	}
	return false;
}

ListNode *sort_link_list(ListNode *head)
{
	vector<int > GG;
	while (head)
	{
		GG.push_back(head->val);
		head = head->next;
	}

	sort(GG.begin(), GG.end());
	ListNode *head_ = new ListNode(GG[0]);

	ListNode *last = head_;
	for (int i=1;i<GG.size();i++)
	{
		ListNode *node = new ListNode(GG[i]);
		last->next = node;
		last = node;
	}

	return head_;

}

int numComponents(ListNode* head, vector<int>& G) {
	ListNode *p_head = head;
	
	int cnt = 0;
	while (p_head)
	{
		bool found_head = false;
		bool found_tail = false;
		int val = p_head->val;
		if (find_ele(val,G))
		{
			found_head = true;
		}
		if (!find_ele(val,G)&&found_head)
		{
		
			found_head = false;
			found_tail = true;
		}
		if (find_ele(val,G)&&(!p_head->next)&&found_head)
		{

			found_head = false;
			found_tail = true;
		}
		if (found_head==false&&found_tail==true)
		{
			cnt++;
		}
		p_head = p_head->next;
	}
	return cnt;
}

void test_numComponents()
{
	ListNode *p0 = new ListNode(0);
	ListNode *p1 = new ListNode(3); 
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(4);
	ListNode *p4 = new ListNode(1);



	p0->next = p1;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;


  
  int a[] = { 3,0,2 };
  vector<int > kk(a, a + sizeof(a) / sizeof(int));
  
  int kkk = numComponents(p0, kk);
  cout << " 1    " << kkk;
}







//int findCircleNum(vector<vector<int>>& M) 
//{
//	int cnt = 0;
//	int m = M.size();
//	int n = M[0].size();
//	vector<vector<bool> >(m,(n,bool))
//	for (int i=0;i<m;i++)
//	{
//		for (int j=0;j<n;j++)
//		{
//			helper(M, visited, i, j);
//		}
//	}
//}
//
//void test_findCircleNum()
//{
//	
//}
//


class Q_Node {
public:
	bool val;
	bool isLeaf;
	Q_Node* topLeft;
	Q_Node* topRight;
	Q_Node* bottomLeft;
	Q_Node* bottomRight;

	Q_Node() {}

	Q_Node(bool _val, bool _isLeaf, Q_Node* _topLeft, Q_Node* _topRight, Q_Node* _bottomLeft, Q_Node* _bottomRight) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = _topLeft;
		topRight = _topRight;
		bottomLeft = _bottomLeft;
		bottomRight = _bottomRight;
	}
};

 // 将矩阵四分
vector<vector<int>>  build_config_vector(vector<vector<int>>& grid,int is_left,int is_top)
{
	int m = grid.size();
	int n = grid[0].size();
	int half = m / 2;
	vector<vector<int>>	 ans;

	for (int i=(half)*(is_left);i<half*(is_left+1);i++)
	{

		vector<int >  tt;
		for (int j = (half)*(is_top); j<half*(is_top + 1); j++)
		{
			tt.push_back(grid[i][j]);
		}
		ans.push_back(tt);
	}
	return ans;
	
}

void test_build_config_vector()
{
	int a[][8] =
	{
		{ 1,1,1,1,0,0,0,0 },
		{ 1,1,1,1,0,0,0,0 },
		{ 1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,0,0,0,0 },
		{ 1,1,1,1,0,0,0,0 },
		{ 1,1,1,1,0,0,0,0 },
		{ 1,1,1,1,0,0,0,0 },
	};
	vector<vector<int>> grid;// (8, vector<int>(8, ))
	for (int i=0;i<8;i++)
	{
		vector<int> kk(a[i], a[i] + 8);
		grid.push_back(kk);
	}

	
	vector<vector<int>> kkk = build_config_vector(grid, 0, 1);

	return;

}

Q_Node* construct(vector<vector<int>>& grid)
{
	Q_Node *ret = new Q_Node();
	int m = grid.size();
	int n = grid[0].size();
	if (m == 1  && n == 1)
	{
		ret->val = grid[0][0]==1;
		ret->isLeaf = true;
		ret->topLeft = nullptr;
		ret->topRight = nullptr;
		ret->bottomLeft = nullptr;
		ret->bottomRight = nullptr;

		return ret;
	}
	vector<vector<int>>	top_left = build_config_vector(grid, 0, 0);
	auto topLeft = construct(top_left);

	vector<vector<int>>	top_right = build_config_vector(grid, 0, 1);
	auto topRight = construct(top_right);

	vector<vector<int>>	bottom_left = build_config_vector(grid, 1, 0);
	auto bottomLeft = construct(bottom_left);

	vector<vector<int>>	bottom_right = build_config_vector(grid, 1, 1);
	auto bottomRight = construct(bottom_right);

	if (topLeft->isLeaf && topRight->isLeaf && bottomRight->isLeaf && bottomLeft->isLeaf
			&& topLeft->val == topRight->val && topRight->val == bottomRight->val && bottomRight->val==bottomLeft->val)	   // 需要合并 
	{
		bool value = topLeft->val;
		delete topLeft;
		delete topRight;
		delete bottomRight;
		delete bottomLeft;

		return new Q_Node(value,true, nullptr, nullptr, nullptr, nullptr);
	}
	else
	{
		return new Q_Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
	}

	return ret;

}



void test_construct()
{
	int a[][8] =
	{
		{ 1,1,1,1,0,0,0,0 },
		{ 1,1,1,1,0,0,0,0 },
		{ 1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,0,0,0,0 },
		{ 1,1,1,1,0,0,0,0 },
		{ 1,1,1,1,0,0,0,0 },
		{ 1,1,1,1,0,0,0,0 },
	};
	vector<vector<int>> grid;// (8, vector<int>(8, ))
	for (int i = 0; i<8; i++)
	{
		vector<int> kk(a[i], a[i] + 8);
		grid.push_back(kk);
	}


	Q_Node* kkk = construct(grid);

	return;
}


void combinationSum3_helper(int total_level,int sum,int level,vector<vector<int>> &ans,vector<int>&cur,vector<bool> &visited)
{
	if (cur.size()==total_level && sum==0)
	{
		ans.push_back(cur);
		return;
	}
//	if (level>=total_level)
//	{
//		return;
//	}
	if (sum<0)
	{
		return;
	}
	for (int i= level;i<9;i++) //visited[i] 标识 (i+1) 是否被访问
	{
	
	if (!visited[i])
		{
			visited[i] = true;
			cur.push_back(i+1);
			combinationSum3_helper(total_level, sum - (i+1), i + 1, ans, cur, visited);
			cur.pop_back();
			visited[i] = false;
		}
		
	}
}
void combinationSum3DFS(int k, int n, int level, vector<int> &out, vector<vector<int> > &res) {
	if (n < 0) return;
	if (n == 0 && out.size() == k) res.push_back(out);
	for (int i = level; i <= 9; ++i) {
		out.push_back(i);
		combinationSum3DFS(k, n - i, i + 1, out, res);
		out.pop_back();
	}
}



vector<vector<int>> combinationSum3(int k, int n) {

	vector<vector<int >> kkkk;
	vector<vector<int >> ffff;
	vector<bool>gg(9, false);
	vector<int> cur;
	combinationSum3_helper(k, n, 0, kkkk, cur, gg);
	combinationSum3DFS(k, n, 1, cur, ffff);


	return kkkk;
}

void test_combinationSum3()
{
	int k = 2;
	int n = 5;
	combinationSum3(k, n);
}


class TtNode
{
public:
	bool is_word;

	TtNode *child[26];

	TtNode():is_word(false)
	{
		for (auto &a : child)
			a = nullptr;
	}
};


void insert(TtNode *node, string word)
{
	for (char c : word)
	{
		int index = c - 'a';
		if (!node->child[index])
		{
			node->child[index] = new TtNode();
		}
		node = node->child[index];
	}
	node->is_word = true;
}

string find_prefix(TtNode *node, string word)
{
	/*string cur = "";
	for (char c : word)
	{
		int index = c - 'a';
		if (!node->child[index])
		{
			break;
		}
		else
		{
			cur.push_back(c);
		}

		if (node->is_word)
		{
			return	cur;
		}

		node = node->child[index];
	}
	return cur;*/

	/**/
	string cur = "";
	for (char c : word)
	{
		int index = c - 'a';
		if (!node->child[index])
		{
			break;
		}
		else
		{
			cur.push_back(c);
		}

		node = node->child[index];
		cout << "kkkk" << char(index)<<node->is_word<<endl;

		if (node->is_word)
		{
			return	cur;
		}

	}
	return word;

}

string replaceWords(vector<string> &dict,string sentence)
{
	string res = "", t = "";
	istringstream is(sentence);
	TtNode *root = new TtNode();
	for (string word:dict)
	{
		insert(root, word);
	}
	while (is>>t)
	{
		if (!res.empty())
		{
			res += " ";
		}
		res += find_prefix(root, t);
	}
	return res;
}



 void test_replaceWords()
 {
	 vector<string>  words = {"cat","bat","rat"};
	 string sentence = "the cattle was rattled by the battery";
	string ccc =  replaceWords(words, sentence);
	cout << "111" << ccc << "211";
 }


# if 0
class TrieNode
{
public:
	TrieNode *word[26];
	bool is_leaf;
	TrieNode():is_leaf(false)
	{
		for (int i = 0; i < 26; i++)
		{
			word[i] = nullptr;
		}
	}
};

class Trie {
public:
	TrieNode *root;
	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode *p = root; // 要记录最后一个节点的位置,下次直接在后面挂载;
		for (int i=0;i<word.size();i++)
		{
			auto temp = new TrieNode();
			p->word[word[i] - 'a'] = temp;
			if(i==word.size()-1)
			{
				p->is_leaf = true;
			}
			p = temp;
		}
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode *q = root;
		for (int i = 0; i< word.size(); i++)
		{
			if (q->word[word[i]-'a']==nullptr)
			{
				return  false;
			}
			q = q->word[word[i] - 'a'];
		}
		return q->is_leaf == true;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode *q = root;
		for (int i = 0; i<prefix.size(); i++)
		{
			if (q->word[prefix[i] - 'a'] == nullptr)
			{
				return  false;
			}
			q = q->word[prefix[i] - 'a'];
		}
		return true;
	}

};

#endif


class TrieNode
{
public:
	TrieNode * child[26];
	bool is_word;
	TrieNode():is_word(false)
	{
		for (int i = 0; i < 26; i++)
		{
			child[i] = nullptr;
		}
	}
};

class Trie
{
public:

	TrieNode *root;

	Trie() {
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode *p = root;

		for (int i=0;i<word.size();i++)
		{
			int index = word[i] - 'a';
			TrieNode *temp = new TrieNode();
			if (!p->child[index])  // 如果是空的	需要填充一个	 如果不是空的就不用插入  apple app
			{
				p->child[index] = temp;
			}

			p = p->child[index];
		}
		p->is_word = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) 
	{
		
		TrieNode *p = root;

		for (int i=0;i<word.size();i++)
		{
			int index = word[i] - 'a';
			if (!p->child[index])
			{
				return false;
			}
			p = p->child[index];
		}
		return p->is_word;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) 
	{
		TrieNode *p = root;

		for (int i = 0; i< prefix.size(); i++)
		{
			int index = prefix[i] - 'a';
			if (!p->child[index])
			{
				return false;
			}
			p = p->child[index];
		}
		return true;
	}

};

void test_trie_tree()
{
	Trie *trie = new Trie();
	trie->insert("apple");
	cout << " 111    " << trie->search("app") << endl;
	cout << " 111    " << trie->search("apple") << endl;
	cout << " 111    " << trie->startsWith("apple") << endl;
    trie->insert("app");
	cout << " 111    " << trie->search("app") << endl;
	
	return;
}


bool is_pattern(const string& A, const string& B)
{
	if (A.size() != B.size())
	{
		return false;
	}
	int AA[26];
	memset(AA, -1, sizeof(AA));
	int BB[26];
	memset(BB, -1, sizeof(BB));



	for (int i = 0; i < A.size(); i++)
	{
		if (AA[A[i]-'a']>-1) //存在
		{
			if (AA[A[i] - 'a'] != B[i] - 'a')
			{
				return false;
			}
		}
		else
		{
			AA[A[i] - 'a'] = B[i] - 'a';
		}


		if (BB[B[i] - 'a']>-1) //存在
		{
			if (BB[B[i] - 'a'] != A[i] - 'a')
			{
				return false;
			}
		}
		else
		{
			BB[B[i] - 'a'] = A[i] - 'a';
		}
	}

	return true;
}

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
	vector<string> ssss;

	for (auto word :words)
	{
		if (is_pattern(word,pattern))
		{
			ssss.push_back(word);
		}
	}
	return ssss;
}




void test_is_pattern()
{
	string aa("mee");
	string bb("tcc");
    cout<<"  11122  "<<	is_pattern(aa, bb)<<endl;
	return;
}

void test_findAndReplacePattern()
{
	vector<string> ss({ "abc","deq","mee","aqq","dkd","ccc" });
	auto sss("abb");
	findAndReplacePattern(ss, sss);

}

int maxProfit1(vector<int>& prices)
{
	if (prices.size()==0)
	{
		return 0;
	}
	int max = -1;
	for (int i = 0; i < prices.size() - 1; i++)
	{
		int tmp_max = -1;
		for (int j = i + 1; j < prices.size(); j++)
		{
			int tmp = prices[j] - prices[i];
			if (tmp > tmp_max)
			{
				tmp_max = tmp;
			}
		}
		if (tmp_max > max)
		{
			max = tmp_max;
		}
	}
	return max==-1?0:max;
}


void test_maxProfit1()
{
	vector<int> prices = { 7,6,4,3,1 };

	int lll = maxProfit1(prices);

	cout << lll;
}


/*
 *
 *
 * 利润最大为昨天买入,如果今天价格更高那就卖出,这样利润最大;
 *
 *
 */
int maxProfit2(vector<int>& prices) 
{
	if (prices.size() == 0)
		return 0;
	int res = 0;
	for (int i=0;i<prices.size()-1;i++)
	{
		if (prices[i]<prices[i+1])
		{
			res += prices[i + 1] - prices[i];
		}
	}
	return res;
}

void test_maxProfit2()
{
	vector<int> prices = { 7,6,4,3,1 };

	int lll = maxProfit2(prices);

	cout << lll;
}


int maxProfit3(vector<int>& prices) {
	return 0;
}


void test_maxProfit3()
{
	vector<int> prices = { 3,3,5,0,0,3,1,4 };

	int lll = maxProfit3(prices);

	cout << lll;
}


class SSNode {
public:
	int val = NULL;
	vector<SSNode*> children;

	SSNode() {}

	SSNode(int _val, vector<SSNode*> _children) {
		val = _val;
		children = _children;
	}
};
vector<vector<int>> levelOrder(SSNode* root)
{
	vector<vector<int >> ans;
	queue<SSNode *>qqq;
	qqq.push(root);
	while (!qqq.empty())
	{
		vector<int> ttt;
		int size = qqq.size();	  // z这个一定在外面的固定值哦 不要写出for循环的值; todo
		 for (int i=0;i<size;i++)
		 {
			 SSNode * ca = qqq.front();
			 if (ca)
			 {
				 ttt.push_back(ca->val);
			 }
			 qqq.pop();
			 if ((ca->children).size()>0)
			 {
				 for(int i=0;i<ca->children.size();i++)
				 {
					 qqq.push(ca->children[i]);
				 }
			 }

		 }
		 ans.push_back(ttt);
	}

	return ans;

}

void test_levelOrder()
{

	SSNode *node_4 = new SSNode(4, {});
	SSNode *node_5 = new SSNode(5, {});
	SSNode *node_6 = new SSNode(6, {});
	SSNode *node_3 = new SSNode(3, {node_4,node_5,node_6});

	SSNode *node_2 = new SSNode(2, {});
	SSNode *node_1 = new SSNode(1, {node_3,node_2});

	vector<vector<int>>  hhhhh = levelOrder(node_1);
	
	return;


}
	  /*
	   *
	   * 当 a b 相等的时候 灭有返回-1
	   * 当 a!=b 时最长为a最长的长度;
	   *
	   */
int findLUSlength(string a, string b) 
{
	int m = a.size();
	int n = b.size();
	if (a==b)
	{
		return -1;
	}
	else
	{
		return m > n ? m : n;
	}

}


void test_findLUSlength()
{
	string a("aba");
	string b("cdc");

	findLUSlength(a, b);

}




string reverseOnlyLetters(string S) 
{
	int left = 0;
	int rignt = S.size() - 1;
	while (left<rignt)
	{
		while (!isalpha(S[left])&&left<=rignt)
		{
			left++;
		}

		while (!isalpha(S[rignt])&&left<=rignt)
		{
			rignt--;
		}
		if (left<rignt)
		{
			swap(S[left], S[rignt]);
		}
		left++;
		rignt--;
	}
	return S;
}

void test_reverseOnlyLetters()
{
	//string aa = "Test1ng-Leet=code-Q!";
	string aa = "7_28]";
	aa = reverseOnlyLetters(aa);
	return;
}

void shift_string(string &A)
{
	rotate(A.begin(), A.begin() + 1,A.end());
}

bool rotateString(string A, string B) {
	if (A.size() == 0 && B.size() == 0)
		return true;
	for (int i=1;i<A.size();i++)
	{
		shift_string(A);
		cout << "aaaa" << A<< endl;
		if (A==B)
		{
			return true;
		}
	}
	return false;
}

void test_rotateString()
{
	string aaaa("abcde");
	string bbbb("abced");

	bool ttt = rotateString(aaaa,bbbb);
	cout << "aaaa: " << ttt << endl;
}

void post_walkering(TreeNode *root)
{
	
}

int get_max_left(TreeNode *root)
{
	TreeNode *p = root;
	if (!root)
	{
		return 0;
	}
	while (p->right)
	{
		p = p->right;
	}
	return p->val;

}

int get_max_right(TreeNode *root)
{
	TreeNode *p = root;
	if (!root)
	{
		return 0;
	}
	while(p->left)
	{
		p = p->left;
	}
	return p->val;
	
}

int getMinimumDifference1(TreeNode* root,int &min) 
{
	if (!root)
	{
		return 0;
	}
	if (!root->left&&!root->right)
	{
		return root->val;
	}
	int left = -0xffff;
	int right = 0xffff;
	if(root->left)
		left = get_max_left(root->left);
	if (root->right)
		right = get_max_right(root->right);

	int ans = (root->val - left) < (right - root->val) ? (root->val - left) : (right - root->val);
	if (ans<min)
	{
		min = ans;
	}
	cout << root->val << "  left " << left << "    right  " << right<<"  ans  "<<ans<<endl;

	if (root->left)
	{
		getMinimumDifference1(root->left,min);
	}
	if (root->right)
	{
		getMinimumDifference1(root->right,min);
	}
	return 0;

}

void test_getMinimumDifference()
{
	 //[10,5,20,2,8,15,100]
	TreeNode *node_10 = new TreeNode(10);
	TreeNode *node_5 = new TreeNode(5);
	TreeNode *node_20 = new TreeNode(20);
	TreeNode *node_2 = new TreeNode(2);
	TreeNode *node_8 = new TreeNode(8);
	TreeNode *node_15= new TreeNode(15);
	TreeNode *node_100 = new TreeNode(100);
	
	node_5->left = node_2;
	node_5->right = node_8;
	
	node_20->left = node_15;
	node_20->right = node_100;
	
	node_10->left = node_5;
	node_10->right = node_20;
    
 //   TreeNode *node_1 = new TreeNode(1);
 //   TreeNode *node_3 = new TreeNode(3);
 //   TreeNode *node_2 = new TreeNode(2);

	int min = 0xffff;

//	node_1->right = node_3;
//	node_3->left = node_2;


	getMinimumDifference1(node_10,min);
	cout << endl << endl<<min;



}

int get_next_greater_ele(vector<int>& nums,int index)
{
	 for (int i=index+1;i<nums.size()+index;i++)
	 {
		 if (nums[i%nums.size()]>nums[index%nums.size()])
		 {
			 return nums[i%nums.size()];
		 }
	 }
	 return -1;
}

vector<int> nextGreaterElements(vector<int>& nums) 
{
	vector<int> ans;
	for (int i=0;i<nums.size();i++)
	{
		ans.push_back(get_next_greater_ele(nums, i));
	}
	return ans;
}

void test_nextGreaterElements()
{
	vector<int> tttt = { 1,2,3,4,5 };
	vector<int> kk = nextGreaterElements(tttt);

	return;
}

int fourSumCount_time_limit_exceeded(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
	int cnt = 0;
	  for (auto a:A)
		  for (auto b:B)
			  for(auto c:C)
				  for(auto d:D)
				  {
					  if (a+b+c+d==0)
					  {
						  cnt++;
					  }
				  }
	  return cnt;
}

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
	int cnt = 0;
	unordered_map<int, int>ttt;
	for (auto a:A)
		for(auto b:B)
		{
			++ttt[a + b];
		}
	for (auto c : C)
		for (auto d : D)
		{
			int target = -(c + d);
			cnt += ttt[target];
		}
	return cnt;
}

void test_fourSumCount()
{
	
}

class Solution {
public:
	Solution(vector<int> nums):kkk(nums) {

	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return 	kkk;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> qqq = kkk;
		for (int i=0;i<qqq.size();i++)
		{
//https://yjk94.wordpress.com/2017/03/17/%E6%B4%97%E7%89%8C%E7%9A%84%E6%AD%A3%E7%A1%AE%E5%A7%BF%E5%8A%BF-knuth-shuffle%E7%AE%97%E6%B3%95/
			int index = rand() % (qqq.size() - i) + i;  
			swap(qqq[i], qqq[index]);
		}
		return qqq;
	}
	vector<int> kkk;
};

void test_shuffle_array()
{
	
}


void floodFill_helper(vector<vector<int>>& image, int sr, int sc,int old_color, int new_color)
{
	int m = image.size();
	int n = image[0].size();

	if (sr>m - 1 || sr<0)
	{
		return;
	}
	if (sc>n - 1 || sc<0)
	{
		return;
	}
	if (image[sr][sc] != old_color)
	{
		return;
	}
	{
		image[sr][sc] = new_color;
		floodFill_helper(image, sr + 1, sc,old_color, new_color);
		floodFill_helper(image, sr - 1, sc,old_color, new_color);
		floodFill_helper(image, sr, sc + 1,old_color, new_color);
		floodFill_helper(image, sr, sc - 1,old_color, new_color);
	}
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
	if (image[sr][sc]==newColor){
		return image;
	}
	floodFill_helper(image, sr, sc, image[sr][sc], newColor);
	return image;
}

vector<vector<int>>  test_floodFill()
{
	vector<vector<int>> ttt({ { 1,1,1 },{ 1,1,0 },{ 1,0,1 } });
	floodFill_helper(ttt, 1, 1,ttt[1][1], 233);
	return ttt;
}


int BestTimetoBuyandSellStockwithTransactionFee_maxProfit(vector<int>& prices, int fee)
{

	int m = prices.size();
	vector<int> dp(m,0);

	dp[0] = 0;

	for (int i = 1; i < prices.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			int tmp_2;
			if (prices[i]>prices[j])
			{				
				int tmp_1 = max(dp[j], (dp[j] + prices[i] - prices[j] - fee));
				tmp_2 = max(tmp_1, 0);
			}
			else
			{
				tmp_2 = dp[i - 1];
			}
			dp[i] = max(tmp_2, dp[i]);
		}
	}

	return dp[m - 1];
}


void test_BestTimetoBuyandSellStockwithTransactionFee_maxProfit()
{
	vector<int>prices({ 1, 3, 2, 8, 4, 9 });
	int fee = 3;
	BestTimetoBuyandSellStockwithTransactionFee_maxProfit(prices, fee);
	return;
}

int main() {
	//std::cout << "hello?";
	//test_1();
	//test_point();
	//maxAreaOfIsland_test();
	//test_recursion_pass(s,&y);
	//test_backtraceing();
	//test_BinaryGap();
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
	//test_letterCasePermutation();	
	//test_scoreOfParentheses();		 ?
	//test_frequencySort();
	//test_sort();
	//local_test();
	//test_countArrangement();
	//test_generateParenthesis();
	//test_combinationSum3();  ?
	//test_combinationSum();  
	//test_combinationSum2(); 
	//test_stoneGame();
	//test_maxAreaOfIsland();
	//test_subtreeWithAllDeepest();
	//test_minimumDeleteSum();
	//test_minMoves2();
	//test_minMoves();
	//test_productExceptSelf();
	//test_getSum();
	//test_rotatedDigits();
	//test_MagicDictionary();
	//test_numComponents();	?
	//test_findCircleNum(); ?
	//test_build_config_vector();
	//test_construct();
	//test_combinationSum3();
	//test_replaceWords();	??
	//test_trie_tree();
	//test_findAndReplacePattern();
	//test_maxProfit1();
	//test_maxProfit2();
	//test_maxProfit3();	 ??
	//test_levelOrder();
	//test_findLUSlength();
	//test_reverseOnlyLetters();
	//test_rotateString();
	//test_getMinimumDifference();
	//test_nextGreaterElements();
	//test_fourSumCount();
	//test_shuffle_array();
	//test_floodFill();

	test_BestTimetoBuyandSellStockwithTransactionFee_maxProfit();

	











	return 0;
}







