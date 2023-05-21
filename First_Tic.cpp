// C++ tic tac toe program
// made my Eli Murdock
// inputs are: names(Player1,Player2), digits(for mark location)
// possible results: Player1 wins, Player2 wins, Tie

#include <iostream>
using namespace std;

//defines variables
//array of the 9 values needed for the game
char GameBoard[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
// row and column are index values to reference the "GameBoard" array
int row;
int column;
char token = 'X';
bool tie = false;
string n1 = " ";
string n2 = " ";

void functionOne(){

    cout<< "\n   |   |   \n";
    cout<< " "<<GameBoard[0][0]<<" | "<<GameBoard[0][1]<<" | "<<GameBoard[0][2]<<" \n";
    cout<< "___|___|___\n";
    cout<< "   |   |   \n";
    cout<< " "<<GameBoard[1][0]<<" | "<<GameBoard[1][1]<<" | "<<GameBoard[1][2]<<" \n";
    cout<< "___|___|___\n";
    cout<< "   |   |   \n";
    cout<< " "<<GameBoard[2][0]<<" | "<<GameBoard[2][1]<<" | "<<GameBoard[2][2]<<" \n";
    cout<< "   |   |   \n";
}

void functionTwo()
{
    int digit;

    if (token == 'X')
    {
        cout<<n1<<", please enter a number: ";
        cin>>digit;
    }

    if (token == 'O')
    {
        cout<<n2<<", please enter a number: ";
        cin>>digit;
    }

    // user enters the location where the mark will be placed
    if (digit == 1)
    {row = 0; column = 0;}
    if (digit == 2)
    {row = 0; column = 1;}
    if (digit == 3)
    {row = 0; column = 2;}
    if (digit == 4)
    {row = 1; column = 0;}
    if (digit == 5)
    {row = 1; column = 1;}
    if (digit == 6)
    {row = 1; column = 2;}
    if (digit == 7)
    {row = 2; column = 0;}
    if (digit == 8)
    {row = 2; column = 1;}
    if (digit == 9)
    {row = 2; column = 2;}

    //prints invlaid if character entered is not a number 1-9
    else if (digit<1 ||digit>9)
    {
        cout<<"Invalid"<<endl;
    }

    if (token == 'X' && GameBoard[row][column] !='X' && GameBoard[row][column] !='O')
    {
        GameBoard[row][column] = 'X';
        token = 'O';
    }

    else if (token == 'O' && GameBoard[row][column] !='X' && GameBoard[row][column] !='O')
    {
        GameBoard[row][column] = 'O';
        token = 'X';
    }

    else
    {
        cout<<"This is not an empty space!"<<endl;
        functionTwo();
    }
}

bool functionThree()
{
    //checks whether either player has 3 in a row
    for (int i=0;i<3;i++)
    {
        if(GameBoard[i][0] == GameBoard[i][1] && GameBoard[i][1] == GameBoard[i][2] ||
            GameBoard[0][i] == GameBoard[1][i] && GameBoard[1][i] == GameBoard[2][i])
        {
            return true;
        }
        if (GameBoard[0][0] == GameBoard [1][1] && GameBoard[1][1] == GameBoard[2][2] ||
            GameBoard[0][2] == GameBoard [1][1] && GameBoard[1][1] == GameBoard[2][0])
        {
            return true;
        }
    }

    //checks whether all spaces on the board are full
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if(GameBoard[i][j] != 'X' && GameBoard[i][j] != 'O')
            {
                return false;
            }
        }
    }

    tie = true;
    return true;

}

int main()
{
    cout<<"\nEnter the name of the first player: ";
    getline(cin, n1);
    cout<<"Enter the name of the second player: ";
    getline(cin, n2);


    while (functionThree() == false)
    {
        functionOne();
        functionTwo();
        functionThree();
    }
    if (token == 'X' && tie == false)
    {
        functionOne();
        cout<<"\n"<<n2<<" wins!\n"<<endl;
    }
    else if (token == 'O' && tie == false)
    {
        functionOne();
        cout<<"\n"<<n1<<" wins!\n"<<endl;
    }
    else
    {
        functionOne();
        cout<<"\nIt's a draw.\n"<<endl;
    }
} 
    


