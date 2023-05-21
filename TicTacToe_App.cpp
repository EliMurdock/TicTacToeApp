//importing library for building gui
#include <windows.h> 
#include <iostream>

//using standard library
using namespace std;

//defining gameboard, the alphabet is a place holder
char GameBoard[]={'a','b','c','d','e','f','g','h','i'};
char token = 'X';
char winner = 'L';

//defining variables to be used later for each of the button boxes
#define tic1 1
#define tic2 2
#define tic3 3

#define tic4 4
#define tic5 5
#define tic6 6

#define tic7 7
#define tic8 8
#define tic9 9

//defining sections of the HWND variable to be used later for the button boxes as well
HWND hwnd, t1,t2,t3,t4,t5,t6,t7,t8,t9;

// framework for updating the program
LRESULT CALLBACK WindowBuilder(HWND,UINT,WPARAM,LPARAM);

// The basic starting point for creating the window, calling the window function
int WINAPI WinMain(HINSTANCE hInst , HINSTANCE hPrevInst , LPSTR args, int ncmdshow)
{
    //what the window and cursor will look like
    WNDCLASSW wc = {0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW ;
    wc.hCursor = LoadCursor(NULL,IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"myWindowClass";
    wc.lpfnWndProc = WindowBuilder;

    //makes sure classes load
    if(!RegisterClassW(&wc))
        return -1;
    
    //creates the window where the board will be placed
    CreateWindowW(L"myWindowClass",L"Tic-Tac-Toe",WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100,100, 520,540, NULL,NULL,NULL,NULL);

    //def message structure
    MSG msg = {0};

    //Message loop
    while( GetMessage(&msg,NULL,0,0) )
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

// update script from before
LRESULT CALLBACK WindowBuilder(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    switch ( msg)
    {
        //exits the program
        case WM_DESTROY:
            PostQuitMessage(643);
            break;
        default:
            return DefWindowProcW(hWnd,msg,wp,lp);

        //creates the base layout for the game, with 9 buttons 100x100 in size
        case WM_CREATE:
        {
            t1 = CreateWindowW(L"Button",L"",WS_VISIBLE | WS_CHILD, 100,100, 100,100, hWnd,(HMENU) tic1,NULL,NULL);
            t2 = CreateWindowW(L"Button",L"",WS_VISIBLE | WS_CHILD, 200,100, 100,100, hWnd,(HMENU) tic2,NULL,NULL);
            t3 = CreateWindowW(L"Button",L"",WS_VISIBLE | WS_CHILD, 300,100, 100,100, hWnd,(HMENU) tic3,NULL,NULL);
            t4 = CreateWindowW(L"Button",L"",WS_VISIBLE | WS_CHILD, 100,200, 100,100, hWnd,(HMENU) tic4,NULL,NULL);
            t5 = CreateWindowW(L"Button",L"",WS_VISIBLE | WS_CHILD, 200,200, 100,100, hWnd,(HMENU) tic5,NULL,NULL);
            t6 = CreateWindowW(L"Button",L"",WS_VISIBLE | WS_CHILD, 300,200, 100,100, hWnd,(HMENU) tic6,NULL,NULL);
            t7 = CreateWindowW(L"Button",L"",WS_VISIBLE | WS_CHILD, 100,300, 100,100, hWnd,(HMENU) tic7,NULL,NULL);
            t8 = CreateWindowW(L"Button",L"",WS_VISIBLE | WS_CHILD, 200,300, 100,100, hWnd,(HMENU) tic8,NULL,NULL);
            t9 = CreateWindowW(L"Button",L"",WS_VISIBLE | WS_CHILD, 300,300, 100,100, hWnd,(HMENU) tic9,NULL,NULL);

            break;
        }

        //seness when buttons are pressed
        case WM_COMMAND:
        {
            //this side activates on the first players turn only
            if (token == 'X')
            {
                /*Every block of code in this section is similar: if it is the first player's turn, it cheacks to see which
                of the nine buttons was pressed, and activates that block of code. If that button has a value already, it
                does not activate and that player plays again. If the button has no value, then the button is deleted, and a 
                new button is created with the new title, and a set value equal to the player's token*/
                if (LOWORD(wp) == tic1 && GameBoard[0] != 'X' && GameBoard[0] != '0')
                {
                    GameBoard[0] = 'X';
                    token = '0';
                    DestroyWindow(t1);
                    t1 = CreateWindowW(L"Button",L"X",WS_VISIBLE | WS_CHILD, 100,100, 100,100, hWnd,(HMENU) tic1,NULL,NULL);
                }
                else if (LOWORD(wp) == tic2 && GameBoard[1] != 'X' && GameBoard[1] != '0')
                {
                    GameBoard[1] = 'X';
                    token = '0';
                    DestroyWindow(t2);
                    t2 = CreateWindowW(L"Button",L"X",WS_VISIBLE | WS_CHILD, 200,100, 100,100, hWnd,(HMENU) tic2,NULL,NULL);
                }
                else if (LOWORD(wp) == tic3 && GameBoard[2] != 'X' && GameBoard[2] != '0')
                {
                    GameBoard[2] = 'X';
                    token = '0';
                    DestroyWindow(t3);
                    t3 = CreateWindowW(L"Button",L"X",WS_VISIBLE | WS_CHILD, 300,100, 100,100, hWnd,(HMENU) tic3,NULL,NULL);
                }
                else if (LOWORD(wp) == tic4 && GameBoard[3] != 'X' && GameBoard[3] != '0')
                {
                    GameBoard[3] = 'X';
                    token = '0';
                    DestroyWindow(t4);
                    t4 = CreateWindowW(L"Button",L"X",WS_VISIBLE | WS_CHILD, 100,200, 100,100, hWnd,(HMENU) tic4,NULL,NULL);
                }
                else if (LOWORD(wp) == tic5 && GameBoard[4] != 'X' && GameBoard[4] != '0')
                {
                    GameBoard[4] = 'X';
                    token = '0';
                    DestroyWindow(t5);
                    t5 = CreateWindowW(L"Button",L"X",WS_VISIBLE | WS_CHILD, 200,200, 100,100, hWnd,(HMENU) tic5,NULL,NULL);
                }
                else if (LOWORD(wp) == tic6 && GameBoard[5] != 'X' && GameBoard[5] != '0')
                {
                    GameBoard[5] = 'X';
                    token = '0';
                    DestroyWindow(t6);
                    t6 = CreateWindowW(L"Button",L"X",WS_VISIBLE | WS_CHILD, 300,200, 100,100, hWnd,(HMENU) tic6,NULL,NULL);
                }
                else if (LOWORD(wp) == tic7 && GameBoard[6] != 'X' && GameBoard[6] != '0')
                {
                    GameBoard[6] = 'X';
                    token = '0';
                    DestroyWindow(t7);
                    t7 = CreateWindowW(L"Button",L"X",WS_VISIBLE | WS_CHILD, 100,300, 100,100, hWnd,(HMENU) tic7,NULL,NULL);
                }
                else if (LOWORD(wp) == tic8 && GameBoard[7] != 'X' && GameBoard[7] != '0')
                {
                    GameBoard[7] = 'X';
                    token = '0';
                    DestroyWindow(t8);
                    t8 = CreateWindowW(L"Button",L"X",WS_VISIBLE | WS_CHILD, 200,300, 100,100, hWnd,(HMENU) tic8,NULL,NULL);
                }
                else if (LOWORD(wp) == tic9 && GameBoard[8] != 'X' && GameBoard[8] != '0')
                {
                    GameBoard[8] = 'X';
                    token = '0';
                    DestroyWindow(t9);
                    t9 = CreateWindowW(L"Button",L"X",WS_VISIBLE | WS_CHILD, 300,300, 100,100, hWnd,(HMENU) tic9,NULL,NULL);
                }
                
            }

            else // if token = '0' for the second player's turn, see explanation above for more details
            {
                if (LOWORD(wp) == tic1 && GameBoard[0] != 'X' && GameBoard[0] != '0')
                {
                    GameBoard[0] = '0';
                    token = 'X';
                    DestroyWindow(t1);
                    t1 = CreateWindowW(L"Button",L"0",WS_VISIBLE | WS_CHILD, 100,100, 100,100, hWnd,(HMENU) tic1,NULL,NULL);
                }
                else if (LOWORD(wp) == tic2 && GameBoard[1] != 'X' && GameBoard[1] != '0')
                {
                    GameBoard[1] = '0';
                    token = 'X';
                    DestroyWindow(t2);
                    t2 = CreateWindowW(L"Button",L"0",WS_VISIBLE | WS_CHILD, 200,100, 100,100, hWnd,(HMENU) tic2,NULL,NULL);
                }
                else if (LOWORD(wp) == tic3 && GameBoard[2] != 'X' && GameBoard[2] != '0')
                {
                    GameBoard[2] = '0';
                    token = 'X';
                    DestroyWindow(t3);
                    t3 = CreateWindowW(L"Button",L"0",WS_VISIBLE | WS_CHILD, 300,100, 100,100, hWnd,(HMENU) tic3,NULL,NULL);
                }
                else if (LOWORD(wp) == tic4 && GameBoard[3] != 'X' && GameBoard[3] != '0')
                {
                    GameBoard[3] = '0';
                    token = 'X';
                    DestroyWindow(t4);
                    t4 = CreateWindowW(L"Button",L"0",WS_VISIBLE | WS_CHILD, 100,200, 100,100, hWnd,(HMENU) tic4,NULL,NULL);
                }
                else if (LOWORD(wp) == tic5 && GameBoard[4] != 'X' && GameBoard[4] != '0')
                {
                    GameBoard[4] = '0';
                    token = 'X';
                    DestroyWindow(t5);
                    t5 = CreateWindowW(L"Button",L"0",WS_VISIBLE | WS_CHILD, 200,200, 100,100, hWnd,(HMENU) tic5,NULL,NULL);
                }
                else if (LOWORD(wp) == tic6 && GameBoard[5] != 'X' && GameBoard[5] != '0')
                {
                    GameBoard[5] = '0';
                    token = 'X';
                    DestroyWindow(t6);
                    t6 = CreateWindowW(L"Button",L"0",WS_VISIBLE | WS_CHILD, 300,200, 100,100, hWnd,(HMENU) tic6,NULL,NULL);
                }
                else if (LOWORD(wp) == tic7 && GameBoard[6] != 'X' && GameBoard[6] != '0')
                {
                    GameBoard[6] = '0';
                    token = 'X';
                    DestroyWindow(t7);
                    t7 = CreateWindowW(L"Button",L"0",WS_VISIBLE | WS_CHILD, 100,300, 100,100, hWnd,(HMENU) tic7,NULL,NULL);
                }
                else if (LOWORD(wp) == tic8 && GameBoard[7] != 'X' && GameBoard[7] != '0')
                {
                    GameBoard[7] = '0';
                    token = 'X';
                    DestroyWindow(t8);
                    t8 = CreateWindowW(L"Button",L"0",WS_VISIBLE | WS_CHILD, 200,300, 100,100, hWnd,(HMENU) tic8,NULL,NULL);
                }
                else if (LOWORD(wp) == tic9 && GameBoard[8] != 'X' && GameBoard[8] != '0')
                {
                    GameBoard[8] = '0';
                    token = 'X';
                    DestroyWindow(t9);
                    t9 = CreateWindowW(L"Button",L"0",WS_VISIBLE | WS_CHILD, 300,300, 100,100, hWnd,(HMENU) tic9,NULL,NULL);
                }

            }
            break;
        }
    }
// Find a Winner!
// win conditions
if (GameBoard[0] == GameBoard[1] && GameBoard[1] == GameBoard[2] ||
    GameBoard[3] == GameBoard[4] && GameBoard[4] == GameBoard[5] ||
    GameBoard[6] == GameBoard[7] && GameBoard[7] == GameBoard[8] ||
    GameBoard[0] == GameBoard[3] && GameBoard[3] == GameBoard[6] ||
    GameBoard[1] == GameBoard[4] && GameBoard[4] == GameBoard[7] ||
    GameBoard[2] == GameBoard[5] && GameBoard[5] == GameBoard[8] ||
    GameBoard[0] == GameBoard[4] && GameBoard[4] == GameBoard[8] ||
    GameBoard[2] == GameBoard[4] && GameBoard[4] == GameBoard[6])
{
    
    //If the 3-in-a-row is made by player 1, this activates. It makes sure there are no double winners
    if (token == '0' && winner == 'L')
    {
        //print message Player 1 wins 
        winner = 'W';
        CreateWindowW(L"Static",L"Player 1 Wins",WS_VISIBLE | WS_CHILD, 200,40, 100,50, hWnd,NULL,NULL,NULL);
    }
    //If the 3-in-a-row is made by player 1, this activates. It makes sure there are no double winners
    else if (token == 'X' && winner == 'L')
    {
        //print message Player 2 wins
        winner = 'W';
        CreateWindowW(L"Static",L"Player 2 Wins",WS_VISIBLE | WS_CHILD, 200,40, 100,50, hWnd,NULL,NULL,NULL);
    }
    return 0;
}

//checks for ties. If all tiles are filled the last 'if' statement activates
for (int i=0; i<9; i++)
{
    if (GameBoard[i] != 'X' && GameBoard[i] != '0')
    {
        break;
    }

    //prints out the tie message if there was a tie
    if (i == 8 && winner == 'L')
    {+
        CreateWindowW(L"Static",L"The Game is a Tie",WS_VISIBLE | WS_CHILD, 200,40, 150,50, hWnd,NULL,NULL,NULL);
    }
}
}
//The End

