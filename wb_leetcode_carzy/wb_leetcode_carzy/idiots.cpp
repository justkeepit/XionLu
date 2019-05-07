#include "head.h"

TreeNode * construct_from_pre_post_helper(unordered_map<int, int>&map,unordered_map<int, int>&_map,vector<int>&pre,int pre_start,int pre_end,vector<int>&post,int post_start,int post_end)
{

	/*if (pre_start > pre_end || post_start > post_end)
		return nullptr;*/

	if (pre_start==pre_end)
	{
		return new TreeNode(pre[pre_start]);
	}

	if (post_start == post_end)
	{
		return new TreeNode(post[post_start]);
	}
	
	int root_val_in_pre = pre[pre_start];
	
	auto root_ = new TreeNode(root_val_in_pre);  // 1


	// left_start_pre   left_end_pre   right_start_pre   right_end_end
	// left_start_post  left_end_post  right_start_post  right_end_post

	/*
	 *	auto left_start_pre = pre_start + 1;
	auto left_end_post = map[pre[left_start_pre]];

	auto right_end_post = post_end - 1;

	if(right_end_post==post_start) //没有右节点
	{
		root_->left = new TreeNode(pre[left_start_pre]);
		return root_;
	}


	auto right_start_pre = _map[post[right_end_post]];

	auto left_end_pre = right_start_pre - 1;
	auto left_start_post = post_start;
	auto right_start_post = left_end_post + 1;
	auto right_end_pre = pre_end;


	
	auto lf = construct_from_pre_post_helper(map, _map, pre, left_start_pre, left_end_pre, post, left_start_post, left_end_post);


	auto rt = construct_from_pre_post_helper(map, _map, pre, right_start_pre, right_end_pre,post, right_start_post, right_end_post);
	 *
	 *
	 */


	auto left_start_pre = pre_start + 1;
	auto left_len = map[pre[left_start_pre]] - post_start + 1;


	root_->left = construct_from_pre_post_helper(map, _map, pre, pre_start + 1, pre_start + left_len, post, post_start, post_start + left_len - 1);
	root_->right = construct_from_pre_post_helper(map,_map, pre, pre_start+left_len+1,pre_end,post,pre_start+left_len+1,post_end-1);

	return root_;
}

TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) 
{
	unordered_map<int, int> pre_val_post_index,pre_index_post_val;
	for (int i=0;i<pre.size();++i)
	{
		pre_val_post_index[post[i]] = i;
	}

	for (int i = 0; i<pre.size(); ++i)
	{
		pre_index_post_val[pre[i]] = i;
	}
	auto ret=construct_from_pre_post_helper(pre_val_post_index,pre_index_post_val, pre, 0, pre.size() - 1, 
																						   post, 0, post.size() - 1);
	return ret;
}
/*
 *
 *Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
	Output: [1,2,3,4,5,6,7]
 *
 */
void test_constructFromPrePost()
{
	cout << "889. Construct Binary Tree from Preorder and Postorder Traversal" << endl;
	vector<int> pre =  { 1,2,4,5,3,6,7 };
	vector<int> post = { 4,5,2,6,7,3,1 };

	pre = { 2,1,3};
	post = {3, 1,2};
	auto tree = constructFromPrePost(pre, post);

	return;
}
// 遍历树得到最大值和最小值 更新ans
void helper(TreeNode* root, int min, int max, int &ans) {
	if (root == nullptr)
		return;
	if (root->val>max)
		max = root->val;
	if (root->val<min)
		min = root->val;
	if (abs(max - min)>ans)
		ans = abs(max - min);
	helper(root->right, min, max, ans);
	helper(root->left, min, max, ans);
}

int maxAncestorDiff(TreeNode* root) {
	if (root == nullptr)
		return 0;
	int min = root->val;
	int max = root->val;
	int ans = 0;
	helper(root, min, max, ans);
	return ans;
}



void test_1()
{
	auto _8_ = new TreeNode(8);
	auto _3_ = new TreeNode(3);
	auto _10_ = new TreeNode(10);

	_8_->left = _3_;
	_8_->right = _10_;
	auto ack = maxAncestorDiff(_8_);
	cout << ack;
}

void test_maxAncestorDiff()
{
	test_1();
}

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
	stack<int> s;
	int j = 0;
	for (int i=0;i<pushed.size();i++)
	{
		s.push(pushed[i]);
		while(!s.empty()&&s.top()==popped[j])
		{
			s.pop();
			j++;
		}
	}
	return s.empty();
}

void test_validateStackSequences()
{
	cout << "946. Validate Stack Sequences";
	vector<int> pushed = { 1, 2, 3, 4, 5};
	vector<int> popped = { 4,5,3,2,1 };

	auto ack = validateStackSequences(pushed, popped);
	
}
// 如果第i天不用旅行 那么 dp[i] = dp[i-1]
// 如果要去旅行 那么 dp[i] = min(dp[i-1]+costs[0],dp[i-7]+costs[1],dp[i-30]+costs[2])
int mincostTickets(vector<int>& days, vector<int>& costs) {
	vector<int>dp( 366,0);
	int j = 0;
	for (int i=1;i<366;++i)
	{
		if(j<days.size()&&days[j]==i)
		{
			j++;
			int a = min(dp[i - 1] + costs[0], INT_MAX);
			int b = min(a, dp[max(0, i - 7)] + costs[1]);
			int c = min(b, dp[max(0, i - 30)] + costs[2]);
			dp[i] = c;
		}
		else
		{
			dp[i] = dp[i - 1];
		}
	}
	return dp[days[days.size() - 1]];
}

void test_mincostTickets()
{
	vector<int>days =  { 1,2,3,4,5,6,7,8,9,10,30,31 };
	vector<int>costs = { 2,7,15 };
	auto ack = mincostTickets(days, costs);
	cout << "ack " << ack;
	
}

/*int coinChange(vector<int>& coins, int amount) 
{
	vector<int> tmp(amount + 1, 0);
	vector<vector<int>> dp(amount+1, tmp);
	dp[0] = {};
	for (auto i=1;i<amount+1;++i)
	{
		int dp_tmp = INT_MIN;
		int selected_index = -1;
		for (auto j = 0; j < coins.size(); ++j)
		{
			if (dp_tmp < int(dp[max(0, i - coins[j])].size() + 1))
			{
				dp_tmp = dp[max(0, i - coins[j])].size() + 1;
				selected_index = j;
			}
		}
		if (selected_index==-1)
		{
			return -1;
		}
		else
		{

			vector<int> dd(dp[i - selected_index]);
			dd.push_back(coins[selected_index]);
			dp[i] = dd;
		}
	}
	return dp[amount].size();
}*/


int coinChange(vector<int>& coins, int amount)
{
	vector<vector<int>> route;
 	vector<int> dp(amount + 1, -1);
	dp[0] = 0;
	for (auto i = 1; i<amount + 1; ++i)
	{
		int dp_min = INT_MAX;
		for (auto j = 0; j < coins.size(); ++j)
		{
			int index = i - coins[j];
			if(index>=0)
			{
				if(dp_min>dp[i-coins[j]]&& dp[i - coins[j]]!=-1)
				{
					dp_min = dp[i - coins[j]];
				}
			}
		}
		if(dp_min!=INT_MAX&&dp_min!=-1)
			dp[i] = dp_min + 1;
	}
	return dp[amount];
	
}

void test_coinChange()
{
	vector<int>	 coins = { 186, 419, 83, 408 };
	auto amount = 6249;
	auto ack = coinChange(coins, amount);
	cout << "322. Coin Change" << ack;

	/*[186, 419, 83, 408]
	6249*/
	
}
// ksvjLiknTzqn ====>   knzsvzjLiknTszqn
bool is_camelMatch(string A,string B)
{
	int j = 0;
	for (auto ch : A)
	{
		if(ch==B[j])
		{
			j++;
		}
		else if(isupper(ch))
		{
			return false;
		}
	}
	return j == B.size();	
}

vector<bool> camelMatch(vector<string>& queries, string pattern) {
	vector<bool> ret(queries.size(), false);
	for (int i=0;i<queries.size();++i)
	{
		if(is_camelMatch(queries[i],pattern))
		{
			ret[i] = true;
		}
	}
	return ret;
}
// [true,false,true,true,false]

//["CompetitiveProgramming", "CounterPick", "ControlPanel"]
//"CooP"
void test_camelMatch()
{
	vector<string> queries = { "FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack" };
	string pattern  = "FoBaT" ;
	auto ack = is_camelMatch("knzsvzjLiknTszqn", "ksvjLiknTzqn");
	return;
}


int main()
{
	//test_constructFromPrePost(); // todo
	//test_maxAncestorDiff();
	//test_validateStackSequences();
	//test_mincostTickets();
	//test_coinChange();
	test_camelMatch();
}