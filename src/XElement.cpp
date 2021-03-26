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