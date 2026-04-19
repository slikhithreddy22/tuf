def max_consecutive_ones(nums:list,k:int):
        left = right = zeroes = maxOnes = 0
        while (right < len(nums)):
            if (nums[right] == 0):
                zeroes += 1
            if (zeroes > k):
                if (nums[left] == 0):
                    zeroes-=1
                left += 1
            if (zeroes <= k):
                maxOnes = max(right-left+1,maxOnes)
            right += 1
        return maxOnes 


