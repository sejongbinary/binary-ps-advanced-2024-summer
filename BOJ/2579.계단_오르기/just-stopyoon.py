N = int(input()) # 계단 개수
stair = []

for i in range (N) :
    stair.append(int(input())) # 계단 리스트
            
score = [0] * (N) # 점수 저장할 리스트 N개 생성

if len(stair)<=2: # 계단의 개수가 2개 이하일 때
    print(sum(stair))

else: # 계단이 3개 이상일 때
    # 기저 상태
    score[0] = stair[0] # 첫째 계단 수동 계산
    score[1] = stair[0] + stair[1] # 둘째 계단까지 수동 계산

    for i in range(2, N): # 3번째 계단 부터 dp 점화식 이용해서 최대값 구하기
        score[i]=max(score[i-3] + stair[i-1] + stair[i], score[i-2] + stair[i])
        # 세 계단 전의 점수에서 한 계단을 건너뛰고 i번째 계단까지 가는 경우
        # 두 계단 전의 점수에서 바로 i번째 계단으로 가는 경우
        # 둘 중 최댓값을 score[i]에 저장

    print(score[-1]) # 마지막 단계까지의 최대 점수인 score[-1] 출력

# Bottom-Up 방식으로 해결
