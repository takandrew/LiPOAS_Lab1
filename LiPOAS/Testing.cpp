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
	enum {num0 = 0, num1, num2, num3, num4, num5, num12 = 12};

	cout << endl;
	vector<string> testStr;
	map<char, int> testMap;
	bool isSuccess = true;

	testStr.push_back("тестовая строка");
	testMap.insert(pair<char, int>('а', num2));
	testMap.insert(pair<char, int>('в', num1));
	testMap.insert(pair<char, int>('е', num1));
	testMap.insert(pair<char, int>('к', num1));
	testMap.insert(pair<char, int>('о', num2));
	testMap.insert(pair<char, int>('р', num1));
	testMap.insert(pair<char, int>('т', num3));
	testMap.insert(pair<char, int>('с', num2));
	testMap.insert(pair<char, int>('я', num1));
	testMap.insert(pair<char, int>(' ', num1));
	if (!stringProcessingTest(testStr, testMap))
	{
		cout << "Тест с одной строкой провален" << endl;
		isSuccess = false;
	}
	testStr.clear(); testMap.clear();

	testStr.push_back("        ");
	testStr.push_back("    ");
	testMap.insert(pair<char, int>(' ', num12));
	if (!stringProcessingTest(testStr, testMap))
	{
		cout << "Тест с пробелами провален" << endl;
		isSuccess = false;
	}
	testStr.clear(); testMap.clear();

	testMap.insert(pair<char, int>('e', num0));
	if (!stringProcessingTest(testStr, testMap))
	{
		cout << "Тест с отсутствием строки провален" << endl;
		isSuccess = false;
	}
	testMap.clear();

	testStr.push_back("Тест?*!\n тест");
	testStr.push_back("т \t т");
	testMap.insert(pair<char, int>('Т', num1));
	testMap.insert(pair<char, int>('е', num2));
	testMap.insert(pair<char, int>('с', num2));
	testMap.insert(pair<char, int>('т', num5));
	testMap.insert(pair<char, int>('\t', num1));
	testMap.insert(pair<char, int>('\n', num1));
	testMap.insert(pair<char, int>(' ', num3));
	testMap.insert(pair<char, int>('!', num1));
	testMap.insert(pair<char, int>('*', num1));
	testMap.insert(pair<char, int>('?', num1));
	if (!stringProcessingTest(testStr, testMap))
	{
		cout << "Тест со спецсимволами провален" << endl;
		isSuccess = false;
	}
	testStr.clear(); testMap.clear();

	testStr.push_back("а");
	testStr.push_back("а");
	testStr.push_back("а");
	testStr.push_back("а");
	testMap.insert(pair<char, int>('а', num4));
	if (!stringProcessingTest(testStr,testMap))
	{
		cout << "Тест с несколькими строками и одним символом в алфавите провален" << endl;
		isSuccess = false;
	}
	testStr.clear(); testMap.clear();

	if (isSuccess)
		cout << "Все тесты успешно пройдены" << endl;
}
