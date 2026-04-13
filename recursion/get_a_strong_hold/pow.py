def myPow(x,n):
    def cal_pow(x,n):
        if n == 0:
            return 1 
        if n == 1:
            return x 
        res = cal_pow(x,n//2)
        res = res*res

        if n % 2 == 1:
            return res * x
        return res
    res = cal_pow(x,abs(n))
    if n > 0:
        return res
    else:
        return 1/res


print(myPow(2,10))
print(myPow(2.1,3))
print(myPow(2,-2))
print(myPow(2,-2000))
