#ifndef SEPERATINGAXISTHEOREM_H_
#define SEPERATINGAXISTHEOREM_H_
#include "HitBox.h"
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
using two_floats = std::tuple<float, float>;
using std::vector;
using std::tuple;

class SeperatingAxisTheorem
{
public:
	SeperatingAxisTheorem();
	bool isOverlapping(HitBox& obj_1, HitBox& obj_2);
private:
	vector<two_floats> axis_;
	vector<two_floats> vertecies_obj_1_;
	vector<two_floats> vertecies_obj_2_;
	void makeAxes();
	float getDotProduct(const two_floats& pointA, const two_floats& pointB);
	two_floats normalizeAxis(two_floats & axis);
	two_floats projection(const two_floats & axis, vector<two_floats>& verticies);
	bool checkProjectionOverLap();
	void clearAll();


};

#endif
