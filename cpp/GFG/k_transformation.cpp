#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> k_Transformation(int n, int m, int k, vector<vector<int> > grid, int q, vector<vector<int> > queries) {
        
        vector<vector<vector<int>>> temp(k, vector<vector<int>>(n, vector<int>(m, 0)));
        int count;
        vector<int> answers;
        for(int i1=0; i1<k; i1++) {
            
            for(int i2=0; i2<n; i2++) {
                count=0;
                for(int i3=0; i3<m; i3++) {
                    if(grid[i2][i3]==i1) {
                        count++;
                        temp[i1][i2][i3] = count;
                    }
                    else {
                        temp[i1][i2][i3] = count;
                    }
                }
            }

            for(int i3=0; i3<m; i3++) {
                for(int i2=1; i2<n; i2++) {
                    temp[i1][i2][i3]+=temp[i1][i2-1][i3];
                }
            }
        }

        int t, val, lx, ly, rx, ry, sum, last_cell, left_col, top_row, first_cell;
        for(auto query:queries) {
            t = query[0];
            val = query[1];
            lx = query[2];
            ly = query[3];
            rx = query[4];
            ry = query[5];

            t = ((val-t%k)+k)%k;
            //cout<<"$"<<t<<"$";
            last_cell = temp[t][rx][ry];  
            
            if(ly!=0) {
                left_col = temp[t][rx][ly-1];
                // cout<<"#1*";
            }
            else {
                left_col = 0;
                // cout<<"#2*";
            }
            if(lx!=0) {
                top_row = temp[t][lx-1][ry];
                // cout<<"#3*";
            } 
            else {
                top_row= 0;
                // cout<<"#4*";
            }
            if(lx!=0 && ly!=0) {
                first_cell = temp[t][lx-1][ly-1];
                // cout<<"#5*";
            }
            else {
                // cout<<"#my6*";
                first_cell = 0;
                // cout<<"#6*";
            }

            sum = last_cell - left_col - top_row + first_cell;
            //cout<<"#"<<last_cell<<"#"<<left_col<<"#"<<top_row<<"#"<<first_cell<<endl;
            answers.push_back(sum);
        }
        return answers;
    }
};


// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<int> > grid(n, vector<int> (m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];

        int q;
        cin >> q;
        vector<vector<int> > queries(q, vector<int> (6, 0));
        for (int i = 0; i < q; i++)
            for (int j = 0; j < 6; j++)
                cin >> queries[i][j];

        Solution ob;
        vector<int> ans = ob.k_Transformation(n, m, k, grid, q, queries);
        for (auto it: ans)
            cout << it << " ";
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends