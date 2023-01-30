#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "dec.h"
using namespace std;

string board[9] = { " " , " " , " " , " " , " " ," " , " " , " " , " " };
int player = 1;
int position = 0;
bool score1 = false;
bool score2 = false;
string player1 , player2;
string temp;

int Scoreboard()
{
	fstream write("scoreboard.txt");
	while(write >> temp)
	{
	cout << temp << " ";
	}
}
int menu()
{	int input_menu;
	cout << "\n1) Start game \n2) Scoreboard \n3) Exit \n";
	cin >> input_menu;
	if(input_menu==1)
	{
		introduction();
		take_turn();
		end_game();
	}
	else if(input_menu==2)
	{
		Scoreboard();
	}
	else if(input_menu==3)
	{
		exit(0);
	}
}

void introduction()
{
	cout << "players Enter your names \n";
	cin >> player1 ;
	cin >> player2 ;
	cout << "press [Enter] to start game: \n";
	getchar();
	
	
	
	cout << "***************\n";
	cout << "Tic-Tac-Toe\n";
	cout << "***************\n";
	
	cout << player1 <<" X\n";
	cout << player2 <<" O\n";
	
	cout << "The 3x3 grid is shown below: \n\n";
	
	cout << "     |     |      \n";
	cout << "  1  |  2  |  3   \n";
	cout << "_____|_____|_____ \n";
	cout << "     |     |      \n";
	cout << "  4  |  5  |  6   \n";
	cout << "_____|_____|_____ \n";
	cout << "     |     |      \n";
	cout << "  7  |  8  |  9   \n";
	cout << "     |     |      \n";
}


 bool is_winner()
 {
 	bool winner = false;
 	
 	//checking the rows 
 	
 	if((board[0]==board[1]) && (board[1]==board[2]) && board[0] != " ")
 	{
	 winner=true;
	 if(board[0]=="X" && board[1]=="X" && board[2]=="X")
	 {
	 	score1=true;
	 }
	 else if(board[0]=="O" && board[1]=="O" && board[2]=="O")
	 {
	 	score2=true;
	 }
	}
	else if((board[3]==board[4]) && (board[4]==board[5]) && board[3] != " ")
 	{
	 winner=true;
	 if(board[3]=="X" && board[4]=="X" && board[5]=="X")
	 {
	 	score1=true;
	 }
	 else if(board[3]=="O" && board[4]=="O" && board[5]=="O")
	 {
	 	score2=true;
	 }
	}
	else if((board[6]==board[7]) && (board[7]==board[8]) && board[6] != " ")
 	{
	 winner=true;
	 if(board[6]=="X" && board[7]=="X" && board[8]=="X")
	 {
	 	score1=true;
	 }
	 else if(board[6]=="O" && board[7]=="O" && board[8]=="O")
	 {
	 	score2=true;
	 }
	}
 	
 	//checking the columns 
 	
 	else if((board[0]==board[3]) && (board[3]==board[6]) && board[0] != " ")
 	{
	 winner=true;
	 if(board[0]=="X" && board[3]=="X" && board[6]=="X")
	 {
	 	score1=true;
	 }
	 else if(board[0]=="O" && board[3]=="O" && board[6]=="O")
	 {
	 	score2=true;
	 }
	}
	else if((board[1]==board[4]) && (board[4]==board[7]) && board[1] != " ")
 	{
	 winner=true;
	 if(board[1]=="X" && board[4]=="X" && board[7]=="X")
	 {
	 	score1=true;
	 }
	 else if(board[1]=="O" && board[4]=="O" && board[7]=="O")
	 {
	 	score2=true;
	 }
	}
 	else if((board[2]==board[5]) && (board[5]==board[8]) && board[2] != " ")
 	{
	 winner=true;
	 if(board[2]=="X" && board[5]=="X" && board[8]=="X")
	 {
	 	score1=true;
	 }
	 else if(board[2]=="O" && board[5]=="O" && board[8]=="O")
	 {
	 	score2=true;
	 }
	}
	
 	//checking the diagonals
 	
 	else if((board[0]==board[4]) && (board[4]==board[8]) && board[0] != " ")
 	{
	 winner=true;
	 if(board[0]=="X" && board[4]=="X" && board[8]=="X")
	 {
	 	score1=true;
	 }
	 else if(board[0]=="O" && board[4]=="O" && board[8]=="O")
	 {
	 	score2=true;
	 }
	}
	else if((board[2]==board[4]) && (board[4]==board[6]) && board[2] != " ")
 	{
	 winner=true;
	 if(board[2]=="X" && board[4]=="X" && board[6]=="X")
	 {
	 	score1=true;
	 }
	 else if(board[2]=="O" && board[4]=="O" && board[6]=="O")
	 {
	 	score2=true;
	 }
	}
	
	

	return winner;
 }
 
 bool filled_up()
 {
 	bool filled = true;
 	
 	for(int i = 0; i<9; i++)
 	{
 		if(board[i]==" ")
 		{
 			filled = false;
		 }
	 }
	 return filled;
 }
 
 
 void draw()
 {
 	cout << "     |     |      \n";
 	cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] <<"\n";
 	cout << "_____|_____|_____ \n";
 	cout << "     |     |      \n";
 	cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] <<"\n";
 	cout << "_____|_____|_____ \n";
 	cout << "     |     |      \n";
 	cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] <<"\n";
 	cout << "     |     |      \n";
 	cout << endl;
 	
 }
 
 
 
 void set_position()
 {
 	cout<<"player " << player << "'s (Enter: (1-9))";
 	while(!(cin>>position))
 	{
 		cout<< "please Enter a valid number between(1-9)"<<endl;
 		cin.clear();
 		cin.ignore();
	 }
	 
	while (board[position -1] != " ")
	{
	cout<<"oops, that position is already filled\ntry again\n";
	cout<<"player " << player << "'s turn (Enter 1-9):";
	cin>>position;
	cout<<"\n";
	
	 } 
 }
 
 
 
 
void update_board()
{
	if(player%2 ==1)
	{
		board[position -1]= "X";
	}
	else
	{
		board[position -1]= "O";
	}
}


void change_player(){
	if(player == 1){
		player++;
	}
	else{
		player--;
	}
}


void take_turn()
{
	while(!is_winner() && !filled_up())
	{
		//invoking the functions
		set_position();
		update_board();
		change_player();
		draw();
	}
}


void end_game()
{
	if(is_winner())
	{
		cout << "there is a winner!"<<endl;
		if(score1)
		{
			cout << player1 <<" won\n";
			fstream write("scoreboard.txt",ios::app);
			write << player1 << " won " << player2 <<".\n";
		}
		else if(score2)
		{
			cout << player2 <<" won\n";
			fstream write("scoreboard.txt",ios::app);
			write << player2 << " won " << player1 <<".\n";
			write.close();
		}         
	}
	
	else if(filled_up())
	{                
		cout <<"there is a tie!\n"<< endl;
		fstream write("scoreboard.txt",ios::app);
		cout << player1 << " and " << player2 << " tied.\n";
		write.close();
	}
	
}