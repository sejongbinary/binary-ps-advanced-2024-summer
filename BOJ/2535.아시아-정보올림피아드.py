from dataclasses import dataclass #데이터 클래스 정의 (구조체)
from collections import defaultdict 

@dataclass #데이터 클래스 선언
class Student:
    country : int #소속 국가 번호
    num : int #학생 번호
    score : int #성적

N = int(input()) #입력 받을 학생 수 N

st = [] #데이터 클래스를 담을 리스트 선언

for i in range (N):
    country, num, score = map(int, input().split()) #정보 입력
    student = Student(country = country, num = num, score = score) #데이터 클래스에 저장 후, student 변수에 저장
    st.append(student) #student 변수를 st 리스트에 삽입

sorted_st = sorted(st, key = lambda student : student.score, reverse = True) #성적순 정렬
#sorted 함수 사용 -> 정렬된 새 리스트 반환
#key = lambda student : student.socre -> 정렬 기준을 score로 설정
#reverse = True -> 내림차순 정렬

selected_students = [] # 상위 3명을 담을 리스트 선언
country_count = defaultdict(int) #기본값이 0인 딕셔너리 생성

for student in sorted_st: #상위권 학생들의 소속 국가 번호 검토
    if len(selected_students) == 3: #최종 리스트에 3명이 담겼으면 종료
        break
    if country_count[student.country] < 2: #아직 3명이 안 찼으면
        selected_students.append(student) #해당 학생을 최종 리스트에 추가
        country_count[student.country] += 1 #해당 국가 번호의 학생 수를 1 증가

for student in selected_students:
    print(student.country, student.num) #상위 3명 학생 출력
