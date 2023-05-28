/**
* \file TaxesInput.h
* \brief объявление функций для работы с файлом
* \details основная функция ввод данных из файла taxes.txt
* \author Обертинский М.В.
* \date дата последней модификации 10.01.2022
*/
#pragma once
#include"HomeInput.h"
/**
* \brief Функция предназначена для ввода целочисленного значения из файла
* \details ввод переменной количества ресурсов
* \param num количество ресурсов
*/
void first_taxesin(int& num);
/**
* \brief Функция предназначена для ввода массива данных о квартирах
* \details функция вводит данные о квартирах в массив
* \param num количество ресурсов
* \param tariffs[] массив данных о тарифах на ресурсы
*/
void second_taxesin(int num, tariff tariffs[]);
