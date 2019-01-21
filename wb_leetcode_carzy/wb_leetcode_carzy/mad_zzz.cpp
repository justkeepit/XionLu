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
	
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {

	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {

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
	test_MyCircularQueue();
	//return 0;
}