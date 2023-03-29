#include <stdio.h>
#include <conio.h>
/******************************************************macros***********************************************************************************************/

typedef unsigned char   uint8_t;

/*****************************************************global variables**************************************************************************************/

uint8_t configArray[2];
uint8_t position;
uint8_t game_State=2;
uint8_t board[9]= {'1','2','3','4','5','6','7','8','9'};

/***************************************************prototypes*********************************************************************************************/
void drawBoard(uint8_t*board);

void updateBoard (uint8_t *board, uint8_t position, uint8_t value);

uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t * symbol);

void setPlayerConfig(uint8_t *configArray);

void loadAndUpdate(uint8_t playerNumber);

 void getGameState(uint8_t *board, uint8_t *gameState);

 /***************************************************main******************************************************************************************************/

void main(void)
{
uint8_t index_i;

    setPlayerConfig(configArray);
    printf("\nPlayer 1 Symbol is :%c \n ",configArray[0]);
    printf("\nPlayer 2 Symbol is :%c \n ",configArray[1]);
    drawBoard(board);
    for ( index_i=1; index_i<=9; index_i++)
    {
        if (index_i%2!=0)
        {
            printf("Player one turn\n");
            loadAndUpdate(1);
            updateBoard(board,position,configArray[0]);


                getGameState(board,&game_State);
                drawBoard(board);
        }
        else
        {
            printf("Player two turn\n");
            loadAndUpdate(2);
            updateBoard(board,position,configArray[1]);

                getGameState(board,&game_State);
                drawBoard(board);
        }

        if (game_State!=2)
        {
            break;
        }

    }

    if (game_State==0)
    {
        if (index_i%2!=0)
        {
            printf ("CONGRAAATS PLAYER ONE, YOU'RE THE WINEER!!!!!! ");
        }
        else
        {
            printf ("CONGRAAATS PLAYER TWO, YOU'RE THE WINEER!!!!!! ");
        }
    }
    else
    {
        printf ("DRAW,no winner no losers  ");
    }
}

/*********************************************************************************************************************************************************/

void drawBoard(uint8_t *board)
{
    system("cls");
    uint8_t i=0;
    for (i=0; i<9; i++)
    {

        if (i%3==0)
        {
            printf("\n");
        }

 printf("%c   ",board[i]);
    }
    printf("\n");
}
void updateBoard (uint8_t *board, uint8_t position, uint8_t value)
{
        board[position-1]=value;
}
uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t * symbol)
{
    if (playerNumber==1)
    {
        if (symbol[playerNumber-1]=='X'||symbol[playerNumber-1]=='O')
        {
            return 0;
        }
        else
        {
            printf("OOPS wrong symbol, please choose either X or O\n");
            printf("\n");
            return 1;
        }

    }
    else
    {
        if (symbol[playerNumber-1]!=symbol[playerNumber-2])
        {
            if (symbol[playerNumber-1]=='X'||symbol[playerNumber-1]=='O')
            {
                return 0;
            }
            else
            {
                printf("OOPS wrong symbol, please choose either X or O\n");
                printf("\n");
                return 1;
            }

        }
        else
        {
            printf("OOPS duplicated symbol,please choose a different one\n");
            printf("\n");
            return 1;
        }


    }

}
/************************************************************************************************************************************************************/
void setPlayerConfig(uint8_t *configArray)
{
    uint8_t return_status=1;
    while (return_status)
    {
        printf("player 1 please choose a symbol either X or O\n");
        scanf(" %c",&configArray[0]);
        return_status=getPlayerSymbol(1,configArray);
    }

    return_status=1;
    while (return_status)
    {
        printf("player 2 please choose a symbol either X or O\n");
        scanf(" %c",&configArray[1]);
        return_status=getPlayerSymbol(2,configArray);
    }
}

/************************************************************************************************************************************************************/
void loadAndUpdate(uint8_t playerNumber)
{
    printf("please choose a position\n");
    scanf("%d",&position);
}

/************************************************************************************************************************************************************/

void getGameState(uint8_t *board, uint8_t *gameState)
{
    if (board[0]==board[1]&&board[1]==board[2])
    {
        *gameState=0;
    }
     else if (board[3]==board[4]&&board[4]==board[5])
    {
        *gameState=0;
    }
    else if (board[6]==board[7]&&board[7]==board[8])
    {
        *gameState=0;
    }

    else if (board[0]==board[3]&&board[3]==board[6])
    {
        *gameState=0;
    }
    else if (board[1]==board[4]&&board[4]==board[7])
    {
        *gameState=0;
    }
     else if (board[2]==board[5]&&board[5]==board[8])
    {
        *gameState=0;
    }
    else if (board[0]==board[4]&&board[4]==board[8])
    {
        *gameState=0;
    }

    else if (board[2]==board[4]&&board[4]==board[6])
    {
        *gameState=0;
    }
     else if(board[0] != '1' && board[1] != '2' && board[2] != '3' &&
            board[3] != '4' && board[4] != '5' && board[5] != '6' &&
            board[6] != '7' && board[7] != '8' && board[8] != '9')
            {
                *gameState = 1;
            }
    else
    {
        *gameState=2;
    }
}
/**********************************************************************************************************************************************************/
