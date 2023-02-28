#ifndef _IO_HPP_
#define _IO_HPP_

#include "point.hpp"
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Validate whether the input is a number between min and max
 * 
 */
int validate(int min, int max);

/**
 * @brief Generate n random points in the dimension
 * 
 */
vector<Point> randomPoints(int dimension, int n);

/**
 * @brief Read n points from the standard input
 *  
 */
vector<Point> readPoints(int dimension, int n);

/**
 * @brief Read n points from the file with assumption that the file is in the format
 * 
 */
vector<Point> readPoints(string filename);

/**
 * @brief Plot the points and the closest pair
 * 
 */
void plotPoints(vector<Point> points, pair<Point, Point> closestPair);

#endif