/**
* \file Home_i.cpp
* \brief реализация функций для работы с файлом
* \details основная функция ввод данных из файла home.txt
* \author Обертинский М.В.
* \date дата последней модификации 10.01.2022
*/
#include "HomeInput.h"
void first_homein(int& num, int& area) {
	ifstream homefile("home.txt");
	homefile >> num >> area;
}

int second_homein(int num, flat flats[]) {
	int num_of_residents = 0;
	int rubbish;

	ifstream homefile("home.txt");
	
	homefile >> rubbish >> rubbish;

	for (int i = 0; i < num; i++) {
		homefile >> flats[i].flat_area >> flats[i].num_of_residents;
		num_of_residents += flats[i].num_of_residents;
	}

	return num_of_residents;
}