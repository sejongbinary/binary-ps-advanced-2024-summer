def get_gcd(a, b):
    """
    두 수의 최대 공약수(GCD)를 유클리드 호제법을 사용하여 계산하는 함수
    
    매개변수:
    a (int): 첫 번째 숫자
    b (int): 두 번째 숫자
    
    반환값:
    int: a와 b의 최대 공약수
    """

    if b > a:
        a, b = b, a

    while b:
        a, b = b, a % b
    return a


A1, B1 = map(int, input().split())
A2, B2 = map(int, input().split())

# 결과 분수의 분자(A3)와 분모(B3) 계산
A3 = A1 * B2 + A2 * B1
B3 = B1 * B2

# 분자와 분모의 최대 공약수를 구하여 약분한 결과 출력
gcd = get_gcd(A3, B3)
print(A3 // gcd, B3 // gcd)