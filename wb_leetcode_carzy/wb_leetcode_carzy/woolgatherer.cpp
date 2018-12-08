#include "head.h"
#include <thr/xthrcommon.h>
// Username:peng_peng
// password : Peng0peng

#if 0
#endif

/**
* \brief
* \param list 传入的是层序遍历的结果
* \return 构造好的二叉树
*/
void createTree(vector<int> list,TreeNode *&ret)
{

	for (int i = 0; i<list.size(); i++)
	{
		int tmp = list[i];
		if (tmp == 0xff)
		{
			TreeNode *root = nullptr;
			if (i == 0)
			{
				ret = root;
			}
		}
		else
		{
			TreeNode *root = new TreeNode(tmp);
			if (i == 0)
			{
				ret = root;
			}
			if (2*i+1>list.size()-1)
			{
				root->left = nullptr;
			}
			else
			{
				root->left = new TreeNode(list[2 * i + 1]);
			}
			if(2*i+2>list.size()-1)
			{
				root->right = nullptr;
			}
			else
			{
				root->right = new TreeNode(list[2 * i + 2]);
			}
		}
	}

}



double findMaxAverage(vector<int>& nums, int k) {
	 int max = numeric_limits<int>::min();
	 for (int i=0;i<nums.size()-k+1;i++)
	 {
		 int sum = 0;
		 for (int j=i;j<i+k;j++)
		 {			 
			 sum += nums[j];
		 }
		 if (sum>max)
		 {
			 max = sum;
		 }
	 }
	 return max*1.0 / k;
}

void test_findMaxAverage()
{

		 vector<int> nums({ 1, 12, -5, -6, 50, 3 });
		 int k = 4;
	

	// vector<int> nums({
	// 	8860, -853, 6534, 4477, -4589, 8646, -6155, -5577, -1656, -5779, -2619, -8604, -1358, -8009, 4983, 7063, 3104,
	// 	-1560, 4080, 2763,
	// 	5616,-2375,2848,1394,-7173,-5225,-8244,-809,8025,-4072,-4391,-9579,1407,6700,2421,-6685,5481,-1732,-8892,-6645,3077,3287,-4149,
	// 	8701,-4393,-9070,-1777,2237,-3253,-506,-4931,-7366,-8132,5406,-6300,-275,-1908,67,3569,1433,-7262,-437,8303,4498,-379,3054,
	// 	-6285,4203,6908,4433,3077,2288,9733,-8067,3007,9725,9669,1362,-2561,-4225,5442,-9006,-429,160,-9234,-4444,3586,-5711,-9506,
	// 	-79,-4418,-4348,-5891 });
    
	//int k = 93;
	double ans = findMaxAverage(nums, k);
	return;

}
string addBinary_helper(string a, string b, string carry)
{
	 if (a == ""&&b == "")
	 {
	 	return carry;
	 }

	 if (b == "")
	 {
		 return addBinary_helper(a, "", carry);
	 }


	if (a == "")
	{
		return  addBinary_helper("0",b, carry);
	}
	
	

	string c = "0";	  // 进位剩余项
	string d = "0";	  // d是进位
	// 2 3 都是1 
	if (a[a.size() - 1] == '1'&&b[b.size() - 1] == '1'|| a[a.size() - 1] == '1'&&carry == "1"|| carry == "1" &&b[b.size() - 1] == '1')
	{
		
		d = "1";
		if (a[a.size() - 1] == '1'&&b[b.size() - 1] == '1'&& a[a.size() - 1] == '1'&&carry == "1")
			c = "1";
	}
	else  if(a[a.size() - 1] == '1'||b[b.size() - 1] == '1'|| a[a.size() - 1] == '1'||carry == "1")	   // 1个1
	{
		c = "1";
	}
	// else 	// 都是 0 
	// {
	// 	
	// }

	return addBinary_helper(a.substr(0,a.size()-1), b.substr(0,b.size()-1), d)+c;
 }
	



int add_one(int a, int  b, int carry)
{
	if(b==0&&carry==0)
	{
		return a;
	}
	int c = a % 10;
	int d = b % 10;
	int car = (c + d + carry) / 10;
	int z = (c + d + carry) % 10;

	int e = a / 10;
	int f = b / 10;

	return z + 10*add_one(e, f, car);

}

string cut_string_adapted(string shorter,string longer)
{
	string ans;
	int len = longer.size();
	for (int i=0;i<len-shorter.size();i++)
	{
		ans.push_back('0');
	}
	for (int j=0;j<shorter.size();j++)
	{
		ans.push_back(shorter[j]);
	}
	return ans;
}


string addBinary(string a, string b) {
	string longer = a.size() >= b.size() ? a : b;
	string shorter = a.size() < b.size() ? a : b;
	string a_ = cut_string_adapted(shorter, longer);
	string c = "";
	string x = addBinary_helper(a_, longer, c);
	if (x[0] == '0')
		return x.substr(1, x.size() - 1);
	return x;
}

void test_addBinary()
{
	string a("11");
	string b("1");
	string c = "";
	string x = addBinary(a, b);
	cout << "xxx  " << x << endl;

	//int a_ = 666;
	//int b_ = 3333;
	//int c_ = 0;
	//cout << add_one(a_, b_, c_);
}


bool  isSymmetric(TreeNode *left,TreeNode *right)
{
	if (!left&&!right){
		return true;
	}
	if (!left&&right || left&&!right || left->val != right->val) {
		return false;
	}
	return isSymmetric(left->left, right->right)&&isSymmetric(right->left,left->right);
}

bool isSymmetric(TreeNode* root) {
	return isSymmetric(root->left,root->right);
}

void test_isSymmetric()
{
	vector<int > tt({ 1,2,3,4,5,6,7 });
	TreeNode *root = nullptr;
	TreeNode *node_1 = new TreeNode(1);
	TreeNode *node_2 = new TreeNode(2);
	TreeNode *node_3 = new TreeNode(2);
	TreeNode *node_4 = new TreeNode(3);
	TreeNode *node_5 = new TreeNode(3);
	TreeNode *node_6 = new TreeNode(4);
	TreeNode *node_7 = new TreeNode(4);
	node_1->left = node_2;
	node_1->right = node_3;

	node_2->left = node_4;
	node_2->right = node_5;

	node_3->left = node_6;
	node_3->right = node_7;

	cout<< "1212GG   "<<isSymmetric(node_1);


	return;
}

int searchInsert_help(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	while (left<=right)
	{
		int mid = left + (right - left) / 2;
		if(target==nums[mid])
		{
			return mid;
		}
		if(target>nums[mid])
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}

int searchInsert(vector<int>& nums, int target) {
	int ret = -1;
	if (searchInsert_help(nums,target)==-1)
	{
		nums.push_back(target);
		sort(nums.begin(), nums.end());
		return searchInsert_help(nums, target);
	}
	return searchInsert_help(nums, target);	
}



void test_searchInsert()
{
	vector<int> nums({ 1,3,5,6 });
	int target = 4;
	cout<<"111   "<<searchInsert(nums, target);
}

string reverseSTR(string &s,int start,int end)
{
	cout << "   " << start << "   " << end << endl;
	while (start<=end)
	{
		char tp = s[start];
		s[start] = s[end];
		s[end] = tp;

		start++;
		end--;
	}
	return s;
}

string reverseStr(string s, int k) {
	int len = s.size();
	if (k>len)
	{
		k = len;
	}
	for (int i=0;i<len;i+=2*k)
	{
		int res_end = i + k > len ? len : i + k;
		reverseSTR(s, i, res_end-1);
	}
	return s;
}

void test_reverseStr()
{
	string test("hyzqyljrnigxvdtneasepfahmtyhlohwxmkqcdfehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqlimjkfnqcqnajmebeddqsgl");
	int k = 39;
	cout << "test    " << reverseStr(test,k);
	//cout << "test    " << reverseSTR(test, 0,test.size()-1);

}

string backspaceCompare_string2string(string S)
{
	stack<char> ss;
	for (auto c :S)
	{
		if (c=='#')
		{
			if (!ss.empty())
			{
				ss.pop();
			}
			else
			{
				
			}
		}
		else
		{
			ss.push(c);
		}
	}
	string ans;
	while (!ss.empty())
	{
		char c = ss.top();
		ans.push_back(c);
		ss.pop();
	}
	return ans;
}

bool backspaceCompare(string S, string T) {
	string ret_s = backspaceCompare_string2string(S);
	string ret_t = backspaceCompare_string2string(T);
	return ret_s == ret_t;

}

void test_backspaceCompare()
{
	string S("ab#c");
	string T("ad#c");
	cout<<"112121 "<< backspaceCompare(S, T);
}
   /*
 Given the tree:
        4
       / \
      2   7
     / \
    1   3

	   4
	 /   \
    2     7
   / \   /
  1   3 5
And the value to insert: 5
    */


TreeNode* insertIntoBST(TreeNode* root, int val) {
	if (root&&!root->left)
	{	 
		if(val<root->val)
		{	 
			TreeNode *node = new TreeNode(val);
			root->left = node;
			return root;
		}
		
	}
	if (root && !root->right)
	{	
		if (val>root->val)
		{
			TreeNode *node = new TreeNode(val);
			root->right = node;
			return root;
		}
	}

	if (val<root->val)
	{
		root->left =  insertIntoBST(root->left, val);
		return root;
	}
	root->right =  insertIntoBST(root->right,val);
	return root;
	


}

void test_insertIntoBST()
{
	// TreeNode* node1 = new TreeNode(1);
	// TreeNode* node2 = new TreeNode(2);
	// TreeNode* node3 = new TreeNode(3);
	// TreeNode* node4 = new TreeNode(4);
	// TreeNode* node7 = new TreeNode(7);
	//
	// node4->left = node2;
	// node4->right = node7;
	//
	// node2->left = node1;
	// node2->right = node3;

	TreeNode *node61 = new TreeNode(61);
	TreeNode *node46 = new TreeNode(46);
	TreeNode *node66 = new TreeNode(66);
	TreeNode *node43 = new TreeNode(43);
	TreeNode *node39 = new TreeNode(39);

	node61->left = node46;
	node61->right = node66;

	node46->left = node43;
	node43->left = node39;

	auto ss =  insertIntoBST(node61,85);

	system("pause");

	return;
}

void test_redundant_else(int a)
{
	if (a==1)
	{
		cout << " a == 1" << endl;
		return;
	}
	
	{
		cout << " a == 2" << endl;
		return;
	}
}

bool is_same_alpha(char c,char d)
{
	return tolower(c) == tolower(d);
}
bool  is_alphanumeric(char c)
{
	return  isalpha(c) || isdigit(c);
}

bool isPalindrome(string s) {
	if (s.empty())
		return true;
	int start = 0;
	int end = s.size() - 1;
	while (start<=end)
	{
		while (start<=end&& !is_alphanumeric(s[start]))
		{
			start++;
		}
		while (start <= end &&!is_alphanumeric(s[end]))
		{
			end--;
		}
		if (!(is_same_alpha(s[start], s[end]))&& start <= end)
			return false;
		start++;
		end--;
	}
	return true;
}

void test_isPalindrome()
{
	string str("A man, a plan, a canal: Panama");
	cout << "    " << isPalindrome(str);
}

uint32_t reverseBits(uint32_t n) 
{
	uint32_t ans = 0;
	for (int i=0;i<32;i++)
	{
		int c = n % 2;
		n /= 2;
		cout << c;

		uint32_t reverseBit = c << (31 - i);
		ans += reverseBit;
	}
	return ans;
}

void test_reverseBits()
{
	uint32_t num = 1596;
	cout << reverseBits(num);
	return;
}


ListNode * get_negative_sequence_K_(ListNode *head,int K)
{
	
	ListNode *fast = head;
	ListNode *slow = head;
	int index = 0;
	while (index<K&&fast)
	{
		fast = fast->next;
		index++;
	}
	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

ListNode * get_positive_sequence_K_(ListNode *head, int K)
{
	ListNode *fast = head;
	int index = 1;
	while (index<K&&fast)
	{
		fast = fast->next;
		index++;
	}
	return fast;
}

int get_linkList_len(ListNode *head)
{
	if (!head)
	{
		return 0;
	}
	return 1 + get_linkList_len(head->next);
}

bool isPalindrome(ListNode* head) {
	int len = get_linkList_len(head);
	int start = 1;
	int end = len;
	while (start<=len)
	{
		auto positive_node = get_positive_sequence_K_(head, start);
		auto negative_node = get_positive_sequence_K_(head, end);
		if (positive_node->val!=negative_node->val)
		{
			return false;
		}
		start++;
		end--;
	}
	return true;
}

void test_isPalindrome_linkList()
{
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);
	ListNode *node5 = new ListNode(3);
	ListNode *node6 = new ListNode(2);
	ListNode *node7 = new ListNode(1);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	
	node5->next = node6;
	node6->next = node7;

	auto ans = isPalindrome(node1);
	cout << ans;
	return;
}

string convertToTitle(int n) {
	if (n<=26) // 1~26
	{
		return  string(1,'A' + n-1);
	}
	return convertToTitle((n-1)/26) + convertToTitle((n-1) % 26+1);  //0~25  1~26
}

void test_convertToTitle()
{
	int n = 701;
	string ans = convertToTitle(n);
	cout << "1111   " << ans;
}


bool buddyStrings(string A, string B) {
	int cnt_diff = 0;
	int char_map[26] = { 0 };
	bool char_map_bool[26] = { false };
	int l1 = 0;
	int l2 = 0;
	unordered_map<char, int> m;
	if (A.size()!=B.size())
	{
		return false;
	}

	bool same_char_twice = false;
	if (A == B)
	{
		for (int i = 0; i < A.size(); i++)
		{
			char_map[A[i]-'a']++;
		}
		for (int j = 0; j < 26; j++)
		{
			if (char_map[j]>=2)
			{
				same_char_twice = true;
			}
		}
	}
	else
	{
		for (int i = 0; i<A.size(); i++)
		{
			if (A[i] != B[i])
			{
				cnt_diff++;

				if (l2==l1)
				{
					l1 = i;
				}
				else
				{
					l2 = l1;
					l1 = i;
				}
			}
		}
	}

	return (cnt_diff == 2&&A[l1]==B[l2]&&A[l2]==B[l1])||same_char_twice;
}

void test_buddyStrings()
{
	string a("aaa");
	string b("aaa");

	cout << " buddy  " << buddyStrings(a, b);
}

ListNode *remake(ListNode *head) // 加个头
{
	ListNode *new_head = new ListNode(0xff);
	new_head->next = head;
	return new_head;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if (!headA || !headB)
		return nullptr;

	headA = remake(headA);
	headB = remake(headB);

	ListNode *tail_A = headA;
	ListNode *tail_B = headB;

	while (tail_A)
	{
		tail_A = tail_A->next;
	}
	while (tail_B)
	{
		tail_B = tail_B->next;
	}
	int index = 1;
	while (tail_A==tail_B&&(tail_A!=headA||tail_B!=headB))
	{
		tail_A = get_negative_sequence_K_(headA, index);
		tail_B = get_negative_sequence_K_(headB, index);
		index++;
	}
	return tail_A->next;
}

void test_getIntersectionNode()
{
	ListNode *node_a_1 = new ListNode(1);
	ListNode *node_a_2 = new ListNode(2);
	ListNode *node_a_3 = new ListNode(3);
	ListNode *node_a_4 = new ListNode(4);
	ListNode *node_a_5 = new ListNode(5);


	ListNode *node_b_1 = new ListNode(1);
	ListNode *node_b_2 = new ListNode(2);
	ListNode *node_b_3 = new ListNode(3);
	ListNode *node_b_4 = new ListNode(4);
	ListNode *node_b_5 = new ListNode(5);

	ListNode *node_c_1 = new ListNode(11);
	ListNode *node_c_2 = new ListNode(22);
	ListNode *node_c_3 = new ListNode(33);
	ListNode *node_c_4 = new ListNode(44);
	ListNode *node_c_5 = new ListNode(55);

	 node_a_1->next = node_a_2;
	 node_a_2->next = node_a_3;
	 node_a_3->next = node_a_4;
	 node_a_4->next = node_a_5;

	 node_b_1->next = node_b_2;
	 node_b_2->next = node_b_3;
	 node_b_3->next = node_b_4;
	 node_b_4->next = node_b_5;

	 node_c_1->next = node_c_2;
	 node_c_2->next = node_c_3;
	 node_c_3->next = node_c_4;
	 node_c_4->next = node_c_5;

	 node_a_5->next = node_c_1;
	 node_b_5->next = node_c_1;

	ListNode *interSetction_part = getIntersectionNode(node_a_1, node_b_1);

	cout << "getIntersectionNode   " << interSetction_part->val;
	return;
	
}

unordered_map<char,char> isIsomorphic_getMap(string s, string t) {
	unordered_map<char, char> s_t;
	for (int i=0;i<s.size();i++)
	{
		if (s_t.find(s[i])==s_t.end()) // 不在里面
		{
			pair<char, char> sss = make_pair(s[i], t[i]);
			s_t.insert(sss);
		}
		else
		{
			if (s_t[s[i]] != t[i]) {
				s_t.clear();
				return s_t;
			}
		}
	}
	return s_t;
}


bool isIsomorphic(string s, string t) {

	if (s.empty() && t.empty())
		return true;

	unordered_map<char, char> s_t = isIsomorphic_getMap(s, t);

	unordered_map<char, char> t_s = isIsomorphic_getMap(t, s);

	if (s_t.size()!=t_s.size())
	{
		return false;
	}
	if(s_t.empty()||t_s.empty())
	{
		return false;
	}

	for (int  i = 0; i < s.size(); i++)
	{
		if (s_t[t_s[t[i]]]!=t[i])
		{
			return false;
		}
	}
	return true;
}
void test_isIsomorphic()
{
	string s("aba");
	string t("baa");

	cout << "isIsomorphic   " << isIsomorphic(s, t);
	return;
}

int compress_XX(vector<char>& chars) {
	unordered_map<char, int> map;
	for (int i=0;i<chars.size();i++)
	{
		map[chars[i]]++;
	}

	
	string ans;
	// for (auto it=map.begin();it!=map.end();it++)
	// {
	// 	ans.push_back(it->first);
	// 	if (it->second!=1)
	// 	{
	// 		ans += to_string(it->second);
	// 	}
	// }
	bool visited[126-35+1] = { false };
	for (auto it = 0; it<chars.size(); it++)
	{
		if (!visited[chars[it]-35])
		{
			ans.push_back(chars[it]);
			if (map[chars[it]] != 1)
			{
				ans += to_string(map[chars[it]]);
			}
			visited[chars[it] - 35] = true;
		}
		
	}

	chars.clear();
	for (int i=0;i<ans.size();i++)
	{
		chars.push_back(ans[i]);
	}

	return ans.size();
}

int compress(vector<char>& chars) {
	string ans;
	for (int i=0;i<chars.size();i++)
	{
		char ch = chars[i];
		int cnt = 0;
		while (i<chars.size()&&ch==chars[i])
		{
			cnt++;
			i++;
		}
		i--;
		if (i<chars.size())
		{
			ans.push_back(ch);
			if(cnt!=1)
				ans+=(to_string(cnt));
		}
		
	}

	chars.clear();
	for (int i = 0; i<ans.size(); i++)
	{
		chars.push_back(ans[i]);
	}
	return ans.size();
}

void test_compress()
{
	vector<char> chars({ 'a','a','a','b','b','b','a','a' });
	cout << "compressed  "<<compress(chars);
}

void  findMode_helper(TreeNode* root,vector<int>&ret) {
	if (!root)
	{
		return;
	}
	findMode_helper(root->left,ret);
	ret.push_back(root->val);
	findMode_helper(root->right,ret);

}

vector<int> findMode(TreeNode* root) {
	vector<int > ans;
	findMode_helper(root, ans);

	vector<int> ret;
	int cnt_max = -1;
	for (int i=0;i<ans.size();i++)
	{
		int kk = ans[i];
		int cnt = 0;
		while (i<ans.size()&&kk==ans[i])
		{
			cnt++;
			i++;
		}
		i--;
		if (cnt_max<cnt)
		{
			ret.clear();
			cnt_max = cnt;
			ret.push_back(kk);
		}
		else if(cnt_max==cnt)
		{
			ret.push_back(kk);
		}
	}
	return ret;
}

void test_findMode()
{
	TreeNode *node_1 = new TreeNode(1);
	TreeNode *node_2 = new TreeNode(2);
	TreeNode *node_2_1 = new TreeNode(2);

	node_2->right = node_2_1;
	node_2->left = node_1;

	findMode(node_2);

}

class NumArray {
public:
	NumArray(vector<int> nums):vec_(nums) {

	}

	int sumRange(int i, int j) {
		auto ans = 0;
		for (auto k=i;k<=j;k++)
		{
			ans += vec_[k];
		}
		return ans;
	}
private:
	vector<int> vec_;
};

bool is_exist_magic_square(vector<vector<int>>grid)
{ 
	auto m = grid.size();
	auto n = grid[0].size();
	if (m*n!=9)
	{
		return false;
	}
	auto sum = 0;
	for (auto i = 0; i<m; i++)
	{
		for (auto j = 0; j<n; j++)
		{
			sum += grid[i][j];
		}
	}
	auto item_sum = 15;
	bool is_exist_num_k[9] = { false };
	auto cnt = 0;
	for (auto k=0;k<9;k++)
	{
		for (auto i=0;i<m;i++)
		{
			for (auto j=0;j<n;j++)
			{
				if (!is_exist_num_k[k]&&grid[i][j]==k+1)
				{
					is_exist_num_k[k] = true;
					cnt++;
				}
			}
		}
	}
	if (cnt!=9)
	{
		return false;
	}
	
	for (auto i = 0; i<m; i++)
	{
		auto row_sum = 0;
		for (auto j = 0; j<n; j++)
		{
			row_sum += grid[i][j];
		}
		if (row_sum!= item_sum)
		{
			return false;
		}
	}

	for (auto i = 0; i<n; i++)
	{
		auto column_sum = 0;
		for (auto j = 0; j<m; j++)
		{
			column_sum += grid[j][i];
		}
		if (column_sum!= item_sum)
		{
			return false;
		}
	}
	auto diagonal_sum = 0;
	for (auto i = 0; i<n; i++)
	{
		
		diagonal_sum += grid[i][i];
	}
	if (diagonal_sum!= item_sum)
	{
		return false;
	}


	auto reverse_diagonal_sum = 0;
	for (auto i = 0; i<n; i++)
	{
		reverse_diagonal_sum += grid[i][n-1-i];
	}
	return reverse_diagonal_sum == item_sum;
}

vector<vector<int>> get_fixed_grid_3x3(vector<vector<int>> grid,int start_i,int start_j)
{
	vector<vector<int>> ret;
	for (auto i= start_i;i<start_i+3;i++)
	{
		vector<int> item;
		for (auto j=start_j;j<start_j+3;j++)
		{
			item.push_back(grid[i][j]);
		}
		ret.push_back(item);
	}
	return ret;
}


int numMagicSquaresInside(vector<vector<int>>& grid) 
{
	auto m = grid.size();
	auto n = grid[0].size();
	if (m < 3 || n < 3)
		return 0;

	auto fixed_m = m - 2;
	auto fixed_n = n - 2;

	auto cnt = 0;
	for (auto i=0;i<fixed_m;i++)
	{
		for (auto j=0;j<fixed_n;j++)
		{
			auto ss = get_fixed_grid_3x3(grid, i, j);
			if (is_exist_magic_square(ss))
			{
				cnt++;
			}
		}
	}
	return cnt;
}

void test_numMagicSquaresInside()
{
	vector<vector<int>> square({ { 4,3,8,4 },
								 { 9,5,1,9 },
								 { 2,7,6,2 },
	});
	cout << "Magic Squares In Grid "<<numMagicSquaresInside(square);
}


void test_NumArray()
{
	vector<int> num = { -2, 0, 3, -5, 2, -1 };
	auto s = new NumArray(num);
	cout<<s->sumRange(0, 2)<<endl;
	cout << s->sumRange(2, 5)<<endl;
	cout << s->sumRange(0, 5)<<endl;
}

TreeNode* trimBST(TreeNode* root, int L, int R) 
{
	if (!root)
	{
		return nullptr;
	}
	if(root->val<L)
	{
		return trimBST(root->right, L, R);
	}
	if(root->val>R)
	{
		return trimBST(root->left, L, R);
	}
	root->left = trimBST(root->left, L, R);
	root->right = trimBST(root->right, L, R);

	return root;

}

void test_trimBST()
{
	auto _0_node = new TreeNode(0); 
	auto _1_node = new TreeNode(1); 
	auto _2_node = new TreeNode(2); 
	auto _3_node = new TreeNode(3); 
	auto _4_node = new TreeNode(4);

	_3_node->left = _0_node;
	_3_node->right = _4_node;

	_0_node->right = _2_node;
	_2_node->left = _1_node;

	auto ret = trimBST(_3_node, 1, 3);

	return;
}

int rangeSumBST(TreeNode* root, int L, int R) 
{
	if (!root)
		return 0;

	if (!root->left && !root->right) {
		if (root->val >= L&&root->val<= R)
			return root->val;
		return 0;
	}
	if(root->val<L)
	{
		return rangeSumBST(root->right, L, R);
	}
	if (root->val>R)
	{
		return rangeSumBST(root->left, L, R);
	}
	if (root->val>=L&&root->val<=R)
	{
		return rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R) + root->val;
	}
}

void test_rangeSumBST()
{
	/*auto _0_node = new TreeNode(0);
	auto _1_node = new TreeNode(1);
	auto _2_node = new TreeNode(2);
	auto _3_node = new TreeNode(3);
	auto _4_node = new TreeNode(4);

	_3_node->left = _0_node;
	_3_node->right = _4_node;

	_0_node->right = _2_node;
	_2_node->left = _1_node;

	auto _1_node = new TreeNode(1);
	auto _2_node = new TreeNode(2);
	auto _3_node = new TreeNode(3);

	_2_node->left = _1_node;
	_2_node->right = _3_node;

	auto ret = rangeSumBST(_2_node, 1, 2);

*/
	auto node_10 = new TreeNode(10);
	auto node_5 = new TreeNode(5);
	auto node_15 = new TreeNode(15);
	auto node_3 = new TreeNode(3);
	auto node_7 = new TreeNode(7);
	auto node_18 = new TreeNode(18);
	auto node_13 = new TreeNode(13);
	auto node_1 = new TreeNode(1);
	auto node_6 = new TreeNode(6);


	node_10->left = node_5;
	node_5->left = node_3;
	node_5->right = node_7;

	node_10->right = node_15;
	node_15->right = node_18;
	node_15->left = node_13;

	node_3->left = node_1;
	node_7->left = node_6;
	




	auto ret = rangeSumBST(node_10, 6, 10);
	
	cout << "Range Sum of BST   " << ret;
}

void cut_spaces(string &s)
{
	if (s[0] != ' ')
		s = " " + s;
	
	auto index = 0;
	auto len = s.size();
	string ans;
	while (index<len)
	{
		
		while (index<len&&s[index]==' ')
		{
			index++;
		}
		ans.push_back(' ');
		while(index<len&&s[index]!=' ')
		{ 
			ans.push_back(s[index]);
			index++;
		}
		index++;
	}
	if (ans[ans.size() - 1] != ' ')
		ans += " ";
	s = ans;
}

void swap_string(string &s,int start,int end)
{
	while (start<=end)
	{
		swap(s[start], s[end]);
		start++;
		end--;
	}
}

void reverseWords(string &s) 
{
	if (s.empty())
		return;
	auto len = s.size();
	auto index = 0;

	cut_spaces(s);
	vector<int> space_index;
	for (auto i=0;i<s.size();i++)
	{
		if (s[i]==' ')
		{
			space_index.push_back(i);
		}
	}
	for (auto j=0;j<space_index.size()-1;j++)
	{
		swap_string(s, space_index[j], space_index[j + 1]);
	}

	swap_string(s, 0, s.size() - 1);
	if (s[s.size() - 1] == ' ')
		s.pop_back();
	if (s[0] == ' ')
		s= s.substr(1, s.size() - 1);

}
void test_reverseWords()
{
	string words = "the sky is blue";
	reverseWords(words);
	cout << " Reverse Words in a String " << words;
}

bool lemonadeChange(vector<int>& bills) { // 策略sum[i-1] 比 bills[i] 小 5块
	if (bills.size()==1)
	{
		return true;
	}
	auto sum = 0;
	for (auto j=0;j<bills.size();j++)
	{
		if(bills[j]==5)
		{
			sum += 5;
			continue;
		}
		if (sum-bills[j]!=-5)
		{
			return false;
		}
		sum += 5;
	//	sum = sum - bills[j];
	}
	return true;
}

void test_lemonadeChange()
{
	vector<int> ret = { 5,5,5,20,10,20 };
	cout << "Lemonade Change " << lemonadeChange(ret);
}


void get_string_adapted_size(int longer,int shorter,string &str_shorter)
{
	string ret;
	for (auto i = 0; i < longer - shorter; i++)
		ret.push_back('0');
	str_shorter = ret + str_shorter;
}

string addStrings(string num1, string num2) 
{
	
	auto num1_len = num1.size();
	auto num2_len = num2.size();
	auto longer = num1_len >= num2_len ? num1_len:num2_len;
	auto shorter = num1_len < num2_len ? num1_len:num2_len;

	auto str_longer = longer == num1_len ? num1:num2;
	auto str_shorter = shorter == num2_len ? num2 : num1;

	get_string_adapted_size(longer,shorter, str_shorter);

	reverse(str_longer.begin(), str_longer.end());
	reverse(str_shorter.begin(), str_shorter.end());

	string ack;
	auto carry = 0;
	for (auto i=0;i<longer;i++)
	{
		auto sum = (str_shorter[i] - '0') + (str_longer[i] - '0') + carry;
		carry = (sum)/10;
		ack.push_back(sum%10+'0');
		if (i==longer-1)
		{
			if (carry==1)
			{
				ack.push_back('1');
			}
		}
	}
	
	reverse(ack.begin(), ack.end());
	//cout << ack;
	return ack;

}

void test_addStrings()
{
	auto num1 = "1789";
	auto num2 = "321";
	cout << "Add Strings " << addStrings(num1,num2);
}

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
{
	auto sum_index = numeric_limits<int>::max();
	vector<string> ack;
	for(auto i=0;i<list1.size();i++)
	{
		for (auto j=0;j<list2.size();j++)
		{
			if (list1[i]==list2[j])
			{
				if (j+i<sum_index)
				{
					ack.clear();
					ack.push_back(list1[i]);
					sum_index = i + j;
				}
				else if(j+i==sum_index)
				{
					ack.push_back(list1[i]);
				}
			}
		}
	}
	return ack;
}

void test_findRestaurant()
{
	vector<string> list1 = { "Shogun","Tapioca Express","Burger King","KFC" };
	vector<string> list2 = { "KFC","Burger King","Tapioca Express","Shogun" };

	vector<string> ack = findRestaurant(list1,list2);
	cout << "Minimum Index Sum of Two Lists" << ack[0];
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	vector<int> ack;
	for (auto i=0;i<nums1.size();i++)
	{
		for (auto j=0;j<nums2.size();j++)
		{
			if(nums1[i]==nums2[j])
			{
				ack.push_back(nums1[i]);
				nums2.erase(nums2.begin() + j);
				j--;
			}
		}
	}
	return ack;
}

void test_intersect()
{
	vector<int> nums1 = { 1,2,2,1};
	vector<int> nums2 = { 2 };
	vector<int> ack = intersect(nums1, nums2);
	cout << "Intersection of Two Arrays II" << ack[0];
}

void binaryTreePaths_helper_wrong(TreeNode *root,string &ans,vector<string>&ack)
{
	if (!root)
	{
		return;		
	}
	if (!root->left&&!root->right)
	{
		ans += to_string(root->val);
		ack.push_back(ans + to_string(root->val));
		return;
	}
	
	if (root->left) {
		ans += to_string(root->val) + "->";
		binaryTreePaths_helper_wrong(root->left,ans, ack);
	}
	ans.pop_back();
	ans.pop_back();
	ans.pop_back();
	if(root->right)
	{
		ans += to_string(root->val) + "->";
		binaryTreePaths_helper_wrong(root->right, ans, ack);
	}
}

void binaryTreePaths_helper_AC(TreeNode *root, string ans, vector<string>&ack)
{
	if (!root)
	{
		return;
	}
	if (!root->left && !root->right)
	{
		ack.push_back(ans + to_string(root->val));

	}

	if (root->left) {
		binaryTreePaths_helper_AC(root->left, ans + to_string(root->val) + "->", ack);
	}

	if (root->right)
	{

		binaryTreePaths_helper_AC(root->right, ans + to_string(root->val) + "->", ack);
	}
}


vector<string> binaryTreePaths(TreeNode* root) {
	vector<string> ans;
	string ack;
	binaryTreePaths_helper(root,ack, ans);
	return ans;
}

void test_binaryTreePaths()
{
	auto node_1 = new TreeNode(1);
	auto node_2 = new TreeNode(2);
	auto node_3 = new TreeNode(3);
	auto node_5 = new TreeNode(5);

	node_1->left = node_2;
	node_1->right = node_3;

	node_2->right = node_5;

	vector<string> ack = binaryTreePaths(node_1);
	cout << "Binary Tree Paths" << ack[0];
}

int main()
{
//	cout << "woolgatherer.cpp";
	{
	//	test_findMaxAverage();
	//	test_addBinary();
	//	test_isSymmetric();
	//	test_searchInsert();
	//	test_reverseStr();
	//	test_backspaceCompare();
	//	test_insertIntoBST();
	//	test_redundant_else(2);
	//	test_isPalindrome();
	//	test_reverseBits();
	//	test_isPalindrome_linkList();
	//	test_convertToTitle();
	//	test_buddyStrings();
	}
	//test_getIntersectionNode();
	//test_isIsomorphic();
	//test_compress();
	//test_findMode();
	//test_NumArray();
	//test_numMagicSquaresInside();
	//test_trimBST();
	//test_rangeSumBST();
	//test_reverseWords();
	//test_lemonadeChange(); // ?
	//test_addStrings();
	//test_findRestaurant();
	//test_intersect();
	test_binaryTreePaths();

}
