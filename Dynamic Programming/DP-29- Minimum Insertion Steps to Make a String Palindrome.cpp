//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    int s(int x, int y, string &s1, string &s2) {
        vector<int> prev(y+1,0), cur(y+1,0);
        for(int i1 = 1; i1<=x; i1++) {
            for(int i2 = 1; i2<=y; i2++) {
                int match = 0;
                if(s1[i1-1] == s2[i2-1]) match = 1 + prev[i2-1];
                int choice1 = 0 + prev[i2];
                int choice2 = 0 + cur[i2-1];
                cur[i2] = max(match,max(choice1,choice2));        
            }
            prev = cur;
        }
        return cur[y];
    }
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(string &s1, string &s2)
    {
        int x = s1.size();
        int y = s2.size();
        // vector<vector<int>> dp(x+1,vector<int>(y+1,-1));
        return s(x,y,s1,s2);
    }
  public:
    int countMin(string s){
    //complete the function here
        string s2(s.rbegin(),s.rend());
        return (s.size()-lcs(s,s2));
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends
