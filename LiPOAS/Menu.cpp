#include "Menu.h"
#include "Testing.h"

int NumInInt() {
	int variable;
	while (!(cin >> variable) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Некорректно введенные данные. Пожалуйста, введите цифру: " << endl;
	}
	return variable;
}

void Greeting() {
	cout << "Данная программа позволяет вывести в столбец все встречающиеся в тексте символы и количество их встреч в тексте" << endl;
	cout << "Автор: Кувылькин Андрей" << endl;
	cout << "Группа: 494" << endl;
	cout << "Лабораторная работа №1" << endl;
	cout << "Вариант 11" << endl;
	cout << endl;
}

// Основное Меню
bool Menu() {
	enum MenuCase { again = 1, info, testing, finish };
	int variant;
	cout << endl;
	cout << "MENU" << endl;
	cout << "Выберите вариант:" << endl;
	cout << "1. Начать программу заново." << endl;
	cout << "2. Вывести информацию о программе и авторе." << endl;
	cout << "3. Провести тестирование." << endl;
	cout << "4. Выйти из программы." << endl;
	cout << endl;
	variant = NumInInt();
	switch (variant) {
	case again: return true;
	case info: {cout << endl; Greeting(); return Menu(); }
	case testing: {Testing(); return Menu(); }
	case finish: {cout << "Программа завершена." << endl; return false; }
	default: {cout << "Введено неправильное значение." << endl; return Menu(); }
	}
}

// Меню сохранения результата программы в файл
bool MenuResult() {
	enum MenuResuiltCase { Yes = 1, No };
	int variant;
	cout << endl;
	cout << "Сохранить результат в файл?" << endl;
	cout << "1. Да." << endl;
	cout << "2. Нет." << endl;
	cout << endl;
	variant = NumInInt();
	switch (variant) {
	case Yes: return true;
	case No: return false;
	default: {cout << "Введено неправильное значение." << endl; return MenuResult(); }
	}
}

// Меню сохранения исходных данных в файл
bool MenuExportData() {
	enum MenuExportDataCase { Yes = 1, No };
	int variant;
	cout << endl;
	cout << "Сохранить исходные данные в файл?" << endl;
	cout << "1. Да." << endl;
	cout << "2. Нет." << endl;
	cout << endl;
	variant = NumInInt();
	switch (variant) {
	case Yes: return true;
	case No: return false;
	default: {cout << "Введено неправильное значение." << endl; return MenuExportData(); }
	}
}

// Меню выбора расположения исходных данных 
bool MenuImportData() {
	enum MenuImportDataCase { Yes = 1, No };
	int variant;
	cout << endl;
	cout << "Загрузить исходные данные из файла?" << endl;
	cout << "1. Загрузить исходные данные из файла." << endl;
	cout << "2. Ввести исходные данные самостоятельно." << endl;
	cout << endl;
	variant = NumInInt();
	switch (variant) {
	case Yes: return true;
	case No: return false;
	default: {cout << "Введено неправильное значение." << endl; return MenuImportData(); }
	}
}

// Меню выбора перезаписи данных в файл
bool MenuReWrite() {
	enum MenuReWriteCase { ReWrite = 1, SeekClear };
	int variant;
	cout << endl;
	cout << "Файл уже хранит в себе данные. Выберите необходимое действие:" << endl;
	cout << "1. Перезаписать данные в файле" << endl;
	cout << "2. Указать путь к другому файлу" << endl;
	cout << endl;
	variant = NumInInt();
	switch (variant) {
	case ReWrite: return true;
	case SeekClear: return false;
	default: {cout << "Введено неправильное значение." << endl; return MenuReWrite(); }
	}
}