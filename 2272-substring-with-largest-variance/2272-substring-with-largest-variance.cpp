class Solution {
public:
    int largestVariance(string s) {
    int result = 0;
    for (char highFreqChar = 'a'; highFreqChar <= 'z'; ++highFreqChar) {
        for (char lowFreqChar = 'a'; lowFreqChar <= 'z'; ++lowFreqChar) {
            if (highFreqChar == lowFreqChar) continue;
            
            int highFreq = 0;
            int lowFreq = 0;
            bool lowFreqAbandoned = false;
            
            for (const char& ch : s) {
                if (ch == highFreqChar) ++highFreq;
                if (ch == lowFreqChar) ++lowFreq;
                
                if (lowFreq > 0) {
                    result = max(result, highFreq - lowFreq);
                } else {
                    // Edge case: there are no `lowFreqChar` in current interval.
                    // In case if we re-started Kadane algo calculation - 
                    // we can "extend" current interval with 1 previously abandoned 'lowFreqChar'
                    if (lowFreqAbandoned) {
                        result = max(result, highFreq - 1);
                    }
                } 
                
                if (lowFreq > highFreq) {
                    // Kadane's algo calculation re-start: abandon previous chars and their freqs.
                    // Important: the last abandoned char is the `lowFreqChar` - this can be used on further iterations.
                    lowFreq = 0;
                    highFreq = 0;
                    lowFreqAbandoned = true;
                }
            }
        }
    }
    return result;
  }
};