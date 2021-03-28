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
		ofPushMatrix();
		ofTranslate(pos.x, pos.y);
		for (auto e : elementList)
		{
			e->draw();
		}
		ofPopMatrix();
	}
}

void ofxXUserInterface::update()
{

}

shared_ptr<XButton> ofxXUserInterface::addButton(glm::vec2 pos, glm::vec2 size, string _name)
{
	shared_ptr<XButton> btn = make_shared<XButton>( pos, size, _name );

	elementList.push_back(btn);

	return btn;
}

shared_ptr<XSlider> ofxXUserInterface::addSlider(glm::vec2 pos, glm::vec2 size, string _name, float * p, float _min, float _max )
{
	shared_ptr<XSlider> slider = make_shared<XSlider>(pos, size, _name, p, _min, _max );

	elementList.push_back( slider );

	return slider;
}

void ofxXUserInterface::toggleVisible()
{
	visible = !visible;

	for (auto e : elementList)
	{
		e->setVisible( visible );
	}

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

bool ofxXUserInterface::isTouched()
{
	touched = false;

	// if mouse is being pressed then check if any elements have been clicked
	if (ofGetMousePressed())
	{
		for (auto e : elementList)
		{
			if (e->isTouched())
				touched = true;
		}
	}
	// If the gui is not visible then it is not being touched
	return ( touched && visible );
}


void ofxXUserInterface::saveSettings(int & v)
{
	cout << "saving" << endl;
}
void ofxXUserInterface::loadSettings(int & v)
{
	cout << "loading" << endl;

}
void ofxXUserInterface::setPosition(glm::vec2 _p)
{
	pos = _p;


	for (auto e : elementList)
	{
		e->setGlobalPos( pos );
	}
}