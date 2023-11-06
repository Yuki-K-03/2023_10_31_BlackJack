#pragma once
#include "Shoe.h"

struct s_dealer
{
	int cardNum;
	int cardSuit;
};

class CDealer {
private:
	s_dealer* _cardDealer = { 0 };
	s_dealer* _cardDealerCopy = { 0 };
	int _numSize = 0;

public:
	~CDealer();

public:
	void add_card(const CDealer& other, CShoe cShoe);
	s_dealer get_card(int size);
};