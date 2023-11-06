#pragma once

enum e_Suit {
	e_Heart,
	e_Diamond,
	e_Spade,
	e_Club,
};

const int NUMBER_MAX = 13;
const int CARD_MAX = 52;

struct s_card
{
	int cardNum;
	int cardSuit;
};

class CShoe {
private :
	s_card* _cardShoe;
	int _cardSize = CARD_MAX - 1;

public :
	CShoe(int size);
	CShoe(const CShoe& other);

public :
	void get_cardShoe(s_card &other);
	void Shuffle_cardShoe();
	void Show_cradShoe();
};