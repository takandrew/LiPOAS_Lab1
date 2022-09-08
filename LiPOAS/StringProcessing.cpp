#include "StringProcessing.h"

vector<string> printEveryCharUsageNum(map <char, int> gotMap)
{
	if (gotMap.size() == 1)
	{
        if (gotMap.find('e') != gotMap.end())
        {
            cout << "Строка пуста" << endl;
            vector<string> nullStr;
            return nullStr;
        }
	}
    vector<string> mapStr;
    for (auto it = gotMap.cbegin(); it != gotMap.cend(); ++it)
    {
        string key = "";
        key.push_back(it->first);
        if (key == "\n")
            key = "\\n";
        else if (key == "\t")
            key = "\\t";
        else
            key = " " + key;
        int value = it->second;
        string curChar = "Символ: " + key + " Количество повторений: " + to_string(value);
        mapStr.push_back(curChar);
        cout << curChar << endl;
    }
    return mapStr;
}

map <char, int> getEveryCharUsageNum(vector<string> gotStr) {
    if (gotStr.empty())
    {
        map <char, int> emptyMap = { {'e',0} };
        return emptyMap;
    }
    map <char, int> charInGotStr;
    for (int i = 0; i < gotStr.size(); i++) {
        for (int j = 0; j < gotStr[i].size(); j++)
        {
            if (charInGotStr.find(gotStr[i][j]) != charInGotStr.end()) {
                charInGotStr.find(gotStr[i][j])->second = charInGotStr.find(gotStr[i][j])->second + 1;
            }
            else {
                charInGotStr.insert(pair<char, int>(gotStr[i][j], 1));
            }
        }
    }
    return charInGotStr;
}
