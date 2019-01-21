#include "head.h"
#include <thr/xthrcommon.h>
// Username:peng_peng
// password : Peng0peng

#if 0


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
	binaryTreePaths_helper_AC(root,ack, ans);
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

bool flipEquiv(TreeNode* root1, TreeNode* root2) 
{
	if (!root1&&!root2)
	{
		return true;
	}
	if (!root1&&root2||!root2&&root1)
	{
		return false;
	}
	bool left_left = flipEquiv(root1->left, root2->left);
	bool left_right = flipEquiv(root1->left, root2->right);
	bool right_right = flipEquiv(root1->right, root2->right);
	bool right_left = flipEquiv(root1->right, root2->left);

	return root1->val == root2->val && (left_left || left_right) && (right_right || right_left);
}

void test_flipEquiv()
{
	auto node_1 = new TreeNode(1);
	auto node_2 = new TreeNode(2);
	auto node_3 = new TreeNode(3);
	auto node_4 = new TreeNode(4);
	auto node_5 = new TreeNode(5);
	auto node_6 = new TreeNode(6); 
	auto node_7 = new TreeNode(7);
	auto node_8 = new TreeNode(8);

	node_1->left = node_2;
	node_1->right = node_3;

	node_2->left = node_4;
	node_2->right = node_5;

	node_3->left = node_6;

	node_5->left = node_7;
	node_5->right = node_8;

	auto _1_node_1 = new TreeNode(1);
	auto _1_node_2 = new TreeNode(2);
	auto _1_node_3 = new TreeNode(3);
	auto _1_node_4 = new TreeNode(4);
	auto _1_node_5 = new TreeNode(5);
	auto _1_node_6 = new TreeNode(6);
	auto _1_node_7 = new TreeNode(7);
	auto _1_node_8 = new TreeNode(8);

	_1_node_1->left = _1_node_3;
	_1_node_1->right = _1_node_2;

	_1_node_2->left = _1_node_4;
	_1_node_2->right = _1_node_5;

	_1_node_3->right = _1_node_6;

	_1_node_5->left = _1_node_8;
	_1_node_5->right = _1_node_7;

	bool ack = flipEquiv(node_1, _1_node_1);

	cout << " Flip Equivalent Binary Trees" << ack;
}

vector<int> deckRevealedIncreasing(vector<int>& deck) {
	queue<int> ss;
	vector<int> ack;
	for (auto i:deck)
		ss.push(i);
	while (!ss.empty())
	{
		int tmp = ss.front();
		ack.push_back(tmp);
		ss.pop();
		if (!ss.empty())
		{
			int change_num = ss.front();
			ss.pop();
			ss.push(change_num);
		}
	}
	return ack;




}

void test_deckRevealedIncreasing()
{
	vector<int> entry({ 2,13,3,11,5,17,7 });
	vector<int>ack = deckRevealedIncreasing(entry);
	cout << "Reveal Cards In Increasing Order" << ack[0];
}

int get_sum_binary_vector(vector<int> &vec)
{
	 auto nums = vec.size();
	 auto ack = 0;
	 for (int i = nums-1; i >=0 ; i--)
	 	ack += vec[i] * pow(2 , (nums - 1 - i));
	return ack;
}	

int get_sum_matrix(vector<vector<int>> &A)
{
	int ack = 0;
	for (auto j = 0; j < A.size(); j++)
		ack += get_sum_binary_vector(A[j]);
	return ack;
}

void trans_matrix_col(vector<vector<int>>& A,int col)
{
	for (auto i=0;i<A.size();i++)
	{
		A[i][col] = !(A[i][col] == 1);
	}
}

void trans_matrix_row(vector<vector<int>>& A,int row)
{
	for (auto j=0;j<A[row].size();j++)
	{
		A[row][j] = !(A[row][j] == 1);
	}
}

int matrixScore(vector<vector<int>>& A) 
{
	
	auto max = -1;
	while(get_sum_matrix(A)>max)
	{
		max = get_sum_matrix(A);
		for (auto i=0;i<A.size();i++)
		{
			trans_matrix_row(A, i);
			if(get_sum_matrix(A)>max)
			{
				max = get_sum_matrix(A);
			}
			else
			{
				trans_matrix_row(A, i);
			}
		}

		for (auto i = 0; i<A[0].size(); i++)
		{
			trans_matrix_col(A, i);
			if (get_sum_matrix(A)>max)
			{
				max = get_sum_matrix(A);
			}
			else
			{
				trans_matrix_col(A, i);
			}
		}
	}
	return max;
}

void test_matrixScore()
{
	vector<vector<int>> A({ {1,1},{1,1},{0,1} });
	auto ack = matrixScore(A);
	cout << "Score After Flipping Matrix " << ack;
}



void test_vector_remove(vector<int > &nums)
{
	for (size_t i = 0; i < nums.size(); i++)
	{
		nums.erase(nums.begin() + i);
		i--;
	}
}

int removeDuplicates(vector<int>& nums) {
	for (auto i=0;i<nums.size();i++)
	{
		auto cur = nums[i];
		while ((i+1<nums.size())&&nums[i+1]==cur)
		{
			nums.erase(nums.begin() + i);
			//i--;
		}
		
	}
	// return nums.size();
	//test_vector_remove(nums);
	return nums.size();
}


void test_removeDuplicates()
{
	vector<int> ack = { 0,0,1,1,1,2,2,3,3,4,4};
	auto ans = removeDuplicates(ack);
	cout << "Remove Duplicates from Sorted Array" << ans;
}

Node* intersect(Node* quadTree1, Node* quadTree2) 
{
	if (!quadTree1&&!quadTree2)
	{
		return nullptr;
	}

	if (quadTree1->isLeaf&&quadTree2->isLeaf)
	{
		return new Node(quadTree1->val||quadTree2->val,true,0,0,0,0);
	}

	auto top_left = new Node(true, true, 0, 0, 0, 0);
	if (quadTree1->isLeaf &&quadTree2->isLeaf)
		 top_left = intersect(quadTree1, quadTree2);
	else if (!quadTree1->isLeaf&&quadTree2->isLeaf)
		 top_left = intersect(quadTree1->topLeft, quadTree2);
	else if(quadTree1->isLeaf&&!quadTree2->isLeaf)
		 top_left = intersect(quadTree1, quadTree2->topLeft);
	else
		 top_left = intersect(quadTree1->topLeft, quadTree2->topLeft);


	auto top_right = new Node(true, true, 0, 0, 0, 0);
	if (quadTree1->isLeaf &&quadTree2->isLeaf)
		top_right = intersect(quadTree1, quadTree2);
	else if (!quadTree1->isLeaf&&quadTree2->isLeaf)
		top_right = intersect(quadTree1->topRight, quadTree2);
	else if (quadTree1->isLeaf && !quadTree2->isLeaf)
		top_right = intersect(quadTree1, quadTree2->topRight);
	else
		top_right = intersect(quadTree1->topRight, quadTree2->topRight);



	auto bottom_left = new Node(true, true, 0, 0, 0, 0);
	if (quadTree1->isLeaf &&quadTree2->isLeaf)
		bottom_left = intersect(quadTree1, quadTree2);
	else if (!quadTree1->isLeaf&&quadTree2->isLeaf)
		bottom_left = intersect(quadTree1->bottomLeft, quadTree2);
	else if (quadTree1->isLeaf && !quadTree2->isLeaf)
		bottom_left = intersect(quadTree1, quadTree2->bottomLeft);
	else
		bottom_left = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);


	auto bottom_right = new Node(true, true, 0, 0, 0, 0);
	if (quadTree1->isLeaf &&quadTree2->isLeaf)
		bottom_right = intersect(quadTree1, quadTree2);
	else if (!quadTree1->isLeaf&&quadTree2->isLeaf)
		bottom_right = intersect(quadTree1->bottomRight, quadTree2);
	else if (quadTree1->isLeaf && !quadTree2->isLeaf)
		bottom_right = intersect(quadTree1, quadTree2->bottomRight);
	else
		bottom_right = intersect(quadTree1->bottomRight, quadTree2->bottomRight);


	if (top_left->val==top_right->val
		&&top_right->val == bottom_left->val
		&&bottom_left->val==bottom_right->val) // 合并的条件是得到的结果一样的
	{
		auto tmp = top_left;
		delete top_left;
		delete top_right;
		delete bottom_left;
		delete bottom_right;
		return new Node(tmp->val, true, 0, 0, 0, 0);
	}
	return new Node(false, false, top_left, top_right, bottom_left, bottom_right);

}

void test_intersect_Quad_Node()
{


	auto node_1_top_left = new Node(true, true, NULL, NULL, NULL, NULL);
	auto node_1_top_right = new Node(true, true, NULL, NULL, NULL, NULL);
	auto node_1_bottom_left = new Node(false, true, NULL, NULL, NULL, NULL);
	auto node_1_bottom_right = new Node(false, true, NULL, NULL, NULL, NULL);

	auto _1node = new Node(false, false, node_1_top_left, node_1_top_right, node_1_bottom_left, node_1_bottom_right);



	auto _node_1_top_left = new Node(false, true, NULL, NULL, NULL, NULL);
	auto _node_1_top_right = new Node(false, true, NULL, NULL, NULL, NULL);
	auto _node_1_bottom_left = new Node(true, true, NULL, NULL, NULL, NULL);
	auto _node_1_bottom_right = new Node(true, true, NULL, NULL, NULL, NULL);

	auto _node_2_1 = new Node(true, true, 0, 0, 0, 0);
	auto _node_2_2 = new Node(false, false, _node_1_top_left, _node_1_top_right, _node_1_bottom_left, _node_1_bottom_right);
	auto _node_2_3 = new Node(true, true, 0, 0, 0, 0);
	auto _node_2_4 = new Node(true, true, 0, 0, 0, 0);

	auto node_2 = new Node(false, false, _node_2_1, _node_2_2, _node_2_3, _node_2_4);

	auto ack = intersect(node_1_top_left, _node_2_2);

	cout << "Quad Tree Intersection" << 11;
}



bool isMountainArray(vector<int>& A,int index)
{
	auto ascending = true;
	for (auto i =0;i<index;i++)
	{
		if (A[i]>=A[i+1])
		{
			ascending = false;
		}
	}

	auto descending = true;
	for (auto i = index; i<A.size()-1; i++)
	{
		if (A[i] <= A[i + 1])
		{
			descending = false;
		}
	}

	return ascending&&descending;

}

bool validMountainArray(vector<int>& A) {
	if (A.size() < 3)
		return false;
	for (auto i=1;i<A.size()-1;i++)
	{
		if (isMountainArray(A,i))
		{
			return true;
		}
	}
	return false;
}

void test_validMountainArray()
{
	vector<int> ack({ 3,5,5,5 });
	cout << "Valid Mountain Array" << validMountainArray(ack);
}


bool func(pair<char,int>&a,pair<char,int>&b)
{
	return a.second > b.second;
}


string frequencySort(string s) 
{
	unordered_map<char, int> map;
	for (auto ch : s)
	{
		if (map.find(ch)!=map.end()) // 存在ch
		{
			map[ch] = map[ch]++;
			
		}
		else
		{
			map[ch]++;
		}
		
	}
	vector<pair<char, int>> vec;
	auto it = map.begin();
	while (it != map.end())
	{
		vec.push_back(make_pair(it->first,it->second));
		++it;
	}

	sort(vec.begin(), vec.end(), func);
	string ret;
	auto it_vec = vec.begin();
	while (it_vec !=vec.end())
	{
		for (auto i=0;i<it_vec->second;i++)
			ret.push_back(it_vec->first);
		++it_vec;
	}
	return ret;
}



void test_frequencySort()
{
	string ack("cccaaa");
	string ans = frequencySort(ack);
	cout << "Sort Characters By Frequency  " << ans;
}





bool func_int(pair<int, int>&a, pair<int, int>&b)
{
	return a.second > b.second;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> map;
	for (auto ch : nums)
	{
		map[ch]++;
	}
	vector<pair<int, int>> vec;
	auto it = map.begin();
	while (it != map.end())
	{
		vec.push_back(make_pair(it->first, it->second));
		++it;
	}

	sort(vec.begin(), vec.end(), func_int);
	vector<int> ret;
	auto vec_it = vec.begin();

	auto cnt = 0;
	while(vec_it!=vec.end())
	{
		if(cnt<k)
		{
			ret.push_back(vec_it->first);
			cnt++;
		}
		++vec_it;
	}
	
	return ret;
}

void test_topKFrequent()
{
	vector<int> nums({ 1,1,1,2,2,3 });
	auto ans = topKFrequent(nums, 2);
	cout << " Top K Frequent Elements" << ans[0];
}

int get_tree_height(TreeNode *node)
{
	if (!node)
	{
		return 0;
	}
	int left = get_tree_height(node->left);
	int right = get_tree_height(node->right);
	return max(left, right) + 1;
}


void print_tree_helper(TreeNode *root,int cur_H, int start,int end,int height,vector<vector<string>>&ack)
{
	if (!root)
	{
		return;
	}
	if(cur_H==height)
	{
		return;
	}
	ack[cur_H][(start + end) / 2] = to_string(root->val);
	print_tree_helper(root->left, cur_H + 1, start, (start + end) / 2, height, ack);
	print_tree_helper(root->right, cur_H + 1, (start + end) / 2 + 1, end, height, ack);
}

vector<vector<string>> printTree(TreeNode* root) 
{
	int h = get_tree_height(root);
	int w = pow(2, h) - 1;
	vector<vector<string>> ack(h, vector<string>(w, ""));
	print_tree_helper(root, 0, 0, w - 1, h, ack);
	return ack;
}


void test_printTree()
{
	auto node_1 = new TreeNode(1);
	auto node_2 = new TreeNode(2);
	auto node_3 = new TreeNode(3);
	auto node_4 = new TreeNode(4);
	auto node_5 = new TreeNode(5);

	node_1->left = node_2;
	node_2->left = node_3;
	node_3->left = node_4;

	node_1->right = node_5;

	auto ack = printTree(node_1);

	return;
}


int bigger_than_special_index_num(vector<int>&row_nums,int index,int target)
{
	auto cnt = 0;
	for (auto i=0;i<index;i++)
	{
		if (row_nums[i]>target)
		{
			cnt++;
		}
	}
	return cnt;
}




vector<int> get_vec_before_index_row(vector<vector<int>>&M,int row_index)
{
	vector<int> ack;
	for (auto j=0;j<row_index;j++)
	{
		ack.push_back(M[row_index + 1][j]);
	}
	return ack;
}


vector<int> get_vec_before_index_col(vector<vector<int>>&M, int col_index)
{
	vector<int> ack;
	for (auto i=0;i<col_index;i++)
	{
		ack.push_back(M[i][col_index + 1]);
	}
	return ack;
}

int kthSmallest(vector<vector<int>>& matrix, int k) 
{
	vector<int> dialog; // 存在对角线的数字的rank;是逆序的
	auto n = matrix.size();
	for (auto i=0;i<n-1;i++)
	{
		if (i==0)
		{
			dialog.push_back(1);
		}
		else
		{
			vector<int> row = get_vec_before_index_row(matrix,i);
			vector<int> col = get_vec_before_index_col(matrix, i);
			auto cnt = bigger_than_special_index_num(row, i - 1, matrix[i][i]) + bigger_than_special_index_num(col,i-1,matrix[i][i]);

		}
	}
	return dialog[0];
}


void test_kthSmallest()
{
	vector<vector<int>> ack = {
		{1, 5, 9},
		{10,11,13},
		{12,13,15},
	};
	int k = 8;
	auto ans = kthSmallest(ack, k);
	cout << "Kth Smallest Element in a Sorted Matrix " << ans;
}

ListNode *detectCycle(ListNode *head) {
	auto pfast = head;
	auto pslow = head;

	while (pfast&&pfast->next) //此时都在Z的位置
	{
		pfast = pfast->next;
		pfast = pfast->next;
		pslow = pslow->next;
		if(pslow==pfast)
			break;
	}

	if (!pfast || !pfast->next)
		return nullptr;
	pslow = head;
	while (pslow!=pfast)
	{
		pslow = pslow->next;
		pfast = pfast->next;	
	}

	return pslow;
}


void test_detectCycle()
{
	auto node_3 = new ListNode(3);
	auto node_2 = new ListNode(2);
	auto node_0 = new ListNode(0);
	auto node_4 = new ListNode(4);


	node_3->next = node_2;
	node_2->next = node_3;
	// node_0->next = node_4;
	// node_4->next = node_2;

	auto ack = detectCycle(node_3);

	cout << "  Linked List Cycle II " << ack->val;
	return;

}

int findDuplicate(vector<int>& nums) {
	auto fast = nums[0];
	auto slow = nums[0];
	while (true)
	{
		fast = nums[fast];
		slow = nums[nums[slow]];
		if (fast==slow)
		{
			break;
		}
	}
	fast = nums[0];
	while (fast!=slow)
	{
		fast = nums[fast];
		slow = nums[slow];

	}

	return fast;
}

void test_findDuplicate()
{
	vector<int> ack = { 1,3,4,2,2};
	auto res = findDuplicate(ack);
	cout << "Find the Duplicate Number " << res;
}


TreeNode* addOneRow(TreeNode* root, int value, int depth) {
	if (depth==1)
	{
		auto ans = new TreeNode(value);
		ans->left = root;
		return ans;
	}
	if(depth==2)
	{
		auto lf = new TreeNode(value);
		lf->left = root->left;
		//lf->right = nullptr;
		root->left = lf;

		auto lg = new TreeNode(value);
		lg->right = root->right;
		//lg->left = nullptr;
		root->right = lg;
		return root;
	}
	if(root->left)
		root->left = addOneRow(root->left, value, depth - 1);
	if(root->right)
		root->right = addOneRow(root->right, value, depth-1);
	return root;
}


void test_addOneRow()
{
	auto node_4 = new TreeNode(4);
	auto node_2 = new TreeNode(2);
	auto node_6 = new TreeNode(6);
	

	auto node_3 = new TreeNode(3);
	auto node_1 = new TreeNode(1);
	auto node_5 = new TreeNode(5);


	node_4->left = node_2;
	node_4->right = node_6;
	node_2->left = node_3;
	node_2->right = node_1;
	node_6->left = node_5;

	auto ack = addOneRow(node_4, 1, 2);
	cout << "Add One Row to Tree " << ack->val;

}

void get_tree_node_left_node(TreeNode *root,vector<int> &ret)
{
	if (!root)
	{
		return;
	}
	get_tree_node_left_node(root->left, ret);
	if (!root->left && !root->right)
		ret.push_back(root->val);
	get_tree_node_left_node(root->right, ret);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
	vector<int>ack1;
	vector<int>ack2;

	get_tree_node_left_node(root1, ack1);
	get_tree_node_left_node(root2, ack2);
	return ack1 == ack2;
}

void test_leafSimilar()
{
	auto node_3 = new TreeNode(3);
	auto node_5 = new TreeNode(5);
	auto node_1 = new TreeNode(1);
	auto node_6 = new TreeNode(6);
	auto node_2 = new TreeNode(2);
	auto node_9 = new TreeNode(9);
	auto node_8 = new TreeNode(8);
	auto node_7 = new TreeNode(7);
	auto node_4 = new TreeNode(4);

	node_3->left = node_5;
	node_3->right = node_1;


	node_5->left = node_6;
	node_5->right = node_2;

	node_1->left = node_9;
	node_1->right = node_8;

	node_2->left = node_7;
	node_2->right = node_4;

	vector<int> ack;
	get_tree_node_left_node(node_3, ack);
	return;
}


//dir first 控制i,j   second 控制 方向
//first =  1  i 
//first = -1  j
// second =  1  +
// second = -1  -
pair<int,int> status_change(pair<int,int>& cur,pair<int,int>& anchor,int force,pair<int,int>&dir) 
{
	pair<int, int> ret;
	if (abs(cur.first-anchor.first)==force&&abs(cur.second-anchor.second)!=force) //只有继续变化second
	{
		ret.first = cur.first;
		ret.second += dir.second;
		return ret;
	}
	
	if (abs(cur.first - anchor.first) != force&&abs(cur.second - anchor.second) == force) //只有继续变化first
	{
		ret.first += dir.second;
		ret.second = cur.second;
		return ret;
	}

	if (abs(cur.first - anchor.first) == force&&abs(cur.second - anchor.second) == force)  // 现在i,j 都达到了极限
	{
		if(dir.first==1)
		{
			if(dir.second>0) // 控制 i 达到正向最大了
			{
				ret.first = cur.first;
				ret.second = cur.second - dir.second;

				dir.first = -1;
				dir.second = -dir.second;

			}
			else if(dir.second<0) //  控制 i 达到反向最大了 
			{
				ret.first = cur.first;
				ret.second = cur.second - dir.second;

				dir.first = -1;
				dir.second = -dir.second;
			}
		}
		else if(dir.first==-1)
		{
			if (dir.second>0) // 控制 j 达到正向最大了
			{
				ret.first = cur.first - dir.second;
				ret.second = cur.second;

				dir.first = 1;
				dir.second = -dir.second;

			}
			else if (dir.second<0) //  控制 j 达到反向最大了 
			{
				ret.first = cur.first - dir.second;
				ret.second = cur.second;

				dir.first = -1;
				dir.second = -dir.second;
			}
		}
	}

	return ret;


}


vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) 
{
	//pair<int, int> status_change(pair<int, int>& cur, pair<int, int>& anchor, int force, pair<int, int>&dir)

	auto ss =  status_change(make_pair(r0+1, c0+1), make_pair(r0, c0), 1, make_pair(1, 1));

	return{ {} };
}

void test_spiralMatrixIII()
{
	auto R = 5;
	auto C = 6;
	auto r0 = 1;
	auto c0 = 4;
	
	spiralMatrixIII(R, C, r0, c0);


}


int numTrees(int n) {
	vector<int> ack(n+1, 0);
	ack[0] = 1;
	ack[1] = 1;
	for (auto i=2;i<=n;i++)
	{
		for (auto j=0;j<i;j++)
		{
			ack[i] += ack[j] * ack[i-1-j];
		}
	}

	return ack[n];

}

void test_numTrees()
{
	auto n = 3;
	cout << "Unique Binary Search Trees" << numTrees(n);
}

bool vec_func(pair<int,int>&a,pair<int,int>&b)
{
	return a.first < b.first;
}

bool isNStraightHand(vector<int>& hand, int W) 
{
	if (hand.size()%W)
	{
		return false;
	}
	unordered_map<int, int>gpu;
	for (auto i=0;i<hand.size();i++)
	{
		gpu[hand[i]]++;
	}
	vector<pair<int, int>> vec;
	auto m_it = gpu.begin();
	while (m_it!=gpu.end())
	{
		vec.push_back(*m_it);
		++m_it;
	}
	sort(vec.begin(), vec.end(), vec_func);



	for (auto k =0;k<vec.size();)
	{
		if(vec[k].second>0)
			vec[k].second -= 1;
		else if (vec[k].second == 0) {
			k++;
			continue;
		}
		auto index = vec[k].first;
		for (auto i=1;i<W;i++)
		{
			if(k+i>=vec.size())
			{
				return false;
			}
			if (vec[k+i].first!=index+i)
			{
				return false;
			}
			
			if(vec[k+i].first==index+i)
			{
				vec[k + i].second -= 1;
			}
		}
		
	}
	for (auto s= 0;s<vec.size();s++)
	{
		if (vec[s].second)
		{
			return false;
		}
	}

	return true;
}

void test_isNStraightHand()
{
	vector<int> cpu = { 1,1,2,2,3,3 };
	int w = 2;
	auto ack = isNStraightHand(cpu, w);
	cout << "Hand of Straights " << ack;
}

int get_greatest_factor_2_nums(int a,int b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if (b==0)
	{
		return a;
	}
	return get_greatest_factor_2_nums(b, a%b);
}




/*int get_final_all_2_one(vector<int>factor)
{
	if (factor.size()==1)
	{
		return factor[0];
	}
	vector<int> left_vec(factor.begin(), factor.begin() + factor.size() / 2);
	vector<int> right_vec(factor.begin() + factor.size() / 2, factor.end());

	auto left = get_final_all_2_one(left_vec);
	auto right = get_final_all_2_one(right_vec);

	cout << "renttieijasdfsf" << left << right << endl;
	return get_greatest_factor_2_nums(left, right);
}

int get_least_common_multiple(vector<int> &multiple)
{
	return get_final_all_2_one(multiple);
}*/

//分母
vector<int> get_denominator_(string expression)
{
	vector<int> denominator_vec;
	for (auto i = 0; i<expression.size(); i++)
	{
		if (expression[i] == '/')
		{
			i++;
			string tmp;
			auto j = 0;
			while (expression[i + j] != '+'&&expression[i + j] != '-'&&i + j<expression.size())
			{
				tmp.push_back(expression[i + j]);
				j++;
			}
			auto num = stoi(tmp);
			denominator_vec.push_back(num);
		}
	}
	return denominator_vec;
}

void  normalization_string(string &str)
{
	if (isdigit(str[0]))
	{
		str.insert(0, "+");
	}
}
// 分子
vector<int> get_numerator_(string expression) 
{
	vector<int> numerator_vec;
	normalization_string(expression);

	for (auto i = 0; i<expression.size(); i++)
	{
		
		if (expression[i] == '+'||expression[i]=='-')
		{
			auto sign = expression[i] == '+' ? 1 : -1;
			i++;
			string tmp;
			auto j = 0;
			while (expression[i + j] != '/'&&i + j<expression.size())
			{
				tmp.push_back(expression[i + j]);
				j++;
			}
			auto num = stoi(tmp);
			numerator_vec.push_back(num*sign);
		}
	}
	return numerator_vec;
}


int get_less_common_multipled(vector<int> list)
{
	auto first_num = list[0];
	for (auto u = 1;u<list.size();u++)
	{
		auto second_num = list[u];
		auto max_num = get_greatest_factor_2_nums(first_num, second_num);
		first_num = first_num*second_num / max_num;
	}
	return first_num;
}

string fractionAddition(string expression) 
{
	auto denominator = get_denominator_(expression);
	auto numerator_vec = get_numerator_(expression);

	auto denominator_goes_to_num  = 1;
	auto greatest_factor = get_less_common_multipled(denominator);

	


	vector<int> numerator_multipled;
	for (auto i =0;i<numerator_vec.size();i++)
	{
		numerator_multipled.push_back(greatest_factor/denominator[i]*numerator_vec[i]);
	}

	auto ack_last = 0;
	for (auto k =0;k<numerator_multipled.size();k++)
	{
		ack_last += numerator_multipled[k];
	}

	cout << "dfjsdkfj sf" << ack_last;

	auto ret_greatest = get_greatest_factor_2_nums(ack_last, greatest_factor);


	return to_string(ack_last/ret_greatest) + "/" + to_string(greatest_factor/ret_greatest);
	
}

void test_fractionAddition()
{
	string fax = "5/3+1/3";
	auto ack = fractionAddition(fax);
	cout << "Fraction Addition and Subtraction" << ack << endl;

}

int time_pass_based_0000(string A)
{
	auto hours = 0;
	auto minutes = 0;

	string str_hours(A, 0,2);
	string str_minutes(A,3,2);

	return stoi(str_hours) * 60 + stoi(str_minutes);
}

int time_stamp_diff(string A,string B)
{
	auto start = time_pass_based_0000(A);
	auto end = time_pass_based_0000(B);

	if (start>12 * 60)
	{
		if (end<12*60)
		{
			end += 24 * 60;
		}
	}


	return abs(end - start);
}

int findMinDifference(vector<string>& timePoints) 
{
	/*auto min = numeric_limits<int>::max();
	for (auto i=0;i<timePoints.size()-1;i++)
	{
		for (auto j=i+1;j<timePoints.size();j++)
		{
			auto k = time_stamp_diff(timePoints[i], timePoints[j]);
			auto kk = time_stamp_diff(timePoints[j], timePoints[i]);
			int kkk = k < kk ? k : kk;
			if (kkk<min)
			{
				min = kkk;
			}
		}
	}
		
	cout << min;
	return min;*/

	auto ret = INT_MAX;
	vector<int>nums;
	for (auto k = 0; k < timePoints.size(); k++)
		nums.push_back(time_pass_based_0000(timePoints[k]));
	sort(nums.begin(), nums.end());
	for (auto s=1;s<nums.size();s++)
	{
		ret = min(ret, nums[s] - nums[s - 1]);
	}
	return min(ret, 24 * 60 + nums[0] - nums.back());

}

void test_findMinDifference()
{
	
	vector<string> vec({ "05:31","22:08","00:35" });
	
	int jax = findMinDifference(vec);
	cout << "Minimum Time Difference" << jax;
}

vector<vector<int>> levelOrder(TreeNode* root)
{
	vector<vector<int>>ret;
	queue<TreeNode *>qqqq;
	qqqq.push(root);
	while (!qqqq.empty())
	{
		auto so = qqqq.size();
		vector<int> ack;
		for (auto i = 0; i < so; i++)
		{
			auto top = qqqq.front();
			ack.push_back(top->val);
			qqqq.pop();
			if (top->left)
			{
				qqqq.push(top->left);
			}
			if (top->right)
			{
				qqqq.push(top->right);
			}
		}
		ret.push_back(ack);
	}
	return ret;
}

void test_levelOrder()
{
	auto node_3 = new TreeNode(3);
	auto node_9 = new TreeNode(9);
	auto node_20 = new TreeNode(20);
	auto node_15 = new TreeNode(15);
	auto node_7 = new TreeNode(7);


	node_3->left = node_9;
	node_3->right = node_20;

	node_20->left = node_15;
	node_20->right = node_7;
	auto ack = levelOrder(node_3);
	cout << "Binary Tree Level Order Traversal " << ack[0][0];
}


string decodeString(string s) {
	vector<pair<int, string>> ack;
	for (auto i = 0; i<s.size(); i++)
	{
		auto ch = s[i];
		if (isdigit(ch))
		{
			auto k = 0;
			string tmp;
			i++; //数字加1
			i++; //'[' 加1
			while (i + k<s.size() && s[i + k] != ']')
			{
				tmp.push_back(s[i + k]);
				k++;
			}
			pair<int, string> ans = make_pair(ch - '0', tmp);
			ack.push_back(ans);
			i += k;
		}
		else if (isalpha(ch))
		{
			string tmp(1, ch);
			pair<int, string> ans = make_pair(1, tmp);
			ack.push_back(ans);

		}
	}
	string ret;
	for (auto k = 0; k<ack.size(); k++)
	{
		auto num = (ack[k].first);
		for (auto v = 0; v<num; v++)
		{
			ret += ack[k].second;
		}
	}
	return ret;
}

/*
 *
 *   adnfndfds
 *	 3[ef]
 *	 
 */
bool is_last_partten(string s)
{
	if(isdigit(s[0]))
	{
		return s[1] == '['&&s.back() == ']';
	}
	for (auto j=0;j<s.size();j++)
	{
		if (!isalpha(s[j]))
		{
			return false;
		}
	}
	return true;
}
//"100[leetcode]"
string handler_last_partten(string s)
{
	string ret;
	if (isdigit(s[0]))
	{
		auto i = 0;
		while (isdigit(s[i]))
		{
			i++;
		}
		auto num = stoi(string(s.begin(),s.begin()+i));

		string unit(s, i+1, s.size() - i-2);
		for (auto i=0;i<num;i++)
		{
			ret += unit;
		}
	}
	else
	{
		ret = s;
	}
	return ret;
}

/*
 *
 *  得到合适的右括号位置
 */
// [fafj[dadfas][daf[aasd]afd]sakldf]
vector<pair<int,int>> get_right_bracket_pos(string exp)
{
	vector<pair<int, int>>ret;
	stack<char> s;
	stack<int> p;
	auto i = 0;
	for (auto i=0;i<exp.size();i++)
	{
		if (exp[i]=='[')
		{
			s.push(exp[i]);
			p.push(i);
		}
		else if(exp[i] == ']')
		{
			auto left = p.top();
			cout << i << "   " << left << endl;
			auto qut = make_pair(left, i);
			ret.push_back(qut);
			s.pop();
			p.pop();
		}
	}
	return ret;
}

string decodeString_v2(string s) {
	string ret;
	if(is_last_partten(s))
	{
		ret = handler_last_partten(s);
		return ret;
	}
	auto list = get_right_bracket_pos(s);
	for (auto i=0;i<list.size();i++)
	{
		ret += decodeString(string(s.begin(), s.begin() + list[i].first-1));
		ret+= decodeString(string(s.begin() + list[i].first-1, s.begin() + list[i].second+1));
		ret += decodeString( string(s.begin()+list[i].second+1, s.end()));

	}
	return ret;
}

string decodeString_v3(string s)
{
	auto list = get_right_bracket_pos(s);
	while (list.size()>0)
	{
		auto left = list[0].first;
		auto right = list[0].second;


		auto j = left-1;
		auto i = 0;
		if (isdigit(s[j]))
		{
			while (j>=0&&isdigit(s[j]))
			{
				j--;
				i++;
			}
		}
		auto decodeed_one = handler_last_partten(string(s.begin() + left-i, s.begin() + right+1));
		s.replace(s.begin() + left - i, s.begin() + right + 1, decodeed_one);
		list = get_right_bracket_pos(s);
	}
	return s;
}

void test_decodeString()
{
	auto bar("2[abc]3[cd]ef");
	auto ack = decodeString_v3(bar);
	
	cout << "394. Decode String" << ack;
}


vector<pair<int, int>> get_parentheses_pos(string exp)
{
	vector<pair<int, int>>ret;
	stack<char> s;
	stack<int> p;
	auto i = 0;
	for (auto i = 0; i<exp.size(); i++)
	{
		if (exp[i] == '(')
		{
			s.push(exp[i]);
			p.push(i);
		}
		else if (exp[i] == ')')
		{
			auto left = p.top();
			cout << left << "   " << i << endl;
			auto qut = make_pair(left, i);
			ret.push_back(qut);
			s.pop();
			p.pop();
		}
	}
	return ret;
}

string get_trans_string(string tt)
{
	if(tt[0]=='(')
	{
		string num_str(tt.begin() + 1, tt.end() - 1);
		if (num_str.empty())
		{
			return "1";
		}
		if (num_str.size() == 1) {
			auto num_ = stoi(num_str);
			return  to_string(num_ * 2);
		}
		else 
		{
			auto sum = 0;
			// 需要处理特殊的情况 10 不可能出现
			if (num_str.back() == '0')
				return to_string(2 * (stoi(num_str)));



			for (auto k = 0; k < num_str.size(); k++)
				sum += (num_str[k] - '0');
			return to_string(2*sum);
		}
	}
	if (tt.size()>1)
	{
		auto sum = 0;
		for (auto k = 0; k < tt.size(); k++)
			sum += (tt[k] - '0');
		return to_string(sum);
	}
	return tt;
}

vector<int> how_2_cut_str()
{
	return{};
}

int scoreOfParentheses(string S) 
{
	auto ttt= get_parentheses_pos(S);
	string box;
	auto addable = false;
	if (ttt.back().first == 0) //说明这是一个表达式
		addable = true;
	while (!ttt.empty())
	{
		auto left = ttt[0].first;
		auto right = ttt[0].second;
		//vector<int> ant = 
		string tmp(S.begin() + left, S.begin() + right+1);
		auto new_one = get_trans_string(tmp);
		S.replace(S.begin()+left, S.begin()+right + 1, new_one);
		ttt = get_parentheses_pos(S);
	}
	if (!S.empty()&&!addable)
	{
		S = get_trans_string(S);
	}

	return stoi(S);
}

void test_scoreOfParentheses()
{
	//"(()(()()))"
	string tez("()(())()(((()(()())))(((())(()))()))(((())))");
	auto ack = scoreOfParentheses(tez);
	cout << "Score of Parentheses" << ack;
}

vector<int> rightSideView(TreeNode* root) {
	vector<vector<int>> awe;
	if (!root)
	{
		return {};
	}
	queue<TreeNode*> bat;
	bat.push(root);
	while (!bat.empty())
	{
		auto bay = bat.size();
		vector<int> cab;
		for (auto bee=0;bee<bay;bee++)
		{
			
			auto bed = bat.front();
			cab.push_back(bed->val);
			bat.pop();
			if (bed->left)
			{
				bat.push(bed->left);
			}
			if (bed->right)
			{
				bat.push(bed->right);
			}
		}
		awe.push_back(cab);
	}

	vector<int>dam;
	for (auto i = 0; i < awe.size(); i++)
		dam.push_back(awe[i].back());

	return dam;
}

void test_rightSideView()
{
	auto node_1 = new TreeNode(1);
	auto node_2 = new TreeNode(2);
	auto node_3 = new TreeNode(3);
	auto node_4 = new TreeNode(4);
	auto node_5 = new TreeNode(5);

	node_1->left = node_2;
	node_1->right = node_3;

	node_2->right = node_5;
	node_3->right = node_4;
	auto kfc = rightSideView(node_1);
	cout << "Binary Tree Right Side View" << kfc[0] << endl;
}

void combine_help(vector<vector<int>>&ret,vector<int> &cur,vector<bool> visited,int n,int level,int k)
{
	if (level==k)
	{
		ret.push_back(cur);
		return;
	}

	for (auto kkk=1;kkk<n+1;kkk++)
	{
		if (!visited[kkk])
		{
			visited[kkk] = true;
			cur.push_back(kkk);
			combine_help(ret, cur, visited, n, level + 1, k);
			cur.pop_back();
		}
	}
	
}

vector<vector<int>> combine(int n, int k) {
	vector<vector<int>>ret;
	vector<bool> visited(n+1, false);
	vector<int>ack;
	combine_help(ret, ack, visited, n, 0,k);
	return ret;
}

void test_combine()
{
	auto van = 2;
	auto tub = 4;
	auto tug = combine(tub, van);
	cout << "Combinations" << tug[0][0] << endl;
}
/**
 *
 *
 * 前缀和 区间[i,j]前缀和为f[i]
 *  1的个数为 f[j] - f[i-1]  
 *  0的个数为 (j-i+1) - (f[j]-f[i-1])
 *  
 *  本质是枚举所有的操作 
 *		边界左边的1的个数 全部变成0 
 *		边界右边的0的个数 全部变成1
 *		
 *		每个边界操作的结果是相加的结果 取得最小值返回即可.
 *
 *
 */
int minFlipsMonoIncr(string S) {
	int n = S.size();
	vector<int> f(n + 1, 0);
	for (auto i = 1; i <= n; i++)
	{
		f[i] = f[i - 1] + S[i - 1] - '0';
	}
	auto res = INT_MAX;
	for (auto i = 1; i <= n; i++)
	{
		auto left = f[i - 1];
		auto right = (n - i + 1 - (f[n] - f[i - 1]));
		res = min(res, left + right);
	}
	res = min(res, f[n]);
	return res;
}

void test_minFlipsMonoIncr()
{
	string S("00011000");
	auto ack = minFlipsMonoIncr(S);
	cout << "Flip String to Monotone Increasing" << ack;
}

bool lexical(int a,int b)
{
	auto a_str = to_string(a);
	auto b_str = to_string(b);

	return a_str < b_str;

}

vector<int> lexicalOrder_v1(int n) {
	vector<int> fox;
	for (auto k=1;k<n+1;k++)
	{
		fox.push_back(k);
	}
	sort(fox.begin(), fox.end(), lexical);
	return fox;
}

/**
 *2000
 *200
 *20
 *2
 *
 *
 */

int get_proper_num(int n,int k)
{
	if (!(k%10))
	{
		return get_proper_num(n, k / 10);
	}
	return k;
	
}

vector<int> lexicalOrder_v2(int n) {
	vector<int>ack(n, 1);// [1,n]
	
	for (auto i=1;i<n;i++)
	{
		if (ack[i-1]*10<=n)
		{
			ack[i] = ack[i-1] * 10;
		}
		else
		{
			ack[i] = (ack[i-1] + 1)%10==0? get_proper_num(n,ack[i-1]+1): 
			((ack[i-1] + 1)>n?(get_proper_num(n,(ack[i-1]+1)/10+1)):ack[i-1] + 1);
		}
	}
	return ack;
}
void test_lexicalOrder()
{
	auto n = 10;
	auto ack = lexicalOrder_v2(192);
	cout << "Lexicographical Numbers" << ack[0] << endl;
}


double knightProbability(int N, int K, int r, int c) {
	if (K==1)
	{
		return 1;
	}
	vector<vector<vector<double>>> dp(K, vector<vector<double>>(N, vector<double>(N, 1)));
	vector<vector<int>> dirs{ { -1,-2 },{ -2,-1 },{ -2,1 },{ -1,2 },{ 1,2 },{ 2,1 },{ 2,-1 },{ 1,-2 } };
	for (auto k=1;k<K;k++)
	{
		for (auto i=0;i<N;i++)
		{
			for (auto j=0;j<N;j++)
			{
				for(auto u=0;u<8;u++)
				{
					auto x = i;
					x+= dirs[u][0];
					auto y = j; 
					y+= dirs[u][1];
					if (x >= N || x < 0 || y >= N||y<0)
					{
						continue;
					}
					dp[k][i][j] += dp[k - 1][x][y];
				
				}
			}
		}
	}
	return dp[K - 1][r][c]/pow(8,K);
}

void test_knightProbability()
{
	auto N = 3;
	auto K = 2;
	auto r = 0;
	auto c = 0;
	auto ack = knightProbability(N, K, r, c);
	cout << "688. Knight Probability in Chessboard" << ack;
}

string handler_phone(string phone_num)
{
	auto k = 0;
	while (k<phone_num.size())
	{
		if (phone_num[k] == ')' || phone_num[k] == '('||phone_num[k]=='-'||phone_num[k]=='+'||phone_num[k]==' ')
		{
			phone_num.erase(k, 1);
		}
		else
		{
			k++;
		}
	}
	auto ch = phone_num[phone_num.size() - 4];
	auto end = string(phone_num.end() - 3, phone_num.end());
	auto start = "";
	if (phone_num.size()==13)
	{
		start = "+***";
	} 
	else if(phone_num.size()==12)
	{
		start = "+**";
	}
	else if(phone_num.size()==11)
	{
		start = "+*";
	}
	if (phone_num.size() > 10)
		return start + string("-***-***-") + string(1, ch) + end;
	return "***-***-"+ string(1, ch) + end;
}

string tolowerString(string s)
{
	for (auto &ch:s)
	{
		if (isalpha(ch))
		{
			ch = tolower(ch);
		}
	}
	return s;
}

string handler_email(string email)
{
	auto i = 0;
	for (i; i < email.size(); i++)
	{
		if (email[i]=='@')
		{
			break;
		}
	}
	string end(email.begin() + i, email.end());
	return string(1, tolower(email[0])) + "*****" + string(1, tolower(email[i - 1])) + tolowerString(end);
}


string maskPII(string S) {
	auto e = false;
	for(auto ch : S)
	{
		if(ch=='@')
		{
			return handler_email(S);
		}
		
	}
	return handler_phone(S);
}

void test_maskPII()
{
	auto s1("AB@qq.com");
	auto s2("+(501321)-50-23431");

	auto s3("86-(10)12345678");

	auto ack = maskPII(s3);
	cout << "831. Masking Personal Information" << ack;
}

vector<int> vec_union(vector<int> &A,vector<int> B)
{
	for (auto i=0;i<B.size();i++)
	{
		A.emplace_back(B[i]);
	}
	return A;
}


vector<int> vec_int(int N)
{
	if (N < 10)
		return{ N };

	vector<int > ret = vec_int(N / 10);
	return vec_union(ret, vec_int(N % 10));
}


bool isup_not_restrict(int N)
{
	vector<int> vec = vec_int(N);
	if (vec.size()==1)
	{
		return true;
	}
	return vec[0] <= vec[1] && isup_not_restrict(N);
}

bool isbigger(vector<int> num,int k)
{
	for (auto j=k;j>=0;j--)
	{
		if (num[j]>num[k])
		{
			return true;
		}
	}
	return false;
}

int monotoneIncreasingDigits(int N) 
{
	auto vec = vec_int(N);
	auto i = vec.size() - 1;
	auto ss = i+1;
	for (i;i>0;i--)
	{
		if (vec[i - 1] > vec[i] )
		{
			vec[i - 1] -=1;
			ss = i;
		
		}
		
	}
//	cout << "@@@ " << j<<ss << endl;

	
	for (auto s=ss;s<vec.size();s++)
	{
		vec[s] = 9;
	}
	
	auto ans = 0;
	for (int k=vec.size()-1;k>=0;k--)
	{
		auto l = vec.size() - k-1;
		ans += vec[k] * pow(10, l);
	}
	return ans;
}
 // 499699
 // 499999
void test_monotoneIncreasingDigits()
{
	int n = 1234;
	auto ack = monotoneIncreasingDigits(n);
	cout << "738. Monotone Increasing Digits" << ack;
}

int numRescueBoats(vector<int>& people, int limit) 
{
	int ans = 0;
	sort(people.begin(), people.end());
	int i = 0, j = people.size() - 1;
	while (i <= j) {
		if (i != j && people[i] + people[j] <= limit) {
			i++;
			j--;
			ans++;
		}
		else {
			j--;
			ans++;
		}
	}
	return ans;
}

void test_numRescueBoats()
{
	vector<int> people{ 2,4 };
	auto limits = 5;
	auto ack = numRescueBoats(people, limits);
	cout << "881. Boats to Save People " << ack << endl;
}


int main()
{
//	cout << "woolgatherer.cpp";
	{
	//test_findMaxAverage();
	//test_addBinary();
	//test_isSymmetric();
	//test_searchInsert();
	//test_reverseStr();
	//test_backspaceCompare();
	//test_insertIntoBST();
	//test_redundant_else(2);
	//test_isPalindrome();
	//test_reverseBits();
	//test_isPalindrome_linkList();
	//test_convertToTitle();
	//test_buddyStrings();
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
	//test_binaryTreePaths();
	//test_flipEquiv();
	//test_deckRevealedIncreasing(); //?
	//test_matrixScore();
	//test_removeDuplicates();
	//test_intersect_Quad_Node();//?
	//test_validMountainArray();
	//test_frequencySort(); // ??
	//test_topKFrequent();
	//test_printTree();
	//test_kthSmallest(); //?
	//test_detectCycle();
	//test_findDuplicate();
	//test_addOneRow();
	//test_leafSimilar();
	//test_spiralMatrixIII(); ?
	//test_numTrees();
	//test_isNStraightHand();
	//test_fractionAddition();
	//test_findMinDifference();
	//test_levelOrder();
	//test_decodeString();
	//test_scoreOfParentheses();?
	//test_rightSideView();
	//test_combine();
	//test_minFlipsMonoIncr();
	}
	//test_lexicalOrder();
	//test_knightProbability(); //?
	//test_maskPII();
	//test_monotoneIncreasingDigits();
	//test_numRescueBoats();

}

#endif
