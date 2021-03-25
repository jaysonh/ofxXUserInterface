#pragma once

#include "ofMain.h"
#include "XElement.h"

class XButton : public XElement
{
public:
	XButton();
	XButton( glm::vec2 _pos, glm::vec2 _size );
	~XButton();

	void draw();
	void keyPressed(ofKeyEventArgs & args);
	void keyReleased(ofKeyEventArgs & args);

	void mousePressed (ofMouseEventArgs & args);
	void mouseReleased(ofMouseEventArgs & args);

	// Unused mouse functions
	void mouseDragged (ofMouseEventArgs & args){}
	void mouseMoved   (ofMouseEventArgs & args){}
	void mouseScrolled(ofMouseEventArgs & args){}
	void mouseEntered (ofMouseEventArgs & args){}
	void mouseExited  (ofMouseEventArgs & args){}

	// public event handlers
	ofEvent <int> pressedEvt;

private:

	bool pressed = false;

};