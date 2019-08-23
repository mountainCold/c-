#pragma once
#include <vector>
using namespace std;
class Point {
public:
	Point();
	Point(int n1, int n2);
public:
	int x;
	int y;
	int G;
	int H;
	int F;
	int ABS(int x, int y);
	void setH(int endX, int endY);
	friend bool operator==(const Point& rleft, const Point& rRight);
};
class TreeNode {
public:
	TreeNode();
	TreeNode(Point s) ;
	Point curr; //
	Point pre;//上一个点
};
class Astar {
public:
	void SetSign(int s);
	void setStartpos(int stx, int sty);
	void setEndpos(int stx, int sty);
	bool getPath(int sx, int sy, int ex, int ey, vector<Point>& path);
	bool getPath(vector<Point>& path);
protected:
	bool IsEndpos(const Point& point);
	bool isVal(const Point& point);
	void CreatePoint(const Point& center, TreeNode* pArray);
	int GetMinPoint();
	bool searchPath(TreeNode Endnode, vector<Point>& path);
public:
	vector<TreeNode> open;
	vector<TreeNode> close;
	Point Start;
	Point Endpos;
	int sign; //对象标志符
};