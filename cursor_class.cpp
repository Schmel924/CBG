//Cursor_class.cpp
#include "cursor_class.h"

void keyboard_cursor::UP_coord()
{
if (this->y_coord > 0)
	{
	this->y_coord-=1;
	}
}

void keyboard_cursor::DOWN_coord()
{
if(this->y_coord<4)
	{this->y_coord+=1;}
}

void keyboard_cursor::LEFT_coord()
{
if(this->x_coord>0)
	{this->x_coord-=1;}
}

void keyboard_cursor::RIGHT_coord()
{
if (this->x_coord<4)
	{this->x_coord+=1;}
}
