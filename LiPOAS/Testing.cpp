#include "Testing.h"

bool stringProcessingTest(vector<string> gotStr, map<char, int> gotMap)
{
	map<char, int> testingMap = getEveryCharUsageNum(gotStr);
	//printEveryCharUsageNum(testingMap);;
	if (testingMap.size() != gotMap.size())
		return false;
    for (auto it = testingMap.cbegin(), jt = gotMap.cbegin(); it != testingMap.cend(); ++it, ++jt)
    {
		if (it->first != jt->first || it->second != jt->second)
			return false;
    }
	return true;
}

void Testing()
{
	cout << endl;
	vector<string> testStr;
	map<char, int> testMap;
	bool isSuccess = true;

	testStr.push_back("тестовая строка");
	testMap.insert(pair<char, int>('а', 2));
	testMap.insert(pair<char, int>('в', 1));
	testMap.insert(pair<char, int>('е', 1));
	testMap.insert(pair<char, int>('к', 1));
	testMap.insert(pair<char, int>('о', 2));
	testMap.insert(pair<char, int>('р', 1));
	testMap.insert(pair<char, int>('т', 3));
	testMap.insert(pair<char, int>('с', 2));
	testMap.insert(pair<char, int>('я', 1));
	testMap.insert(pair<char, int>(' ', 1));
	if (!stringProcessingTest(testStr, testMap))
	{
		cout << "Тест с одной строкой провален" << endl;
		isSuccess = false;
	}
	testStr.clear(); testMap.clear();

	testStr.push_back("        ");
	testStr.push_back("    ");
	testMap.insert(pair<char, int>(' ', 12));
	if (!stringProcessingTest(testStr, testMap))
	{
		cout << "Тест с пробелами провален" << endl;
		isSuccess = false;
	}
	testStr.clear(); testMap.clear();

	testMap.insert(pair<char, int>('e', 0));
	if (!stringProcessingTest(testStr, testMap))
	{
		cout << "Тест с отсутствием строки провален" << endl;
		isSuccess = false;
	}
	testMap.clear();

	testStr.push_back("Тест?*!\n тест");
	testStr.push_back("т \t т");
	testMap.insert(pair<char, int>('Т', 1));
	testMap.insert(pair<char, int>('е', 2));
	testMap.insert(pair<char, int>('с', 2));
	testMap.insert(pair<char, int>('т', 5));
	testMap.insert(pair<char, int>('\t', 1));
	testMap.insert(pair<char, int>('\n', 1));
	testMap.insert(pair<char, int>(' ', 3));
	testMap.insert(pair<char, int>('!', 1));
	testMap.insert(pair<char, int>('*', 1));
	testMap.insert(pair<char, int>('?', 1));
	if (!stringProcessingTest(testStr, testMap))
	{
		cout << "Тест со спецсимволами провален" << endl;
		isSuccess = false;
	}
	testStr.clear(); testMap.clear();

	//TODO: Придумать последний тест
	//testStr.push_back("");
	//testStr.push_back("");
	////testMap.insert(pair<char, int>('', 2));
	//if (!stringProcessingTest(testStr,testMap))
	//{
	//	cout << "Тест с пустыми строками провален" << endl;
	//	isSuccess = false;
	//}
	//testStr.clear(); testMap.clear();

	if (isSuccess)
		cout << "Все тесты успешно пройдены" << endl;
}
