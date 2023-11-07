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
    int playerScore = 0;
    int dealerScore = 0;

    // 初手ディーラー
    for (int i = 0; i < 2; i++) {
        cDealer.add_card(cDealer, cShoe);
        cShoe.Draw_Size();
    }
    main_dealer = cDealer.get_card(0);
    printf("D -> num:%s, suit:%s\n", CARD_NUMBER[main_dealer.cardNum], CARD_SUIT[main_dealer.cardSuit]);
    printf("Score:%s + a\n\n", CARD_NUMBER[main_dealer.cardNum]);

    // 初手プレイヤ
    for (int i = 0; i < 2; i++) {
        cPlayer.add_card(cPlayer, cShoe);
        cShoe.Draw_Size();
    }
    for (int i = 0; i < cPlayer.get_size(); i++) {
        main_player = cPlayer.get_card(i);
        printf("P -> num:%s, suit:%s\n", CARD_NUMBER[main_player.cardNum], CARD_SUIT[main_player.cardSuit]);
    }
    printf("Score:%d\n", playerScore = cPlayer.SumScore());
    printf("\n");

    // ゲーム開始
    // プレイヤ
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
        printf("Score:%d\n", playerScore = cPlayer.SumScore());
        if (playerScore > 21) {
            printf("ブレイク\n");
        }
    } while (select != 1 && playerScore <= 21);
    printf("\n");

    // ディーラー
    for (int i = 0; i < cDealer.get_size(); i++) {
        main_dealer = cDealer.get_card(i);
        printf("D -> num:%s, suit:%s\n", CARD_NUMBER[main_dealer.cardNum], CARD_SUIT[main_dealer.cardSuit]);
    }
    printf("Score:%d\n", dealerScore = cDealer.SumScore());
    printf("\n");
    while (dealerScore < 17) {
        cDealer.add_card(cDealer, cShoe);
        cShoe.Draw_Size();
        for (int i = 0; i < cDealer.get_size(); i++) {
            main_dealer = cDealer.get_card(i);
            printf("D -> num:%s, suit:%s\n", CARD_NUMBER[main_dealer.cardNum], CARD_SUIT[main_dealer.cardSuit]);
        }
        printf("Score:%d\n", dealerScore = cDealer.SumScore());
        if (dealerScore > 21) {
            printf("ブレイク\n");
        }
    }

    // 勝利判定
    if (playerScore > 21 && dealerScore < 21) {
        printf("\nディーラーの勝利\n");
    }
    else if (dealerScore > 21 && playerScore < 21) {
        printf("\nプレイヤの勝利\n");
    }
    else if (playerScore > dealerScore) {
        printf("\nプレイヤの勝利\n");
    }
    else if (dealerScore > playerScore) {
        printf("\nディーラーの勝利\n");
    }
    else {
        printf("ドロー\n");
    }

    return 0;
}