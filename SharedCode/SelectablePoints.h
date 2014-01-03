#pragma once

#include "EventWatcher.h"
#include "DraggablePoint.h"

class SelectablePoints : public EventWatcher {
protected:
	vector<DraggablePoint> points;
	set<unsigned int> selected;
	float pointSize, clickRadiusSquared;
	
public:
	SelectablePoints()
	:clickRadiusSquared(0) {
	}
	unsigned int size() {
		return points.size();
	}
	void add(const ofVec2f& v) {
		points.push_back(DraggablePoint());
		points.back().position = v;
        points.back().modelPoint = v;
	}
    DraggablePoint get(int i){
        return points[i];
    }
    
	void setClickRadius(float clickRadius) {
		this->clickRadiusSquared = clickRadius * clickRadius;
	}
	void mousePressed(ofMouseEventArgs& mouse) {
		bool shift = ofGetKeyPressed(OF_KEY_SHIFT);
		bool hitAny = true;
		for(int i = 0; i < size(); i++) {
			bool hit = points[i].isHit(mouse, clickRadiusSquared);
			if(hit && !hitAny) {
				if(!points[i].selected) {
					points[i].selected = true;
					selected.insert(i);
					hitAny = true;
				}
			} else if(!shift) {
				points[i].selected = false;
				selected.erase(i);
			}
		}
	}
	void draw(){
		for(int i = 0; i < size(); i++) {
			points[i].draw(clickRadiusSquared);
		}
	}
};