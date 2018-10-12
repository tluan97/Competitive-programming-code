/*
	RECT_IN_RECT
	tested
*/
#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;

// Checks if rectangle of sides x,y fits inside one of sides X,Y
// Not tested with doubles but should work fine :)
// Code as written rejects rectangles that just touch.
bool RectInRect(int X, int Y, int x, int y){
	if (Y>X) swap(Y,X);
	if (y>x) swap(y,x);
	double diagonal = sqrt(double(X)*X+double(Y)*Y);
	if (x<X && y<Y) return true;
	else if (y>=Y || x>=diagonal) return false;
	else {
		double w,theta,tMin=PI/4,tMax=PI/2;
		while (tMax-tMin>eps){
			theta = (tMax+tMin)/2.0;
			w = (Y-x*cos(theta))/sin(theta);
			if (w<0 || x*sin(theta)+w*cos(theta)<X) tMin=theta;
			else tMax=theta;
		}
		return (w>y);
	}
}

void testRectInRect(){
	assert(RectInRect(2,2,1,1)==true);
	assert(RectInRect(5,4,3,2)==true);
	assert(RectInRect(4,4,3,3)==true);
	assert(RectInRect(2,4,3,2)==false);
	assert(RectInRect(1,1,1,1)==false);
}
int main(){
	testRectInRect();
}
