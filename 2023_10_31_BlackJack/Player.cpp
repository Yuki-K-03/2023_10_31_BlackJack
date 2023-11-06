#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Player.h"
using namespace std;

void CPlayer::operator = (const CPlayer& other) {
	printf("ope");
}

//CPlayer::CPlayer() {
//	printf("numSize:%d\n", _numSize);
//	_cardPlayer = new s_player[_numSize + 1];
//	_cardPlayer[_numSize].cardNum = 0;
//	_cardPlayer[_numSize].cardSuit= 0;
//}
//
//CPlayer::CPlayer(const CPlayer& other) {
//	printf("copy\n");
//	_cardPlayer = new s_player[other._numSize];
//	_numSize = other._numSize;
//	copy(other._cardPlayer, other._cardPlayer + _numSize, _cardPlayer);
//}
//
CPlayer::~CPlayer() {
	printf("delete\n");
	if (_cardPlayer != NULL) {
		delete[] _cardPlayer;
		_cardPlayer = NULL;
	}
	if (_cardPlayerCopy != NULL) {
		delete[] _cardPlayerCopy;
		_cardPlayerCopy = NULL;
	}
}

void CPlayer::add_card(const CPlayer& other, CShoe cShoe) {
	cShoe.Show_cradShoe();
	_numSize++;
	printf("numSize:%d\n", _numSize);
	if (_numSize > 1) {
		_cardPlayerCopy = new s_player[_numSize];

		copy(other._cardPlayer, other._cardPlayer + _numSize, _cardPlayerCopy);

		for (int i = 0; i < _numSize; i++) {
			printf("\ncopy%d*%d\n", i, other._cardPlayer[i].cardNum);
		}
		_cardPlayer = new s_player[_numSize];

		copy(_cardPlayerCopy, _cardPlayerCopy + _numSize, _cardPlayer);
	}
	else {
		_cardPlayer = new s_player[_numSize];
	}

	cShoe.get_cardShoe(_cardPlayer[_numSize - 1].cardNum, _cardPlayer[_numSize - 1].cardSuit);

	for (int i = 0; i < _numSize; i++) {
		printf("\n%d*%d\n", i, _cardPlayer[i].cardNum);
	}
}