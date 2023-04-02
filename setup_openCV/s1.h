#pragma once
#include<iostream>
#include<math.h>
#include<vector>
#include"CLU.h"

using namespace std;

class block
{
public:

	block(vector<double>pos,double r)
	{
		this->center = pos;
		this->R = r;
	}
	~block(){}

	void setLight(vector<double>data)
	{
		this->light = NormalizeVec(data);
	}

	bool isInside(vector<double>point)
	{
		double tmp = 0;
		for (int i = 0; i < 3; i++)
		{
			tmp += (point[i] - this->center[i]) * (point[i] - this->center[i]);
		}
		if (sqrt(tmp) < this->R)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isSurface(vector<double>pos)
	{
		double tmp = 0;
		for (int i = 0; i < 3; i++)
		{
			tmp = tmp + (pos[i] - this->center[i]) * (pos[i] - this->center[i]);
		}
		if (sqrt(tmp) - this->R <= 5)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	vector<double> NormalVec(vector<double>pos)
	{
		if (this->isSurface(pos)==false)
		{
			std::cout << "选取点不在表面";
			return vector<double>{0,0,0};
		}
		else
		{
			vector<double>vec{0,0,0};
			for (int i = 0; i < 3; i++)
			{
				vec[i]= 2 * (pos[i] - this->center[i]);
			}
			return NormalizeVec(vec);
		}
	}

private:
	vector<double>center;
	double R;
	vector<double>light;
};


class player
{
public:
	player(vector<double>pos,vector<double>view);
	~player();

private:
	double x, y, z;
	vector<double>view;
};

player::player(vector<double>pos, vector<double>view)
{
	this->x = pos[0];
	this->y = pos[1];
	this->z = pos[2];
	this->view = view;
}

player::~player()
{
}



