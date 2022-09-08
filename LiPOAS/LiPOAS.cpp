#include <iostream>
#include "StringProcessing.h"
#include "Menu.h"
#include "Testing.h"
#include <vector>
#include "Files.h"
using namespace std;

vector<string> textInputFile(vector<string> text)
{
	ifstream fin;
	int fileReadCorrectCheck = 0;
	cout << "Введите путь к файлу:" << endl;
	string path;
	cin >> path;

	fileReadCorrectCheck = FileReadCorrectChecking(path);
	while (fileReadCorrectCheck == false) { // Проверка корректности файла
		cout << "Ошибка открытия файла. Пожалуйста попробуйте еще раз." << endl;
		cout << "Введите путь к файлу:" << endl;
		cin >> path;
		fileReadCorrectCheck = FileReadCorrectChecking(path);
	}
	string buffer = "\0";
	fin.open(path);
	while (!fin.eof()) { // Чтение текста из файла
		while (getline(fin, buffer))
			text.push_back(buffer);
	}
	fin.close();
	while (text.size() == 0) {
		cout << "Данный файл не содержит текст. Пожалуйста попробуйте еще раз." << endl;
		cout << "Введите путь к файлу:" << endl;
		cin >> path;
		fileReadCorrectCheck = FileReadCorrectChecking(path);
		while (fileReadCorrectCheck == false) { // Проверка корректности файла
			cout << "Ошибка открытия файла. Пожалуйста попробуйте еще раз." << endl;
			cout << "Введите путь к файлу:" << endl;
			cin >> path;
			fileReadCorrectCheck = FileReadCorrectChecking(path);
		}
		buffer = "\0";
		fin.open(path);
		while (!fin.eof()) { // Чтение текста из файла
			while (getline(fin, buffer))
				text.push_back(buffer);
		}
		fin.close();
	}
	return text;
}

vector<string> textInputManual(vector<string> text)
{
	cout << "Введите текст:" << endl;
	cout << "Чтобы завершить ввод текста, нажмите Enter дважды." << endl;
	string buffer = "\0";
	bool firstTry = true;
	while (true) {
		getline(cin, buffer);
		if (buffer != "\0")
			text.push_back(buffer);
		else {
			if (text.size() == false) {
				if (firstTry == true)
					firstTry = false;
				else {
					cout << "Вы не ввели текст. Пожалуйста, попробуйте еще раз." << endl;
					cout << "Введите текст:" << endl;
					cout << "Чтобы завершить ввод текста, нажмите Enter дважды." << endl;
				}
			}
			else
				break;
		}
	}
	return text;
}


int main()
{
    setlocale(LC_ALL, "RU");
    Greeting();
    Testing();
	SetConsoleCP(1251);
	while (true) {
		vector<string> text;
		if (MenuImportData() == true) { // Проверка происхождения исходных данных
			text = textInputFile(text);
			cout << endl << "Полученный из файла текст:" << endl;
			for (unsigned int i = 0; i < text.size(); i++)
				cout << text[i] << endl;
			cout << endl;
		}
		else { // Ввод текста с клавиатуры
			text = textInputManual(text);
			if (MenuExportData() == true) // Возможность вывода исходного текста в файл
				FileWriteData(text);
		}
		map <char, int> resultMap = getEveryCharUsageNum(text);
		vector<string> resultStr = printEveryCharUsageNum(resultMap);
		if (MenuResult() == true) // Возможность выбора сохранения результата программы в файл
		{
			FileWriteData(resultStr);
		}
		if (Menu() == false) // Вызов основного меню после завершения работы программы
			return false;
	}
	return 0;
}

