/*Game of passing potatoes...The player who gets potato after n passes  gets eliminated
.The player who who remains uneliminated wins the game */

#include<iostream>
#include"doublylinkedlist_implementation.h"
using namespace std;

void play_potatopass(dnode *&player)
{ int num_p,pass;
     cout<<"Enter num of players :";
    cin>>num_p;
    cout<<"Enter num of passes :";
    cin>>pass;
    int i,count=1;
 // storing playernames
  player=new dnode;
  dnode *start_player=player;
  player->left='\0';

  char c='A';
  player->data=c++;
  cout<<"Players names  : ";
   cout<<player->data<<"  ";
    for(i=1;i<num_p; i++)
    {   player->right=new dnode;
        player->right->data=c++;
         cout<<player->right->data<<"  ";
        player->right->right='\0';
       player->right->left=player;
       player=player->right;

    }
    player->right=start_player;
     start_player->left=player;
     player=start_player;
 //game starts
 cout<<"\nGAME STARTS";
 while(count++ < num_p)
 {
     for(i=0;i< pass;i++)
        player=player->right;
     cout<<"\n player "<< player->data <<"  eliminated ";
     //deleting player
     player->left->right=player->right;
     player->right->left=player->left;
     player=player->right;
 }

cout<<"\n\nWinner of the game : Player "<< player->data;


}

int main()
{
dnode *player;
play_potatopass(player);
}


