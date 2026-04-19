def longest_substring(text):
    cur_max = 0
    max_str = ''
    for i in text:
        if i in max_str:
            n = max_str.index(i)
            max_str = max_str[n+1:]
            max_str+=i
#            print(max_str)
#            print(cur_max)
            cur_max = max(len(max_str),cur_max)
        else:
            max_str+=i
            cur_max = max(len(max_str),cur_max)
#            print(max_str)
#            print(cur_max)
    print(cur_max)


longest_substring("abcabcbb")
longest_substring("bbbbb")
longest_substring("pwwkew")


