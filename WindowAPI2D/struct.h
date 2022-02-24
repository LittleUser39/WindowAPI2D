#pragma once

struct iPoint
{
	int x;
	int y;
};

struct fPoint	//좌표에 관한 값
{
	float x;
	float y;

	fPoint()
	{
		x = 0;
		y = 0;
	}

	fPoint(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
};

struct fVec2	//방향성이 필요 - 방향성에 관한 값
{
	float x;
	float y;

	fVec2()
	{
		x = 0;
		y = 0;
	}

	fVec2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	fVec2 Nomarlize()
	{
		float z = sqrt(x * x + y * y);
		
		x = x / z;
		y = y / z;

		return *this;
	}
};