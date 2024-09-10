#include <iostream>
#include <vector>
#include <clocale>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	// �������������
	vector<int> myTape; // �������� ����������� �����, ������ ����� ����� ����� 20
	for (size_t i = 0; i < 20; i++)
		myTape.push_back(-1); // ������ ����� ���������� ��������� -1

	size_t myMark = 5; // ��������� ��������� ������� - ���� ����� �������� �����, ������� - 5 �� 20
	size_t wordLen = 20;
	int temp, alphabetLen, statementLen;

	cout << "������� ����� ����� �� ����� 6:" << endl; // ����� ����� ����� ��������
	while (wordLen > 6 || wordLen < 0) {
		cout << endl << "������� ����� �����:" << endl;
		cin >> wordLen;
		if (wordLen > 6 || wordLen == 0)
			cout << endl << "������� ���������� ����� �����, �� ������ 0 � ������� 6!" << endl;
	}

	cout << endl << "������� ����� �����������:" << endl;
	for (size_t i = myMark; i < myMark + wordLen; i++) {
		cin >> temp;
		myTape[i] = temp;
	} temp = 0;

	cout << "������ ������� �����:" << endl;
	for (size_t i = 0; i < myTape.size(); i++)
		cout << setw(4) << myTape[i] << setw(3);

	vector<vector<string>> functionalMatrix;
	cout << endl << "������� ����� ��������:" << endl;
	cin >> alphabetLen;
	cout << endl << "������� ����� ���������:" << endl;
	cin >> statementLen;
	vector<string> tempVecStatement;
	for (size_t i = 0; i < alphabetLen; i++)
		tempVecStatement.push_back("---"); // �� ��������� ��� �������� �������������� ������� -
	for (size_t i = 0; i < statementLen; i++)
		functionalMatrix.push_back(tempVecStatement);

	cout << endl << "������� �������:" << endl;
	vector<int> myAlphabet;
	for (size_t i = 0; i < alphabetLen; i++) {
		cin >> temp;
		myAlphabet.push_back(temp);
	} temp = 0;

	cout << endl << "�� ����� �������:" << endl;
	for (size_t i = 0; i < myAlphabet.size(); i++)
		cout << setw(4) << myAlphabet[i] << setw(3);

	cout << endl << "������� ������ �������������� ������� � ������� 0L0 (� ����� - ����� ���������), ���� ������� ������, ������� ---. qk ������������ 9, ������ - l." << endl;
	string tempStr;
	for (size_t i = 0; i < statementLen; i++)
		for (size_t j = 0; j < alphabetLen; j++) {
			cout << "��� ����� �������������� " << myAlphabet[j] << " � ��������� q" << i << " ?" << endl;
			cin >> tempStr;
			functionalMatrix[i][j] = tempStr;
		}
	tempStr.clear();

	cout << endl << "�� ������ �������������� �������:" << endl;
	for (size_t i = 0; i < statementLen; i++) {
		cout << endl << endl;
		for (size_t j = 0; j < alphabetLen; j++) {
			cout << setw(4) << functionalMatrix[i][j] << setw(3);
		}
	}
	cout << endl << endl;

	int value = 0; // ��� ����� �������� � ������
	size_t position = myMark; // ��������� �������
	int state = 0; // ��������� ������

	while (state != 9) {
		for (int i = 0; i < alphabetLen; i++) {
			if (myTape[position] == myAlphabet[i] && state != 9)
			{
				// ������ � ������ �����
				switch (functionalMatrix[state][i][0])
				{
				case '0':
					myTape[position] = 0;
					break;
				case '1':
					myTape[position] = 1;
					break;
				case '2':
					myTape[position] = 2;
					break;
				case '3':
					myTape[position] = 3;
					break;
				case '4':
					myTape[position] = 4;
					break;
				case 'l':
					myTape[position] = -1;
					break;
				default:
					myTape[position] = myTape[position];
					break;
				}

				// ����� �������
				if (functionalMatrix[state][i][1] == '-')
					position = position;
				if (functionalMatrix[state][i][1] == 'R')
					position += 1;
				if (functionalMatrix[state][i][1] == 'L')
					position -= 1;

				// ����� ��������� (stoi �� ����� ��� ������������...)
				switch (functionalMatrix[state][i][2])
				{
				case '-':
					state = state;
					break;
				case '0':
					state = 0;
					break;
				case '1':
					state = 1;
					break;
				case '2':
					state = 2;
					break;
				case '3':
					state = 3;
					break;
				case '4':
					state = 4;
					break;
				case '5':
					state = 5;
					break;
				case '6':
					state = 6;
					break;
				case '7':
					state = 7;
					break;
				case '8':
					state = 8;
					break;
				default:
					state = 9;
					break;
				}
			}
		}
	}

	cout << "�������� �����:" << endl;
	for (size_t i = 0; i < myTape.size(); i++)
		cout << setw(4) << myTape[i] << setw(3);

	system("pause");
	return 0;
}