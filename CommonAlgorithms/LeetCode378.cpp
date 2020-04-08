//解法一：一开始将所有的数据都放入到priority_queue中，这导致程序的性能下降，方法二将采用懒惰push到priority_queue中的方法来解，提高性能
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int x_size = matrix.size();
        int y_size = matrix[0].size();
        
        int i= 0, j = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for(i = 0 ; i < x_size; i++){
            for(j =  0; j < y_size; j++){
                q.push(matrix[i][j]);
            }
        }
        int ans;
        while(k > 0){
            ans = q.top();
            q.pop();
            k--;
        }
        return ans;
    }
};

//解法三： 全局数据排序，排序的平均时间复杂度理论上较高，但是在实际测试时发现解法三优于解法一。
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int x_size = matrix.size();
        int y_size = matrix[0].size();
        vector<int> ans;
        int i= 0, j = 0;
       
        for(i = 0 ; i < x_size; i++){
            for(j =  0; j < y_size; j++){
                ans.push_back(matrix[i][j]);
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};