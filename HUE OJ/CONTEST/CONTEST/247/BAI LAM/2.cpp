#include <iostream>
#include <string>
using namespace std;
int kk=0,m=4;
// Function to find all strings of length n containing balanced parentheses
void balParenthesis(string str, int n, int open)
{
	// if n is odd with no open parentheses, balanced parentheses
	// cannot be formed
	if ((n & 1) && !open)
		return;

	// base case: length n is reached
	if (n == 0)
	{
		// if output string contains all balanced parenthesis, print it
		if (open == 0){
			kk++;
			if (kk==m) cout << str << endl;
		}
		return;
	}

	// Optimization: return if we cannot close all open parentheses with
	// left characters
	if (open > n)
		return;

	// recur with open parentheses
	balParenthesis(str + "(", n - 1, open + 1);

	// recur with closed parentheses only if output string has at-least
	// one unclosed parentheses
	if (open > 0)
		balParenthesis(str + ")", n - 1, open - 1);
}

// main function
int main()
{
	int n = 6;
	string str;

	balParenthesis(str, n, 0);

	return 0;
}
