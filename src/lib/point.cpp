#include "header/point.hpp"
#include <cmath>
#include <iostream>

Point::Point() {
    id = 0;
    dimension = 0;
    coordinates = vector<double>();
}

Point::Point(int id, int dimension, vector<double> coordinates){
    this->id = id;
    this->dimension = dimension;
    this->coordinates = coordinates;
}

Point::Point(const Point& p){
    id = p.id;
    dimension = p.dimension;
    coordinates = p.coordinates;
}

void Point::operator=(const Point& p) {
    id = p.id;
    dimension = p.dimension;
    coordinates = p.coordinates;
}

int Point::getId(){
    return id;
}

int Point::getDimension() {
    return dimension;
}

double Point::getCoordinate(int i) {
    return coordinates[i];
}

double Point::distance(const Point& p) const {
    double sum = 0;
    for (int i = 0; i < dimension; i++) {
        sum += pow(coordinates[i] - p.coordinates[i], 2);
    }
    return sqrt(sum);
}

void Point::print(){
    cout<<"(";
    for(int i = 0; i < dimension; i++){
        cout<<coordinates[i];
        if(i != dimension - 1){
            cout<<", ";
        }
    }
    cout<<")"<<endl;
}