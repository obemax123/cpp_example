/**
* \file Taxes_i.cpp
* \brief ���������� ������� ��� ������ � ������
* \details �������� ������� ���� ������ �� ����� taxes.txt
* \author ����������� �.�.
* \date ���� ��������� ����������� 10.01.2022
*/
#include"TaxesInput.h"
void first_taxesin(int& num) {
	ifstream taxesfile("taxes.txt");
	taxesfile >> num;
}
void second_taxesin(int num, tariff tariffs[]) {
	ifstream taxesfile("taxes.txt");

	int rubbish;

	taxesfile >> rubbish;

	for (int i = 0; i < num; i++) {
		taxesfile >> tariffs[i].name >> tariffs[i].cost >> tariffs[i].k;
	}
}