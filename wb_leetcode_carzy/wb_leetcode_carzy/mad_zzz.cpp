// Username:peng_peng
// password : Peng0peng

#include "head.h"
#include <functional>
#include <atomic>

#if 0
#endif


vector<string> word_to_vec_same_char(string S)
{
	vector<string> S_vec;
	int start, end;
	start = end = 0;
	while (start <= end&&end <= S.size() - 1)
	{
		while (S[start] == S[end] && end <= S.size() - 1)
		{
			end++;
		}
		string ack(S.begin() + start, S.begin() + end);
		S_vec.push_back(ack);
		start = end;
	}
	return S_vec;
}

bool is_expressive_word(string S,string word)
{
	auto s_vec = word_to_vec_same_char(S);
	auto word_vec = word_to_vec_same_char(word);
	if (s_vec.size() != word_vec.size())
		return false;
	for (auto k=0;k<s_vec.size();k++)
	{
		if (s_vec[k][0]!=word_vec[k][0])
		{
			return false;
		}
		if (s_vec[k]==word_vec[k]) // 两个一样的那么
		{
			continue;
		}
		if (s_vec[k].size() < word_vec[k].size())
			return false;
		if (s_vec[k].size()>=3)
		{
			continue;
		}
		if (s_vec[k].size()<3)
		{
			return false;
		}
	}
	return true;

}

int expressiveWords(string S, vector<string>& words) {
	auto ack = 0;
	for (auto l=0;l<words.size();l++)
	{
		if (is_expressive_word(S, words[l]))
			ack++;
	}
	return ack;
}

void test_expressiveWords()
{
	auto S("aaa");
	vector<string>words_vec{"aaaa"};
	auto ack = expressiveWords(S, words_vec);
	cout <<"809. Expressive Words "<< ack;

	/*auto ack = is_expressive_word(S, words_vec[0]);
	return;*/
}

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	
};

bool sort_func(Interval a,Interval b)
{
	if (a.end < b.start)
		return true;
	else if(a.end<b.start)
	{
		return false;
	}
	else if (a.start==b.end)
	{
		return a.start < b.end;
	}
	return false;
}

vector<int> findRightInterval_v0(vector<Interval>& intervals) {
	vector<int >ack;
	for (auto i = 0; i < intervals.size(); i++)
	{
		auto end = intervals[i].end;
		auto found = false;
		auto index = 0;
		for (auto jj=0;jj<intervals.size();jj++)
		{
			auto start = intervals[jj].start;
			if (end<=start)
			{
				found = true;
				index = jj;
				break;
			}
		}
		if (found)
		{
			ack.push_back(index);
		}else
		{
			ack.push_back(-1);
		}
	}
	return ack;
}

// 需要建立intervals 索引与开始位置的映射
vector<int> findRightInterval(vector<Interval>& intervals) {
	vector<int >ack;
	vector<int> ret;
	unordered_map<int, int> map; // 开始:索引的位置 
	for (auto j=0;j<intervals.size();j++)
	{
		map[intervals[j].start] = j;
		ack.push_back(intervals[j].start);
	}
	sort(ack.begin(), ack.end(),greater<int>());
	for (auto i=0;i<intervals.size();i++)
	{
		auto end = intervals[i].end;
	
		auto index = 0;
		for (auto j=0;j<ack.size();j++) // start>=end  满足条件
		{
			auto start = ack[j];
			if (start<end)
			{
				index = j;
				break;
			}
		}
		ret.push_back(index>0?map[ack[index-1]]:-1);

	}
	return ret;
}
void test_findRightInterval()
{
	auto i1 = Interval(3, 4);
	auto i2 = Interval(2, 3);
	auto i3 = Interval(1, 2);
	vector<Interval> i_vec;
	i_vec.push_back(i1);
	i_vec.push_back(i2);
	i_vec.push_back(i3);
	auto ack = findRightInterval(i_vec);
	cout << "436. Find Right Interval" << ack[0] << endl;

}

void gameOfLife(vector<vector<int>>& board) {

}

void test_gameOfLife()
{
	vector<vector<int>> life(
	{
			{0,1,0},
			{0,0,1},
			{1,1,1},
			{0,0,0}
	}
	);
	gameOfLife(life);
	cout << "289. Game of Life" << life[0][0];
}

/*const string[] = {
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};*/

string originalDigits(string s)
{
	vector<int> ack(10, 0);
	vector<int> tmp(26, 0);
	for (auto ch : s)
	{
		if (ch == 'z')
		{
			ack[0]++;
		}
		else if (ch == 'w')
		{
			ack[2]++;
		}
		else if(ch=='u')
		{
			ack[4]++;
		}
		else if (ch == 'x')
		{
			ack[6]++;

		}
		else if (ch == 'g')
		{
			ack[8]++;
		}
		tmp[ch - 'a']++;
	}
	ack[5] = tmp['f' - 'a'] - ack[4];
	ack[7] = tmp['v' - 'a'] - ack[5];
	ack[9] = tmp['i' - 'a'] - ack[8] - ack[6] - ack[5];
	ack[3] = tmp['t' - 'a'] - ack[8] - ack[2];
	ack[1] = tmp['o' - 'a'] - ack[0] - ack[2] - ack[4];

	string ret = "";
	for (auto k=0;k<10;k++)
	{
		for (auto  i = 0; i  < ack[k] ; i++)
		{
			ret += to_string(k);
		};
	}
	return ret;
}

void test_originalDigits()
{
	auto str = "owoztneoer";
	auto orange = originalDigits(str);
	cout << "Reconstruct Original Digits from English" << orange << endl;
}

bool sort_vec(pair<char,int> A,pair<char,int> B)
{
	return A.first < B.first;
}

string customSortString(string S, string T) 
{
	unordered_map<char, int> map_index;
	for (auto i = 0; i<S.size(); i++)
	{
		map_index[S[i]] = i+1;
	}
	vector<pair<int, char>> map_vec;
	for (auto it=map_index.begin();it!=map_index.end();++it)
	{
		pair<int, char> tmp = make_pair(it->second,it->first);
		map_vec.push_back(tmp);

	}
	sort(map_vec.begin(), map_vec.end(), sort_vec);
	

	unordered_map<char, int> map_cnt;

	

	for (auto i : T)
	{
		map_cnt[i]++;
	}

	vector<int> unvisited(26, 0);
	
	for (auto i : T)
	{
		if (map_index[i]==0)
		{
			unvisited[i - 'a'] = 1;
		}
	}

	string ret;

	for (auto& k : map_vec)
	{
		auto cnt = map_cnt[k.second];
		for(auto j=0;j<cnt;j++)
		{
			ret += string(1, k.second);
		}
	}

	for (auto u = 0;u<unvisited.size();u++)
	{
		if (unvisited[u])
		{
			auto cnt = map_cnt[u+'a'];
			for (auto v=0;v<cnt;v++)
			{
				ret += string(1, u+'a');
			}
		}
		
	}


	return ret;
}

void test_customSortString()
{
	string S("hucw");
	string T("utzoampdgkalexslxoqfkdjoczajxtuhqyxvlfatmptqdsochtdzgypsfkgqwbgqbcamdqnqztaqhqanirikahtmalzqjjxtqfnh");
	string ack = customSortString(S, T);
	cout << "791. Custom Sort String" << ack;
}


void canVisitAllRooms_help(vector<vector<int>>&rooms,vector<bool>&visited,int &cur_room){
	cout << "cur_room" << cur_room << endl;
	if(!visited[cur_room])
	{
		visited[cur_room] = true;
		for (auto i=0;i<rooms[cur_room].size();i++)
			if(!visited[rooms[cur_room][i]])
				canVisitAllRooms_help(rooms, visited, rooms[cur_room][i]);
	}
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
	auto room_nums = rooms.size();
	vector<bool> visited(room_nums, false);
	auto first_index = 0;
	canVisitAllRooms_help(rooms, visited,first_index);
	auto cnt = 0;
	for (auto k : visited)
	{
		if (k)
			cnt++;
	}
	return cnt == room_nums;
}

void test_canVisitAllRooms()
{
	vector<vector<int>> vex = { {1},{2},{3},{} };
	auto ack = canVisitAllRooms(vex);
	cout << "841. Keys and Rooms" << ack << endl;
}


int minFallingPathSum(vector<vector<int>>& A) 
{
	vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0));
	for (auto i=0;i<A.size();i++)
	{
		dp[0][i] = A[0][i];
	}
	for (auto i=1;i<A.size();i++)
	{
		for (auto j=0;j<A[0].size();j++)
		{
			auto left = INT_MAX;
			auto right = INT_MAX;
			if(j!=0)
			{
				left =  dp[i - 1][j-1];
			}

			if (j != A[0].size() - 1)
			{
				right = dp[i - 1][j + 1];
			}
			auto mid = dp[i - 1][j];
			auto val = min(min(left, mid), right);
			cout << "val    " << val<<endl;
			dp[i][j] = A[i][j] + val;
		}
		cout << endl;
	}
	auto ans = INT_MAX;
	for (auto k=0;k<A.size();k++)
	{
		if (dp.back()[k]<ans)
		{
			ans = dp.back()[k];
		}
	}
	return ans;
	
}


void test_minFallingPathSum()
{
	vector<vector<int>> max({ { 1,2,3 },{ 4,5,6 },{ 7,8,9 } });
	auto ack = minFallingPathSum(max);
	cout << ack;
}


string optimalDivision(vector<int>& nums) {
	if (nums.empty())
		return "";
	if (nums.size()==1)
	{
		return to_string(nums[0]);
	}

	if (nums.size()==2)
	{
		return to_string(nums[0]) + "/" + to_string(nums[1]) ;
	}


	string head = to_string(nums[0]) + "/";

	string inner_str;
	for (auto i=1;i<nums.size();i++)
	{
		inner_str += to_string(nums[i]) + "/";
	}
	inner_str.pop_back();
	inner_str += ")";
	return head + "(" + inner_str;
}

void test_optimalDivision()
{
	vector<int> kkk = { 1000,100,10,2 };
	cout << "553. Optimal Division" << optimalDivision(kkk);
	return;
}

class CBTInserter {
public:
	CBTInserter(TreeNode* root) {
		vec.clear();
		queue<TreeNode *>qq;
		qq.push(root);
		while (!qq.empty())
		{
			TreeNode *cur = qq.front();
			qq.pop();
			vec.push_back(cur);
			if (cur->left)
			{
				qq.push(cur->left);
			}
			if (cur->right)
			{
				qq.push(cur->right);
			}
		}

	}

	int insert(int v) {
		auto node = new TreeNode(v);
		auto len = vec.size();
		if (!vec[(len - 1) / 2]->left)
		{
			vec[(len - 1) / 2]->left = node;
		}
		else if(!vec[(len-1)/2]->right)
		{
			vec[(len - 1) / 2]->right = node;
		}
		vec.push_back(node);
		return vec[(len-1) / 2]->val;
	}

	TreeNode* get_root() {
		return vec[0];
	}
private:
	vector<TreeNode *>vec;
};


void test_CBTInserter()
{
	auto n1 = new TreeNode(1);
	auto n2 = new TreeNode(2);
	auto n3 = new TreeNode(3);
	auto n4 = new TreeNode(4);
	auto n5 = new TreeNode(5);
	auto n6 = new TreeNode(6);

	n1->left = n2;
	n1->right = n3;

	n2->left = n4;
	n2->right = n5;

	n3->left = n6;

	auto ss = new CBTInserter(n1);
	ss->insert(7);
	ss->insert(8);

	return;
}


int get_tree_height(TreeNode *root)
{
	if (!root)
	{
		return 0;
	}
	return max(get_tree_height(root->left), get_tree_height(root->right)) + 1;
}


TreeNode* subtreeWithAllDeepest(TreeNode* root) {
	if (!root)
	{
		return nullptr;
	}

	auto left = get_tree_height(root->left);
	
	auto right = get_tree_height(root->right);

	if (left==right)
	{
		return root;
	}
	else if(left>right)
	{
		return subtreeWithAllDeepest(root->left);
	}
	else
	{
		return subtreeWithAllDeepest(root->right);
	}



}

void test_subtreeWithAllDeepest()
{
	auto n3 = new TreeNode(3);
	auto n5 = new TreeNode(5);
	auto n1 = new TreeNode(1);
	auto n6 = new TreeNode(6);
	auto n2 = new TreeNode(2);
	auto n0 = new TreeNode(0);
	auto n8 = new TreeNode(8);
	auto n7 = new TreeNode(7);
	auto n4 = new TreeNode(4);

	n3->left = n5;
	n3->right = n1;

	n5->left = n6;
	n5->right = n2;

	n1->left = n0;
	n1->right = n8;

	/*n2->left = n7;
	n2->right = n4;*/

	auto ack = subtreeWithAllDeepest(n3);
	cout << "865. Smallest Subtree with all the Deepest Nodes" << ack->val;
	return;
}


//本质上是map 映射关系
class UnionFind
{
private:
	int m_count;
	vector<int> id;
public:
	UnionFind(int N)
	{
		this->m_count = N;
		for (auto i=0;i<N;i++)
		{
			id.push_back(i);
		}

	}

	int count()
	{
		return this->m_count;
	}

	bool is_connect(int p,int q)
	{
		return find(p) == find(q);
	}

	int find(int p)
	{
		return id[p];
	}

	void union_(int p,int q)
	{
		int p_p = find(p);
		int p_q = find(q);
		if (p_p==p_q)
		{
			return;
		}
		id[q] = p_p;
	}


};



int cal_basic(string str) // 基础计算
{
	char c;
	auto i = 0;
	for (i;i<str.size();i++)
	{
		if(str[i]=='+'||str[i]=='-'||str[i]=='*')
		{
			c = str[i];
			break;
		}
	}
	string first(str.begin(), str.begin() + i);
	string second(str.begin() + i + 1, str.end());
	auto i_ = stoi(first);
	auto j_ = stoi(second);
	if (c == '*')
		return i_*j_;
	else if (c == '+')
		return i_ + j_;
	else
		return i_ - j_;
}

vector<int> diffWaysToCompute(string input) 
{
	vector<int> index;
	for (auto i=0;i<input.size();i++)
	{
		if (input[i]=='+'||input[i]=='-'||input[i]=='*')
		{
			index.push_back(i);
		}
	}
	if (index.empty())
	{
		return{ stoi(input) };
	}
	if (index.size() == 1)
		return{ cal_basic(input) };
	//处理前面的所有的结果;
	//string front(input.begin(), input.begin() +index[0]);

	//处理后面所有的结果
	vector<int > ans;
	for(auto k=0;k<index.size();k++)
	{
		string first(input.begin(), input.begin() + index[k]);
		string second(input.begin() + index[k] + 1, input.end());

		vector<int> f = diffWaysToCompute(first);
		vector<int> g = diffWaysToCompute(second);
		for (auto i:f)
		{
			for (auto j:g)
			{
				if (input[index[k]]=='+')
				{
					ans.push_back(i+j);
				}
				else if(input[index[k]]=='-')
				{
					ans.push_back(i-j);
				}
				else
				{
					ans.push_back(i*j);
				}
				
			}
		}
	}

	return ans;
}

void test_diffWaysToCompute()
{
	string str("2*3-4*5");
	vector<int> ans = diffWaysToCompute(str);
	cout << "241. Different Ways to Add Parentheses "<< ans[0];
}


class MyCircularDeque {
public:

	vector<int> _eggs;
	int max_capacitiy;
	/** Initialize your data structure here. Set the size of the deque to be k. */
	MyCircularDeque(int k) {
		max_capacitiy = k;
	}

	/** Adds an item at the front of Deque. Return true if the operation is successful. */
	bool insertFront(int value) {
		if (!isFull())
		{
			vector<int> tmp;
			for (int i = 0; i<_eggs.size(); i++)
			{
				tmp.push_back(_eggs[i]);
			}
			_eggs.clear();
			
			for (int i = tmp.size()-1; i >=0 ; i--)
			{
				_eggs.push_back(tmp[i]);
			}
			_eggs.push_back(value);
			_eggs = vector<int>(_eggs.rbegin(), _eggs.rend());
			return true;
		}
		return false;
	}

	/** Adds an item at the rear of Deque. Return true if the operation is successful. */
	bool insertLast(int value) {
		if (!isFull())
		{
			_eggs.push_back(value);
			return true;
		}
		return false;
	}

	/** Deletes an item from the front of Deque. Return true if the operation is successful. */
	bool deleteFront() {
		if (!isEmpty())
		{
			_eggs = vector<int>(_eggs.begin() + 1, _eggs.end());
			return true;
		}
		return false;
		
	}

	/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
	bool deleteLast() {
		if (!isEmpty())
		{
			_eggs = vector<int>(_eggs.begin(), _eggs.end()-1);
			return true;
		}	
		return false;
	}

	/** Get the front item from the deque. */
	int getFront() {
		if (isEmpty())
			return -1;
		return _eggs.front();
	}

	/** Get the last item from the deque. */
	int getRear() {
		if (isEmpty())
			return -1;
		return _eggs.back();
	}

	/** Checks whether the circular deque is empty or not. */
	bool isEmpty() {
		return _eggs.size()==0;
	}

	/** Checks whether the circular deque is full or not. */
	bool isFull() {
		return _eggs.size() == max_capacitiy;
	}

	void treavel_()
	{
		cout << "travels___________";
		for (auto i=0;i<_eggs.size();i++)
		{
			cout << _eggs[i] << "     ";
		}
		cout << endl;
	}
};

void test_MyCircularDeque()
{
	/*auto obj = new MyCircularDeque(3);
	cout << obj->insertLast(1) << endl;
	cout << obj->insertLast(2)<<endl;
	cout << obj->insertFront(3)<<endl;
	//obj->treavel_();
	cout << obj->insertFront(4)<<endl;
	cout <<"rear"<< obj->getRear() << endl;
	cout << obj->isFull() << endl;
	cout << obj->deleteLast() << endl;
	cout << obj->insertFront(4) << endl;
	obj->treavel_();

	cout << obj->getFront() << endl;
	obj->treavel_();*/


	auto obj = new MyCircularDeque(4);
	obj->insertFront(9);
	obj->deleteLast();
	obj->getRear();
	obj->getFront();
	obj->getFront();
	obj->deleteFront();
	obj->insertFront(6);
	obj->insertLast(5);
	obj->insertFront(9);
	obj->getFront();
	obj->insertFront(6);
	cout << "641. Design Circular Deque" << endl;

}


class Codec {
public:	
	// Encodes a tree to a single string.  // 先做一个中序遍历
	string serialize(TreeNode* root) {
		ostringstream out;
		serialize(root, out);
		return out.str();
 	}

	void serialize(TreeNode* root,ostringstream &out) {
		if(root)
		{
			out << root->val << ' ';
			serialize(root->left, out);
			serialize(root->right, out);
		}else
		{
			out << "#";
		}
	}

	TreeNode *deserialize(string data)
	{
		istringstream in(data);
		return deserialize(in);
	}

	TreeNode *deserialize(istringstream &in)
	{
		string val;
		in >> val;
		if(val=="#")
		{
			return nullptr;
		}
		TreeNode *root = new TreeNode(stoi(val));
		root->left = deserialize(in);
		root->right = deserialize(in);
		return root;
	}
};

class MyCircularQueue {
public:

	vector<int> eggs;
	int max_capacitiy;
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k):max_capacitiy(k) {

	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (isFull())
		{
			return false;
		}
		vector<int> tmp;
		for (int i=eggs.size()-1;i>=0;i--)
		{
			tmp.push_back(eggs[i]);
		}
		eggs.clear();
		for (auto i=0;i<tmp.size();i++)
		{
			eggs.push_back(tmp[i]);
		}
		eggs.push_back(value);
		eggs = vector<int>(eggs.rbegin(), eggs.rend());
		return true;

	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (isEmpty())
		{
			return false;
		}
		eggs = vector<int>(eggs.begin(), eggs.end() - 1);
		return true;
	}

	/** Get the front item from the queue. */
	int Front() {
		if(!isEmpty())
		{
			return eggs.back();
		}
		return -1;
	}

	/** Get the last item from the queue. */
	int Rear() {
		if (!isEmpty())
		{
			return eggs[0];
		}
		return -1;
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		return eggs.size() == 0;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		return eggs.size() == max_capacitiy;
	}
};


void test_MyCircularQueue()
{
	auto circularQueue = new MyCircularQueue(3);
	cout<<circularQueue->enQueue(1)<<endl;  // return true
	cout<<circularQueue->enQueue(2)<<endl;  // return true
	cout<<circularQueue->enQueue(3)<<endl;  // return true
	cout<<circularQueue->enQueue(4)<<endl;  // return false, the queue is full
	cout<<circularQueue->Rear()<<endl;  // return 3
	cout<<circularQueue->isFull()<<endl;  // return true
	cout<<circularQueue->deQueue()<<endl;  // return true
	cout<<circularQueue->enQueue(4)<<endl;  // return true
	cout<<circularQueue->Rear()<<endl;  // return 4

}

bool is_same_tree(TreeNode *root1,TreeNode *root2)
{
	if (!root1)
	{
		return !root2;
	}
	if (!root2)
	{
		return !root1;
	}
	return  root1->val == root2->val && is_same_tree(root1->left, root2->left) && is_same_tree(root1->right, root2->right);


}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
{
	if (!root)
	{
		return{};
	}

}

void test_findDuplicateSubtrees()
{
	TreeNode *n1 = new TreeNode(1);
	TreeNode *n2_1 = new TreeNode(2);
	TreeNode *n3 = new TreeNode(3);
	TreeNode *n4_1 = new TreeNode(4);

	TreeNode *n2_2 = new TreeNode(2);
	TreeNode *n4_2 = new TreeNode(4);

	TreeNode *n4_3 = new TreeNode(4);


	n1->left = n2_1;
	n1->right = n3;
	n2_1->left = n4_1;

	n3->left = n2_2;
	n3->right = n4_2;

	n2_2->left = n4_3;

	auto obj = new  Codec();
	cout << obj->serialize(n1);
}

void test_Codec()
{
	TreeNode *n1 = new TreeNode(1);
	TreeNode *n2 = new TreeNode(2);
	TreeNode *n3 = new TreeNode(3);
	TreeNode *n4 = new TreeNode(4);

	n1->left = n2;

	n2->left = n3;

	auto obj = new Codec;
	auto str =  obj->serialize(n1);
	cout << str;
}


// 标记出friend_A的所有朋友
void traversing_graph(vector<vector<int>> &M,vector<bool> &visited,int cur_node)
{
	visited[cur_node] = true;
	for (int k=0;k<M[0].size();k++)
	{
		if(!M[cur_node][k]||visited[k])
			continue;
		traversing_graph(M, visited, k);
	}

}

int findCircleNum(vector<vector<int>>& M) {
	vector<bool> visited(M.size(),false);
	int cnt = 0;
	for (auto i = 0; i < M.size(); i++)
	{
		if (visited[i])
		{
			continue;
		}
		traversing_graph(M, visited, i);
		cnt++;
	}
	return cnt;
}

void test_findCircleNum()
{
	vector<vector<int>> M =
	{
		{ 1,1,0,0,0,0,0,1,0,0,0,0,0,0,0 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,1,0,1,1,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,1,0,0,0,0,1,1,0,0,0,0 },
		{ 0,0,0,1,0,1,0,0,0,0,1,0,0,0,0 },
		{ 0,0,0,1,0,0,1,0,1,0,0,0,0,1,0 },
		{ 1,0,0,0,0,0,0,1,1,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,1,1,1,0,0,0,0,1,0 },
		{ 0,0,0,0,1,0,0,0,0,1,0,1,0,0,1 },
		{ 0,0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,1,1,1,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,1,0,0 },
		{ 0,0,0,0,0,0,1,0,1,0,0,0,0,1,0 },
		{ 0,0,0,0,0,0,0,0,0,1,0,0,0,0,1 },
	};
//	{ { 1,0,0,1 },{ 0,1,1,0 },{ 0,1,1,1 },{ 1,0,1,1 } };

	cout << "547. Friend Circles" << findCircleNum(M);
	return;
}

// [0,2]  [1,5]
// 如果没有交集  返回错误的交集[-1,0]
Interval cal_inter_section( Interval &A,  Interval &B)
{
	Interval ahead = A.start <= B.start ? A : B;
	Interval last = (ahead.start == A.start&&ahead.end==A.end) ? B : A;

	if(last.start<=ahead.end)
	{
		return Interval(last.start, min(last.end, ahead.end));
	}
	return Interval(-1, 0);
}

vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) 
{
	/*int i = 0;
	int j  = 0;
	vector<Interval> ans;
	while (i!=A.size()&&j!=B.size())
	{
		auto ret =  cal_inter_section(A[i], B[j]);
		if(ret.start!=-1)
			ans.push_back(ret);
	}*/
	vector<Interval> ans;
	for (int i = 0; i < A.size(); i++)
	{
		for (int j=0;j<B.size();j++)
		{
			auto ret = cal_inter_section(A[i], B[j]);
			if (ret.start != -1)
				ans.push_back(ret);
		}
	}

	return ans;
	
}





void test_intervalIntersection()
{
	Interval _1 = Interval(0, 2);
	Interval _2 = Interval(5, 10);
	Interval _3 = Interval(13, 23);
	Interval _4 = Interval(24, 25);
	

	Interval _1_ = Interval(1, 5);
	Interval _2_ = Interval(8, 12);
	Interval _3_ = Interval(15, 24);
	Interval _4_ = Interval(25, 26);

	vector<Interval> A;
	A.push_back(_1);
	A.push_back(_2);
	A.push_back(_3);
	A.push_back(_4);


	vector<Interval> B;
	B.push_back(_1_);
	B.push_back(_2_);
	B.push_back(_3_);
	B.push_back(_4_);


	intervalIntersection(A, B);
	cout << "986. Interval List Intersections " << endl;
	
}

int get_sum_by_index(vector<int>&nums, int start,int end)
{
	auto sum = 0;
	auto up = end >= start;
	for (auto i=start;i<=end;up?i++:i--)
	{
		sum += nums[i];
	}
	return sum;
}

int pivotIndex_0(vector<int>& nums)
{
	if (nums.size() == 0)
		return -1;
	auto cur_index = 0;
	while (cur_index!=nums.size())
	{
	
		auto a = get_sum_by_index(nums, 0, cur_index - 1);
		auto b = get_sum_by_index(nums, cur_index + 1, nums.size() - 1);
		
		if (a==b)
		{
			return cur_index;
		}
		cur_index++;
	}
	return -1;
}



int pivotIndex(vector<int>& nums)
{
	if (nums.size() == 0)
		return -1;
	auto cur_index = 0;
	auto s1 = 0;
	auto s2 = get_sum_by_index(nums, 0, nums.size() - 1)-nums[0];
	if (s1 == s2)
		return 0;
	cur_index++;
	while (cur_index != nums.size())
	{
		
		cout << "s1===>  " << s1 << endl;
		cout << "s2===>  " << s2 << endl;


		s1 += nums[cur_index-1];
		s2 -= nums[cur_index];
		
		
		cout << "s1  " << s1 << endl;
		cout << "s2  " << s2 << endl;

		if (s1 == s2)
		{
			return cur_index;
		}
		
		
		cur_index++;
	}
	return -1;
}

void test_pivot_index()
{
	//vector<int> nums = { 1, 7, 3, 6, 5, 6 };
	vector<int> nums = { -1,-1,-1,0,1,1 };
	cout << "724. Find Pivot Index" << endl;
	cout << pivotIndex(nums);
}



int countSegments(string s)
{

	auto cnt = 0;
	if (s.empty())
		return 0;
	for (auto i = 0; i < s.size();)
	{
		auto word = false;
		while (i<s.size()&& s[i] != ' ')
		{
			word = true;
			i++;
		}
		if (word &&(i == s.size() || s[i] == ' '))
		{
			cnt++;
		}
		while (s[i] == ' '&&i<s.size())
		{
			i++;
		}
	}
	return cnt;
}

void test_countSegments()
{
	cout << "434. Number of Segments in a String" << endl;
	string s("   is John   ");
//	s = "         ";
	cout << countSegments(s);
}

int cal_dis(int index,bool go_right,vector<int>&seats)
{
	int end = 0;
	auto cnt = 0;
	if (go_right)
	{
		end = seats.size()-1;
		int i = 0;
		for (i=index;i<=end;i++)
		{
			if(!seats[i])
			{
				cnt++;
			}
			else
			{
				break;
			}
			
		}
		if (i == seats.size())
			return numeric_limits<int>::max();
		
	}
	else
	{
		int i = 0;
		for (i=index;i>=0;i--)
		{
			if (!seats[i])
			{
				cnt++;	
			}
			else
			{
				break;
			}
			
		}
		if (i == -1)
			return numeric_limits<int>::max();
	}
	return cnt;
}

int maxDistToClosest(vector<int>& seats) 
{
	vector<int> dp(seats.size(),0);
	for (auto i=0;i<seats.size();i++)
	{
		if(!seats[i])
		{
			auto left = cal_dis(i, 0, seats);
			auto right = cal_dis(i, 1, seats);
			cout <<i<< "left " << left << "      right" << right << endl;
			dp[i] = min(left, right);
		}
	}
	auto ret = -1;
	for (auto k=0;k<dp.size();k++)
	{
		if (dp[k]>ret)
		{
			ret = dp[k];
		}
	}
	return ret;
}

void test_maxDistToClosest()
{
	cout << "849. Maximize Distance to Closest Person" << endl;	
	vector<int> seats({ 1, 0, 0, 0, 1, 0, 1 });
//	vector<int> seats({ 1, 0, 0, 0 });
	cout << maxDistToClosest(seats);
}

string licenseKeyFormatting(string S, int K) 
{
	string uppercase_nodash_str;
	for (auto ch : S)
	{
		if (isalpha(ch))
		{
			if (ch>='a'&&ch<='z')
			{
				uppercase_nodash_str.push_back(ch-'a'+'A');
			}
			else
			{
				uppercase_nodash_str.push_back(ch);
			}
			

		}
		else if(isdigit(ch))
		{
			uppercase_nodash_str.push_back((ch));
		}
	}
	if (uppercase_nodash_str.size() == 0)
		return "";
	auto first = uppercase_nodash_str.size() % K;
	string str;
	bool first_start = true;
	for (auto i=0;i<uppercase_nodash_str.size();)
	{
		if(first_start)
		{
			for (auto j=0;j<first;j++)
			{
				str.push_back(uppercase_nodash_str[i]);
				i++;
			}
			if(first&&uppercase_nodash_str.size()>K)
				str.push_back('-');
			first_start = false;
		}
		for (auto v=0;v<K&&v+i<uppercase_nodash_str.size();v++)
		{
			str.push_back(uppercase_nodash_str[v + i]);
		}
		str.push_back('-');
		i += K;
	}
	return string(str.begin(), str.end() - 1);
}


void test_licenseKeyFormatting()
{
	cout << "482. License Key Formatting" << endl;
	string s("5F3Z-2e-9-w");
	s = "2-5g-3-J";
	s = "2";
	auto k = 4;
	k = 2;
	cout << licenseKeyFormatting(s, k);

}

int dominantIndex(vector<int>& nums) {
	auto index = -1;
	auto biggest = 0;
	auto second_biggest = 0;
	for (auto i=0;i<nums.size();i++)
	{
		if (nums[i]>=biggest)
		{	
			second_biggest = biggest;
			biggest = nums[i];
			index = i;
			
		}
		else if(nums[i]>=second_biggest)
		{
			second_biggest = nums[i];
		}
	}
	return biggest >= 2 * second_biggest ? index : -1;
}

void test_dominantIndex()
{
	vector<int> nums({ 3, 6, 1, 0 });
	nums = { 1, 2, 3, 4 };
	auto ack = dominantIndex(nums);
	cout << "747. Largest Number At Least Twice of Others" << endl;
	cout << ack;
}



bool is_good_substring(string s,string sub)
{
	auto len_s = s.size();
	auto len_sub = sub.size();
	if (!len_s%len_sub || len_s==len_sub)
	{
		return false;
	}
	int cnt = len_s / len_sub;

	string tmp_sub = string(s.begin(), s.begin() + len_sub);
	
	cout << s<<"                   " << sub << endl;
	return tmp_sub == sub;
}


bool repeatedSubstringPattern(string s) {
	for (auto i=0;i<s.size();i++)
	{
		for (auto j=1;j<s.size()-i+1;j++)
		{
			if (is_good_substring(s,s.substr(i,j)))
			{
				return true;
			}
		}
	}
	return false;
}

void test_repeatedSubstringPattern()
{
	cout << "459. Repeated Substring Pattern" << endl;
	string s("abab");
	auto ack = repeatedSubstringPattern(s);
	cout << ack;
}


/*
 *			  5
             / \
            4   5
           / \   \
          1   1   5
 *
 *
 */
int longestUnivaluePath(TreeNode* root) {
	return 0;
}

void test_longestUnivaluePath(){
	cout << "687. Longest Univalue Path" << endl;
	auto node0 = new TreeNode(5);
	auto node1 = new TreeNode(4);
	auto node2 = new TreeNode(5);
	auto node3 = new TreeNode(1);
	auto node4 = new TreeNode(1);
	auto node5 = new TreeNode(5);

	node0->left = node1;
	node0->right = node2;
}


int find_special_largest_nums(vector<int> &A,int low,int up)
{
	for (int j=up;j>=low;j--)
	{
		for (int i = 0; i < A.size(); i++) {
			if (A[i] == j)
			{
				return i;
			}
		}
	}

	return -1;
}



string largestTimeFromDigits_XXX(vector<int>& A) 
{
	vector<int> ret;
	int first_index = find_special_largest_nums(A, 0, 2);
	if (first_index == -1)
		return "";
	if(A[first_index]==2)
	{
		ret.push_back(2);
		A.erase(A.begin() + first_index);
		int second_index = find_special_largest_nums(A, 0, 3);
		if (second_index == -1)
			return "";
		ret.push_back(A[second_index]);
		A.erase(A.begin() + second_index);
		int third_index = find_special_largest_nums(A, 0, 5);
		if (third_index == -1)
			return "";
		ret.push_back(A[third_index]);
		A.erase(A.begin() + third_index);
		int fouth_index = find_special_largest_nums(A, 0, 9);
		ret.push_back(A[fouth_index]);


		cout << "xxxx" << endl;
	}
	else
	{
		ret.push_back(A[first_index]);
		A.erase(A.begin() + first_index);
		int second_index = find_special_largest_nums(A, 0, 9);
		if (second_index == -1)
			return "";
		ret.push_back(A[second_index]);
		A.erase(A.begin() + second_index);
		int third_index = find_special_largest_nums(A, 0, 5);
		if (third_index == -1)
			return "";
		ret.push_back(A[third_index]);
		A.erase(A.begin() + third_index);
		int fouth_index = find_special_largest_nums(A, 0, 9);
		ret.push_back(A[fouth_index]);

		cout << "yyyyy" << endl;
	}

	string ack = "";
	for (int i = 0; i < 4; i++)
	{
		ack.push_back(ret[i] + '0');
		if(i==1)
		{
			ack.push_back(':');

		}
	}
	
	return ack;
}


void dfs(vector<int> &A,int cur,vector<int> &C,vector<bool>&visited)
{
	if (cur == A.size()) {
		for (int j = 0; j < C.size(); j++)
			cout << C[j];
		cout << endl;
		return;
	}
	for (int i=cur;i<A.size();i++)
	{
		if(!visited[i])
		{
			visited[i] = true;
			C.push_back(A[i]);
			dfs(A, cur+1, C,visited);
			C.pop_back();
		}
		
	}
}

string largestTimeFromDigits(vector<int >&A)
{
	//sort(A.begin(), A.end());
	vector<int> CCC;
	vector<bool> visited(A.size(), false);
	dfs(A, 0, CCC,visited);
	return "";
	
}

void test_largestTimeFromDigits()
{
	vector<int> nums({ 2,0,6,7});

	auto ack = largestTimeFromDigits(nums);
	cout << "949. Largest Time for Given Digits" << endl;
}


TreeNode * create_all_possible_tree(int N,vector<TreeNode *>&list)
{
	if (N == 1)
	{
		auto ret = new TreeNode(0);
		list.push_back(ret);
		return ret;
	}
	for (int i=1;2*i+1<=N;i+=2)
	{
		auto root = new TreeNode(0);
		auto left = create_all_possible_tree(i, list);
		auto right = create_all_possible_tree(N - 1 - i, list);
		root->left = left;
		root->right = right;
		list.push_back(root);
		return root;
	}
}

vector<TreeNode*> allPossibleFBT(int N) {
	if (N == 1)
		return { new TreeNode(0)};
	vector<TreeNode *>ret;
	for (int i=1;i<N;i+=2)
	{
		auto left = allPossibleFBT(i);
		auto right = allPossibleFBT(N -i-1);
		for (auto i_left:left)
		{
			for (auto i_right:right)
			{
				auto root = new TreeNode(0);
				root->left = i_left;
				root->right = i_right;
				ret.push_back(root);
			}
		}
	}
	return ret;
}

void test_allPossibleFBT()
{
	int N = 7;
	cout << "894. All Possible Full Binary Trees";
	vector<TreeNode *> ack = allPossibleFBT(N);
	return;
}

vector<int> partitionLabels(string S) {
	unordered_map<char, int> ttt;
	for (int i=0;i<S.size();++i)
	{
		ttt[S[i]] = i;
	}
	int start = 0; int last = 0;
	vector<int> ret;
	for (int i = 0; i < S.size(); ++i) // 遍历所有的字符 如果当前的index小于字符所在位置的最小值,那就一直变量 
	{
		last = max(last, ttt[S[i]]);
		if(i==last)
		{
			ret.push_back(last - start + 1);
			start = last + 1;
		}
	}

	return ret;
}

bool sort_map(pair<char, int> A, pair<char, int> B)
{
	return B.second < A.second;
}

bool is_legal_string(string S)
{
	for (int i = 1; i < S.size(); i++)
	{
		if (S[i] == S[i - 1])
			return false;
	}
	return true;
}

string reorganizeString(string S) {
	map<char, int> ttt;
	for (int i=0;i<S.size();++i)
	{
		ttt[S[i]]++;
	}
	// 策略 先放数量多的字符 
	vector<pair<char, int>> vec;
	for(auto it = ttt.begin();it!=ttt.end();++it)
	{
		char ch = it->first;
		int ch_num = it->second;
		vec.push_back(make_pair(ch,ch_num));
	}
	sort(vec.begin(), vec.end(), sort_map);
	string a_ret(S);

	for (int i = 0; i < S.size(); )
	{
		if(vec.begin()->second>=1)
		{
	    	a_ret[i++] = vec.begin()->first;
			cout << "   11   " << vec.begin()->first<<endl;
			vec.begin()->second -= 1;
			sort(vec.begin(), vec.end(), sort_map);
		}

		if(vec.begin()+1!=vec.end()&& (vec.begin() + 1)->first!=a_ret[i-1])
		{
			if ((vec.begin()+1)->second >= 1)
			{
				a_ret[i++] = (vec.begin()+1)->first;
				cout << "   22   " << (vec.begin()+1)->first << endl;

				(vec.begin()+1)->second -= 1;
			}
			
		}
		sort(vec.begin(), vec.end(), sort_map);
		
	}
	cout << a_ret << endl;
	if (is_legal_string(a_ret))
		return a_ret;
	return "";
}







void test_reorganizeString()
{
	cout << "767. Reorganize String" << endl;
	string s = "rvhrlpiesrrryrbrrrrrxrkirranrrrrbdrrzgasoxrrr";/**/
	
	auto ack = reorganizeString(s);
	//cout <<"out  "<< ack1<<endl;
	cout <<"out " << ack;

	return;
}

void test_partitionLabels()
{
	cout << "763. Partition Labels";
	string s = "ababcbacadefegdehijhklij";
	auto ack = partitionLabels(s);
	return;
}

	void solver(TreeNode *root,TreeNode* parent, int &ans)
	{
		if (!root)
		{
			return;
		}
		solver(root->left,root,ans);
		solver(root->right,root,ans);

		if(root->val>1) // 将多余的给到父节点
		{
			parent->val += (root->val-1);
			ans+= (root->val-1);
			root->val = 1;
		}
		else if(root->val<1) // 从父节点拿过来
		{
			parent->val -= (1 - root->val);
			ans += (1 - root->val);
			root->val = 1;
		}
	}

	int distributeCoins(TreeNode* root) {
		int ans = 0;
		solver(root,nullptr, ans);
		cout << ans;
		return ans;
	}

void test_distributeCoins(){
	TreeNode *node_3 = new TreeNode(0);
	TreeNode *node_0_0 = new TreeNode(3);
	TreeNode *node_0_1 = new TreeNode(0);

	node_3->left = node_0_0;
	node_3->right = node_0_1;
	distributeCoins(node_3);
}

vector<int> sortArray(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	return nums;
}

void test_sortArray()
{
	vector<int> arr = { 0, 0, 1, 1, 2, 5 };
	auto ack  = sortArray(arr);
}


/*
 *[
 * [1,4],[1,5],[2,5],[2,4],[2,3],[1,3],
 * [0,3],[0,4],[0,5],[3,5],[3,4],[3,3],
 * [3,2],[2,2],[1,2],[0,2],[4,5],[4,4],
 * [4,3],[4,2],[4,1],[3,1],[2,1],[1,1],
 * [0,1],[4,0],[3,0],[2,0],[1,0],[0,0],
 *]
 *
 *
 */

vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) 
{
	return{ {} };
}

void test_spiralMatrixIII()
{
	int R, C, r0, c0;
	R = 5, C = 6, r0 = 1, c0 = 4;
	cout << "885. Spiral Matrix III";
	auto kkk = spiralMatrixIII(R, C, r0, c0);
}

string i_2_sting(int i)
{
	if (i == 0)
		return "0";
	if (i == 1)
		return "1";
	return i_2_sting(i / 2) + i_2_sting(i % 2);
}

bool queryString(string S, int N) 
{
	for (int i=1;i<=N;++i)
	{
		auto check_str = i_2_sting(i);
		cout << " check_str" << check_str<<endl;
		if(S.find(check_str)==std::string::npos)
			return false;
	}
	return true;
}

void test_queryString()
{
	string s = "0110";
	int N = 4;
	cout<<queryString(s,N);
}

int get_vec_sqr(vector<int> node)
{
	auto sum = 0;
	for (int i=0;i<node.size();i++)
	{
		sum += node[i] * node[i];
	}
	return sum;
}
bool sort_vec_dw(pair<vector<int>, int> A, pair<vector<int>, int> B)
{
	return A.second < B.second;
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
	map<vector<int>, int> ttt;
	for (int i = 0; i < points.size(); ++i)
	{
		ttt[points[i]] = get_vec_sqr(points[i]);
	}
	vector<pair<vector<int>, int>> cot;
	auto it = ttt.begin();
	while (it != ttt.end())
	{
		cot.push_back(make_pair(it->first, it->second));
		++it;
	}
	sort(cot.begin(), cot.end(),sort_vec_dw);
	vector<vector<int>> ret;
	for (int k=0;k<K;k++)
	{
		ret.push_back(cot[k].first);
	}
	return ret;
}

void test_kClosest()
{
	vector<vector<int>> pos = { {3, 3},{5, -1},{-2, 4} };
	cout << "973. K Closest Points to Origin" << endl;
	int k = 1;
	auto ack = kClosest(pos, k);

	auto h = 1;
	return;

}

TreeNode* insert_2_max_tree(TreeNode *root,int val)
{
	if (!root)
		return new TreeNode(val);

	if (root->val<val)
	{
		auto new_root = new TreeNode(val);
		new_root->left = root;
		return new_root;
	}
	
	if (root->right&&val>root->right->val)
	{
		auto right_tree = root->right;
		auto new_node = new TreeNode(val);
		root->right = new_node;
		new_node->left = right_tree;
		return root;
	}

	if(root->left&&val<root->left->val)
	{
		return insert_2_max_tree(root->left, val);
	}

	if (root->left&&val>root->left->val)
	{
		return insert_2_max_tree(root->right, val);
	}
	
	
}

TreeNode* insertIntoMaxTree(TreeNode* root, int val)
{
	return insert_2_max_tree(root, val);
}
void test_1()
{
	TreeNode* _node5 = new TreeNode(5);
	TreeNode* _node2 = new TreeNode(2);
	TreeNode* _node3 = new TreeNode(3);
	TreeNode* _node1 = new TreeNode(1);

	_node5->left = _node2;
	_node5->right = _node3;

	_node2->right = _node1;

	auto value = 4;
	auto ack = insertIntoMaxTree(_node5, value);
}

void test_2()
{
	TreeNode* _node5 = new TreeNode(5);
	TreeNode* _node2 = new TreeNode(2);
	TreeNode* _node4 = new TreeNode(4);
	TreeNode* _node1 = new TreeNode(1);

	_node5->left = _node2;
	_node5->right = _node4;

	_node2->right = _node1;

	auto value = 3;
	auto ack = insertIntoMaxTree(_node5, value);
	value += 1;
}

void test_insertIntoMaxTree()
{

	test_2();
	return;

}

int main()
{
	//test_expressiveWords();
	//test_findRightInterval();
	//test_gameOfLife();// todo
	//test_originalDigits();
	//test_customSortString();
	//test_canVisitAllRooms();
	//test_minFallingPathSum();
	//test_optimalDivision();
	//test_CBTInserter();
	//test_subtreeWithAllDeepest();
	//test_diffWaysToCompute();
	//test_MyCircularDeque();
	//test_MyCircularQueue();
	//test_findDuplicateSubtrees(); //?
	//test_Codec(); //todo
	//test_findCircleNum();
	//test_intervalIntersection();
	//test_pivot_index();
	//test_countSegments();
	//test_maxDistToClosest();
	//test_licenseKeyFormatting();
	//test_dominantIndex();
	//test_repeatedSubstringPattern(); //todo
	//test_largestTimeFromDigits(); // todo
	//test_allPossibleFBT();
	//test_partitionLabels();
	//test_reorganizeString();
	//test_distributeCoins();
	//test_queryString();
	//test_kClosest();
	test_insertIntoMaxTree();
	return 0;
}
