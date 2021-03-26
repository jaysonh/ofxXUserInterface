#pragma once

#include "ofMain.h"
#include "XElement.h"
#include "XGlobals.h"

class XSlider;
class XButton;
// Custom user interface class
// allows for nice looking buttons and sliders
class ofxXUserInterface
{
public:

	void init();
	void draw();
	void update();

	void toggleVisible();

	void keyPressed (ofKeyEventArgs & args);
	void keyReleased(ofKeyEventArgs & args);

	bool isTouched();

	shared_ptr < XButton > addButton( glm::vec2 pos, glm::vec2 size );
	shared_ptr < XSlider > addSlider( glm::vec2 pos, glm::vec2 size, float * p, float _min= 0.0, float _max =1.0 );

private:

	bool visible = DEFAULT_VISIBLE_STATUS;
	bool touched = false;
	vector < shared_ptr< XElement > > elementList;
};