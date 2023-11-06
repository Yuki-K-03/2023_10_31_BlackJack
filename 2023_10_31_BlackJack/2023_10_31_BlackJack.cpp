#include <cstdio>
#include <iostream>
#include "Player.h"
#include "Dealer.h"
#include "Shoe.h"
using namespace std;

int main()
{
    CShoe cShoe(CARD_MAX);
    s_card shoe;

    //cShoe.Shuffle_cardShoe();
    cShoe.Show_cradShoe();

    cShoe.get_cardShoe(shoe);
    printf("%d:%d\n", shoe.cardNum, shoe.cardSuit);
    cShoe.get_cardShoe(shoe);
    printf("%d:%d\n", shoe.cardNum, shoe.cardSuit);

    {
        cShoe.get_cardShoe(shoe);
        printf("%d:%d\n", shoe.cardNum, shoe.cardSuit);
        cShoe.get_cardShoe(shoe);
        printf("%d:%d\n", shoe.cardNum, shoe.cardSuit);
    }
    cShoe.get_cardShoe(shoe);
    printf("%d:%d\n", shoe.cardNum, shoe.cardSuit);

    CPlayer cPlayer;

    cPlayer.add_card(cPlayer, cShoe);
    cPlayer.add_card(cPlayer, cShoe);
    cPlayer.add_card(cPlayer, cShoe);
}