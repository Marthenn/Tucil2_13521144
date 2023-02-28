#include "header/solver.hpp"
#include <cfloat>

void swap(vector<Point>& points, int i, int j){
    Point temp = points[i];
    points[i] = points[j];
    points[j] = temp;
}

double min(double a, double b){
    return a < b ? a : b;
}

int partition(vector<Point>& points, int left, int right, int k){
    int pivot = left;
    int count = 0;

    for(int i = left + 1; i <= right; i++){
        if(points[i].getCoordinate(k) < points[pivot].getCoordinate(k)){
            count++;
        }
    }

    swap(points, pivot, left + count);

    int i = left, j = right;
    int idx = left + count;

    while(i < idx && j > idx){
        if(points[i].getCoordinate(k) < points[idx].getCoordinate(k)){
            i++;
        } else if(points[j].getCoordinate(k) > points[idx].getCoordinate(k)){
            j--;
        } else {
            swap(points, i, j);
            i++;
            j--;
        }
    }

    return idx;
}

void qSort(vector<Point>& points, int left, int right, int k){
    if(left >= right){
        return;
    }

    int pivot = partition(points, left, right, k);

    qSort(points, left, pivot - 1, k);
    qSort(points, pivot + 1, right, k);
}

pair<Point, Point> bruteForce(vector<Point>& points, int& count){
    double minDistance = DBL_MAX;
    Point p1, p2;

    for(int i = 0; i < points.size(); i++){
        for(int j = i + 1; j < points.size(); j++){
            count++;
            double distance = points[i].distance(points[j]);
            if(distance < minDistance){
                minDistance = distance;
                p1 = points[i];
                p2 = points[j];
            }
        }
    }

    return make_pair(p1, p2);
}

pair<Point, Point> divideUtil(vector<Point>& points, int& count, int bound){
    if(points.size() <= bound || points[0].getDimension() == 1){
        return bruteForce(points, count);
    }

    int mid = points.size() / 2;
    vector<Point> left(points.begin(), points.begin() + mid);
    vector<Point> right(points.begin() + mid, points.end());

    pair<Point, Point> leftPair = divideUtil(left, count, bound);
    pair<Point, Point> rightPair = divideUtil(right, count, bound);

    Point p1, p2;
    double minDistance;
    if(leftPair.first.distance(leftPair.second) < rightPair.first.distance(rightPair.second)){
        p1 = leftPair.first;
        p2 = leftPair.second;
        minDistance = leftPair.first.distance(leftPair.second);
    } else {
        p1 = rightPair.first;
        p2 = rightPair.second;
        minDistance = rightPair.first.distance(rightPair.second);
    }

    vector<Point> strip;
    for(int i = 0; i < points.size(); i++){
        if(abs(points[i].getCoordinate(0) - points[mid].getCoordinate(0)) < minDistance){
            strip.push_back(points[i]);
        }
    }

    // qSort(strip, 0, strip.size() - 1, 1);

    for(int i = 0; i < strip.size(); i++){
        //for(int j = i + 1; j < strip.size() && (strip[j].getCoordinate(1) - strip[i].getCoordinate(1)) < minDistance; j++){
        for(int j = i + 1; j < strip.size(); j++){
            count++;
            double distance = strip[i].distance(strip[j]);
            if(distance < minDistance){
                minDistance = distance;
                p1 = strip[i];
                p2 = strip[j];
            }
        }
    }
    return(make_pair(p1, p2));
}

pair<Point, Point> divideConquer(vector<Point>& points, int& count, int bound){
    qSort(points, 0, points.size() - 1, 1);
    return divideUtil(points, count, bound);
}