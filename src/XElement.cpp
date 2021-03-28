#include "XElement.h"

XElement::XElement()
{
	ofRegisterKeyEvents  (this);
	ofRegisterMouseEvents(this);

}
XElement::~XElement()
{

}

void XElement::update()
{

} 

bool XElement::isTouched()
{
	return touched;
}
void XElement::setVisible( const bool _visible )
{
	visible = _visible;
}


void XElement::setGlobalPos(const glm::vec2 _p)
{
	globalPos = _p; 
	
	boundBox = ofRectangle(pos.x + globalPos.x, pos.y + globalPos.y, size.x, size.y);
}