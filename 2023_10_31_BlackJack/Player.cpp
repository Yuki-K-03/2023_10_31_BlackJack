#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Player.h"
using namespace std;

void CPlayer::operator = (const CPlayer& other) {
	
}

CPlayer::CPlayer() {
	_cardPlayer = new s_card[_numSize];
	_cardPlayer[_numSize - 1].cardNum = 0;
	_cardPlayer[_numSize - 1].cardSuit= 0;
}

CPlayer::~CPlayer() {
	if (_cardPlayer != NULL) {
		delete[] _cardPlayer;
		_cardPlayer = NULL;
	}
}

void CPlayer::add_card(const CPlayer& other, CShoe cShoe) {
	cShoe.Show_cradShoe();
	_numSize++;
	_cardPlayer = new s_card[_numSize];
	_cardPlayer[0].cardNum = 0;
	_cardPlayer[0].cardSuit = 0;

	copy(other._cardPlayer, other._cardPlayer + _numSize, _cardPlayer);

	cShoe.get_cardShoe(_cardPlayer[_numSize - 1]);

	for (int i = 0; i < _numSize; i++) {
		printf("\n*%d\n", _cardPlayer[i].cardNum);
	}
}