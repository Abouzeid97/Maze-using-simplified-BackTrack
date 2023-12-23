/* Hello There !!!!
PLEASE READ THE DESCRIPTION IF YOU ARE STUCK IN CODE OR NEED SOME EXPLAINATION
This is Abouzeid97 I've used Visual Studio 2010 
and have been updated to version 2022 
###########################################################################
In this code I've used a HardCoded Maze using the function : Maze()
for more details see the class "cnode" this is how I created the maze
###########################################################################
Creating the maze:
let's say we have a Mouse in symbol 'Q'
It needs to reach the apple in symbol "@"
The maze was created having some obstacles in symbol "#"
And every step has been taken by the mouse it took the symbol "."
###########################################################################
The algorithm used Explaination :
As we said the mouse take the symbol 'Q' 
it checks in every step which step to take
check which step is = " " 
(checking up, down, left and right)
looping in this fuction till it reaches the apple
###########################################################################
The code will shows ONLY the results of backTrack algorithm 
it only shows all the solutions could be made to reach the apple
###########################################################################
GOOD LUCK !! 
*/


#include<iostream>
#include<stdio.h>
using namespace std;
class cnode
{
public:
	char x[8][8];
	cnode* pnext;
};

class clist
{
public:
	cnode* phead;
	cnode* ptail;
	clist()
	{
		phead = NULL;
		ptail = NULL;
	}
	~clist()
	{
		cnode* ptrav;
		ptrav = phead;
		while (ptrav != NULL)
		{
			phead = phead->pnext;
			delete ptrav;
			ptrav = phead;
		}
	};
	void attach(cnode* pnn)
	{
		if (phead == NULL)
		{
			phead = pnn;
			ptail = pnn;
		}
		else
		{
			ptail->pnext = pnn;
			ptail = pnn;
		}
	};
	void dispall()
	{
		cnode* ptrav;
		ptrav = phead;
		while (ptrav != NULL)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << ptrav->x;

			}
			ptrav = ptrav->pnext;
		}
	};
};

class cstack
{
public:
	cnode* phead;
	cnode* ptail;
	cstack()
	{
		phead = NULL;
		ptail = NULL;
	}
	void push(cnode* pnn)
	{
		pnn->pnext = phead;
		phead = pnn;
	};
	cnode* pop()
	{
		if (phead == NULL)
		{
			return NULL;
		}
		cnode* ptrav = phead;
		phead = phead->pnext;
		ptrav->pnext = NULL;
		return ptrav;
	};
};

void backtrack(cnode* pcurr, cstack& s)
{
	int i;
	cnode* pchild;
	int flag;
	int hr;
	int hc;
	int r;
	int c;

	for (i = 0; i < 4; i++)
	{
		flag = 0;
		pchild = new cnode;
		pchild->pnext = NULL;

		for (r = 0; r < 8; r++)
		{
			for (c = 0; c < 8; c++)
			{
				pchild->x[r][c] = pcurr->x[r][c];

				if (pcurr->x[r][c] == 'Q')
				{
					hr = r;
					hc = c;
				}
			}
		}
		//1st child
		if (i == 0)
		{
			if (pchild->x[hr][hc + 1] == '@')
			{
				for (r = 0; r < 8; r++)
				{
					for (c = 0; c < 8; c++)
					{
						cout << pchild->x[r][c] << "|";
					}
					cout << endl;
				}
				cout << endl;
			}
			else
			{
				if (pchild->x[hr][hc + 1] == ' ' && hc + 1 < 8)
				{
					pchild->x[hr][hc] = '.';
					pchild->x[hr][hc + 1] = 'Q';
					flag = 1;
				}
			}
		}
		//2nd child
		if (i == 1)
		{
			if (pchild->x[hr][hc - 1] == '@')
			{
				for (r = 0; r < 8; r++)
				{
					for (c = 0; c < 8; c++)
					{
						cout << pchild->x[r][c] << "|";
					}
					cout << endl;
				}
				cout << endl;
			}
			else
			{
				if (pchild->x[hr][hc - 1] == ' ' && hc - 1 > -1)
				{
					pchild->x[hr][hc] = '.';
					pchild->x[hr][hc - 1] = 'Q';
					flag = 1;
				}
			}
		}
		//3rd child
		if (i == 2)
		{
			if (pchild->x[hr + 1][hc] == '@')
			{
				for (r = 0; r < 8; r++)
				{
					for (c = 0; c < 8; c++)
					{
						cout << pchild->x[r][c] << "|";
					}
					cout << endl;
				}
				cout << endl;
			}
			else
			{
				if (pchild->x[hr + 1][hc] == ' ' && hr + 1 < 8)
				{
					pchild->x[hr][hc] = '.';
					pchild->x[hr + 1][hc] = 'Q';
					flag = 1;
				}
			}
		}
		//4th child
		if (i == 3)
		{
			if (pchild->x[hr - 1][hc] == '@')
			{
				for (r = 0; r < 8; r++)
				{
					for (c = 0; c < 8; c++)
					{
						cout << pchild->x[r][c] << "|";
					}
					cout << endl;
				}
				cout << endl;
			}
			else
			{
				if (pchild->x[hr - 1][hc] == ' ' && hr - 1 > -1)
				{
					pchild->x[hr][hc] = '.';
					pchild->x[hr - 1][hc] = 'Q';
					flag = 1;
				}
			}
		}
		if (flag == 1)
		{
			s.push(pchild);
		}
	}
}

void Maze()
{
	/// creating a hardcoded maze 
	cnode* pcurr;
	int r;
	int c;
	cstack s;
	pcurr = new cnode;

	for (r = 0; r < 8; r++)
	{
		for (c = 0; c < 8; c++)
		{
			pcurr->x[r][c] = ' ';
		}
	}
	pcurr->pnext = NULL;
	pcurr->x[0][1] = '#';
	pcurr->x[0][3] = '#';
	pcurr->x[1][5] = '#';
	pcurr->x[1][6] = '#';
	pcurr->x[2][1] = '#';
	pcurr->x[2][4] = '@';
	pcurr->x[2][5] = '#';
	pcurr->x[3][2] = '#';
	pcurr->x[3][4] = '#';
	pcurr->x[3][7] = '#';
	pcurr->x[4][0] = '#';
	pcurr->x[4][6] = '#';
	pcurr->x[4][2] = '#';
	pcurr->x[5][4] = '#';

	for (int i = 0; i < 5; i++)
	{
		pcurr->x[6][i] = '#';
	}
	pcurr->x[6][6] = '#';
	pcurr->x[7][0] = 'Q';

	s.push(pcurr);
	while (s.phead != NULL)
	{
		pcurr = s.pop();
		
		backtrack(pcurr, s);
	}
}

void main()
{
	Maze();
}
// ABOUZEID97 
