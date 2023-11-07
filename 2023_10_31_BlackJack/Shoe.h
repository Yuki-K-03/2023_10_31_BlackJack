#pragma once

const int NUMBER_MAX = 13;
const int CARD_MAX = 52;

struct s_card
{
	int cardNum;
	int cardSuit;
};

class CShoe {
private :
	s_card _cardShoe[CARD_MAX];
	int _cardSize = CARD_MAX - 1;

public :
	CShoe();

public :
	void get_cardShoe(int &num, int &suit);
	void Show_cradShoe();
	void Draw_Size();
};