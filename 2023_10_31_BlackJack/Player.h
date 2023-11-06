#pragma once
#include "Shoe.h"

class CPlayer {
private :
	s_card* _cardPlayer;
	s_card* _cardPlayerCpy;
	//int* _pNum;
	int _numSize = 0;

public :
	void operator = (const CPlayer& other);

public :
	CPlayer(const CPlayer& other);
	CPlayer();
	~CPlayer();

public :
	void add_card(const CPlayer& other, CShoe cShoe);
	int get_pNum();
	int get_Size();
};