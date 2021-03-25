#include "ofxXUserInterface.h"

#include "XSlider.h"
#include "XButton.h"

void ofxXUserInterface::init()
{
	elementList.clear(); // empty list of ui elements

	ofRegisterKeyEvents(this); // listen for key events
}

void ofxXUserInterface::draw()
{
	if (visible)
	{
		for (auto e : elementList)
		{
			e->draw();
		}
	}
}

void ofxXUserInterface::update()
{

}

shared_ptr<XButton> ofxXUserInterface::addButton(glm::vec2 pos, glm::vec2 size)
{
	shared_ptr<XButton> btn = make_shared<XButton>( pos, size );

	elementList.push_back(btn);

	return btn;
}

shared_ptr<XSlider> ofxXUserInterface::addSlider(glm::vec2 pos, glm::vec2 size)
{
	shared_ptr<XSlider> slider = make_shared<XSlider>(pos, size);

	elementList.push_back( slider );

	return slider;
}

void ofxXUserInterface::toggleVisible()
{
	visible = !visible;
}

void ofxXUserInterface::keyPressed(ofKeyEventArgs & args)
{
	if (args.key == '\t') // tab key 
	{
		toggleVisible();
	}
}

void ofxXUserInterface::keyReleased(ofKeyEventArgs & args)
{

}