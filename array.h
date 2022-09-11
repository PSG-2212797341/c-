// 三子棋头文件：
// #define ROW 3
// #define COL 3

// void InitBoard(char board[ROW][COL],int rwo,int col);
// void DisplayBoard(char board[ROW][COL],int row,int col);    
// void PlayerMove(char board[ROW][COL],int row,int col);
// void ComputerMove(char board[ROW][COL],int row,int col);
// char IsWin(char board[ROW][COL],int row,int col);
// int IsFair(char board[ROW][COL],int row,int col);

// 扫雷头文件：
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10

void InitBoard(char board[ROWS][COLS],int rows,int cols,char set);              //初始化。
void DisplayBoard(char board[ROWS][COLS],int row,int col);                      //打印
void SetMine(char board[ROWS][COLS],int row,int col);                           //放雷。
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);     //扫雷。