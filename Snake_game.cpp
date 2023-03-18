#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace std;

// global variables
bool gameOver;
const int width = 40;
const int height = 20;
int x, y, frogX, frogY, score;
int tailX[100], tailY[100];
int nTail;
string name;
int style;

// creating a datatype to set the direction of motion
enum movement
{
    stop = 0,
    Left,
    Right,
    upward,
    downward

} direction;

// creating structure to store values for printing it on screen
struct HighestScore
{
    int bestscore;
    string bestplayer;

} data; //creating variable

// printing introduction
void structure()
{
    cout << "   Enter your name : ";
    cin >> name;
    cout << "\n\n";
    cout << "   Would style would you like to play ?" <<endl;;
    cout << "   Traditional [press 1]" <<endl;
    cout << "   Free [press2]\n" <<endl;
    cout << "   Command : ";
    cin >> style;
}

// putting the default highscore when the file is empty
void firstsave()
{
    fstream txtfile("Snake_game.txt");
    if (txtfile.peek() == EOF)  // checking if file is empty
    {
        if (txtfile.is_open())  
        {
            txtfile << 0 << endl;
            txtfile << "Gyan" << endl;
            data.bestscore = 0;  // updating struct members
            data.bestplayer = "Gyan";
        }
        else
        {
            cout << "File can't be opened" << endl;
        }
    }
    else
    {
        txtfile >> data.bestscore;
        txtfile >> data.bestplayer;
    }
    txtfile.close();
}

// initiating the global variables
void start()
{
    gameOver = false;
    direction = stop;
    x = width / 2;
    y = height / 2;

    srand(time(0)); // generating a frog at a random position
    frogX = rand() % width;
    frogY = rand() % height;

    score = 0;
}

// hidind the cursor
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE); // storing the handle of std output stream
                                                  // in out variable
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo); // getting the cursor info and storing it in cursorinfo
    cursorInfo.bVisible = showFlag;         // set the cursor visibility according to
                                            // the value in showflag
    SetConsoleCursorInfo(out, &cursorInfo); // updating the cursor info in out
}

// building the interface of the game
void Build()
{
    // clearing the console and setting cursor position to top left
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});

    for (int i = 0; i < width + 2; i++) // the upper boundary
    {
        cout << "+";
    }
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {
                cout << "+"; // left boundary
            }
            if (i == y && j == x)
            {
                cout << "o"; // snake head
            }
            else if (i == frogY && j == frogX)
            {
                cout << "*"; // frog
            }
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++) // snake tail
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                {
                    cout << " ";
                }
            }

            if (j == width - 1) // right boundary
            {
                cout << "+";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++) // lower boundary
    {
        cout << "+";
    }

    cout << "\n\n";
    cout << "               Score : " << score << "\n\n"; // displaying score
    cout << "       Highest score : " << data.bestscore << " [" << data.bestplayer << "]";
}

// taking the direction of motion as input
void Input()
{
    if (_kbhit()) // to check if any key is pressed
    {
        switch (_getch())
        {
        case 'a':
            direction = Left;
            break;
        case 'd':
            direction = Right;
            break;
        case 'w':
            direction = upward;
            break;
        case 's':
            direction = downward;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

// controlling the movement of the snake
void Logic()
{
    for (int i = nTail; i > 0; i--) // updating the position of each part
    {                               // of the snake's body
        tailX[i] = tailX[i - 1];
        tailY[i] = tailY[i - 1];
    }
    tailX[0] = x;
    tailY[0] = y;

    switch (direction) // changing the direction according to input
    {
    case Left:
        x--;
        break;
    case Right:
        x++;
        break;
    case upward:
        y--;
        break;
    case downward:
        y++;
        break;
    default:
        break;
    }
    
    if (style == 1) {
        if (x > width || x < 0 || y > height || y < 0) {   // to end game when snake comes
            gameOver = true;                               // in contact with the boundary
        }
    }

    else if (style == 2) {
        if (x >= width)                   // to continue from opposite side when
            x = 0;                        // snake collides with the boundary
        else if (x < 0)
            x = width - 1;
        if (y >= height)
            y = 0;
        else if (y < 0)
            y = height - 1;
    }

    for (int i = 0; i < nTail; i++)         // to check if snakes head (x,y) is not
        if (tailX[i] == x && tailY[i] == y) // coinciding with it's body
            gameOver = true;

    if (x == frogX && y == frogY)
    {
        score += 10;                       // updating score
        frogX = rand() % width;            // regenerating frog at a random position
        frogY = rand() % height;
        nTail++;                           // updating number of tails
    }
}

// updating the highest score in the snake_game.txt file
void savescore()
{
    string x;
    int i = 0;
    bool change = false;
    int oldscoreInt;

    fstream txtfile("Snake_game.txt");   // opening the file
    if (txtfile.is_open())
    {

        while (getline(txtfile, x))
        { // reading each line
            if (i % 2 == 0)
            {
                stringstream convert(x); // converting string to int for comparison
                convert >> oldscoreInt;

                if (oldscoreInt <= score)
                {
                                         // if score is higher than highest score
                    string scoreline = to_string(score) + "\n";
                    x = scoreline;
                    data.bestscore = score;
                    change = true;
                }
            }
            else
            {                           
                if (change == true)      // replacing name
                {
                    x = name + "\n";
                    data.bestplayer = name;
                }
            }
            i++;
        }
        txtfile.close();                 // closing the file

        // reopen the file in write mode and write the updated scores and names back to the file
        fstream txtfile2("Snake_game.txt", ios::out | ios::trunc);
        if (txtfile2.is_open())
        {
            txtfile2 << data.bestscore << endl;
            txtfile2 << data.bestplayer << endl;
            txtfile2.close();            // closing the file
        }
        else
        {
            cout << "Error: Unable to open file for writing." << endl;
        }
        txtfile2.close();
    }
    else
    {
        cout << "  File is empty..." << endl;
    }
}

int main()
{
    structure();
    firstsave();
    start();

    while (!gameOver)
    {
        ShowConsoleCursor(false);
        Build();
        Input();
        Logic();
        Sleep(100);
    }
    savescore();
    return 0;
}
