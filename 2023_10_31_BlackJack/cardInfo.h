#pragma once

enum e_Suit {
	e_Heart,
	e_Diamond,
	e_Spade,
	e_Club,
};

const int NUMBER_MAX = 13;
const int CARD_MAX = 52;
const char* CARD_SUIT[] = { "heart", "diamond", "spade", "club" };
const char* CARD_NUMBER[] = { " " ,"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

struct s_card
{
	int cardNum;
	int cardSuit;
};