t = int(input())
for _ in range(t):
    n = int(input())
    
    if n == 1:
        print(1)
        continue
    
    num = ["0"] * ((n + 1) // 2)
    
    # 1..3..
    num[0] = "1"
    for i in range(1, len(num)):
        num_copy = num.copy()
        num_copy[-i] = "3"
        num_str = "".join(num_copy)
        num_int = int(num_str)
        print(num_int ** 2)
    
    # 14 ** 2 = 196 ~ 13 ** 2 = 169
    num_copy = num.copy()
    num_copy[1] = "4"
    num_str = "".join(num_copy)
    num_int = int(num_str)
    print(num_int ** 2)
    
    # 3..1..
    num[0] = "3"
    for i in range(1, len(num)):
        num_copy = num.copy()
        num_copy[-i] = "1"
        num_str = "".join(num_copy)
        num_int = int(num_str)
        print(num_int ** 2)
    