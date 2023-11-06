#include <cstdio>
#include <iostream>
#include "Player.h"
#include "Dealer.h"
#include "Shoe.h"
using namespace std;

int main()
{
    CShoe cShoe;
    s_card shoe{};

    cShoe.Show_cradShoe();

    CPlayer cPlayer;

    cPlayer.add_card(cPlayer, cShoe);
    cShoe.Draw_Size();
    cPlayer.add_card(cPlayer, cShoe);
    cShoe.Draw_Size();
    cPlayer.add_card(cPlayer, cShoe);
}