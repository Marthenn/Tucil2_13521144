#ifndef _SOLVER_HPP_
#define _SOLVER_HPP_

#include "point.hpp"
#include <vector>
#include <utility>
using namespace std;

/**
 * @brief Sort the points based on the coordinate of the (k+1)-th dimension
 * 
 */
void qSort(vector<Point>& points, int left, int right, int k);

/**
 * @brief Find the closest pair of points using brute force
 * 
 * @param points Vector of points
 * @param count Number of distance calculation
 * @return pair<Point, Point> of the closest pair of points
 */
pair<Point, Point> bruteForce(vector<Point>& points, int& count);

/**
 * @brief Find the closest pair of points using divide and conquer
 * 
 * @param points Vector of points
 * @param count Number of distance calculation
 * @param bound The boundary of number of points before using brute force
 * @return pair<Point, Point> of the closest pair of points
 */
pair<Point, Point> divideConquer(vector<Point>& points, int& count, int bound);

#endif