tt = int(input())
for _ in range(tt):
    s = input()
    a, b = s.split()
    product = bin(int(a, 2) * int(b, 2))[2:]
    print(product)