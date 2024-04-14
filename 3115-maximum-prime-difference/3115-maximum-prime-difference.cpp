#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        vector<bool> isPrime(100, false);
        unordered_set<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
        for (int p : primes) {
            isPrime[p] = true;
        }
        
        int n = nums.size();
        int i = 0, j = n - 1;
        while (i <= j) {
            if (isPrime[nums[i]] && isPrime[nums[j]]) {
                return j - i;
            } else if (isPrime[nums[i]]) {
                j--;
            } else if (isPrime[nums[j]]) {
                i++;
            } else {
                i++;
                j--;
            }
        }
        return 0;
    }
};
