#pragma once

#include "ofMain.h"

class XElement
{
public:
	 XElement();
	~XElement();

	void update();
	virtual void draw() =0;

	virtual void keyPressed  (ofKeyEventArgs & args) = 0;
	virtual void keyReleased (ofKeyEventArgs & args) = 0;

	virtual void mouseDragged  (ofMouseEventArgs & args) = 0;
	virtual void mousePressed  (ofMouseEventArgs & args) = 0;
	virtual void mouseReleased (ofMouseEventArgs & args) = 0;
	virtual void mouseMoved    (ofMouseEventArgs & args) = 0;
	virtual void mouseScrolled (ofMouseEventArgs & args) = 0;
	virtual void mouseEntered  (ofMouseEventArgs & args) = 0;
	virtual void mouseExited   (ofMouseEventArgs & args) = 0;
	
protected:

	glm::vec2   pos;
	glm::vec2   size;
	bool        visible = false;
	ofRectangle boundBox;
private:

};