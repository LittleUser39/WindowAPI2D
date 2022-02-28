#pragma once

struct iPoint
{
	int x;
	int y;
};

struct fPoint	//��ǥ�� ���� ��
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
	//��ǥ���� ������ ������
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
};

struct fVec2	//���⼺�� �ʿ� - ���⼺�� ���� ��
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