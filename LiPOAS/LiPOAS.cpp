#include <iostream>
#include "StringProcessing.h"
#include "Menu.h"
using namespace std;




int main()
{
    setlocale(LC_ALL, "RU");
    string text = "Наш лес большой. В лесу растут ели, сосны, дубы, липы, берёзы. В лесу гуляют дети. Они ищут грибы. Боря и Андрюша нашли два рыжика, много маслят. Юра и Яша нашли в лесу ёжика. Они положили ёжика в шапку и принесли домой. Ёжик уколол Юру, но Юра не плакал";
	map <char, int> textMap = getEveryCharUsageNum(text);
    printEveryCharUsageNum(textMap);
}

