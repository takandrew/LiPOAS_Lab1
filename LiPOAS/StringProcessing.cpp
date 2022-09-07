#include "StringProcessing.h"

void printEveryCharUsageNum(map <char, int> gotMap)
{
	if (gotMap.size() == 1)
	{
        if (gotMap.find('e') != gotMap.end())
        {
            cout << "Строка пуста" << endl;
            return;
        }
	}
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

        cout << "Символ: " << key << " Количество повторений: " << it->second << "\n";
    }
    return;
}

map <char, int> getEveryCharUsageNum(string gotStr) {
    if (gotStr.empty())
    {
        map <char, int> emptyMap = { {'e',0} };
        return emptyMap;
    }
    map <char, int> charInGotStr;
    for (int i = 0; i < gotStr.size(); i++) {
        if (charInGotStr.find(gotStr[i]) != charInGotStr.end()) {
            charInGotStr.find(gotStr[i])->second = charInGotStr.find(gotStr[i])->second + 1;
        }
        else {
            charInGotStr.insert(std::pair<char, int>(gotStr[i], 1));
        }
    }
    return charInGotStr;
}
