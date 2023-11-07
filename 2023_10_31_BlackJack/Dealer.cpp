#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Dealer.h"
using namespace std;

CDealer::~CDealer() {
	//printf("delete\n");
	if (_cardDealer != NULL) {
		delete[] _cardDealer;
		_cardDealer = NULL;
	}
	if (_cardDealerCopy != NULL) {
		delete[] _cardDealerCopy;
		_cardDealerCopy = NULL;
	}
}

void CDealer::add_card(const CDealer& other, CShoe cShoe) {
	//cShoe.Show_cradShoe();
	_numSize++;
	//printf("numSize:%d\n", _numSize);
	if (_numSize > 1) {
		_cardDealerCopy = new s_dealer[_numSize];

		copy(other._cardDealer, other._cardDealer + _numSize, _cardDealerCopy);

		_cardDealer = new s_dealer[_numSize];

		copy(_cardDealerCopy, _cardDealerCopy + _numSize, _cardDealer);
	}
	else {
		_cardDealer = new s_dealer[_numSize];
	}

	cShoe.get_cardShoe(_cardDealer[_numSize - 1].cardNum, _cardDealer[_numSize - 1].cardSuit);

	for (int i = 0; i < _numSize; i++) {
		//printf("\n%d*%d\n", i, _cardDealer[i].cardNum);
	}
}

s_dealer CDealer::get_card(int size) {
	return _cardDealer[size];
}

int CDealer::get_size() {
	return _numSize;
}

int CDealer::SumScore() {
	int sumScore = 0;
	bool b_Ace = false;
	for (int i = 0; i < _numSize; i++) {
		//printf("scr:%d\n", _cardPlayer[i].cardNum);
		if (_cardDealer[i].cardNum == 1) {
			b_Ace = true;
			sumScore += 11;
		}
		else if (_cardDealer[i].cardNum >= 10) {
			sumScore += 10;
		}
		else {
			sumScore += _cardDealer[i].cardNum;
		}

		if (sumScore > 21 && b_Ace) {
			sumScore -= 10;
			b_Ace = false;
		}
	}

	return sumScore;
}