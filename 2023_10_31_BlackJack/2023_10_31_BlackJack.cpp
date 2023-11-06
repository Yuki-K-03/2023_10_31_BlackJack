#include <cstdio>
#include <iostream>
#include "Player.h"
#include "Dealer.h"
#include "Shoe.h"
using namespace std;

const char* CARD_SUIT[] = { "heart", "diamond", "spade", "club" };
const char* CARD_NUMBER[] = { " " ,"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

int main()
{
    CShoe cShoe;

    cShoe.Show_cradShoe();

    CPlayer cPlayer;
    CDealer cDealer;

    for (int i = 0; i < 2; i++) {
        cDealer.add_card(cDealer, cShoe);
        cShoe.Draw_Size();
    }

    cPlayer.add_card(cPlayer, cShoe);
    cShoe.Draw_Size();
    cPlayer.add_card(cPlayer, cShoe);
    cShoe.Draw_Size();
    cPlayer.add_card(cPlayer, cShoe);
}