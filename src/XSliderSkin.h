#pragma once

#include "ofMain.h"

class XSliderSkin
{
public:

	void init(glm::vec2 _pos, glm::vec2 _size, string _name )
	{
		pos  = _pos;
		size = _size;
		name = _name;
	}

	void setValue(float _v)
	{
		pctValue = _v;
	}

	virtual void draw() = 0;
protected:

	glm::vec2 pos;
	glm::vec2 size;
	float     pctValue;
	string    name;
};