class Solution {

private:
	bool isPalindrome(string& word, int l, int r) {
		while (l < r)
		{
			if (word[l] != word[r]) return false;
			l++; r--;
		}
		return true;
	}
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		unordered_map<string, int> mp;
		vector<vector<int>> ans;
		int emptyInd = -1;
		vector<int> indexOfPalindromes;
		for (int i = 0; i < words.size(); ++i)
		{
			if (words[i] == "")
			{
				emptyInd = i;
				continue;
			}
			if (isPalindrome(words[i], 0, words[i].size() - 1))
				indexOfPalindromes.push_back(i);
			string str = words[i];
			reverse(begin(str), end(str));
			mp[str] = i;
		}
		for (int i = 0; i < words.size(); ++i)
		{
			for (int cut = 0; cut < words[i].size(); ++cut)
			{
				
				if (isPalindrome(words[i], cut, words[i].size() - 1))
				{
					string right = words[i].substr(0, cut);
					if (mp.find(right) != end(mp) && mp[right] != i)
					{
						ans.push_back(vector<int> {i, mp[right]});
					}
				}
				
				if (isPalindrome(words[i], 0, cut - 1))
				{
					string left = words[i].substr(cut);
					if (mp.find(left) != end(mp) && mp[left] != i)
					{
						ans.push_back(vector<int> {mp[left], i});
					}
				}
			}
		}
		if (emptyInd != -1)
			for (int x : indexOfPalindromes)
			{
				ans.push_back(vector<int> {emptyInd, x});
				ans.push_back(vector<int> {x, emptyInd});
			}
		return ans;
	}
};