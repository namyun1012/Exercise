n, m = input().split()
n = int(n)
m = int(m)


m = min(n-m, m)

result = 1

for i in range(m) :
    result *= (n-i)
    result //= i+1

print(result)

#파이썬을 이용해서 문제 풀어보기 // 는 몫, 정수셈임