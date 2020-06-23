#include"tetris-cplusplus.h"

int TetrisData::score = 0; //게임점수
int TetrisData::level = 1; //게임레벨
int TetrisData::speed = 180;
int TetrisData::board[BOARD_HEIGHT + 1][BOARD_WIDTH + 2] = { 0, };
int TetrisData::blocks[28][4][4] =
{
	// ####
	{
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 1 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 1 },
		{ 0, 0, 0, 0 }
	},

	// ##
	// ##
	{
		{ 1, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},

	//  #
	// ###
	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 1, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 1, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 0 },
		{ 0, 1, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 1, 0, 0 }
	},

	//   #
	// ###
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 1, 0 },
		{ 1, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 1, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 1, 0 },
		{ 1, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 0, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 }
	},

	// #
	// ###
	{
		{ 0, 0, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 1, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},

	//  ##
	// ##
	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 1, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 1, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 0 }
	},

	// ##
	//  ##
	{
		{ 0, 0, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 1, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 1, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 }
	},
}; // end blocks[][][]

//[1] 커서 숨기기 : true(보이기), false(숨기기)
void Cursor::CursorVisible(bool blnCursorVisible)    // Console.CursorVisible = false;
{
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = blnCursorVisible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//[2] 현재 콘솔 내의 커서 위치를 설정
void Cursor::SetCursorPosition(int cursorLeft, int cursorTop)    // Console.SetCursorPosition(posX, posY); 
{
	int posX = cursorLeft;
	int posY = cursorTop;

	COORD pos = { posX, posY };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//[3] 커서의 현재 위치 정보 얻기
COORD Cursor::GetCursorPosition(void)
{
	COORD cursor;
	CONSOLE_SCREEN_BUFFER_INFO cursorInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursor.X = cursorInfo.dwCursorPosition.X;
	cursor.Y = cursorInfo.dwCursorPosition.Y;
	return cursor;
}
//[4] 시작 화면 및 콘솔 초기화
void Init::ConsoleInit()
{
	// 콘솔 초기화 및 시작 화면 구성 영역 
	cout<<"C++ 언어 콘솔 테트리스"<<endl<<endl;
	printf(""
		"===================================        \n"
		"조작법:                                        \n"
		"[→]     블록을 오른쪽으로 이동              \n"
		"[←]     블록을 왼쪽으로 이동                \n"
		"[↑]     블록을 왼쪽으로 회전하기            \n"
		"[↓]     블록을 아래로 1칸 내리기            \n"
		"[Space]  아래로 떨어뜨리기                    \n"
		"                                            \n"
		"아무키나 누르면 시작됩니다.                    \n"
		"===================================           \n");
	_getch();
	system("cls");            // Console.Clear();
	CursorVisible(false);    // 커서 숨기기
	SetCursorPosition(0, 0); //보드표시 시작위치 설정
}

//[9] 블록 보드판에서 1인식
void Init::BoardInit(int n, int move1, int move2)
{
	COORD pos = GetCursorPosition();

	int arrX = pos.X + move1;  //콘솔좌표 열
	int arrY = pos.Y + move2;  //콘솔좌표 행
	int x, y;

	/*커서위치정보->배열위치정보 변경*/
	arrX = arrX / 2 - 2; //콘솔좌표->배열 열 변환값
	arrY = arrY - 2;     //콘솔좌표->배열 행 변환값

					 //보드판에서 블록 이동시 1인식
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			if (TetrisData::blocks[n][y][x] == 1)
			{
				TetrisData::board[arrY + y][arrX + x] = 1;
			}
		}
	}
}
//[5] 게임판 그리기 
void Draw::DrawField(void)
{
	int x, y;

	//중앙 보드 라인
	for (x = 1; x <= BOARD_WIDTH + 1; x++)
	{
		TetrisData::board[BOARD_HEIGHT][x] = 1; //board 배열 중앙 1인식
		SetCursorPosition((BOARD_X)+x * 2, BOARD_Y + BOARD_HEIGHT);  //콘솔좌표
		cout<<"━";
	}
	//왼쪽 보드 라인
	for (y = 0; y < BOARD_HEIGHT + 1; y++)
	{
		TetrisData::board[y][0] = 1; //board 배열 왼쪽 1인식
		SetCursorPosition(BOARD_X, BOARD_Y + y);
		if (y == BOARD_HEIGHT)
			cout<<"┗";
		else
			cout<<"┃";
	}
	//오른쪽 보드 라인
	for (y = 0; y < BOARD_HEIGHT + 1; y++)
	{
		TetrisData::board[y][BOARD_WIDTH + 1] = 1; //board 배열 오른쪽 1인식
		SetCursorPosition(BOARD_X + (BOARD_WIDTH + 2) * 2, BOARD_Y + y);
		if (y == BOARD_HEIGHT)
			cout<<"┛";
		else
			cout<<"┃";
	}

	//모서리값 값 변경
	TetrisData::board[20][0] = 1;
	TetrisData::board[20][11] = 1;

	puts(" ");
}
//[6] 점수판 출력
void Show::ShowPoint(void)
{
	SetCursorPosition(40, 3);
	cout<<"C++ 언어 콘솔 테스리스";
	SetCursorPosition(40, 5);
	printf("레벨: %d\n", TetrisData::level);
	SetCursorPosition(40, 7);
	printf("점수: %d\n", TetrisData::score);
}
//[7] 사용 가능 위치 체크
// 특정 위치에 블록이 들어갈 수 있는지 아닌지를 체크
// 들어갈 수 있으면 true, 없으면 false 반환
bool Start::CanPositionedAt(int rotation, int move1, int move2)
{
	int x, y;
	int arrX, arrY; // 배열좌표저장
	COORD pos = GetCursorPosition();

	arrX = pos.X + move1;
	arrY = pos.Y + move2;

	arrX = (arrX / 2) - 2;
	arrY = arrY - BOARD_Y;

	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			if ((TetrisData::blocks[rotation][y][x] == 1) && TetrisData::board[arrY + y][arrX + x] == 1)
				return false;  //보드와 벽돌 겹침
		}
	}
	return true;  //겹치지 않음
}

//[8] 현재 위치에 블록 출력
void Start::WriteBlock(int rotation)
{
	int i, j;
	COORD cursor = GetCursorPosition();

	if (CanPositionedAt(rotation, 0, 0) == true)
	{
		//콘솔창위치 설정, 배열값에서 1은 ■출력, 0은 출력없음
		for (i = 0; i < 4; i++)        // 행 반복
		{
			for (j = 0; j < 4; j++)    // 열 반복
			{
				SetCursorPosition(cursor.X + (j * 2), cursor.Y + i);
				if (TetrisData::blocks[rotation][i][j] == 1)
				{
					cout<<"■";
				}
			}
		}
		SetCursorPosition(cursor.X, cursor.Y);
	}
}

//[10] /*배열,블록 옮김*/
void Start::Stepper(int column)
{
	int y, x;

	/*board배열 값 행 다운*/
	for (y = column; y >= 0; y--)
	{
		for (x = 1; x <= 10; x++)
		{
			TetrisData::board[y][x] = TetrisData::board[y - 1][x];
		}
	}
	/*board배열 0행에 0삽입*/
	for (x = 1; x <= 10; x++)
		TetrisData::board[0][x] = 0;

	/*board배열 1값 전체 출력 */
	for (y = 1; y <= 19; y++)
	{
		for (x = 1; x <= 10; x++)
		{
			SetCursorPosition((BOARD_X)+x * 2 + 1, y + BOARD_Y);
			if (TetrisData::board[y][x] == 1)
				cout<<"■";
			else
				cout<<"  ";
		}
	}
}

//[11] 레벨 스코어 계산
void Start::CountScore(void)
{
	Show show;
	TetrisData::score += 10;
	if (TetrisData::score % 30 == 0)
	{
		TetrisData::level += 1;
		TetrisData::speed -= 30; // 레벨 1증가시마다 스피드는 30 밀리초 빨라짐
	}
	show.ShowPoint();
}

//[12] 
/* 1~10까지 행의 열 전체가 1로되면 블록사라짐. 사라지면 Stepper함수 실행 */
void Start::RemoveLine(void)
{
	int i;
	int x, y;
	int z = 0;

	// 19행부터 시작해서 1행까지 반복
	for (y = 19; y >= 1; y--)
	{
		//행기준으로 4번 반복
		for (z = 0; z < 4; z++)
		{
			i = 0;
			//1열부터 10열까지 증가
			for (x = 1; x < 11; x++)
			{
				//행기준
				if (TetrisData::board[y][x] == 1)
				{
					i++;
					//1이 10개면 행 블록 삭제
					if (i == 10)
					{
						for (x = 1; x < 11; x++)
						{
							SetCursorPosition((x + 2) * 2, y + 2);
							cout<<"  ";
						}
						//행 기준으로 블록 내리기
						CountScore();
						Stepper(y);
					} // end if
				} // end if
			}
		}
	} // end for
} // end RemoveLine()
	
//[13] 현재 블록 클리어    
void Start::ClearBlock(int rotation, int move1, int move2)
{
	int x, y;

	COORD cursor = GetCursorPosition();

	if (CanPositionedAt(rotation, move1, move2) == true)
	{
		for (y = 0; y < 4; y++)
		{
			for (x = 0; x < 4; x++)
			{
				SetCursorPosition(cursor.X + (x * 2), cursor.Y + y);
				if (TetrisData::blocks[rotation][y][x] == 1)
					cout<<" ";
			}
		}
		SetCursorPosition(cursor.X + move1, cursor.Y + move2);
	}
}

//[14] 게임 시작
void Start::StartGame(void)
{
	int n;
	int kb;
	int c = 2;

	srand((unsigned)time(0)); // rand() 함수로 랜덤값을 주기 위해서 초기값 부여

						  /*게임 시작~끝*/
	while (1)
	{
		//블록 생성 위치 좌표(13, 2)에서 시작 
		SetCursorPosition(13, 2);

		n = rand() % 7;        // 0~27까지의 인덱스 생성 : 블록 종류 결정
		n = n * 4;            // 각 블록의 첫번째 블록(0, 4, 8, 12, 16, 20, 24)을 기준으로 출력 그리고 방향키로 변환할 수 있도록 

		if (TetrisData::level == 10) // 레벨이 10에 도달하면 게임 승리
		{
			SetCursorPosition(40, 15);
			cout<<"게임 클리어";
			getchar();
			exit(1);
		}

		if (CanPositionedAt(n, 0, 0) == false)
			break; //게임 끝                

		/*블록 한개 위~밑 이동*/
		while (1)
		{
			int ww = 0;
			int k = 0;

			/*블록 아래로 이동*/
			while (!_kbhit())
			{
				//블록 쇼
				WriteBlock(n);
				//딜레이 타임
				Sleep(DELAY + TetrisData::speed);
				//아래이동시 1있는지 확인
				if (CanPositionedAt(n, 0, 1) == false)
				{
					ww = 1;
					BoardInit(n, 0, 0);//보드 벽돌 배열 1추가
					RemoveLine();
					break;
				}
				ClearBlock(n, 0, 1);  //board배열 +1행 
			}
			/*CanPositionedAt함수에서 배열값 1발견시 중지*/
			if (ww == 1)
				break;

			kb = _getch();

			/*방향키*/
			switch (kb)
			{
			case TetrisData::LEFT:
				ClearBlock(n, -2, 0);
				WriteBlock(n);
				break;
			case TetrisData::RIGHT:
				ClearBlock(n, 2, 0);
				WriteBlock(n);
				break;
			case TetrisData::UP:
				// 첫수를구한다.
				k = n / 4;
				k *= 4;

				// 다음수가 끝수이하인가?
				if ((n + 1) <= (k + 3))
				{
					k = n + 1;
				}

				if (CanPositionedAt(k, 0, 0) == true)
				{
					ClearBlock(n, 0, 0);
					n = k;
					WriteBlock(n);
					break;
				}
				break;
			case TetrisData::DOWN:
				ClearBlock(n, 0, 2);
				break;
			case TetrisData::SPACE:    // 아래로 뚝 떨어지는 로직
				while (1)
				{
					ClearBlock(n, 0, 1);
					if (CanPositionedAt(n, 0, 1) == false)
					{
						WriteBlock(n);
						BoardInit(n, 0, 0);
						break;
					}
				}
			default: break;
			} // end switch
		} // end while(블록)        
	} // end while(게임)
}

//[15] 게임 종료 화면
void End::EndGame()
{
	SetCursorPosition(40, 15);
	cout<<"게임 종료";
	getchar(); // 입력 대기 
	system("cls");
}

아래 코드는 main함수를 가지고 있는 tetris.cpp 파일의 코드이다. C++ tetris class를 사용하기 위해서 tetris-cplusplus 헤더파일을 include한다.
#include"tetris-cplusplus.h"

//[!] 메인 함수
int main()
{
	Init init;
	Draw draw;
	Show show;
	Start start;
	End end;

	init.ConsoleInit(); // 시작 화면 

	draw.DrawField(); // 게임 영역 출력

	show.ShowPoint(); // 점수판 출력

	start.StartGame(); // 게임 시작

	end.EndGame(); // 게임 종료 화면
}
