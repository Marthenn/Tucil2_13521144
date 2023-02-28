#ifndef _POINT_HPP_
#define _POINT_HPP_

#include <vector>
#include <cmath>
using namespace std;

class Point {
    private:
        int id;
        int dimension;
        vector<double> coordinates;
    
    public:
        /**
         * @brief Construct a new Point object with default value 0 for id and dimension
         * 
         */
        Point();

        /**
         * @brief Construct a new Point object
         * 
         * @param id The id of the point
         * @param dimension The dimension of the point
         * @param coordinates The coordinates of the point
         */
        Point(int id, int dimension, vector<double> coordinates);

        /**
         * @brief Construct a new Point object from another point
         * 
         */
        Point(const Point& p);

        /**
         * @brief Assign a point to another point
         * 
         */
        void operator=(const Point& p);

        /**
         * @brief Get the Id of the point
         * 
         */
        int getId();

        /**
         * @brief Get the Dimension of the point
         * 
         */
        int getDimension();

        /**
         * @brief Get the Coordinate of the point in the i-th dimension
         * 
         */
        double getCoordinate(int i);

        /**
         * @brief The euclidean distance this point and point p
         * 
         */
        double distance(const Point& p) const;

        /**
         * @brief Print the coordinates of the point
         * 
         */
        void print();
};

#endif