#include "AStar.h"
#include "MapTank.h"

Point::Point() {}
Point::Point(int n1, int n2)
{
	x = n1;
	y = n2;
	G = 0;
}
int Point::ABS(int x, int y)
{
	if (x > y)
	{
		return x - y;
	}
	else
	{
		return y - x;
	}
}
void Point::setH(int endX, int endY)
{
	H = ABS(x, endX) + ABS(y, endY);
	F = G + H;
}
bool operator==(const Point& rleft, const Point& rRight)
{
	return (rleft.x == rRight.x) && (rleft.y == rRight.y);
}

TreeNode::TreeNode()
{
}
TreeNode::TreeNode(Point s) :curr(s)
{
}

void Astar::SetSign(int s)
{
	sign = s;
}

void Astar::setStartpos(int stx, int sty)
{
	Start.x = stx;
	Start.y = sty;
}

void Astar::setEndpos(int stx, int sty)
{
	Endpos.x = stx;
	Endpos.y = sty;
}

bool Astar::getPath(int sx, int sy, int ex, int ey, vector<Point>& path)
{
	setStartpos(sx, sy);
	setEndpos(ex, ey);
	return getPath(path);
}

bool Astar::getPath(vector<Point>& path)
{
	if (IsEndpos(Start))
	{
		return false;
	}
	open.clear();
	close.clear();
	TreeNode point = { Start };
	open.push_back(point);
	TreeNode stcArray[4];
	while (!open.empty()) {
		int nMinIndex = GetMinPoint();
		CreatePoint(open[nMinIndex].curr, stcArray);
		close.push_back(open[nMinIndex]);
		open.erase(open.begin() + nMinIndex);
		for (int i = 0; i < 4; ++i)
		{
			if (IsEndpos(stcArray[i].curr))
			{
				return searchPath(stcArray[i], path);
			}
			else if (isVal(stcArray[i].curr))
			{
				open.push_back(stcArray[i]);
			}
		}
	}
	return false;
}

bool Astar::IsEndpos(const Point& point)
{
	return (point.x == Endpos.x) && (point.y == Endpos.y);
}

bool Astar::isVal(const Point& point)
{
	int n = close.size();
	for (unsigned int i = 0; i < open.size(); ++i)
	{
		if (point == open[i].curr)
		{
			return false;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (close[i].curr == point)
		{
			return false;
		}
	}
	for (int i =point.x-1;i<point.x+2;i++)
	{
		for (int j=point.y-1;j<point.y+2;j++)
		{
			int xx = Map.GetMapVal(i, j);
			if (Map.GetMapVal(i, j) >= 1&& Map.GetMapVal(i, j) <= 3)
			{
				return false;
			}		
		}
	}
	
	if (point.x < 0 || point.y < 0)
	{
		return false;
	}
	return true;
}

void Astar::CreatePoint(const Point& center, TreeNode* pArray)
{
	int nStepX[4] = { 0 , 0 , -1 , 1 };
	int nStepY[4] = { -1 , 1 , 0 , 0 };
	for (int i = 0; i < 4; i++)
	{
		pArray[i].pre = center;
		pArray[i].curr.G = center.G + 1;
		pArray[i].curr.x = center.x + nStepX[i];
		pArray[i].curr.y = center.y + nStepY[i];
		pArray[i].curr.setH(Endpos.x, Endpos.y);
	}
}
int Astar::GetMinPoint()
{
	int minIndex = 0;
	int F = open.begin()->curr.F;
	for (int i = 0; i < open.size(); ++i)
	{
		if (F > open[i].curr.F)
		{
			// 保存最小值
			F = open[i].curr.F;
			// 记录最小值得下标
			minIndex = i;
		}
	}
	return minIndex;
}

bool Astar::searchPath(TreeNode Endnode, vector<Point>& path)
{
	for (int i = 0; i < close.size(); ++i)
	{
		if (close[i].curr == Endnode.pre)
		{
			path.push_back(close[i].curr);
			Endnode = close[i];
			i = 0;
		}
	}
	return !path.empty();
}
