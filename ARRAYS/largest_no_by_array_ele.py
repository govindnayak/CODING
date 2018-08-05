def comparator(a, b):
    ab = str(a)+str(b)
    ba = str(b)+str(a)
    return cmp(int(ba), int(ab))
 
a = [54, 546, 548, 60,]
sorted_array = sorted(a, cmp=comparator)
number = "".join([str(i) for i in sorted_array])
print(number)