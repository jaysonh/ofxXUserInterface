#pragma once

#include "ofMain.h"
#include "XElement.h"
#include "XButtonSkin.h"

class XButton : public XElement
{
public:
	XButton();
	XButton( glm::vec2 _pos, glm::vec2 _size, string _name );
	~XButton();

	void draw();
	void keyPressed(ofKeyEventArgs & args);
	void keyReleased(ofKeyEventArgs & args);

	void mousePressed (ofMouseEventArgs & args);
	void mouseReleased(ofMouseEventArgs & args);
	void mouseMoved(ofMouseEventArgs & args);

	void addSkin(XButtonSkin * _skin);

	// Unused mouse functions
	void mouseDragged (ofMouseEventArgs & args){}
	void mouseScrolled(ofMouseEventArgs & args){}
	void mouseEntered (ofMouseEventArgs & args){}
	void mouseExited  (ofMouseEventArgs & args){}

	// public event handlers
	ofEvent <int> pressedEvt;
	ofJson getJson();
	void   setJson(ofJson json);

private:

	bool pressed   = false;
	bool mouseOver = false;
	XButtonSkin * skin;
	bool useSkin = false;
};