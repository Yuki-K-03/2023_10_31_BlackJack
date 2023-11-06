#include <iostream>
#include <ctime>
#include "Shoe.h"
using namespace std;

CShoe::CShoe(int size = CARD_MAX) {
	_cardShoe = new s_card[CARD_MAX];
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

CShoe::CShoe(const CShoe& other) {
	printf("cpy\n");
	_cardShoe = new s_card[other._cardSize];
	_cardSize = other._cardSize;
	copy(other._cardShoe, other._cardShoe + _cardSize, _cardShoe);
}

void CShoe::get_cardShoe(s_card& other) {
	printf("size:%d\n", _cardSize);
	other = _cardShoe[_cardSize--];
}

void CShoe::Shuffle_cardShoe() {
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


void CShoe::Show_cradShoe() {
	for (int i = 0; i <= _cardSize; i++) {
		printf("%d:%d, ", _cardShoe[i].cardNum, _cardShoe[i].cardSuit);
	}
	printf("\n");
}