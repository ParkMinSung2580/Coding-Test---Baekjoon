#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    // 장르 - 해당 장르의 전체 재생 횟수
    unordered_map<string, int> genreHash;

    // 장르 - 인덱스로 곡정보 저장 (genres[i]는 장르, i는 고유 번호)
    vector<pair<string, int>> genreIndex; 
    
    for(int i = 0; i < genres.size(); i++)
    {
        genreHash[genres[i]] += plays[i]; // 장르별 총 재생 횟수 계산
        genreIndex.push_back({genres[i], i}); // (장르 이름, 고유 번호) 저장
    }
    
    // 재생 플레이 횟수에 따른 정렬 (내림차순)
    // 재생 횟수가 같으면 고유 번호 오름차순
    sort(genreIndex.begin(), genreIndex.end(),
         [&](const pair<string, int>& a, const pair<string, int>& b) {
             if (plays[a.second] == plays[b.second]) {
                 return a.second < b.second; // 재생 횟수가 같으면 고유 번호 오름차순
             }
             return plays[a.second] > plays[b.second]; // 재생 횟수 내림차순
         });
    
    // --- 여기서부터 수정 및 추가 ---

    // 장르에 따른 플레이횟수 정렬을 위한 벡터 생성
    // (총 재생 횟수, 장르 이름) 형태로 저장하여 정렬합니다.
    vector<pair<int, string>> sortedGenresByPlays;
    for (auto const& pair : genreHash) {
        sortedGenresByPlays.push_back({pair.second, pair.first}); 
    }

    // 총 재생 횟수 내림차순으로 장르 정렬
    sort(sortedGenresByPlays.begin(), sortedGenresByPlays.end(),
         [](const pair<int, string>& a, const pair<int, string>& b) {
             return a.first > b.first; // 첫 번째 원소 (총 재생 횟수) 기준 내림차순
         });
    
    // 정렬된 장르 순서대로 노래를 선택하여 answer에 추가
    for(auto const& genreInfo : sortedGenresByPlays) // 이제 'sortedGenresByPlays'를 순회합니다.
    {
        string currentGenreName = genreInfo.second; // 현재 처리할 장르 이름
        int count = 0; // 해당 장르에서 선택한 노래 수
        
        // genreIndex는 모든 노래가 재생 횟수와 고유 번호 기준으로 이미 정렬되어 있습니다.
        // 이 정렬된 리스트에서 현재 장르의 노래들을 찾아 순서대로 추가합니다.
        for(int j = 0; j < genreIndex.size(); j++)
        {
            // 현재 노래의 장르가 처리 중인 장르와 같으면
            if(currentGenreName == genreIndex[j].first)
            {
                if(count < 2) // 해당 장르에서 아직 두 곡을 선택하지 않았다면
                {
                    answer.push_back(genreIndex[j].second); // 노래의 고유 번호(인덱스) 추가
                    count++;
                } else {
                    // 이미 두 곡을 선택했으므로 이 장르의 노래는 더 이상 추가할 필요 없음
                    break; // 효율을 위해 내부 루프 종료
                }
            }
        }
    }
    
    return answer;
}