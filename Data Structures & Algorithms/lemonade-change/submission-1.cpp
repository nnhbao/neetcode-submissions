class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5=0,c10=0;
        for (int i = 0 ; i <bills.size(); i++) {
            if (bills[i]==5) c5++;
            if (bills[i] == 10) {
                if (c5 == 0) return false;
                else c5--, c10++;
            } else if (bills[i] == 20) {
                if (c5 >= 3) c5-=3;
                else if (c5 > 0 && c10>0) c5--, c10--;
                else return false;
            }
      }
      return true;
    }
};