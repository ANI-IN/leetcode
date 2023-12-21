class Solution:
    def numDecodings(self, s: str) -> int:
      if s[0] == '0':
        return 0

      dp = [[0, 0] for i in range(len(s) + 1)]

      dp[0][0] = 1
      dp[1][0] = 1

      for i in range(1, len(s)):
        # zero must be second
        if s[i] == '0':
          if s[i-1] not in ['1', '2']:
            return 0
          dp[i+1] = [0, dp[i][0]]
  
        elif '00' < s[i-1:i+1] < '27' and s[i-1] != '0':
          dp[i+1] = [sum(dp[i]), sum(dp[i-1])]
    
        else:
          dp[i+1] = [sum(dp[i]), 0]
    
      return sum(dp[len(s)])