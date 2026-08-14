class Solution {
public:
  long long power(long long number, int n) 
  {
    long long res = 1;
    for (int i = 0; i < n; i++) {
        res *= number;
             
    }
    return res;
  }
  int bins(int n, int low, int high, int m )
  {
    if(low>high)
    {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if(power(mid,n) == m)
    {
        return mid;
    }
    else if(power(mid,n) > m)
    {
        return bins(n, low, mid-1,m);
    }
    else
    {
        return bins(n, mid+1, high,m);
    }
  }
  int NthRoot(int n, int m)
  {
    return bins(n, 1, m, m); 
  }
};

