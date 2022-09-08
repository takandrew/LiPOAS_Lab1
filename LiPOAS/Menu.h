#pragma once
#include <iostream>
using namespace std;

int NumInInt();
void Greeting(); // Приветствие
bool Menu(); // Основное Меню
bool MenuResult(); // Меню сохранения результата программы в файл
bool MenuExportData(); // Меню сохранения исходных данных в файл
bool MenuImportData(); // Меню выбора происхождения исходных данных 
bool MenuReWrite(); // Меню выбора перезаписи данных в файл