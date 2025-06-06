/*************************************************************************
	> File Name: 8.LC264.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 17 Feb 2025 10:51:48 AM CST
 ************************************************************************/
class Solution {
public:
    int nthUglyNumber(int n) {
       set<long long> s;
        s.insert(1);
        long long ans = 0;
        while (n--) {
            ans = *s.begin();
            s.erase(s.begin());
            if(ans % 5 == 0) {
                s.insert(ans * 5);
            } else if(ans % 3 == 0) {
                s.insert(ans * 3);
                s.insert(ans * 5);
            } else {
                s.insert(ans * 2);
                s.insert(ans * 3);
                s.insert(ans * 5);
            }
        }
        return ans;
    }
};
