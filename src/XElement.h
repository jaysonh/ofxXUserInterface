#pragma once

#include "ofMain.h"

class XElement
{
public:
	 XElement();
	~XElement();

	void update();
	bool isTouched();

	void setVisible( const bool _visible );

	void setGlobalPos( const glm::vec2 _p );

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

	string      name;
	glm::vec2   pos;
	glm::vec2   globalPos;
	glm::vec2   size;
	bool        visible = false;
	ofRectangle boundBox;
	bool		touched = false;
private:

};