def max_score(cardPoints:list,k:int):
    total_points = 0
    for i in cardPoints:
        total_points+=i
    left = 0
    right = low = len(cardPoints)-k
    mini_sum = 0
    for j in range(left,right):
        mini_sum += cardPoints[j]
    print(right, mini_sum)
    cur_sum =  mini_sum
    for j in range(right,len(cardPoints)):
            cur_sum = cur_sum - cardPoints[left] + cardPoints[j]
            print(j,cur_sum,cardPoints[left],cardPoints[j])
            left += 1
            if cur_sum < mini_sum:
                mini_sum = cur_sum
                low = j

    print(total_points - mini_sum)


max_score([1,2,3,4,5,6,1],3)
max_score([2,2,2], 2)
max_score([9,7,7,9,7,7,9],  7)
