#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    long long numberCard;
    unordered_map<long long, int> cardCntMap;

    // 입력
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> numberCard;

        // 현재 입력받은 숫자 카드가 map에 존재하는 경우, 카운트 증가
        // 존재하지 않는 경우 숫자 카드를 key로 한 value 값을 1로 초기화
        auto it = cardCntMap.find(numberCard);
        if (it != cardCntMap.end()){
            it->second += 1;
        } else {
            cardCntMap[numberCard] = 1;
        }
    }

    // map을 순회하면서 가장 많이 가지고 있는 정수를 찾기
    long long maxNumberCardKey = 0;
    int maxCnt = 0;

    for (const auto& pair : cardCntMap){
        if (pair.second < maxCnt) continue;
        if (pair.second == maxCnt and maxNumberCardKey < pair.first)
            continue;
        
        maxNumberCardKey = pair.first;
        maxCnt = pair.second;
    }

    // 출력
    cout << maxNumberCardKey;

    return 0;
}
