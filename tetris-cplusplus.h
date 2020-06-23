#ifndef __TETRIS_C_PLUS_PLUS__
#define __TETRIS_C_PLUS_PLUS__

#include <iostream>        // cout, printf(), scanf(), ...
#include <stdlib.h>        // rand()
#include <time.h>        // time() 
#include <conio.h>        // _getch()
#include <windows.h>    // wincon.h, ...

#define true 1
#define false 0
#define bool int

#define BOARD_WIDTH 10        // 게임 영역의 가로(열) >= 10 : ━
#define BOARD_HEIGHT 20        // 게임 영역의 세로(행) >= 20 : ┃

#define BOARD_X 4 //보드 열 x좌표
#define BOARD_Y 2 //보드 행 y좌표

#define DELAY 100//지연
using namespace std;

class TetrisData{
public:
	// 키보드의 방향키와 스페이스에 대한 열거형 지정
	// _getch()가 반환하는 값이 
	enum ControlKeys
	{
		UP = 72,
		DOWN = 80,
		LEFT = 75,
		RIGHT = 77,
		SPACE = 32
	};
	static int score; //게임점수
	static int level; //게임레벨
	static int speed;
	static int board[BOARD_HEIGHT + 1][BOARD_WIDTH + 2];
	// 테트리스 블록 : 총 7개의 블록 생성
	static int blocks[28][4][4]; 
};
class Cursor {

protected:
	 //[1] 커서 숨기기 : true(보이기), false(숨기기)
	void CursorVisible(bool blnCursorVisible) ;   // Console.CursorVisible = false;
	//[2] 현재 콘솔 내의 커서 위치를 설정
	void SetCursorPosition(int cursorLeft, int cursorTop);    // Console.SetCursorPosition(posX, posY); 
	//[3] 커서의 현재 위치 정보 얻기
	COORD GetCursorPosition(void);
};

class Init : public Cursor
{
public:
	//[4] 시작 화면 및 콘솔 초기화
	void ConsoleInit();
protected:
	//[9] 블록 보드판에서 1인식
	void BoardInit(int n, int move1, int move2);
};

class Draw : public Cursor
{
public:
	//[5] 게임판 그리기 
	void DrawField(void);
};

class Show : public Cursor
{
public:
	//[6] 점수판 출력
	void ShowPoint(void);
};

class Start :  public Init
{
private:
	bool CanPositionedAt(int rotation, int move1, int move2);
	//[8] 현재 위치에 블록 출력
	void WriteBlock(int rotation);
	//[6] 점수판 출력
	void ShowPoint(void);
	//[10] /*배열,블록 옮김*/
	void Stepper(int column);
	//[11] 레벨 스코어 계산
	void CountScore(void);
	//[12] 
	/* 1~10까지 행의 열 전체가 1로되면 블록사라짐. 사라지면 Stepper함수 실행 */
	void RemoveLine(void);
	//[13] 현재 블록 클리어    
	void ClearBlock(int rotation, int move1, int move2);
public:
	//[14] 게임 시작
	void StartGame(void);
};

class End : public Cursor
{
public:
	//[15] 게임 종료 화면
	void EndGame();
};

#endif
