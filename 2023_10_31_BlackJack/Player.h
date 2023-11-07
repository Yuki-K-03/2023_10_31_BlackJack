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
	~CPlayer();

public :
	void add_card(const CPlayer& other, CShoe cShoe);
	int get_size();
	s_player get_card(int size);
	int SumScore();
};