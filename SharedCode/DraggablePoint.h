#pragma once

class DraggablePoint {
public:
	ofVec2f position, positionStart;
    ofVec2f modelPosition;
	bool selected, dragging;
	
	DraggablePoint()
	:selected(false)
	,dragging(false) {
	}
	bool isHit(ofVec2f v, float clickRadiusSquared) {
		return position.distanceSquared(v) < clickRadiusSquared;
	}
	void draw(float clickRadiusSquared) {
		float r = sqrt(clickRadiusSquared);
		ofPushStyle();
		ofNoFill();
		ofSetLineWidth(2);
		if(selected) {
			ofSetColor(ofColor::yellow);
			ofCircle(position, r + 4);
		}
		ofPopStyle();
		ofPushStyle();
		ofFill();
		ofCircle(position, r);
		ofPopStyle();
	}
};