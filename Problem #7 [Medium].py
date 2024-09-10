# This problem was asked by Facebook.

# Given the mapping a = 1, b = 2, … z = 26, and an encoded message, count the number of ways it can be decoded.

# For example, the message ‘111’ would give 3, since it could be decoded as ‘aaa’, ‘ka’, and ‘ak’.

# You can assume that the messages are decodable. For example, ‘001’ is not allowed.
# 确定dp数组，我们定义f[i]为长度为n的字符串解码方案数
# 递推公式: f[i] = f [i-1] when s[i-1]!='0'
#          f[i] = f[i-2]  when s[i-2] !='0' and (s[i-2] -'0')*10+(s[i-1]-'0') <=26
#  初始化：f[0] = 1 空字符串只有一种方案数，0
# 从左到右依次遍历即可
def numDecodings(self, s: str) -> int:
        n = len(s)
        dp = [0] * (n+1)
        dp[0] = 1
        for i in range(1, n+1):
            if s[i-1] != '0':
                dp[i] += dp[i-1]
            if i >= 2 and s[i-2] != '0' and int(s[i-2:i]) <= 26:
                dp[i] += dp[i-2]
        return dp[n]

