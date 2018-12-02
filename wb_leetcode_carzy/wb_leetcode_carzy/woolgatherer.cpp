#include "head.h"
// Username:peng_peng
// password : Peng0peng

#if 0
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
	// vector<int> nums({ 1, 12, -5, -6, 50, 3 });
	// int k = 4;

	vector<int> nums({ 8860,-853,6534,4477,-4589,8646,-6155,-5577,-1656,-5779,-2619,-8604,-1358,-8009,4983,7063,3104,-1560,4080,2763,
		5616,-2375,2848,1394,-7173,-5225,-8244,-809,8025,-4072,-4391,-9579,1407,6700,2421,-6685,5481,-1732,-8892,-6645,3077,3287,-4149,
		8701,-4393,-9070,-1777,2237,-3253,-506,-4931,-7366,-8132,5406,-6300,-275,-1908,67,3569,1433,-7262,-437,8303,4498,-379,3054,
		-6285,4203,6908,4433,3077,2288,9733,-8067,3007,9725,9669,1362,-2561,-4225,5442,-9006,-429,160,-9234,-4444,3586,-5711,-9506,
		-79,-4418,-4348,-5891 });

	int k = 93;
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

int main()
{
//	cout << "woolgatherer.cpp";
//	test_findMaxAverage();
	test_addBinary();
}
#endif