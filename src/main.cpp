#include "lib/header/io.hpp"
#include "lib/header/solver.hpp"
#include <chrono>

int main(){
    int n;
    cout<<"Input options:\n 1. Random points\n 2. Read from file\n 3. Read from standard input\n";
    cout<<"Enter your choice: "; int ans = validate(1,3);
    vector<Point> points;
    string filename;
    int dimension;
    switch(ans){
        case 1:
            cout<<"Enter number of points(2-5000): "; n = validate(2,5000);
            cout<<"Enter dimension(1-100): "; dimension = validate(1, 100);
            points = randomPoints(dimension, n);
            break;
        case 2:
            cout<<"Enter file name: "; cin>>filename;
            points = readPoints(filename);
            break;
        case 3:
            cout<<"Enter number of points(2-5000): "; n = validate(2,5000);
            cout<<"Enter dimension(1-100): "; dimension = validate(1, 100);
            points = readPoints(dimension, n);
            break;
        default:
            cout<<"Invalid input"<<endl;
            exit(1);
    }
    
    cout<<"Enter number of points before using brute force (min 3): "; int bound = validate(3, INT_MAX);

    int count = 0;
    auto start = chrono::high_resolution_clock::now();
    pair<Point, Point> closestPair = bruteForce(points, count);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration<double, milli>(end - start).count();
    cout << "Number of operations: " << count << endl;
    cout << "Closest pair of points: " << closestPair.first.getId() << " and " << closestPair.second.getId() << endl;
    cout << "Coordinate of the first point: "; closestPair.first.print();
    cout << "Coordinate of the second point: "; closestPair.second.print();
    cout << "Distance: " << closestPair.first.distance(closestPair.second) << endl;
    cout << duration << " ms" << endl;

    count = 0;
    start = chrono::high_resolution_clock::now();
    closestPair = divideConquer(points, count, bound);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration<double, milli>(end - start).count();
    cout << "Number of operations: " << count << endl;
    cout << "Closest pair of points: " << closestPair.first.getId() << " and " << closestPair.second.getId() << endl;
    cout << "Coordinate of the first point: "; closestPair.first.print();
    cout << "Coordinate of the second point: "; closestPair.second.print();
    cout << "Distance: " << closestPair.first.distance(closestPair.second) << endl;
    cout << duration << " ms" << endl;

    cout << "Ran on AMD Ryzen 5 4500U 6-Core Processor 2.40 GHz with 8 GB of RAMs\n";

    if(points[0].getDimension() == 2 || points[0].getDimension() == 3){
        cout << "Do you want to plot the points?\n 1. Yes\n 2. No\n";
        cout << "Enter your choice: "; ans = validate(1,2);
        if(ans == 1){
            plotPoints(points, closestPair);
        }
    }
    return 0;
}