#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <vector>


int main(void)
{
    srand(time(0));
    int width = 20;
    int height = 15;
    int x = 10;
    int y= 7;
    int fruitX = rand() % (width - 1);
    if (fruitX == 0)
    {
        fruitX = 1;
    }
    int fruitY = rand() % (height - 1);
    if (fruitY == 0)
    {
        fruitY = 1;
    }
    int score = 0;
    bool gameOver = false;
    char dir = 'd';
    std::vector<int> tailX(100);
    std::vector<int> tailY(100);
    int tailLength = 0;
    system("cls");
    while (!gameOver)
    {
        std::cout << "\033[H";
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                if ((i == 0) || (i == height - 1) || (j == 0) || (j == width - 1))
                {
                    std::cout << "#";
                }
                else if ((i == y && j == x))
                {
                    std::cout << "O";
                }
                else if (i == fruitY && j == fruitX)
                {
                    std::cout << "*";
                }
                else
                {
                    bool printTail = false;
                    for (int k = tailLength - 1; k >= 0; --k)
                    {
                        if (tailX[k] == j && tailY[k] == i)
                        {
                            std::cout << "o";
                            printTail = true;
                            break;
                        }
                    }
                    if (printTail != true)
                    {
                        std::cout << " ";
                }
            }
        }
            std::cout << '\n';
        }
        std::cout << "Score: " << score << '\n';
        if (_kbhit())
        {
            char key = _getch();
            if (key == 'w' && dir != 's')
            dir = 'w';
            else if (key == 'a' && dir != 'd')
            dir = 'a';
            else if (key == 's' && dir != 'w')
            dir = 's';
            else if (key == 'd' && dir != 'a')
            dir = 'd';
        }
        for (int i = tailLength - 1; i > 0; --i)
        {
            tailX[i] = tailX[i - 1];
            tailY[i] = tailY[i - 1];
        }
        tailX[0] = x;
        tailY[0] = y;
        if (dir == 'w')
        y--;
        if (dir == 'a')
        x--;
        if (dir == 's')
        y++;
        if (dir == 'd')
        x++;
        for (int k = tailLength - 1; k >= 0; --k)
        {
            if (tailX[k] == x && tailY[k] == y)
            {
                gameOver = true;
                std::cout << "CRASHED!!";
            }
        }
        if (x == 0)
        {
            x = width - 2;
        }
        else if (x == width - 1)
        {
            x = 1;
        }
        if (y == 0)
        {
            y = height - 2;
        }
        else if (y == height - 1)
        {
            y = 1;
        }
        if (x == fruitX && y == fruitY)
        {
            score += 10;
            tailLength += 1;
            fruitX = rand() % (width - 1);
            if (fruitX == 0)
            {
                fruitX = 1;
            }
            fruitY = rand() % (height - 1);
            if (fruitY == 0)
            {
                fruitY = 1;
            }
        }
        Sleep(150);
    }
}