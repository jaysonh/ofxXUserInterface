#include "XButton.h"

XButton::XButton()
{
}

XButton::XButton(glm::vec2 _pos, glm::vec2 _size, string _name)
{
	pos  = _pos;
	size = _size; 
	name = _name;

	boundBox = ofRectangle(pos.x, pos.y, size.x, size.y);

	visible = true;
}

XButton::~XButton()
{

}

void XButton::draw()
{
	if (useSkin)
	{
		skin->draw();
	}
	else
	{
		if (pressed)
			ofSetColor(ofColor::green);
		else
			ofSetColor(ofColor::blue);

		ofDrawRectangle(pos.x, pos.y, size.x, size.y);
	}
}

void XButton::keyPressed(ofKeyEventArgs & args)
{

}
void XButton::keyReleased(ofKeyEventArgs & args)
{

}

void XButton::mousePressed(ofMouseEventArgs & args)
{
	if (visible)
	{
		if (boundBox.inside(args.x, args.y))
		{
			pressed = true;  
			touched = true;
			ofNotifyEvent(pressedEvt, args.button);
		}
		else
		{
			pressed = false;
			touched = false;
		}
	}
}

void XButton::mouseReleased(ofMouseEventArgs & args)
{
	if (visible)
	{
		pressed = false;
		touched = false;
	}
}

void XButton::mouseMoved(ofMouseEventArgs & args)
{
	mouseOver = boundBox.inside(args.x, args.y);

	skin->setMouseOver( mouseOver );
}

void XButton::addSkin(XButtonSkin * _skin)
{
	skin = _skin;

	skin->init(pos, size, name);
	useSkin = true;
}