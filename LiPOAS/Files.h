#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include <vector>
#include <filesystem>
#include<Windows.h>
#include <atlbase.h>
#include "Menu.h"

#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>

using namespace std::experimental::filesystem;
using namespace std;

bool FileExist(string path); // Проверка существования файла
void FileWriteData(vector<string>& text); // Вывод текста в файл
bool ReadOnlyChecking(string path); //Функция, проверяющая, является ли файл доступным только для чтения. Принимает путь к файлу.
bool FileCorrectChecking(string path); //Функция, проверяющая корректность файла
bool FileReadCorrectChecking(string path); //Функция, проверяющая корректность файла, из которого считывают данные
bool FileOpenChecking(string path); // Функция, проверяющая открытие файла