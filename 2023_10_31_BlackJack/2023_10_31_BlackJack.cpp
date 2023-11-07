#include <cstdio>
#include <iostream>
#include "Player.h"
#include "Dealer.h"
#include "Shoe.h"
using namespace std;

const char* CARD_SUIT[] = { "heart", "diamond", "spade", "club" };
const char* CARD_NUMBER[] = { " ", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

int main()
{
    CShoe cShoe;

    cShoe.Show_cradShoe();
    printf("\n");

    CPlayer cPlayer;
    CDealer cDealer;

    s_dealer main_dealer;
    s_player main_player;

    int select = 0;
    // 初手ディーラー
    for (int i = 0; i < 2; i++) {
        cDealer.add_card(cDealer, cShoe);
        cShoe.Draw_Size();
    }
    main_dealer = cDealer.get_card(0);
    printf("D -> num:%s, suit:%s\n", CARD_NUMBER[main_dealer.cardNum], CARD_SUIT[main_dealer.cardSuit]);
    /*for (int i = 0; i < cDealer.get_size(); i++) {
        main_dealer = cDealer.get_card(i);
        printf("D -> num:%s, suit:%s\n", CARD_NUMBER[main_dealer.cardNum], CARD_SUIT[main_dealer.cardSuit]);
    }*/
    // 初手プレイヤ
    for (int i = 0; i < 2; i++) {
        cPlayer.add_card(cPlayer, cShoe);
        cShoe.Draw_Size();
    }
    for (int i = 0; i < cPlayer.get_size(); i++) {
        main_player = cPlayer.get_card(i);
        printf("P -> num:%s, suit:%s\n", CARD_NUMBER[main_player.cardNum], CARD_SUIT[main_player.cardSuit]);
    }

    // ゲーム開始
    do {
        printf("1 > スタンド\n2 > ヒット\n> ");
        cin >> select;
        if (select == 2) {
            cPlayer.add_card(cPlayer, cShoe);
            cShoe.Draw_Size();
        }
        for (int i = 0; i < cPlayer.get_size(); i++) {
            main_player = cPlayer.get_card(i);
            printf("P -> num:%s, suit:%s\n", CARD_NUMBER[main_player.cardNum], CARD_SUIT[main_player.cardSuit]);
        }
    } while (select != 1);


}