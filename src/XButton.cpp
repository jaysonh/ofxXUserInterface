#include "XButton.h"

XButton::XButton()
{
}

XButton::XButton(glm::vec2 _pos, glm::vec2 _size)
{
	pos  = _pos;
	size = _size; 

	boundBox = ofRectangle(pos.x, pos.y, size.x, size.y);

	visible = true;
}

XButton::~XButton()
{

}

void XButton::draw()
{
	if (pressed)
		ofSetColor(ofColor::green);
	else
		ofSetColor(ofColor::blue);

	ofDrawRectangle(pos.x, pos.y, size.x, size.y);
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
			ofNotifyEvent(pressedEvt, args.button);
		}
		else
		{
			pressed = false;
		}
	}
}

void XButton::mouseReleased(ofMouseEventArgs & args)
{
	if (visible)
	{
		pressed = false;
	}
}