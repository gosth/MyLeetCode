 class Solution {
            public:
                int compareVersion(string version1, string version2) {
                    int version1Index = 0, version2Index = 0;
                    while (version1Index < version1.size() || version2Index < version2.size()) {
                        int32_t version1Value = 0, version2Value = 0;
                        std::string version1Num, version2Num;
                        for (; version1Index < version1.size(); ++version1Index) {
                            const auto version1Char = version1[version1Index];
                            if (version1Char != '.') {
                                version1Num += version1Char;
                            } else {
                                ++version1Index;
                                break;
                            }
                        }
                        for (; version2Index < version2.size(); ++version2Index) {
                            const auto version2Char = version2[version2Index];
                            if (version2Char != '.') {
                                version2Num += version2Char;
                            } else {
                                ++version2Index;
                                break;
                            }
                        }
                        for (int i = 0; i < version1Num.size(); ++i) {
                            version1Value = version1Value * 10 + version1Num[i] - '0';
                        }
                        for (int i = 0; i < version2Num.size(); ++i) {
                            version2Value = version2Value * 10 + version2Num[i] - '0';
                        }
                        if (version1Value > version2Value) {
                            return 1;
                        } else if (version1Value < version2Value) {
                            return -1;
                        }
                    }
                    return 0;

                }
            };