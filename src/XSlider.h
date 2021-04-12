#pragma once

#include "ofMain.h"
#include "XElement.h"
#include "XSliderSkin.h"

class XSlider : public XElement
{
public:
	//XSlider();
	XSlider( glm::vec2            _pos, 
			 glm::vec2            _size,
			 string               _name,
			 float *			  _p,
			 float                _minValue = 0.0f, 
			 float                _maxValue = 1.0f  );
	~XSlider();

	void draw();
	ofJson getJson();
	void   setJson(ofJson json);

	void keyPressed (ofKeyEventArgs & args);
	void keyReleased(ofKeyEventArgs & args);

	void mousePressed(ofMouseEventArgs & args);
	void mouseDragged(ofMouseEventArgs & args);

	void addSkin( XSliderSkin * _skin );

	// public event handlers
	ofEvent <float> pressedEvt;

	float getValue();

	// Unused mouse functions
	void mouseReleased(ofMouseEventArgs & args) {}
	void mouseMoved   (ofMouseEventArgs & args) {}
	void mouseScrolled(ofMouseEventArgs & args) {}
	void mouseEntered (ofMouseEventArgs & args) {}
	void mouseExited  (ofMouseEventArgs & args) {}

private:
	void updateValue(float _x);

	float * value;
	XSliderSkin * skin;
	bool useSkin = false;
	float minValue, maxValue;
	float pctVal;
};