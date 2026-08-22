#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize == 0) return cities.size() * 5;
    
    int answer = 0;
    // 가장 오랫동안 사용되지않은 것 삭제
    vector<string> cache;
    cache.reserve(cacheSize);
    
    for(string city : cities)
    {
        bool cachehit = false;
        transform(city.begin(), city.end(), city.begin(), ::toupper);
        
        for(int i = 0; i < cache.size(); ++i)
        { 
            if(city == cache[i]) // 캐시 히트
            {
                ++answer;
                // 타이머 다시
                cache.erase(cache.begin()+i);
                cachehit = true;
                break;
            }
        }
        // 캐시 미스
        if(!cachehit)
        {
            // 가장 오래된 것 교체
            answer+= 5;
            if(cache.size() == cacheSize) cache.erase(cache.begin());
        }
        cache.push_back(city);
    }
    
    
    return answer;
}