#pragma once

#include "ofMain.h"

class XButtonSkin
{
public:

	void init(glm::vec2 _pos, glm::vec2 _size, string _name);
	void setMouseOver(bool mouseOver);
	virtual void draw() = 0;

protected:

	glm::vec2 pos;
	glm::vec2 size; 
	string    name;
	bool mouseOver = false;

};