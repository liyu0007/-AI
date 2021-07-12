#include "ArtificialIntelligence.h"


CArtificialIntelligence::CArtificialIntelligence(int depth):Tree( (int)(pow(5,depth)-1)/4)
{
	for(int i = 0;i <= 14;i++)
	{
		for(int j = 0;j <= 14;j++)
		{
			Score[i][j] = 0;
		}
	}
	for(int i = 0;i<(int)(pow(5,depth)-1)/4-1;i++)
	{
		Tree[i] = NULL;
	}
}


CArtificialIntelligence::~CArtificialIntelligence(void)
{

}
POINT CArtificialIntelligence::FindMax(int score[15][15])
{
	POINT temp;
	temp.x = temp.y = 0;
	int max = score[0][0];
	for(int i = 0;i<15;i++)
	{
		for(int j = 0;j<15;j++)
		{
			if(score[i][j] > max)
			{
				max = score[i][j];
				temp.x = j;
				temp.y = i;
			}
		}
	}
	return temp;
}
POINT CArtificialIntelligence::FindSecondMax(int score[15][15])
{
	POINT pointTemp = {0};
	pointTemp = FindMax(score);//���ĵ�
	//���ĵ�÷ֱ��0
	score[pointTemp.y][pointTemp.x] = 0;
	//�������ĵ㣬���ǵڶ���ĵ�
	pointTemp = FindMax(score);
	return pointTemp;
}
POINT CArtificialIntelligence::FindThirdMax(int score[15][15])
{
	POINT pointTemp = {0};
	pointTemp = FindMax(score);//���ĵ�
	//���ĵ�÷ֱ��0
	score[pointTemp.y][pointTemp.x] = 0;
	pointTemp = FindMax(score);//�ڶ���ĵ�
	//�����÷ֱ��0
	score[pointTemp.y][pointTemp.x] = 0;
	pointTemp = FindMax(score);//������ĵ�
	return pointTemp;
}
void CArtificialIntelligence::InitScore(int Score[15][15])
{
	for(int i = 0;i <= 14;i++)
	{
		for(int j = 0;j <= 14;j++)
		{
			Score[i][j] = 0;
		}
	}
}
CountNumber CArtificialIntelligence::CountNum(int a,int b,int c,int d,int f)
{
	CountNumber Temp;
	Temp.Black = 0;
	Temp.White = 0;
	if(a == 1)
		Temp.White++;
	if(a == 2)
		Temp.Black++;
	if(b == 1)
		Temp.White++;
	if(b == 2)
		Temp.Black++;
	if(c == 1)
		Temp.White++;
	if(c == 2)
		Temp.Black++;
	if(d == 1)
		Temp.White++;
	if(d == 2)
		Temp.Black++;
	if(f == 1)
		Temp.White++;
	if(f == 2)
		Temp.Black++;
	return Temp;
}
bool CArtificialIntelligence::PlayerWinGame(CBackArray BackArray)//1��ʾ��Ӯ�� 0��ʾ�����Ӯ
{
	//������Ԫ��
	for(int i = 0;i <= 14;i++)
	{
		for(int j = 0;j <= 10;j++)
		{
			if(BackArray.ChessBoard[i][j] == 1 && BackArray.ChessBoard[i][j+1] == 1
				&& BackArray.ChessBoard[i][j+2] == 1 && BackArray.ChessBoard[i][j+3] == 1
				&&  BackArray.ChessBoard[i][j+4] == 1)
				return 1;
		}
	}
	//������Ԫ��
	for(int i = 0;i <= 10;i++)
	{
		for(int j = 0;j <= 14;j++)
		{
			if(BackArray.ChessBoard[i][j] == 1 && BackArray.ChessBoard[i+1][j] == 1
				&& BackArray.ChessBoard[i+2][j] == 1 && BackArray.ChessBoard[i+3][j] == 1
				&&  BackArray.ChessBoard[i+4][j] == 1)
				return 1;
		}
	}
	//��б�ŵ���Ԫ��
	for(int i = 0;i <= 10;i++)
	{
		for(int j = 0;j <= 10;j++)
		{
			if(BackArray.ChessBoard[i][j] == 1 && BackArray.ChessBoard[i+1][j+1] == 1
				&& BackArray.ChessBoard[i+2][j+2] == 1 && BackArray.ChessBoard[i+3][j+3] == 1
				&&  BackArray.ChessBoard[i+4][j+4] == 1)
				return 1;
		}
	}
	//��б�ŵ���Ԫ��
	for(int i = 4;i <= 14;i++)
	{
		for(int j = 0;j <= 10;j++)
		{
			if(BackArray.ChessBoard[i][j] == 1 && BackArray.ChessBoard[i-1][j+1] == 1
				&& BackArray.ChessBoard[i-2][j+2] == 1 && BackArray.ChessBoard[i-3][j+3] == 1
				&&  BackArray.ChessBoard[i-4][j+4] == 1)
				return 1;
		}
	}
	return 0;
}
bool CArtificialIntelligence::ComputerWinGame(CBackArray BackArray)//1��ʾ��Ӯ�� 0��ʾ�����Ӯ
{
	//������Ԫ��
	for(int i = 0;i <= 14;i++)
	{
		for(int j = 0;j <= 10;j++)
		{
			if(BackArray.ChessBoard[i][j] == 2 && BackArray.ChessBoard[i][j+1] == 2
				&& BackArray.ChessBoard[i][j+2] == 2 && BackArray.ChessBoard[i][j+3] == 2
				&&  BackArray.ChessBoard[i][j+4] == 2)
				return 1;
		}
	}
	//������Ԫ��
	for(int i = 0;i <= 10;i++)
	{
		for(int j = 0;j <= 14;j++)
		{
			if(BackArray.ChessBoard[i][j] == 2 && BackArray.ChessBoard[i+1][j] == 2
				&& BackArray.ChessBoard[i+2][j] == 2 && BackArray.ChessBoard[i+3][j] == 2
				&&  BackArray.ChessBoard[i+4][j] == 2)
				return 1;
		}
	}
	//��б�ŵ���Ԫ��
	for(int i = 0;i <= 10;i++)
	{
		for(int j = 0;j <= 10;j++)
		{
			if(BackArray.ChessBoard[i][j] == 2 && BackArray.ChessBoard[i+1][j+1] == 2
				&& BackArray.ChessBoard[i+2][j+2] == 2 && BackArray.ChessBoard[i+3][j+3] == 2
				&&  BackArray.ChessBoard[i+4][j+4] == 2)
				return 1;
		}
	}
	//��б�ŵ���Ԫ��
	for(int i = 4;i <= 14;i++)
	{
		for(int j = 0;j <= 10;j++)
		{
			if(BackArray.ChessBoard[i][j] == 2 && BackArray.ChessBoard[i-1][j+1] == 2
				&& BackArray.ChessBoard[i-2][j+2] == 2 && BackArray.ChessBoard[i-3][j+3] == 2
				&&  BackArray.ChessBoard[i-4][j+4] == 2)
				return 1;
		}
	}
	return 0;
}
int CArtificialIntelligence::MaxMin(int first,int second,int third,int fourth,int fifth,int playerorcomputer)
{
	int Eval = first;
	if(playerorcomputer)//������
	{
		if(second > Eval)
			Eval = second;
		if(third > Eval)
		{
			Eval = third;
		}
		if(fourth > Eval)
			Eval = fourth;
		if(fifth > Eval)
			Eval = fifth;
	}
	else
	{
		if(second < Eval)
			Eval = second;
		if(third < Eval)
		{
			Eval = third;
		}
		if(fourth < Eval)
			Eval = fourth;
		if(fifth < Eval)
			Eval = fifth;
	}
	return Eval;
}
void CArtificialIntelligence::DeleteTree()
{
	for(unsigned int i = 0;i < Tree.capacity();i++)
	{
		if(Tree[i])	
		{
			delete Tree[i];
			Tree[i] = NULL;
		}
	}
}
POINT CArtificialIntelligence::MaxMinSearch(int depth)
{
	POINT pointTemp = {0};
	int layer = depth;//Ҫ�����Ĳ㣬��Ҷ�ӽ�㿪ʼ
	for(int i = 0;i <depth-2;i++)
	{
		for(int j = ((int)pow(5,layer-1)-1)/4;j <= ((int)pow(5,layer)-1)/4-1;j += 5)
		{
			//�ж��ǲ��ǿ�
			if(Tree[j])
			{
				//���ǿո���PlayerOrcomputer,����һ��ֵ�����ڵ�
				Tree[(j-1)/5]->Evaluation = MaxMin(Tree[j]->Evaluation,Tree[j+1]->Evaluation,Tree[j+2]->Evaluation,Tree[j+3]->Evaluation,Tree[j+4]->Evaluation,Tree[j]->PlayOrComputer);
			}
		}
		layer--;
		if(2 == layer)//˵����һ�������ӽڵ㶼�������
		{
			//�ҵ㼴��,�϶��������ĵ�
			int MaxEval = MaxMin(Tree[1]->Evaluation,Tree[2]->Evaluation,Tree[3]->Evaluation,Tree[4]->Evaluation,Tree[5]->Evaluation,1);
			for(int i = 1;i <= 5;i++)
			{
				if(Tree[i]->Evaluation == MaxEval)
				{
					pointTemp = Tree[i]->point;
					break;
				}
			}
		}
	}

	return pointTemp;
}

void CArtificialIntelligence::CreateTree(CBackArray BackArray,int depth)
{
	//����deepth��ȵ���ȫ5����
	//�ȴ������ڵ�
	int PlayerFive = 0;
	int ComputerFive = 0;
	Node* Root = new Node;
	Root->BackArray = BackArray;
	Root->PlayOrComputer = 0;
	Root->HasSon = 1;
	Root->Evaluation = 0;//���ڵ��ֵû������
	InitScore(Root->Score);
	GetScore(Root->BackArray,Root->PlayOrComputer,Root->Score);
	Tree[0] = Root;
	for(int i = 0;i < (pow(5,depth-1)-1)/4;i++)
	{
		//������i�������ӽڵ㣬����֮ǰ�жϸ��ڵ��Ƿ�5��
		//5���Ͳ���Ҫ�ӽڵ���
		if(Tree[i] && Tree[i]->HasSon)
		{
			//��һ������
			Node* FirstSon = new Node;
			FirstSon->BackArray = Tree[i]->BackArray;
			FirstSon->PlayOrComputer = 1-Tree[i]->PlayOrComputer;//����ڵ��෴
			FirstSon->point = FindMax(Tree[i]->Score);
			if(Tree[i]->PlayOrComputer == 0)//��ʾ�ֵ���������
				FirstSon->BackArray.ChessBoard[FirstSon->point.y][FirstSon->point.x] = 2;
			else
				FirstSon->BackArray.ChessBoard[FirstSon->point.y][FirstSon->point.x] = 1;
			
			InitScore(FirstSon->Score);
			GetScore(FirstSon->BackArray,FirstSon->PlayOrComputer,FirstSon->Score);
			//�ж��Ƿ����ӽڵ�
			if( 5*i+1 < (pow(5,depth-1)-1)/4 && !PlayerWinGame(FirstSon->BackArray) && !ComputerWinGame(FirstSon->BackArray))
				FirstSon->HasSon = 1;//���ӽڵ�Ļ���û�б�Ҫ�����ֵ
			else
			{
				FirstSon->HasSon = 0;
				Evaluation(*FirstSon);
			}
			Tree[5*i+1] = FirstSon;
			//�ڶ�������
			Node* SecondSon = new Node;
			SecondSon->BackArray = Tree[i]->BackArray;
			SecondSon->PlayOrComputer = 1-Tree[i]->PlayOrComputer;//����ڵ��෴
			SecondSon->point = FindSecondMax(Tree[i]->Score);
			if(Tree[i]->PlayOrComputer == 0)//��ʾ�ֵ���������
				SecondSon->BackArray.ChessBoard[SecondSon->point.y][SecondSon->point.x] = 2;
			else
				SecondSon->BackArray.ChessBoard[SecondSon->point.y][SecondSon->point.x] = 1;
			
			InitScore(SecondSon->Score);
			GetScore(SecondSon->BackArray,SecondSon->PlayOrComputer,SecondSon->Score);
			if( 5*i+2 < (pow(5,depth-1)-1)/4 && !PlayerWinGame(SecondSon->BackArray) && !ComputerWinGame(SecondSon->BackArray))
				SecondSon->HasSon = 1;
			else
			{
				SecondSon->HasSon = 0;
				Evaluation(*SecondSon);
			}
			Tree[5*i+2] = SecondSon;
			//����������
			Node* ThirdSon = new Node;
			ThirdSon->BackArray = Tree[i]->BackArray;
			ThirdSon->PlayOrComputer = 1-Tree[i]->PlayOrComputer;//����ڵ��෴
			ThirdSon->point = FindSecondMax(Tree[i]->Score);
			if(Tree[i]->PlayOrComputer == 0)//��ʾ�ֵ���������
				ThirdSon->BackArray.ChessBoard[ThirdSon->point.y][ThirdSon->point.x] = 2;
			else
				ThirdSon->BackArray.ChessBoard[ThirdSon->point.y][ThirdSon->point.x] = 1;
			InitScore(ThirdSon->Score);
			GetScore(ThirdSon->BackArray,ThirdSon->PlayOrComputer,ThirdSon->Score);
			if( 5*i+3 < (pow(5,depth-1)-1)/4 && !PlayerWinGame(ThirdSon->BackArray) && !ComputerWinGame(ThirdSon->BackArray))
				ThirdSon->HasSon = 1;
			else
			{
				ThirdSon->HasSon = 0;
				Evaluation(*ThirdSon);
			}
			Tree[5*i+3] = ThirdSon;
			//���ĸ�����
			Node* FourthSon = new Node;
			FourthSon->BackArray = Tree[i]->BackArray;
			FourthSon->PlayOrComputer = 1-Tree[i]->PlayOrComputer;//����ڵ��෴
			FourthSon->point = FindSecondMax(Tree[i]->Score);
			if(Tree[i]->PlayOrComputer == 0)//��ʾ�ֵ���������
				FourthSon->BackArray.ChessBoard[FourthSon->point.y][FourthSon->point.x] = 2;
			else
				FourthSon->BackArray.ChessBoard[FourthSon->point.y][FourthSon->point.x] = 1;
			
			InitScore(FourthSon->Score);
			GetScore(FourthSon->BackArray,FourthSon->PlayOrComputer,FourthSon->Score);
			if( 5*i+4 < (pow(5,depth-1)-1)/4 && !PlayerWinGame(FourthSon->BackArray) && !ComputerWinGame(FourthSon->BackArray))
				FourthSon->HasSon = 1;
			else
			{
				FourthSon->HasSon = 0;
				Evaluation(*FourthSon);
			}
			Tree[5*i+4] = FourthSon;
			//���������
			Node* FifthSon = new Node;
			FifthSon->BackArray = Tree[i]->BackArray;
			FifthSon->PlayOrComputer = 1-Tree[i]->PlayOrComputer;//����ڵ��෴
			FifthSon->point = FindSecondMax(Tree[i]->Score);
			if(Tree[i]->PlayOrComputer == 0)//��ʾ�ֵ���������
				FifthSon->BackArray.ChessBoard[FifthSon->point.y][FifthSon->point.x] = 2;
			else
				FifthSon->BackArray.ChessBoard[FifthSon->point.y][FifthSon->point.x] = 1;
			
			InitScore(FifthSon->Score);
			GetScore(FifthSon->BackArray,FifthSon->PlayOrComputer,FifthSon->Score);
			if( 5*i+5 < (pow(5,depth-1)-1)/4 && !PlayerWinGame(FifthSon->BackArray) && !ComputerWinGame(FifthSon->BackArray))
				FifthSon->HasSon = 1;
			else
			{
				FifthSon->HasSon = 0;
				Evaluation(*FifthSon);
			}
			Tree[5*i+5] = FifthSon;
		}
	}
}

void CArtificialIntelligence::Evaluation(Node& node)
{
	node.Evaluation = 0;
	int PlayChongFour = 0;//���ĵĸ���
	int PlayHuoThree = 0;
	int ComputerChongFour = 0;//���ĵĸ���
	int ComputerHuoThree = 0;
	int PlayMianThree = 0;
	int ComputerMianThree = 0;
	int playerhuotwo = 0;
	int playhuoone = 0;
	int computerhuoone = 0;
	int computerhuotwo = 0;
	//��5 100000
	if(ComputerWinGame(node.BackArray))
	{
		node.Evaluation += 200000;
		return;
	}
	if(PlayerWinGame(node.BackArray))
	{
		node.Evaluation -= 200000;
		return;
	}
	//��4 9990 ֻ�ܳ�����6Ԫ������
	//1.����6Ԫ��
	for(int i = 0;i < 15;i++)
	{
		for(int j = 0;j <= 9;j++)
		{
			//��4
			if(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i][j+1] == 1 &&
				node.BackArray.ChessBoard[i][j+2] == 1 && node.BackArray.ChessBoard[i][j+3] == 1 &&
				node.BackArray.ChessBoard[i][j+4] == 1 && node.BackArray.ChessBoard[i][j+5] == 0 )
			{
				node.Evaluation -= 50000;
				return;
				
			}
			if(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i][j+1] == 2 &&
				node.BackArray.ChessBoard[i][j+2] == 2 && node.BackArray.ChessBoard[i][j+3] == 2 &&
				node.BackArray.ChessBoard[i][j+4] == 2 && node.BackArray.ChessBoard[i][j+5] == 0 )
			{
				node.Evaluation += 50000;
				return;
				
			}
			//��3
			if((node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i][j+1] == 1 &&
				node.BackArray.ChessBoard[i][j+2] == 1 && node.BackArray.ChessBoard[i][j+3] == 0 &&
				node.BackArray.ChessBoard[i][j+4] == 1 && node.BackArray.ChessBoard[i][j+5] == 0 )||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i][j+1] == 1 &&
				node.BackArray.ChessBoard[i][j+2] == 0 && node.BackArray.ChessBoard[i][j+3] == 1 &&
				node.BackArray.ChessBoard[i][j+4] == 1 && node.BackArray.ChessBoard[i][j+5] == 0))
			{
				PlayHuoThree++;
			}
			if((node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i][j+1] == 2 &&
				node.BackArray.ChessBoard[i][j+2] == 2 && node.BackArray.ChessBoard[i][j+3] == 0 &&
				node.BackArray.ChessBoard[i][j+4] == 2 && node.BackArray.ChessBoard[i][j+5] == 0 )||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i][j+1] == 2 &&
				node.BackArray.ChessBoard[i][j+2] == 0 && node.BackArray.ChessBoard[i][j+3] == 2 &&
				node.BackArray.ChessBoard[i][j+4] == 2 && node.BackArray.ChessBoard[i][j+5] == 0))
			{
				ComputerHuoThree++;
			}
			//��4���֮һ
			if((node.BackArray.ChessBoard[i][j] == 2 && node.BackArray.ChessBoard[i][j+1] == 1 &&
				node.BackArray.ChessBoard[i][j+2] == 1 && node.BackArray.ChessBoard[i][j+3] == 1 &&
				node.BackArray.ChessBoard[i][j+4] == 1 && node.BackArray.ChessBoard[i][j+5] == 0 )||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i][j+1] == 1 &&
				node.BackArray.ChessBoard[i][j+2] == 1 && node.BackArray.ChessBoard[i][j+3] == 1 &&
				node.BackArray.ChessBoard[i][j+4] == 1 && node.BackArray.ChessBoard[i][j+5] == 2))
			{
				PlayChongFour++;
			}
			if((node.BackArray.ChessBoard[i][j] == 1 && node.BackArray.ChessBoard[i][j+1] == 2 &&
				node.BackArray.ChessBoard[i][j+2] == 2 && node.BackArray.ChessBoard[i][j+3] == 2 &&
				node.BackArray.ChessBoard[i][j+4] == 2 && node.BackArray.ChessBoard[i][j+5] == 0 )||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i][j+1] == 2 &&
				node.BackArray.ChessBoard[i][j+2] == 2 && node.BackArray.ChessBoard[i][j+3] == 2 &&
				node.BackArray.ChessBoard[i][j+4] == 2 && node.BackArray.ChessBoard[i][j+5] == 1))
			{
				ComputerChongFour++;
			}
			//��3
			if((node.BackArray.ChessBoard[i][j] == 2 && node.BackArray.ChessBoard[i][j+1] == 1 &&
				node.BackArray.ChessBoard[i][j+2] == 1 && node.BackArray.ChessBoard[i][j+3] == 1 &&
				node.BackArray.ChessBoard[i][j+4] == 0 && node.BackArray.ChessBoard[i][j+5] == 0 )||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i][j+1] == 0 &&
				node.BackArray.ChessBoard[i][j+2] == 1 && node.BackArray.ChessBoard[i][j+3] == 1 &&
				node.BackArray.ChessBoard[i][j+4] == 1 && node.BackArray.ChessBoard[i][j+5] == 2))
			{
				PlayMianThree++;
				/*node.Evaluation -= 150;*/
			}
			if((node.BackArray.ChessBoard[i][j] == 1 && node.BackArray.ChessBoard[i][j+1] == 2 &&
				node.BackArray.ChessBoard[i][j+2] == 2 && node.BackArray.ChessBoard[i][j+3] == 2 &&
				node.BackArray.ChessBoard[i][j+4] == 0 && node.BackArray.ChessBoard[i][j+5] == 0 )||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i][j+1] == 0 &&
				node.BackArray.ChessBoard[i][j+2] == 2 && node.BackArray.ChessBoard[i][j+3] == 2 &&
				node.BackArray.ChessBoard[i][j+4] == 2 && node.BackArray.ChessBoard[i][j+5] == 1))
			{
				ComputerMianThree++;
				/*node.Evaluation += 150;*/
			}
		}
	}
	//2.����
	for(int i = 0;i <= 9;i++)
	{
		for(int j = 0;j < 15;j++)
		{
			//��4
			if(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j] == 1 &&
				node.BackArray.ChessBoard[i+2][j] == 1 && node.BackArray.ChessBoard[i+3][j] == 1 &&
				node.BackArray.ChessBoard[i+4][j] == 1 && node.BackArray.ChessBoard[i+5][j] == 0 )
			{
				node.Evaluation -= 50000;
				return;
				
			}
			if(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j] == 2 &&
				node.BackArray.ChessBoard[i+2][j] == 2 && node.BackArray.ChessBoard[i+3][j] == 2 &&
				node.BackArray.ChessBoard[i+4][j] == 2 && node.BackArray.ChessBoard[i+5][j] == 0 )
			{
				node.Evaluation += 50000;
				return;
				
			}
			//��3
			if((node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j] == 1 &&
				node.BackArray.ChessBoard[i+2][j] == 1 && node.BackArray.ChessBoard[i+3][j] == 0 &&
				node.BackArray.ChessBoard[i+4][j] == 1 && node.BackArray.ChessBoard[i+5][j] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j] == 1 &&
				node.BackArray.ChessBoard[i+2][j] == 0 && node.BackArray.ChessBoard[i+3][j] == 1 &&
				node.BackArray.ChessBoard[i+4][j] == 1 && node.BackArray.ChessBoard[i+5][j] == 0) )
			{
				PlayHuoThree++;
			}
			if((node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j] == 2 &&
				node.BackArray.ChessBoard[i+2][j] == 2 && node.BackArray.ChessBoard[i+3][j] == 0 &&
				node.BackArray.ChessBoard[i+4][j] == 2 && node.BackArray.ChessBoard[i+5][j] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j] == 2 &&
				node.BackArray.ChessBoard[i+2][j] == 0 && node.BackArray.ChessBoard[i+3][j] == 2 &&
				node.BackArray.ChessBoard[i+4][j] == 2 && node.BackArray.ChessBoard[i+5][j] == 0) )
			{
				ComputerHuoThree++;
			}
			//��4
			if((node.BackArray.ChessBoard[i][j] == 2 && node.BackArray.ChessBoard[i+1][j] == 1 &&
				node.BackArray.ChessBoard[i+2][j] == 1 && node.BackArray.ChessBoard[i+3][j] == 1 &&
				node.BackArray.ChessBoard[i+4][j] == 1 && node.BackArray.ChessBoard[i+5][j] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j] == 1 &&
				node.BackArray.ChessBoard[i+2][j] == 1 && node.BackArray.ChessBoard[i+3][j] == 1 &&
				node.BackArray.ChessBoard[i+4][j] == 1 && node.BackArray.ChessBoard[i+5][j] == 2) )
			{
				PlayChongFour++;
			}
			if((node.BackArray.ChessBoard[i][j] == 1 && node.BackArray.ChessBoard[i+1][j] == 2 &&
				node.BackArray.ChessBoard[i+2][j] == 2 && node.BackArray.ChessBoard[i+3][j] == 2 &&
				node.BackArray.ChessBoard[i+4][j] == 2 && node.BackArray.ChessBoard[i+5][j] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j] == 2 &&
				node.BackArray.ChessBoard[i+2][j] == 2 && node.BackArray.ChessBoard[i+3][j] == 2 &&
				node.BackArray.ChessBoard[i+4][j] == 2 && node.BackArray.ChessBoard[i+5][j] == 1) )
			{
				ComputerChongFour++;
			}
			//��3
			if((node.BackArray.ChessBoard[i][j] == 2 && node.BackArray.ChessBoard[i+1][j] == 1 &&
				node.BackArray.ChessBoard[i+2][j] == 1 && node.BackArray.ChessBoard[i+3][j] == 1 &&
				node.BackArray.ChessBoard[i+4][j] == 0 && node.BackArray.ChessBoard[i+5][j] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j] == 0 &&
				node.BackArray.ChessBoard[i+2][j] == 1 && node.BackArray.ChessBoard[i+3][j] == 1 &&
				node.BackArray.ChessBoard[i+4][j] == 1 && node.BackArray.ChessBoard[i+5][j] == 2) )
			{
				PlayMianThree++;
				/*node.Evaluation -= 150;*/
			}
			if((node.BackArray.ChessBoard[i][j] == 1 && node.BackArray.ChessBoard[i+1][j] == 2 &&
				node.BackArray.ChessBoard[i+2][j] == 2 && node.BackArray.ChessBoard[i+3][j] == 2 &&
				node.BackArray.ChessBoard[i+4][j] == 0 && node.BackArray.ChessBoard[i+5][j] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j] == 0 &&
				node.BackArray.ChessBoard[i+2][j] == 2 && node.BackArray.ChessBoard[i+3][j] == 2 &&
				node.BackArray.ChessBoard[i+4][j] == 2 && node.BackArray.ChessBoard[i+5][j] == 1) )
			{
				ComputerMianThree++;
				/*node.Evaluation += 150;*/
			}
		}
	}
	//3.��б
	for(int i = 0;i < 10;i++)
	{
		for(int j = 0;j < 10;j++)
		{
			//��4
			if(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j+1] == 1 &&
				node.BackArray.ChessBoard[i+2][j+2] == 1 && node.BackArray.ChessBoard[i+3][j+3] == 1 &&
				node.BackArray.ChessBoard[i+4][j+4] == 1 && node.BackArray.ChessBoard[i+5][j+5] == 0 )
			{
				node.Evaluation -= 50000;
				return;
				
			}
			if(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j+1] == 2 &&
				node.BackArray.ChessBoard[i+2][j+2] == 2 && node.BackArray.ChessBoard[i+3][j+3] == 2 &&
				node.BackArray.ChessBoard[i+4][j+4] == 2 && node.BackArray.ChessBoard[i+5][j+5] == 0 )
			{
				node.Evaluation += 50000;
				return;
			}
			//��3
			if( (node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j+1] == 1 &&
				node.BackArray.ChessBoard[i+2][j+2] == 1 && node.BackArray.ChessBoard[i+3][j+3] == 0 &&
				node.BackArray.ChessBoard[i+4][j+4] == 1 && node.BackArray.ChessBoard[i+5][j+5] == 0 ) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j+1] == 1 &&
				node.BackArray.ChessBoard[i+2][j+2] == 0 && node.BackArray.ChessBoard[i+3][j+3] == 1 &&
				node.BackArray.ChessBoard[i+4][j+4] == 1 && node.BackArray.ChessBoard[i+5][j+5] == 0 ) )
			{
				PlayHuoThree++;
			}
			if( (node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j+1] == 2 &&
				node.BackArray.ChessBoard[i+2][j+2] == 2 && node.BackArray.ChessBoard[i+3][j+3] == 0 &&
				node.BackArray.ChessBoard[i+4][j+4] == 2 && node.BackArray.ChessBoard[i+5][j+5] == 0 ) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j+1] == 2 &&
				node.BackArray.ChessBoard[i+2][j+2] == 0 && node.BackArray.ChessBoard[i+3][j+3] == 2 &&
				node.BackArray.ChessBoard[i+4][j+4] == 2 && node.BackArray.ChessBoard[i+5][j+5] == 0 ) )
			{
				ComputerHuoThree++;
			}
			//��4
			if( (node.BackArray.ChessBoard[i][j] == 2 && node.BackArray.ChessBoard[i+1][j+1] == 1 &&
				node.BackArray.ChessBoard[i+2][j+2] == 1 && node.BackArray.ChessBoard[i+3][j+3] == 1 &&
				node.BackArray.ChessBoard[i+4][j+4] == 1 && node.BackArray.ChessBoard[i+5][j+5] == 0 ) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j+1] == 1 &&
				node.BackArray.ChessBoard[i+2][j+2] == 1 && node.BackArray.ChessBoard[i+3][j+3] == 1 &&
				node.BackArray.ChessBoard[i+4][j+4] == 1 && node.BackArray.ChessBoard[i+5][j+5] == 2 ) )
			{
				PlayChongFour++;
			}
			if( (node.BackArray.ChessBoard[i][j] == 1 && node.BackArray.ChessBoard[i+1][j+1] == 2 &&
				node.BackArray.ChessBoard[i+2][j+2] == 2 && node.BackArray.ChessBoard[i+3][j+3] == 2 &&
				node.BackArray.ChessBoard[i+4][j+4] == 2 && node.BackArray.ChessBoard[i+5][j+5] == 0 ) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j+1] == 2 &&
				node.BackArray.ChessBoard[i+2][j+2] == 2 && node.BackArray.ChessBoard[i+3][j+3] == 2 &&
				node.BackArray.ChessBoard[i+4][j+4] == 2 && node.BackArray.ChessBoard[i+5][j+5] == 1 ) )
			{
				ComputerChongFour++;
			}
			//��3
			if( (node.BackArray.ChessBoard[i][j] == 2 && node.BackArray.ChessBoard[i+1][j+1] == 1 &&
				node.BackArray.ChessBoard[i+2][j+2] == 1 && node.BackArray.ChessBoard[i+3][j+3] == 1 &&
				node.BackArray.ChessBoard[i+4][j+4] == 0 && node.BackArray.ChessBoard[i+5][j+5] == 0 ) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j+1] == 0 &&
				node.BackArray.ChessBoard[i+2][j+2] == 1 && node.BackArray.ChessBoard[i+3][j+3] == 1 &&
				node.BackArray.ChessBoard[i+4][j+4] == 1 && node.BackArray.ChessBoard[i+5][j+5] == 2 ) )
			{
				PlayMianThree++;
				/*node.Evaluation -= 150;*/
			}
			if( (node.BackArray.ChessBoard[i][j] == 1 && node.BackArray.ChessBoard[i+1][j+1] == 2 &&
				node.BackArray.ChessBoard[i+2][j+2] == 2 && node.BackArray.ChessBoard[i+3][j+3] == 2 &&
				node.BackArray.ChessBoard[i+4][j+4] == 0 && node.BackArray.ChessBoard[i+5][j+5] == 0 ) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j+1] == 0 &&
				node.BackArray.ChessBoard[i+2][j+2] == 2 && node.BackArray.ChessBoard[i+3][j+3] == 2 &&
				node.BackArray.ChessBoard[i+4][j+4] == 2 && node.BackArray.ChessBoard[i+5][j+5] == 1 ) )
			{
				ComputerMianThree++;
				/*node.Evaluation += 150;*/
			}
		}
	}
	//4.��б
	for(int i = 5;i < 15;i++)
	{
		for(int j = 0;j < 10;j++)
		{
			//��4
			if(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i-1][j+1] == 1 &&
				node.BackArray.ChessBoard[i-2][j+2] == 1 && node.BackArray.ChessBoard[i-3][j+3] == 1 &&
				node.BackArray.ChessBoard[i-4][j+4] == 1 && node.BackArray.ChessBoard[i-5][j+5] == 0 )
			{
				node.Evaluation -= 50000;
				return;
				
			}
			if(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i-1][j+1] == 2 &&
				node.BackArray.ChessBoard[i-2][j+2] == 2 && node.BackArray.ChessBoard[i-3][j+3] == 2 &&
				node.BackArray.ChessBoard[i-4][j+4] == 2 && node.BackArray.ChessBoard[i-5][j+5] == 0 )
			{
				node.Evaluation += 50000;
				return;
				
			}
			//��3
			if((node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i-1][j+1] == 1 &&
				node.BackArray.ChessBoard[i-2][j+2] == 1 && node.BackArray.ChessBoard[i-3][j+3] == 0 &&
				node.BackArray.ChessBoard[i-4][j+4] == 1 && node.BackArray.ChessBoard[i-5][j+5] == 0 )|| 
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i-1][j+1] == 1 &&
				node.BackArray.ChessBoard[i-2][j+2] == 0 && node.BackArray.ChessBoard[i-3][j+3] == 1 &&
				node.BackArray.ChessBoard[i-4][j+4] == 1 && node.BackArray.ChessBoard[i-5][j+5] == 0 ))
			{
				PlayHuoThree++;
			}
			if((node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i-1][j+1] == 2 &&
				node.BackArray.ChessBoard[i-2][j+2] == 2 && node.BackArray.ChessBoard[i-3][j+3] == 0 &&
				node.BackArray.ChessBoard[i-4][j+4] == 2 && node.BackArray.ChessBoard[i-5][j+5] == 0 )|| 
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i-1][j+1] == 2 &&
				node.BackArray.ChessBoard[i-2][j+2] == 0 && node.BackArray.ChessBoard[i-3][j+3] == 2 &&
				node.BackArray.ChessBoard[i-4][j+4] == 2 && node.BackArray.ChessBoard[i-5][j+5] == 0 ))
			{
				ComputerHuoThree++;
			}
			//��4
			if((node.BackArray.ChessBoard[i][j] == 2 && node.BackArray.ChessBoard[i-1][j+1] == 1 &&
				node.BackArray.ChessBoard[i-2][j+2] == 1 && node.BackArray.ChessBoard[i-3][j+3] == 1 &&
				node.BackArray.ChessBoard[i-4][j+4] == 1 && node.BackArray.ChessBoard[i-5][j+5] == 0 )|| 
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i-1][j+1] == 1 &&
				node.BackArray.ChessBoard[i-2][j+2] == 1 && node.BackArray.ChessBoard[i-3][j+3] == 1 &&
				node.BackArray.ChessBoard[i-4][j+4] == 1 && node.BackArray.ChessBoard[i-5][j+5] == 2 ))
			{
				PlayChongFour++;
			}
			if((node.BackArray.ChessBoard[i][j] == 1 && node.BackArray.ChessBoard[i-1][j+1] == 2 &&
				node.BackArray.ChessBoard[i-2][j+2] == 2 && node.BackArray.ChessBoard[i-3][j+3] == 2 &&
				node.BackArray.ChessBoard[i-4][j+4] == 2 && node.BackArray.ChessBoard[i-5][j+5] == 0 )|| 
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i-1][j+1] == 2 &&
				node.BackArray.ChessBoard[i-2][j+2] == 2 && node.BackArray.ChessBoard[i-3][j+3] == 2 &&
				node.BackArray.ChessBoard[i-4][j+4] == 2 && node.BackArray.ChessBoard[i-5][j+5] == 1 ))
			{
				ComputerChongFour++;
			}
			//��3
			if((node.BackArray.ChessBoard[i][j] == 2 && node.BackArray.ChessBoard[i-1][j+1] == 1 &&
				node.BackArray.ChessBoard[i-2][j+2] == 1 && node.BackArray.ChessBoard[i-3][j+3] == 1 &&
				node.BackArray.ChessBoard[i-4][j+4] == 0 && node.BackArray.ChessBoard[i-5][j+5] == 0 )|| 
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i-1][j+1] == 0 &&
				node.BackArray.ChessBoard[i-2][j+2] == 1 && node.BackArray.ChessBoard[i-3][j+3] == 1 &&
				node.BackArray.ChessBoard[i-4][j+4] == 1 && node.BackArray.ChessBoard[i-5][j+5] == 2 ))
			{
				PlayMianThree++;
				/*node.Evaluation -= 150;*/
			}
			if((node.BackArray.ChessBoard[i][j] == 1 && node.BackArray.ChessBoard[i-1][j+1] == 2 &&
				node.BackArray.ChessBoard[i-2][j+2] == 2 && node.BackArray.ChessBoard[i-3][j+3] == 2 &&
				node.BackArray.ChessBoard[i-4][j+4] == 0 && node.BackArray.ChessBoard[i-5][j+5] == 0 )|| 
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i-1][j+1] == 0 &&
				node.BackArray.ChessBoard[i-2][j+2] == 2 && node.BackArray.ChessBoard[i-3][j+3] == 2 &&
				node.BackArray.ChessBoard[i-4][j+4] == 2 && node.BackArray.ChessBoard[i-5][j+5] == 1 ))
			{
				ComputerMianThree++;
				/*node.Evaluation += 150;*/
			}
		}
	}
	////��Ԫ������3������ͳ��/////////////////////////////////////////////////////////////////////////
	//������Ԫ��
	for(int i = 0;i <= 14;i++)
	{
		for(int j = 0;j <= 10;j++)
		{
			//��3
			if(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i][j+1] == 1
				&& node.BackArray.ChessBoard[i][j+2] == 1 && node.BackArray.ChessBoard[i][j+3] == 1
				&&  node.BackArray.ChessBoard[i][j+4] == 0)
				PlayHuoThree++;
			if(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i][j+1] == 2
				&& node.BackArray.ChessBoard[i][j+2] == 2 && node.BackArray.ChessBoard[i][j+3] == 2
				&&  node.BackArray.ChessBoard[i][j+4] == 0)
				ComputerHuoThree++;
			//��4
			if( (node.BackArray.ChessBoard[i][j] == 1 && node.BackArray.ChessBoard[i][j+1] == 0
				&& node.BackArray.ChessBoard[i][j+2] == 1 && node.BackArray.ChessBoard[i][j+3] == 1
				&&  node.BackArray.ChessBoard[i][j+4] == 1)||
				(node.BackArray.ChessBoard[i][j] == 1 && node.BackArray.ChessBoard[i][j+1] == 1
				&& node.BackArray.ChessBoard[i][j+2] == 0 && node.BackArray.ChessBoard[i][j+3] == 1
				&&  node.BackArray.ChessBoard[i][j+4] == 1) || 
				(node.BackArray.ChessBoard[i][j] == 1 && node.BackArray.ChessBoard[i][j+1] == 1
				&& node.BackArray.ChessBoard[i][j+2] == 1 && node.BackArray.ChessBoard[i][j+3] == 0
				&&  node.BackArray.ChessBoard[i][j+4] == 1))
				PlayChongFour++;
			if( (node.BackArray.ChessBoard[i][j] == 2 && node.BackArray.ChessBoard[i][j+1] == 0
				&& node.BackArray.ChessBoard[i][j+2] == 2 && node.BackArray.ChessBoard[i][j+3] == 2
				&&  node.BackArray.ChessBoard[i][j+4] == 2)||
				(node.BackArray.ChessBoard[i][j] == 2 && node.BackArray.ChessBoard[i][j+1] == 2
				&& node.BackArray.ChessBoard[i][j+2] == 0 && node.BackArray.ChessBoard[i][j+3] == 2
				&&  node.BackArray.ChessBoard[i][j+4] == 2) || 
				(node.BackArray.ChessBoard[i][j] == 2 && node.BackArray.ChessBoard[i][j+1] == 2
				&& node.BackArray.ChessBoard[i][j+2] == 2 && node.BackArray.ChessBoard[i][j+3] == 0
				&&  node.BackArray.ChessBoard[i][j+4] == 2))
				ComputerChongFour++;
			//��2
			if( (node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i][j+1] == 1
				&& node.BackArray.ChessBoard[i][j+2] == 1 && node.BackArray.ChessBoard[i][j+3] == 0
				&&  node.BackArray.ChessBoard[i][j+4] == 0)||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i][j+1] == 0
				&& node.BackArray.ChessBoard[i][j+2] == 1 && node.BackArray.ChessBoard[i][j+3] == 1
				&&  node.BackArray.ChessBoard[i][j+4] == 0) || 
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i][j+1] == 1
				&& node.BackArray.ChessBoard[i][j+2] == 0 && node.BackArray.ChessBoard[i][j+3] == 1
				&&  node.BackArray.ChessBoard[i][j+4] == 0))
				playerhuotwo++;
				/*node.Evaluation -= 200;*/
			if( (node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i][j+1] == 2
				&& node.BackArray.ChessBoard[i][j+2] == 2 && node.BackArray.ChessBoard[i][j+3] == 0
				&&  node.BackArray.ChessBoard[i][j+4] == 0)||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i][j+1] == 0
				&& node.BackArray.ChessBoard[i][j+2] == 2 && node.BackArray.ChessBoard[i][j+3] == 2
				&&  node.BackArray.ChessBoard[i][j+4] == 0) || 
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i][j+1] == 2
				&& node.BackArray.ChessBoard[i][j+2] == 0 && node.BackArray.ChessBoard[i][j+3] == 2
				&&  node.BackArray.ChessBoard[i][j+4] == 0))
				computerhuotwo++;
				/*node.Evaluation += 200;*/
			//��1
			if( (node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i][j+1] == 1
				&& node.BackArray.ChessBoard[i][j+2] == 0 && node.BackArray.ChessBoard[i][j+3] == 0
				&&  node.BackArray.ChessBoard[i][j+4] == 0)||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i][j+1] == 0
				&& node.BackArray.ChessBoard[i][j+2] == 1 && node.BackArray.ChessBoard[i][j+3] == 0
				&&  node.BackArray.ChessBoard[i][j+4] == 0) || 
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i][j+1] == 0
				&& node.BackArray.ChessBoard[i][j+2] == 0 && node.BackArray.ChessBoard[i][j+3] == 1
				&&  node.BackArray.ChessBoard[i][j+4] == 0))
				playhuoone++;
				/*node.Evaluation -= 20;*/
			if( (node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i][j+1] == 2
				&& node.BackArray.ChessBoard[i][j+2] == 0 && node.BackArray.ChessBoard[i][j+3] == 0
				&&  node.BackArray.ChessBoard[i][j+4] == 0)||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i][j+1] == 0
				&& node.BackArray.ChessBoard[i][j+2] == 2 && node.BackArray.ChessBoard[i][j+3] == 0
				&&  node.BackArray.ChessBoard[i][j+4] == 0) || 
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i][j+1] == 0
				&& node.BackArray.ChessBoard[i][j+2] == 0 && node.BackArray.ChessBoard[i][j+3] == 2
				&&  node.BackArray.ChessBoard[i][j+4] == 0))
				computerhuoone++;
				/*node.Evaluation += 20;*/
		}
	}
	//������Ԫ��
	for(int i = 0;i <= 10;i++)
	{
		for(int j = 0;j <= 14;j++)
		{
			//��3
			if(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j] == 1
				&& node.BackArray.ChessBoard[i+2][j] == 1 && node.BackArray.ChessBoard[i+3][j] == 1
				&&  node.BackArray.ChessBoard[i+4][j] == 0)
				PlayHuoThree++;
			if(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j] == 2
				&& node.BackArray.ChessBoard[i+2][j] == 2 && node.BackArray.ChessBoard[i+3][j] == 2
				&&  node.BackArray.ChessBoard[i+4][j] == 0)
				ComputerHuoThree++;
			//��4
			if( (node.BackArray.ChessBoard[i][j] == 1 && node.BackArray.ChessBoard[i+1][j] == 0
				&& node.BackArray.ChessBoard[i+2][j] == 1 && node.BackArray.ChessBoard[i+3][j] == 1
				&&  node.BackArray.ChessBoard[i+4][j] == 1) ||
				(node.BackArray.ChessBoard[i][j] == 1 && node.BackArray.ChessBoard[i+1][j] == 1
				&& node.BackArray.ChessBoard[i+2][j] == 0 && node.BackArray.ChessBoard[i+3][j] == 1
				&&  node.BackArray.ChessBoard[i+4][j] == 1) ||
				(node.BackArray.ChessBoard[i][j] == 1 && node.BackArray.ChessBoard[i+1][j] == 1
				&& node.BackArray.ChessBoard[i+2][j] == 1 && node.BackArray.ChessBoard[i+3][j] == 0
				&&  node.BackArray.ChessBoard[i+4][j] == 1))
				PlayChongFour++;
			if( (node.BackArray.ChessBoard[i][j] == 2 && node.BackArray.ChessBoard[i+1][j] == 0
				&& node.BackArray.ChessBoard[i+2][j] == 2 && node.BackArray.ChessBoard[i+3][j] == 2
				&&  node.BackArray.ChessBoard[i+4][j] == 2) ||
				(node.BackArray.ChessBoard[i][j] == 2 && node.BackArray.ChessBoard[i+1][j] == 2
				&& node.BackArray.ChessBoard[i+2][j] == 0 && node.BackArray.ChessBoard[i+3][j] == 2
				&&  node.BackArray.ChessBoard[i+4][j] == 2) ||
				(node.BackArray.ChessBoard[i][j] == 2 && node.BackArray.ChessBoard[i+1][j] == 2
				&& node.BackArray.ChessBoard[i+2][j] == 2 && node.BackArray.ChessBoard[i+3][j] == 0
				&&  node.BackArray.ChessBoard[i+4][j] == 2))
				ComputerChongFour++;
			//��2
			if( (node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j] == 1
				&& node.BackArray.ChessBoard[i+2][j] == 1 && node.BackArray.ChessBoard[i+3][j] == 0
				&&  node.BackArray.ChessBoard[i+4][j] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j] == 0
				&& node.BackArray.ChessBoard[i+2][j] == 1 && node.BackArray.ChessBoard[i+3][j] == 1
				&&  node.BackArray.ChessBoard[i+4][j] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j] == 1
				&& node.BackArray.ChessBoard[i+2][j] == 0 && node.BackArray.ChessBoard[i+3][j] == 1
				&&  node.BackArray.ChessBoard[i+4][j] == 0))
				playerhuotwo++;
				/*node.Evaluation -= 200;*/
			if( (node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j] == 2
				&& node.BackArray.ChessBoard[i+2][j] == 2 && node.BackArray.ChessBoard[i+3][j] == 0
				&&  node.BackArray.ChessBoard[i+4][j] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j] == 0
				&& node.BackArray.ChessBoard[i+2][j] == 2 && node.BackArray.ChessBoard[i+3][j] == 2
				&&  node.BackArray.ChessBoard[i+4][j] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j] == 2
				&& node.BackArray.ChessBoard[i+2][j] == 0 && node.BackArray.ChessBoard[i+3][j] == 2
				&&  node.BackArray.ChessBoard[i+4][j] == 0))
				computerhuotwo++;
				/*node.Evaluation += 200;*/
			//��1
			if( (node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j] == 1
				&& node.BackArray.ChessBoard[i+2][j] == 0 && node.BackArray.ChessBoard[i+3][j] == 0
				&&  node.BackArray.ChessBoard[i+4][j] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j] == 0
				&& node.BackArray.ChessBoard[i+2][j] == 1 && node.BackArray.ChessBoard[i+3][j] == 0
				&&  node.BackArray.ChessBoard[i+4][j] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j] == 0
				&& node.BackArray.ChessBoard[i+2][j] == 0 && node.BackArray.ChessBoard[i+3][j] == 1
				&&  node.BackArray.ChessBoard[i+4][j] == 0))
				playhuoone++;
				/*node.Evaluation -= 20;*/
			if( (node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j] == 2
				&& node.BackArray.ChessBoard[i+2][j] == 0 && node.BackArray.ChessBoard[i+3][j] == 0
				&&  node.BackArray.ChessBoard[i+4][j] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j] == 0
				&& node.BackArray.ChessBoard[i+2][j] == 2 && node.BackArray.ChessBoard[i+3][j] == 0
				&&  node.BackArray.ChessBoard[i+4][j] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j] == 0
				&& node.BackArray.ChessBoard[i+2][j] == 0 && node.BackArray.ChessBoard[i+3][j] == 2
				&&  node.BackArray.ChessBoard[i+4][j] == 0))
				computerhuoone++;
				/*node.Evaluation += 20;*/
		}
	}
	//��б�ŵ���Ԫ��
	for(int i = 0;i <= 10;i++)
	{
		for(int j = 0;j <= 10;j++)
		{
			//��3
			if(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j+1] == 1
				&& node.BackArray.ChessBoard[i+2][j+2] == 1 && node.BackArray.ChessBoard[i+3][j+3] == 1
				&&  node.BackArray.ChessBoard[i+4][j+4] == 0)
				PlayHuoThree++;
			if(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j+1] == 2
				&& node.BackArray.ChessBoard[i+2][j+2] == 2 && node.BackArray.ChessBoard[i+3][j+3] == 2
				&&  node.BackArray.ChessBoard[i+4][j+4] == 0)
				ComputerHuoThree++;
			//��4
			if( (node.BackArray.ChessBoard[i][j] == 1 && node.BackArray.ChessBoard[i+1][j+1] == 0
				&& node.BackArray.ChessBoard[i+2][j+2] == 1 && node.BackArray.ChessBoard[i+3][j+3] == 1
				&&  node.BackArray.ChessBoard[i+4][j+4] == 1) ||
				(node.BackArray.ChessBoard[i][j] == 1 && node.BackArray.ChessBoard[i+1][j+1] == 1
				&& node.BackArray.ChessBoard[i+2][j+2] == 0 && node.BackArray.ChessBoard[i+3][j+3] == 1
				&&  node.BackArray.ChessBoard[i+4][j+4] == 1)||
				(node.BackArray.ChessBoard[i][j] == 1 && node.BackArray.ChessBoard[i+1][j+1] == 1
				&& node.BackArray.ChessBoard[i+2][j+2] == 1 && node.BackArray.ChessBoard[i+3][j+3] == 0
				&&  node.BackArray.ChessBoard[i+4][j+4] == 1) )
				PlayChongFour++;
			if( (node.BackArray.ChessBoard[i][j] == 2 && node.BackArray.ChessBoard[i+1][j+1] == 0
				&& node.BackArray.ChessBoard[i+2][j+2] == 2 && node.BackArray.ChessBoard[i+3][j+3] == 2
				&&  node.BackArray.ChessBoard[i+4][j+4] == 2) ||
				(node.BackArray.ChessBoard[i][j] == 2 && node.BackArray.ChessBoard[i+1][j+1] == 2
				&& node.BackArray.ChessBoard[i+2][j+2] == 0 && node.BackArray.ChessBoard[i+3][j+3] == 2
				&&  node.BackArray.ChessBoard[i+4][j+4] == 2)||
				(node.BackArray.ChessBoard[i][j] == 2 && node.BackArray.ChessBoard[i+1][j+1] == 2
				&& node.BackArray.ChessBoard[i+2][j+2] == 2 && node.BackArray.ChessBoard[i+3][j+3] == 0
				&&  node.BackArray.ChessBoard[i+4][j+4] == 2) )
				ComputerChongFour++;
			//��2
			if( (node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j+1] == 1
				&& node.BackArray.ChessBoard[i+2][j+2] == 1 && node.BackArray.ChessBoard[i+3][j+3] == 0
				&&  node.BackArray.ChessBoard[i+4][j+4] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j+1] == 0
				&& node.BackArray.ChessBoard[i+2][j+2] == 1 && node.BackArray.ChessBoard[i+3][j+3] == 1
				&&  node.BackArray.ChessBoard[i+4][j+4] == 0)||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j+1] == 1
				&& node.BackArray.ChessBoard[i+2][j+2] == 0 && node.BackArray.ChessBoard[i+3][j+3] == 1
				&&  node.BackArray.ChessBoard[i+4][j+4] == 0) )
				playerhuotwo++;
				/*node.Evaluation -= 200;*/
			if( (node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j+1] == 2
				&& node.BackArray.ChessBoard[i+2][j+2] == 2 && node.BackArray.ChessBoard[i+3][j+3] == 0
				&&  node.BackArray.ChessBoard[i+4][j+4] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j+1] == 0
				&& node.BackArray.ChessBoard[i+2][j+2] == 2 && node.BackArray.ChessBoard[i+3][j+3] == 2
				&&  node.BackArray.ChessBoard[i+4][j+4] == 0)||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j+1] == 2
				&& node.BackArray.ChessBoard[i+2][j+2] == 0 && node.BackArray.ChessBoard[i+3][j+3] == 2
				&&  node.BackArray.ChessBoard[i+4][j+4] == 0) )
				computerhuotwo++;
				/*node.Evaluation += 200;*/
			//��1
			if( (node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j+1] == 1
				&& node.BackArray.ChessBoard[i+2][j+2] == 0 && node.BackArray.ChessBoard[i+3][j+3] == 0
				&&  node.BackArray.ChessBoard[i+4][j+4] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j+1] == 0
				&& node.BackArray.ChessBoard[i+2][j+2] == 1 && node.BackArray.ChessBoard[i+3][j+3] == 0
				&&  node.BackArray.ChessBoard[i+4][j+4] == 0)||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j+1] == 0
				&& node.BackArray.ChessBoard[i+2][j+2] == 0 && node.BackArray.ChessBoard[i+3][j+3] == 1
				&&  node.BackArray.ChessBoard[i+4][j+4] == 0) )
				playhuoone++;
				/*node.Evaluation -= 20;*/
			if( (node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j+1] == 2
				&& node.BackArray.ChessBoard[i+2][j+2] == 0 && node.BackArray.ChessBoard[i+3][j+3] == 0
				&&  node.BackArray.ChessBoard[i+4][j+4] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j+1] == 0
				&& node.BackArray.ChessBoard[i+2][j+2] == 2 && node.BackArray.ChessBoard[i+3][j+3] == 0
				&&  node.BackArray.ChessBoard[i+4][j+4] == 0)||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i+1][j+1] == 0
				&& node.BackArray.ChessBoard[i+2][j+2] == 0 && node.BackArray.ChessBoard[i+3][j+3] == 2
				&&  node.BackArray.ChessBoard[i+4][j+4] == 0) )
				computerhuoone++;
				/*node.Evaluation += 20;*/
		}
	}
	//��б�ŵ���Ԫ��
	for(int i = 4;i <= 14;i++)
	{
		for(int j = 0;j <= 10;j++)
		{
			//��3
			if(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i-1][j+1] == 1
				&& node.BackArray.ChessBoard[i-2][j+2] == 1 && node.BackArray.ChessBoard[i-3][j+3] == 1
				&&  node.BackArray.ChessBoard[i-4][j+4] == 0)
				PlayHuoThree++;
			if(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i-1][j+1] == 2
				&& node.BackArray.ChessBoard[i-2][j+2] == 2 && node.BackArray.ChessBoard[i-3][j+3] == 2
				&&  node.BackArray.ChessBoard[i-4][j+4] == 0)
				ComputerHuoThree++;
			//��4
			if( (node.BackArray.ChessBoard[i][j] == 1 && node.BackArray.ChessBoard[i-1][j+1] == 0
				&& node.BackArray.ChessBoard[i-2][j+2] == 1 && node.BackArray.ChessBoard[i-3][j+3] == 1
				&&  node.BackArray.ChessBoard[i-4][j+4] == 1) ||
				(node.BackArray.ChessBoard[i][j] == 1 && node.BackArray.ChessBoard[i-1][j+1] == 1
				&& node.BackArray.ChessBoard[i-2][j+2] == 0 && node.BackArray.ChessBoard[i-3][j+3] == 1
				&&  node.BackArray.ChessBoard[i-4][j+4] == 1) ||
				(node.BackArray.ChessBoard[i][j] == 1 && node.BackArray.ChessBoard[i-1][j+1] == 1
				&& node.BackArray.ChessBoard[i-2][j+2] == 1 && node.BackArray.ChessBoard[i-3][j+3] == 0
				&&  node.BackArray.ChessBoard[i-4][j+4] == 1))
				PlayChongFour++;
			if( (node.BackArray.ChessBoard[i][j] == 2 && node.BackArray.ChessBoard[i-1][j+1] == 0
				&& node.BackArray.ChessBoard[i-2][j+2] == 2 && node.BackArray.ChessBoard[i-3][j+3] == 2
				&&  node.BackArray.ChessBoard[i-4][j+4] == 2) ||
				(node.BackArray.ChessBoard[i][j] == 2 && node.BackArray.ChessBoard[i-1][j+1] == 2
				&& node.BackArray.ChessBoard[i-2][j+2] == 0 && node.BackArray.ChessBoard[i-3][j+3] == 2
				&&  node.BackArray.ChessBoard[i-4][j+4] == 2) ||
				(node.BackArray.ChessBoard[i][j] == 2 && node.BackArray.ChessBoard[i-1][j+1] == 2
				&& node.BackArray.ChessBoard[i-2][j+2] == 2 && node.BackArray.ChessBoard[i-3][j+3] == 0
				&&  node.BackArray.ChessBoard[i-4][j+4] == 2))
				ComputerChongFour++;
			//��2
			if( (node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i-1][j+1] == 1
				&& node.BackArray.ChessBoard[i-2][j+2] == 1 && node.BackArray.ChessBoard[i-3][j+3] == 0
				&&  node.BackArray.ChessBoard[i-4][j+4] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i-1][j+1] == 0
				&& node.BackArray.ChessBoard[i-2][j+2] == 1 && node.BackArray.ChessBoard[i-3][j+3] == 1
				&&  node.BackArray.ChessBoard[i-4][j+4] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i-1][j+1] == 1
				&& node.BackArray.ChessBoard[i-2][j+2] == 0 && node.BackArray.ChessBoard[i-3][j+3] == 1
				&&  node.BackArray.ChessBoard[i-4][j+4] == 0))
				playerhuotwo++;
				/*node.Evaluation -= 200;*/
			if( (node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i-1][j+1] == 2
				&& node.BackArray.ChessBoard[i-2][j+2] == 2 && node.BackArray.ChessBoard[i-3][j+3] == 0
				&&  node.BackArray.ChessBoard[i-4][j+4] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i-1][j+1] == 0
				&& node.BackArray.ChessBoard[i-2][j+2] == 2 && node.BackArray.ChessBoard[i-3][j+3] == 2
				&&  node.BackArray.ChessBoard[i-4][j+4] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i-1][j+1] == 2
				&& node.BackArray.ChessBoard[i-2][j+2] == 0 && node.BackArray.ChessBoard[i-3][j+3] == 2
				&&  node.BackArray.ChessBoard[i-4][j+4] == 0))
				computerhuotwo++;
				/*node.Evaluation += 200;*/
			//��1
			if( (node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i-1][j+1] == 1
				&& node.BackArray.ChessBoard[i-2][j+2] == 0 && node.BackArray.ChessBoard[i-3][j+3] == 0
				&&  node.BackArray.ChessBoard[i-4][j+4] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i-1][j+1] == 0
				&& node.BackArray.ChessBoard[i-2][j+2] == 1 && node.BackArray.ChessBoard[i-3][j+3] == 0
				&&  node.BackArray.ChessBoard[i-4][j+4] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i-1][j+1] == 0
				&& node.BackArray.ChessBoard[i-2][j+2] == 0 && node.BackArray.ChessBoard[i-3][j+3] == 1
				&&  node.BackArray.ChessBoard[i-4][j+4] == 0))
				playhuoone++;
				/*node.Evaluation -= 20;*/
			if( (node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i-1][j+1] == 2
				&& node.BackArray.ChessBoard[i-2][j+2] == 0 && node.BackArray.ChessBoard[i-3][j+3] == 0
				&&  node.BackArray.ChessBoard[i-4][j+4] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i-1][j+1] == 0
				&& node.BackArray.ChessBoard[i-2][j+2] == 2 && node.BackArray.ChessBoard[i-3][j+3] == 0
				&&  node.BackArray.ChessBoard[i-4][j+4] == 0) ||
				(node.BackArray.ChessBoard[i][j] == 0 && node.BackArray.ChessBoard[i-1][j+1] == 0
				&& node.BackArray.ChessBoard[i-2][j+2] == 0 && node.BackArray.ChessBoard[i-3][j+3] == 2
				&&  node.BackArray.ChessBoard[i-4][j+4] == 0))
				computerhuoone++;
				/*node.Evaluation += 20;*/
		}
	}
	//��4 9950
	//˫��3 9900 ����һ����4һ����3
	//����3  1000
	if( PlayChongFour + PlayHuoThree >= 2 )//��4 ����������
	{
		if(PlayChongFour > 0)
		{
			node.Evaluation -= 30000;//����+������˫������в��
		}
		else
		{
			node.Evaluation -= 20000;
		}
	}
	else
	{
		if(PlayChongFour == 1)
			node.Evaluation -= 10000;
		if(PlayHuoThree == 1)
			node.Evaluation -= 1000;
	}

	if( ComputerChongFour + ComputerHuoThree >= 2 )//��4 ����������
	{
		if(ComputerChongFour > 0)
		{
			node.Evaluation += 30000;
		}
		else
		{
			node.Evaluation += 20000;
		}
	}
	else
	{
		if(ComputerChongFour == 1)
			node.Evaluation += 10000;
		if(ComputerHuoThree == 1)
			node.Evaluation += 1000;
	}
	//�޷�����5����û�����壬����Ԫ����ͳ�Ƽ��ɣ�
	//��3   150
	//��2   200
	//��1   20
	node.Evaluation += ComputerMianThree*150;
	node.Evaluation -= PlayMianThree*150;
	node.Evaluation += computerhuotwo*200;
	node.Evaluation -= playerhuotwo*200;
	node.Evaluation += computerhuoone*20;
	node.Evaluation -= playhuoone*20;
}

void CArtificialIntelligence::GetScore(CBackArray BackArray,int num,int Score[15][15])
{
	int ScoreTableBlack[5];
	int ScoreTableWhite[5];
	if(num == 0)//���ƺ�������÷ֱ�
	{
		for(int i = 0;i<5;i++)
		{
			ScoreTableBlack[i] = ScoreTable1[i];
			ScoreTableWhite[i] = ScoreTable2[i];
		}
	}
	if(num == 1)//���ư�������÷ֱ��൱�ڵ÷ֱ�Ե�
	{
		for(int i = 0;i<5;i++)
		{
			ScoreTableBlack[i] = ScoreTable2[i];
			ScoreTableWhite[i] = ScoreTable1[i];
		}
	}
	//������Ԫ��
	for(int i = 0;i <= 14;i++)
	{
		for(int j = 0;j <= 10;j++)
		{
			CountNumber Temp;
			Temp = CountNum(BackArray.ChessBoard[i][j],BackArray.ChessBoard[i][j+1]
				,BackArray.ChessBoard[i][j+2], BackArray.ChessBoard[i][j+3]
				,BackArray.ChessBoard[i][j+4]);
			if(Temp.White == 0 && Temp.Black != 0)//��Ԫ��û�а����к���
			{
				if(BackArray.ChessBoard[i][j] == 0)//��λ��
					Score[i][j] += ScoreTableBlack[Temp.Black];
				if(BackArray.ChessBoard[i][j+1] == 0)//��λ��
					Score[i][j+1] += ScoreTableBlack[Temp.Black];
				if(BackArray.ChessBoard[i][j+2] == 0)//��λ��
					Score[i][j+2] += ScoreTableBlack[Temp.Black];
				if(BackArray.ChessBoard[i][j+3] == 0)//��λ��
					Score[i][j+3] += ScoreTableBlack[Temp.Black];
				if(BackArray.ChessBoard[i][j+4] == 0)//��λ��
					Score[i][j+4] += ScoreTableBlack[Temp.Black];
			}
			if(Temp.Black == 0)//�޺���
			{
				if(BackArray.ChessBoard[i][j] == 0)//��λ��
					Score[i][j] += ScoreTableWhite[Temp.White];
				if(BackArray.ChessBoard[i][j+1] == 0)//��λ��
					Score[i][j+1] += ScoreTableWhite[Temp.White];
				if(BackArray.ChessBoard[i][j+2] == 0)//��λ��
					Score[i][j+2] += ScoreTableWhite[Temp.White];
				if(BackArray.ChessBoard[i][j+3] == 0)//��λ��
					Score[i][j+3] += ScoreTableWhite[Temp.White];
				if(BackArray.ChessBoard[i][j+4] == 0)//��λ��
					Score[i][j+4] += ScoreTableWhite[Temp.White];
			}
			//�����������û�з���
		}
	}
	//������Ԫ��
	for(int i = 0;i <= 10;i++)
	{
		for(int j = 0;j <= 14;j++)
		{
			CountNumber Temp;
			Temp = CountNum(BackArray.ChessBoard[i][j],BackArray.ChessBoard[i+1][j],
				BackArray.ChessBoard[i+2][j],BackArray.ChessBoard[i+3][j] ,
				BackArray.ChessBoard[i+4][j]);
			if(Temp.White == 0 && Temp.Black != 0)//��Ԫ��û�а���
			{
				if(BackArray.ChessBoard[i][j] == 0)//��λ��
					Score[i][j] += ScoreTableBlack[Temp.Black];
				if(BackArray.ChessBoard[i+1][j] == 0)//��λ��
					Score[i+1][j] += ScoreTableBlack[Temp.Black];
				if(BackArray.ChessBoard[i+2][j] == 0)//��λ��
					Score[i+2][j] += ScoreTableBlack[Temp.Black];
				if(BackArray.ChessBoard[i+3][j] == 0)//��λ��
					Score[i+3][j] += ScoreTableBlack[Temp.Black];
				if(BackArray.ChessBoard[i+4][j] == 0)//��λ��
					Score[i+4][j] += ScoreTableBlack[Temp.Black];
			}
			if(Temp.Black == 0)//�޺���
			{
				if(BackArray.ChessBoard[i][j] == 0)//��λ��
					Score[i][j] += ScoreTableWhite[Temp.White];
				if(BackArray.ChessBoard[i+1][j] == 0)//��λ��
					Score[i+1][j] += ScoreTableWhite[Temp.White];
				if(BackArray.ChessBoard[i+2][j] == 0)//��λ��
					Score[i+2][j] += ScoreTableWhite[Temp.White];
				if(BackArray.ChessBoard[i+3][j] == 0)//��λ��
					Score[i+3][j] += ScoreTableWhite[Temp.White];
				if(BackArray.ChessBoard[i+4][j] == 0)//��λ��
					Score[i+4][j] += ScoreTableWhite[Temp.White];
			}
		}
	}
	//��б�ŵ���Ԫ��
	for(int i = 0;i <= 10;i++)
	{
		for(int j = 0;j <= 10;j++)
		{
			CountNumber Temp;
			Temp = CountNum(BackArray.ChessBoard[i][j] , BackArray.ChessBoard[i+1][j+1] 
				,BackArray.ChessBoard[i+2][j+2],  BackArray.ChessBoard[i+3][j+3],
				BackArray.ChessBoard[i+4][j+4]);
			if(Temp.White == 0 && Temp.Black != 0)//��Ԫ��û�а���
			{
				if(BackArray.ChessBoard[i][j] == 0)//��λ��
					Score[i][j] += ScoreTableBlack[Temp.Black];
				if(BackArray.ChessBoard[i+1][j+1] == 0)//��λ��
					Score[i+1][j+1] += ScoreTableBlack[Temp.Black];
				if(BackArray.ChessBoard[i+2][j+2] == 0)//��λ��
					Score[i+2][j+2] += ScoreTableBlack[Temp.Black];
				if(BackArray.ChessBoard[i+3][j+3] == 0)//��λ��
					Score[i+3][j+3] += ScoreTableBlack[Temp.Black];
				if(BackArray.ChessBoard[i+4][j+4] == 0)//��λ��
					Score[i+4][j+4] += ScoreTableBlack[Temp.Black];
			}
			if(Temp.Black == 0)//�޺���
			{
				if(BackArray.ChessBoard[i][j] == 0)//��λ��
					Score[i][j] += ScoreTableWhite[Temp.White];
				if(BackArray.ChessBoard[i+1][j+1] == 0)//��λ��
					Score[i+1][j+1] += ScoreTableWhite[Temp.White];
				if(BackArray.ChessBoard[i+2][j+2] == 0)//��λ��
					Score[i+2][j+2] += ScoreTableWhite[Temp.White];
				if(BackArray.ChessBoard[i+3][j+3] == 0)//��λ��
					Score[i+3][j+3] += ScoreTableWhite[Temp.White];
				if(BackArray.ChessBoard[i+4][j+4] == 0)//��λ��
					Score[i+4][j+4] += ScoreTableWhite[Temp.White];
			}
		}
	}
	//��б�ŵ���Ԫ��
	for(int i = 4;i <= 14;i++)
	{
		for(int j = 0;j <= 10;j++)
		{
			CountNumber Temp;
			Temp = CountNum(BackArray.ChessBoard[i][j], BackArray.ChessBoard[i-1][j+1]
				,BackArray.ChessBoard[i-2][j+2], BackArray.ChessBoard[i-3][j+3] 
				,BackArray.ChessBoard[i-4][j+4]);
			if(Temp.White == 0 && Temp.Black != 0)//��Ԫ��û�а���
			{
				if(BackArray.ChessBoard[i][j] == 0)//��λ��
					Score[i][j] += ScoreTableBlack[Temp.Black];
				if(BackArray.ChessBoard[i-1][j+1] == 0)//��λ��
					Score[i-1][j+1] += ScoreTableBlack[Temp.Black];
				if(BackArray.ChessBoard[i-2][j+2] == 0)//��λ��
					Score[i-2][j+2] += ScoreTableBlack[Temp.Black];
				if(BackArray.ChessBoard[i-3][j+3] == 0)//��λ��
					Score[i-3][j+3] += ScoreTableBlack[Temp.Black];
				if(BackArray.ChessBoard[i-4][j+4] == 0)//��λ��
					Score[i-4][j+4] += ScoreTableBlack[Temp.Black];
			}
			if(Temp.Black == 0)//�޺���
			{
				if(BackArray.ChessBoard[i][j] == 0)//��λ��
					Score[i][j] += ScoreTableWhite[Temp.White];
				if(BackArray.ChessBoard[i-1][j+1] == 0)//��λ��
					Score[i-1][j+1] += ScoreTableWhite[Temp.White];
				if(BackArray.ChessBoard[i-2][j+2] == 0)//��λ��
					Score[i-2][j+2] += ScoreTableWhite[Temp.White];
				if(BackArray.ChessBoard[i-3][j+3] == 0)//��λ��
					Score[i-3][j+3] += ScoreTableWhite[Temp.White];
				if(BackArray.ChessBoard[i-4][j+4] == 0)//��λ��
					Score[i-4][j+4] += ScoreTableWhite[Temp.White];
			}
		}
	}
}