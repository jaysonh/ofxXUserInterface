#pragma once

#include "ofMain.h"
#include "XElement.h"

class XSlider : public XElement
{
public:
	XSlider();
	XSlider( glm::vec2 _pos, 
			 glm::vec2 _size,
			 float     _minValue = 0.0f, 
			 float     _maxValue = 1.0f  );
	~XSlider();

	void draw();

	void keyPressed (ofKeyEventArgs & args);
	void keyReleased(ofKeyEventArgs & args);

	void mousePressed(ofMouseEventArgs & args);
	void mouseDragged(ofMouseEventArgs & args);

	// public event handlers
	ofEvent <float> pressedEvt;

	// Unused mouse functions
	void mouseReleased(ofMouseEventArgs & args) {}
	void mouseMoved   (ofMouseEventArgs & args) {}
	void mouseScrolled(ofMouseEventArgs & args) {}
	void mouseEntered (ofMouseEventArgs & args) {}
	void mouseExited  (ofMouseEventArgs & args) {}

private:

	void updateValue( float _x );

	float minValue, maxValue;
	float pctVal;
};