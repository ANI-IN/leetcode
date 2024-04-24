#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextSmallerToLeft(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> nextSmallerToRight(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        const int mod = 1e9 + 7;
        int n = arr.size();
        long long sum = 0;

        vector<int> NSL = nextSmallerToLeft(arr);
        vector<int> NSR = nextSmallerToRight(arr);

        for (int i = 0; i < n; i++) {
            int l = i - NSL[i];
            int r = NSR[i] - i;
            long long total_ways_for_i_min = static_cast<long long>(l) * r;
            long long sum_i_in_total_ways = static_cast<long long>(arr[i]) * total_ways_for_i_min;
            sum = (sum + sum_i_in_total_ways) % mod;
        }

        return static_cast<int>(sum);
    }
};
