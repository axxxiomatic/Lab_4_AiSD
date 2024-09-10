#include <iostream>
#include <vector>
#include <clocale>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	// Инициализация
	vector<int> myTape; // Имитация бесконечной ленты, вектор будет иметь длину 20
	for (size_t i = 0; i < 20; i++)
		myTape.push_back(-1); // Лямбду будем кодировать значением -1

	size_t myMark = 5; // Начальное положение каретки - чуть левее середины ленты, условно - 5 из 20
	size_t wordLen = 20;
	int temp, alphabetLen, statementLen;

	cout << "Введите слово длины не более 6:" << endl; // Длина слова также условная
	while (wordLen > 6 || wordLen < 0) {
		cout << endl << "Введите длину слова:" << endl;
		cin >> wordLen;
		if (wordLen > 6 || wordLen == 0)
			cout << endl << "Введите корректную длину слова, не равную 0 и меньшую 6!" << endl;
	}

	cout << endl << "Введите слово поэлементно:" << endl;
	for (size_t i = myMark; i < myMark + wordLen; i++) {
		cin >> temp;
		myTape[i] = temp;
	} temp = 0;

	cout << "Сейчас имеется лента:" << endl;
	for (size_t i = 0; i < myTape.size(); i++)
		cout << setw(4) << myTape[i] << setw(3);

	vector<vector<string>> functionalMatrix;
	cout << endl << "Введите длину алфавита:" << endl;
	cin >> alphabetLen;
	cout << endl << "Введите число состояний:" << endl;
	cin >> statementLen;
	vector<string> tempVecStatement;
	for (size_t i = 0; i < alphabetLen; i++)
		tempVecStatement.push_back("---"); // По умолчанию все элементы функциональной таблицы -
	for (size_t i = 0; i < statementLen; i++)
		functionalMatrix.push_back(tempVecStatement);

	cout << endl << "Введите алфавит:" << endl;
	vector<int> myAlphabet;
	for (size_t i = 0; i < alphabetLen; i++) {
		cin >> temp;
		myAlphabet.push_back(temp);
	} temp = 0;

	cout << endl << "Вы ввели алфавит:" << endl;
	for (size_t i = 0; i < myAlphabet.size(); i++)
		cout << setw(4) << myAlphabet[i] << setw(3);

	cout << endl << "Вводите ячейки функциональной таблицы в формате 0L0 (в конце - номер состояния), если элемент пустой, введите ---. qk обозначается 9, лямбда - l." << endl;
	string tempStr;
	for (size_t i = 0; i < statementLen; i++)
		for (size_t j = 0; j < alphabetLen; j++) {
			cout << "Как будет обрабатываться " << myAlphabet[j] << " в состоянии q" << i << " ?" << endl;
			cin >> tempStr;
			functionalMatrix[i][j] = tempStr;
		}
	tempStr.clear();

	cout << endl << "Вы задали функциональную матрицу:" << endl;
	for (size_t i = 0; i < statementLen; i++) {
		cout << endl << endl;
		for (size_t j = 0; j < alphabetLen; j++) {
			cout << setw(4) << functionalMatrix[i][j] << setw(3);
		}
	}
	cout << endl << endl;

	int value = 0; // Что будет записано в ячейку
	size_t position = myMark; // Положение каретки
	int state = 0; // Состояние машины

	while (state != 9) {
		for (int i = 0; i < alphabetLen; i++) {
			if (myTape[position] == myAlphabet[i] && state != 9)
			{
				// Запись в ячейку ленты
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

				// Сдвиг каретки
				if (functionalMatrix[state][i][1] == '-')
					position = position;
				if (functionalMatrix[state][i][1] == 'R')
					position += 1;
				if (functionalMatrix[state][i][1] == 'L')
					position -= 1;

				// Смена состояний (stoi не хотел его обрабатывать...)
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

	cout << "Итоговая лента:" << endl;
	for (size_t i = 0; i < myTape.size(); i++)
		cout << setw(4) << myTape[i] << setw(3);

	system("pause");
	return 0;
}