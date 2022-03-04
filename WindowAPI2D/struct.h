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
	//좌표끼리 연산자 재정의
	fPoint& operator=(const fPoint& other)
	{
		x = other.x;
		y = other.y;

		return *this;
	}

	fPoint operator+(const fPoint& other)
	{
		return fPoint(x + other.x, y + other.y);
	}

	fPoint operator-(const fPoint& other)
	{
		return fPoint(x - other.x, y - other.y);
	}
	template<typename T> 
	fPoint operator*(T num)
	{
		return fPoint(x * num, y * num);
	}
	template<typename T>
	fPoint operator/(T num)
	{
		assert(0 != num);
		return fPoint(x / num, y / num);
	}
	fPoint Nomarlize()
	{
		float z = sqrt(x * x + y * y);

		x = x / z;
		y = y / z;

		return *this;
	}

	float Length()
	{
		return	sqrt(x * x + y * y);
	}
};
typedef iPoint iVec2;
typedef fPoint fVec2;

