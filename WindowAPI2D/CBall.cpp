#include "framework.h"
#include "CBall.h"

void CBall::Update()
{

}

void CBall::Render(HDC hDc)
{
	Ellipse(hDc,
		GetPos().x - GetScale().x / 2,
		GetPos().y - GetScale().y / 2,
		GetPos().x + GetScale().x / 2,
		GetPos().y + GetScale().y / 2);
}
