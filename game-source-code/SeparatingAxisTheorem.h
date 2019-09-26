#ifndef SEPARATINGAXISTHEOREM_H_
#define SEPARATINGAXISTHEOREM_H_
#include "HitBox.h"
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
using two_floats = std::tuple<float, float>;
using std::vector;
using std::tuple;

/** \class SeparatingAxisTheorem
 * \brief This class uses the Separating Axis Theorem to check for collisions
 * between two game objects.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class SeparatingAxisTheorem
{
public:
	SeparatingAxisTheorem();
	/** This method takes the HitBoxes of two game objects and returns true if they
	 * overlap.
	 * \param obj_1 of type HitBox
	 * \param obj_2 of type HitBox
	 * \return bool
	 */
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
