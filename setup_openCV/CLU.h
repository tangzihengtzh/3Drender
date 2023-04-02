#pragma once
#include<stdio.h>
#include<math.h>
#include<vector>

using namespace std;

vector<double> NormalizeVec(vector<double>vec)
{
	double tmp = 0;
	for (int i = 0; i < 3; i++)
	{
		tmp = tmp + pow(vec[i],2);
	}
	vector<double>ans(3);
	for (int i = 0; i < 3; i++)
	{
		ans[i] = vec[i] / sqrt(tmp);
	}
	return ans;
}

double inMul(vector<double>v1, vector<double>v2)
{
	double tmp = 0;
	for (int i = 0; i < 3; i++)
	{
		tmp = tmp + v1[i] * v2[i];
	}
	return tmp;
}