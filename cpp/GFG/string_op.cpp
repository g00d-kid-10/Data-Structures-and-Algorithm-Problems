// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

bool is_Vow(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

class Solution 
{
	public:
	int solve(int n,string s)
	{
        int temp[n], temp1[n], temp2[n];
        int count1 = 0, count2 = 0;

        for(int i=0; i<n; i++) {

            if(i%2 == 0) {temp1[i] = 1;} else {temp1[i] = 0;}
            if(i%2 == 0) {temp2[i] = 0;} else {temp2[i] = 1;}

            if(is_Vow(s[i])) {
                temp[i] = 1;
            }
            else {
                temp[i] = 0;
            }
        }

        for(int i=0; i<n; i++) {
            if(temp[i] != temp1[i]) {
                count1++;
            }

            if(temp[i] != temp2[i]) {
                count2++;
            }
        }
        return (count1<count2) ? count1 : count2 ;
	}
};

// { Driver Code Starts.


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
	    string s;
	    cin >> s;
	    Solution obj;
	    int ans = obj.solve(n,s);
	    cout << ans << "\n";
	}

	return 0;
}

  // } Driver Code Ends