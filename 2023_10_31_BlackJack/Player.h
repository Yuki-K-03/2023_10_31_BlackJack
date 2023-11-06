#pragma once
#include "Shoe.h"

struct s_player
{
	int cardNum;
	int cardSuit;
};

class CPlayer {
private :
	s_player* _cardPlayer = { 0 };
	s_player* _cardPlayerCopy = { 0 };
	int _numSize = 0;

public :
	void operator = (const CPlayer& other);

public :
	/*CPlayer();
	CPlayer(const CPlayer& other);*/
	~CPlayer();

public :
	void add_card(const CPlayer& other, CShoe cShoe);
	int get_pNum();
	int get_Size();
};