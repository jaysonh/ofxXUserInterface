#include "XButtonSkin.h"

void XButtonSkin::init(glm::vec2 _pos, glm::vec2 _size, string _name)
{
	pos = _pos;
	size = _size;
	name = _name;
}

void XButtonSkin::setMouseOver(bool _mouseOver)
{
	mouseOver = _mouseOver;
}