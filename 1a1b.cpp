#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <stdlib.h>
using namespace std;
class num1a1b
{
	public:
	void start();       //starting game
	bool game_restart();//restarting game
	void get_name();    //get user's name
	void player_clear();//clearing user's info
	void startingPage();//starting background

	private:
	struct player //player's info
	{
		string name;
		string userNum;
		vector<int> a;
		vector<int> b;
		vector<string> num;	
		int round = 0;
	};

	void update_1a1b(string guess, player &p, player opp); //update player's guess record
	void print_1a1b(player p1, player p2);				   //print player's guess history	
	void user_guess(player &p, player opp);                //get player's guess
	string  get_num(player p);							   //get player's answer
	bool exists(char c, player p);                         //check if the player's guess contains
	                                                       //repeating number
	bool num_check(string num);                            //check if the player's guess is a right format
	player p1{"Player 1", "", {}, {}, {}};
	player p2{"Player 2", "", {}, {}, {}};


	bool game_end = false; //bool for checking if the game is finished
	string winner;
	
};
void print_space(int n);
void print_gameName();



int main()
{
	num1a1b game;
	game.startingPage();	
	
	do{
	game.start();
	}while(game.game_restart());	
} //end of "main"



void num1a1b::startingPage()
{
	system("clear");

	//print 1a1b on the screen
	print_gameName();
	cout << "                          press enter any key to start                               \n";

	string s;
	getline(cin , s);
	system("clear");
	
	print_gameName();	

} //end of "startingPage"



void num1a1b::start()
{
	//get user name
	get_name();
		
	int turn = 1;
	//clear player's record
	player_clear();
	print_gameName();	

	//save user1's answer
	p1.userNum = get_num(p1);
	
	print_gameName();	

	//save user2's answer
	p2.userNum = get_num(p2);
		
	system("clear");

	//get users' guess, taking turns
	while(!game_end)
	{
		//print users' guess record
		print_1a1b(p1, p2);

		switch(turn)
		{
			case 1:
			user_guess(p1, p2);
			turn = 2;
			break;

			case 2:
			user_guess(p2, p1);
			turn = 1;
			break;
		}
		
		system("clear");
	}
} //end of "start"



string num1a1b::get_num(player p)
{
	string num;
	do{
	cout << p.name << " Enter your 4 digit number" << endl;
	cin >> num;
	} while(!num_check(num));

	return num;
} //end of "get_num"



void num1a1b::user_guess(player &p, player opp)
{
	string num;
	do{
		cout << p.name << " Guess "<< opp.name<< "'s 4 digit number: ";
		cin >> num; } while(!num_check(num));

	cout << "update" <<endl;
	update_1a1b(num, p, opp);
	p.round++;
} //end of "user_guess"



void num1a1b::update_1a1b(string guess, player &p, player opp)
{
	
	cout << p.a.size() << endl;
	p.a.push_back(0);
	p.b.push_back(0);
	p.num.push_back(guess);

	for(int i = 0; i < 4 ; ++i)
	{
		if(guess[i] == opp.userNum[i] )
		{
			p.a[p.round]++;
		}
		else if(exists(guess[i], opp))
		{
			p.b[p.round]++;
		}
	}

	if(p.a.back() == 4)
	{
		game_end = true;
		winner = p.name;
	}
} //end of "update_1a1b"



bool num1a1b::exists(char c, player p)
{
	for(char i : p.userNum)
	{
		if(c == i)
		return true;
	}

	return false;
} //end of "exists"



bool num1a1b::num_check(string num)
{
	if(num.size() != 4)
	{
		cout << "\nEnter number size of 4\n\n";
		return false;
	}
	for(int i = 0 ; i < 3 ; ++i)
	{
	//	cout << "i " << i << endl;
		for(int j = i + 1; j < 4; ++ j)
		{
	//		cout << "j" << j << endl;
			if(num[i] == num[j])
			{
				cout << "\nEnter numbers that doesn't repeat\n\n";
				return false;
			}
		}
	}
	for(int i = 0 ; i < 4 ; ++i)
	{
			if(!(isdigit(num[i])) )
		{
			cout << "\nEnter only numbers\n\n";
			return false;
		}
	}

	cout << "return" << endl;

	return true;
} //end of "num_check"



void num1a1b::print_1a1b(player p1, player p2)
{
	cout << "	RECORD\n\n";

	for(int i = 0; i < static_cast<int> (p1.a.size()); ++i)
	{
		cout << p1.name << " " << p1.num[i] <<  "  " << p1.a[i] <<"a " << p1.b[i] << "b ";

		if(i < static_cast<int> (p2.a.size()))
		{
		cout << "            |" << p2.name << " " << p2.num[i] 
			<<  "  " << p2.a[i] <<"a " << p2.b[i] << "b     \n";	
		}

	}
	cout << endl;

	print_space(15 - p1.a.size());

} //end of "print_1a1b"



bool num1a1b::game_restart()
{
	char c;
	print_gameName();
	print_space(7);
	cout << "The numer was " << p1.name << ": " << p1.userNum << "  " << p2.name << ": " << p2.userNum;
	cout << "\nwinner is " << winner <<"\n\nDo you want to play again? (y/n):";
	
	cin >> c;
	

	if(toupper(c) == 'Y')
	{
		game_end = false;
		return true;
	}
	 return false;
} //end of "game_restart"



void num1a1b::get_name()
{
	
	string name;
	cout << "Player 1 Enter your name: ";
	cin >> name;
	p1.name = name;

	cout << "\nPlayer 2 Enter your name: ";
	cin >> name;
	p2.name = name;

} //end of "get_name"



void num1a1b::player_clear()
{
	p1.a.clear();
	p1.b.clear();
	p1.num.clear();
	p2.a.clear();
	p2.b.clear();
	p2.num.clear();
	p1.round = p2.round = 0;
	p1.userNum = "";
	p2.userNum = "";
} //end of "player_clear"



void print_space(int n)
{
	for(int i = 0; i < n; ++i)
	{
		cout << endl;
	}
} //end of "print_space"



void print_gameName()
{	system("clear");
	cout << endl << endl << endl;
	cout << "                 ____    "<<"     _________    "<<"       ____     "<<"   ___             \n";
	cout << "                /    |   "<<"    /         \\   "<<"      /    |    "<<"   |  |                \n";
	cout << "               / /|  |   "<<"   /    ___    \\  "<<"     / /|  |    "<<"   |  |                \n";
	cout << "              / / |  |   "<<"  /    /   \\    \\ "<<"    / / |  |    "<<"   |  |                \n";
	cout << "             /_/  |  |   "<<" /    /     \\    |"<<"   /_/  |  |    "<<"   |  |                \n";
	cout << "                  |  |   "<<"|    /       \\   |"<<"        |  |    "<<"   |  |   _____        \n";
	cout << "                  |  |   "<<"|   |        |   |"<<"        |  |    "<<"   |  |  /     \\       \n";
	cout << "                  |  |   "<<"|   |        |   |"<<"        |  |    "<<"   |  | /  ___  \\      \n";
	cout << "                  |  |   "<<"|   |        |   |"<<"        |  |    "<<"   |  |/  /   \\  \\     \n";
	cout << "                  |  |   "<<"|    \\      /    |"<<"        |  |    "<<"   |     |     |  |    \n";
	cout << "                  |  |   "<<" \\    \\    /     |"<<"        |  |    "<<"   |     |     |  |    \n";
	cout << "               ___|  |___"<<"  \\    \\__/  /|  |"<<"     ___|  |___ "<<"   |     |     |  |    \n";
	cout << "              |         |"<<"   \\        / |  |"<<"     |         |"<<"   |  |\\  \\___/  /     \n";
	cout << "              |_________|"<<"    \\______/  |__|"<<"     |_________|"<<"   |__| \\_______/      \n";
	cout << "                                                                                     \n";
	cout << "                                                                                     \n";
	cout << "                                                                           by Jacobee       \n";

 		cout << endl;  

 	print_space(2);      
} //end of "print_gameName"

