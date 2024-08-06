from dataclasses import dataclass # 데이터 클래스 자료구조

@dataclass
class Candidate: # 데이터 클래스 선언
    number: int # 후보 번호
    vote: int # 득표 수

N = int(input()) # 총 후보 수 N

can = [] # 데이터 클래스를 담을 리스트 선언

for i in range(N): # N명의 후보에 대한 득표 수 입력 + 데이터 클래스 저장
    number = i + 1
    vote = int(input())
    candidate = Candidate(number=number, vote=vote)
    can.append(candidate)

cnt = 0 # 매수해야 하는 사람 수

while True:
    # 단일 후보일 경우
    if N == 1:
        print(cnt) # 0 출력
        break

    # 득표수를 기준으로 내림차순 정렬
    sorted_can = sorted(can, key=lambda candidate: candidate.vote, reverse=True)
    # 최다득표자의 명수 확인
    max_vote = sorted_can[0].vote
    # 리스트 상에서 최다득표자 수 추출하여 리스트로 저장 (리스트 컴프리헨션)
    top_can = [c for c in sorted_can if c.vote == max_vote]

    # 최다 득표자가 여러 명일 경우
    if len(top_can) > 1:
        for candidate in top_can:
            if candidate.number != 1:
                candidate.vote -= 1 # 최다득표자 중 아무에게 표 뺏기
                can[0].vote += 1 # 1번 후보에게 표 추가
                cnt += 1
                break
    # 아니면 그냥 1등에게서 표 뺏기
    else:
        if sorted_can[0].number != 1:
            sorted_can[0].vote -= 1
            can[0].vote += 1
            cnt += 1
        else:
            print(cnt)
            break
