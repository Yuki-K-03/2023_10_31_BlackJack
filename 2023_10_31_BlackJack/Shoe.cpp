#include <iostream>
#include <ctime>
#include "Shoe.h"
using namespace std;

CShoe::CShoe() {
	srand((unsigned int)time(NULL));

	for (int i = 0; i < CARD_MAX; i++) {
		_cardShoe[i].cardNum = i % NUMBER_MAX + 1;
		_cardShoe[i].cardSuit = i / NUMBER_MAX;
	}


	int randNum = 0;
	for (int i = 1; i <= CARD_MAX - 1; i++) {
		randNum = rand() % (CARD_MAX - i);
		swap(_cardShoe[CARD_MAX - i], _cardShoe[randNum]);
	}
}
void CShoe::get_cardShoe(int &num, int &suit) {
	//printf("size:%d %d-%d\n", _cardSize, _cardShoe[_cardSize].cardNum, _cardShoe[_cardSize].cardSuit);
	num = _cardShoe[_cardSize].cardNum;
	suit = _cardShoe[_cardSize].cardSuit;
}

void CShoe::Show_cradShoe() {
	for (int i = 0; i <= _cardSize; i++) {
		printf("%d:%d, ", _cardShoe[i].cardNum, _cardShoe[i].cardSuit);
	}
	printf("\n");
}

void CShoe::Draw_Size() {
	_cardSize--;
}