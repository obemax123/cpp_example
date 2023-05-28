/**
* \file TaxesInput.h
* \brief ���������� ������� ��� ������ � ������
* \details �������� ������� ���� ������ �� ����� taxes.txt
* \author ����������� �.�.
* \date ���� ��������� ����������� 10.01.2022
*/
#pragma once
#include"HomeInput.h"
/**
* \brief ������� ������������� ��� ����� �������������� �������� �� �����
* \details ���� ���������� ���������� ��������
* \param num ���������� ��������
*/
void first_taxesin(int& num);
/**
* \brief ������� ������������� ��� ����� ������� ������ � ���������
* \details ������� ������ ������ � ��������� � ������
* \param num ���������� ��������
* \param tariffs[] ������ ������ � ������� �� �������
*/
void second_taxesin(int num, tariff tariffs[]);
