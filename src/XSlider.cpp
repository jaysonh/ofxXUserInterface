#include "XSlider.h"

XSlider::XSlider()
{

}

XSlider::XSlider( glm::vec2 _pos, glm::vec2 _size, float _minValue, float _maxValue)
{
	pos  = _pos;
	size = _size;

	minValue = _minValue;
	maxValue = _maxValue;

	boundBox = ofRectangle( pos.x, pos.y, size.x, size.y );
	visible = true;

	pctVal = 0.0;
}

XSlider::~XSlider()
{

}

void XSlider::draw()
{
	// draw background of slider
	ofSetColor(125,0,0);
	ofDrawRectangle(pos.x, pos.y, size.x, size.y);

	// Draw foreground of slider
	ofSetColor(255, 0, 0);
	ofDrawRectangle(pos.x, pos.y, size.x * pctVal, size.y);
}

void XSlider::keyPressed(ofKeyEventArgs & args)
{
}
void XSlider::keyReleased(ofKeyEventArgs & args)
{
}

void XSlider::mouseDragged(ofMouseEventArgs & args)
{
	if (visible)
	{
		if (boundBox.inside(args.x, args.y))
		{
			updateValue(args.x);
		}
	}
}

void XSlider::mousePressed(ofMouseEventArgs & args)
{
	if (visible)
	{
		if (boundBox.inside(args.x, args.y))
		{
			updateValue( args.x );			
		}
	}
}

void XSlider::updateValue(float _x)
{
	pctVal = ofMap(_x, pos.x, pos.x + size.x, minValue, maxValue, true);
	if (_x == pos.x+1) pctVal = 0.0;
	if (_x == pos.x + size.x - 1) pctVal = 1.0;
	ofNotifyEvent(pressedEvt, pctVal);
}