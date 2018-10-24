
// Username:peng_peng
// password : Peng0peng

#include "head.h"

int cal_min_cost(vector<int> & coins, int *parr, int total) {
	int min_index = -1;  //��������coins
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
		if (t == -1) // ���ܱ�ת��
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

	//char *str[3] = {	// ��һ��ָ������  �����Ԫ����ָ�� ����ָ��
	//	"Hello,this is a sample!",
	//	"Hi,good morning.",
	//	"Hello world"
	//};
	//char s[80];
	//strcpy(s, str[0]); //Ҳ��д��strcpy(s,*str);  
	//cout <<"1   "<< *(str+1)<<"    ";
	//strcpy(s, str[1]); //Ҳ��д��strcpy(s,*(str+1));  
	//cout << "2   " << s << "    ";

	//strcpy(s, str[2]); //Ҳ��д��strcpy(s,*(str+2)); 
	//cout << "3   " << s << "    ";

	//int array[10] = { -1,2,3,4,5,6,7,8,9 };
	//int (*ptr)[10] = &array;	    // ����һ������ָ�� ָ�������ָ��

	//int *base = (int *)ptr;  // ptr + 1 �������������С����λ;
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
	//get_memory(&str, 100);	// �ܲ��ܸ��Ĳ���Ҫ��ʵ������÷��Ĺ�ϵ.���ǿ�ʵ�����βε��������ǵ�������һ����;
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
	//	if (left==right)					// �������
	//	{
	//		return new TreeNode(nums[left]);
	//	}
	int mid = get_maxValue_index(nums, left, right);
	TreeNode *root = new TreeNode(nums[mid]);
	root->left = do_hand(nums, left, mid - 1);	// ��������һ�������left ��right�Ĳ�ͬ;
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
			if (!right_1)	     //�Ƿ���Ҫ����  
				right_1 = true;
			else
				max_grap = max(max_grap, grap);
			grap = 1;   // ��С�ĳ�����1
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
		// map�ĵ������������� first ����std::pair�ĵ�һ����Ա(Type1)��second ���ʵڶ�����Ա (Type2)
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
	for (int k = 0, i = 0; k<S.size(); k++)	 // �����ߵ�ֻ��Ҫʹ��һ��ֵȥ�ж� ���м��Ҫ����ֵ	Ĭ��index_1 <= index_2
	{
		if (S[k] == C && i == 0) // ��һ������C	   ʹ�� index_2 �ж�
		{
			index_1 = index_2;
			index_2 = tt[++i];
			ans.push_back(0);
			cout << S[k] << "   1: " << index_1 << "    _2: " << index_2 << "  k :  " << k << " ans " << ans[k] << endl;
			continue;
		}
		if (S[k] == C && i == tt.size() - 1) // ���һ������C		 ʹ�� index_1 �ж�
		{
			index_1 = index_2;
			index_2 = 1;
		}


		if (abs(k - index_1)<abs(k - index_2)) // ��index1 ��һ��
		{
			ans.push_back(k - index_1);
		}

		else {  // 	 ��index2 ��һ��
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
		//С��2���������Ǻ���Ҳ��������  
		return false;
	}
	for (int i = 2; i < n / 2 + 1; ++i)
	{
		cout << "      iiiiiiii      " << i << endl;
		// �ͱ�����һ��С��������������������֤������  
		if (0 == n % i)
		{
			// �����ˣ�����  
			return false;
		}
	}
	return true; // ��û����������  
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
		int cnt = tree.size();   // Ҫ����������� ��������ľͲ���ѭ����ȥ�� ������forѭ������;
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
		if (left==right)	  // if ֻ�����м䲻�ܺ���һ��if�����ȼ�����.
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
			//����������Ҫ��,�ָ���ԭ��������,����ǻ��ݷ���Ҫ��.
			visted[i] = false;
			curr.pop_back();	   
		}
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> permus;
	if (nums.size() == 0)  return  permus;
	vector<bool> visted(nums.size(), false);
	vector<int> curr;   //��¼��ǰ�������
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
 * ʹ�����  �󲻴���λ�ĺ�
 * ʹ������� �����λ
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



int numComponents(ListNode* head, vector<int>& G) {
	ListNode *p_head = head;
	int cnt = 0;
	while (p_head)
	{
		int val = p_head->val;
		bool broken = true;
		for (int i=0;i<G.size();i++)
		{
			if (val==G[i])
			{
				broken = false;
				break;
			}	
		}
		if (broken)
			cnt++;
		p_head = p_head->next;
	}
	return cnt;
}

void test_numComponents()
{
	ListNode *p0 = new ListNode(0);
	ListNode *p1 = new ListNode(1); 
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(3);
	ListNode *p4 = new ListNode(4);



	p0->next = p1;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;		 
	int a[] = { 0, 3, 1, 4 };
	vector<int > kk(a, a + sizeof(a) / sizeof(int));

	int kkk = numComponents(p0, kk);
	cout << " 1    " << kkk;
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
	//test_numComponents();		 ?




	return 0;
}







