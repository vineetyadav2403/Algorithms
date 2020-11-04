// Recursive solution 

int LIS(int a[],int pre,int cur,int &n){
    if(cur==n) return 0;
    
    int op1 = 0;
    if(pre == -1 || a[pre]<a[cur]){
        op1 = 1 + LIS(a,cur,cur+1,n);
    }
    int op2 = LIS(a,pre,cur+1,n);
    return max(op1,op2);
}

int longestSubsequence(int n, int a[])
{
   return LIS(a,-1,0,n);
}


//Menoizartion solution

int dp[1001][1001] = {0};
int LIS(int a[],int pre,int cur,int &n){
    if(cur==n) return 0;
    
    if(pre !=-1 && dp[pre][cur]!=0)
        return dp[pre][cur];
    
    int op1 = 0;
    if(pre == -1 || a[pre]<a[cur]){
        op1 = 1 + LIS(a,cur,cur+1,n);
    }
    int op2 = LIS(a,pre,cur+1,n);
    
    if(pre!=-1) dp[pre][cur] = max(op1,op2);
    return max(op1,op2);
}

int longestSubsequence(int n, int a[])
{
   return LIS(a,-1,0,n);
}

// Top down approach
