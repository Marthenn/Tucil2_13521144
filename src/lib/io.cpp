#include "header/io.hpp"
#include <sstream>
#include <fstream>

double random(int limit = 1000){
    unsigned long long x;
    __builtin_ia32_rdrand64_step(&x);
    return (double) (x % (int) (limit+1));
}

int validate(int min, int max){
    int x;
    while(!(cin >> x) || x < min || x > max){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please input an integer between " << min << " and " << max << ": ";
    }
    cin.clear();
    cin.ignore(1000, '\n');
    return x;
}

bool validate(double x){
    return x >= 0 && x <= 1000;
}

bool validate(string input, int dimension){
    /*
        cin.clear() and cin.ignore() is used to clear the input buffer
    */

    stringstream ss(input);
    string coordinate;
    int count = 0;
    while(ss >> coordinate){
        double x;
        try{
            x = stod(coordinate);
        } catch (const std::invalid_argument& ia) {
            cin.clear();
            cin.ignore(1000, '\n');
            return false;
        }
        if(!validate(x)){
            cin.clear();
            cin.ignore(1000, '\n');
            return false;
        }
        count++;
    }
    if(count != dimension){
        return false;
    }
    cin.clear();
    cin.ignore(1000, '\n');
    return true;
}

vector<Point> randomPoints(int dimension, int n){
    vector<Point> points;
    for(int i = 0; i < n; i++){
        vector<double> coordinates;
        for(int j = 0; j < dimension; j++){
            double x = random();
            coordinates.push_back(x);
        }
        Point p(i, dimension, coordinates);
        points.push_back(p);
    }
    return points;
}

vector<Point> readPoints(int dimension, int n){
    cout << "Input " << n << " points in " << dimension << " dimension" << endl;
    vector<Point> points;
    for(int i = 0; i < n; i++){
        cout << "Point " << i+1 << ": ";
        string input;
        getline(cin, input);
        while(!validate(input, dimension)){
            cout << "Invalid input" << endl;
            cout << "Point " << i+1 << ": ";
            getline(cin, input);
        }
        stringstream ss(input);
        string coordinate;
        vector<double> coordinates;
        while(ss >> coordinate){
            double x = stod(coordinate);
            coordinates.push_back(x);
        }
        Point p(i, dimension, coordinates);
        points.push_back(p);
    }
    return points;
}

vector<Point> readPoints(string filename){
    ifstream file(filename);
    string line;
    vector<Point> points;
    int dimension;
    int n = 0;
    while(getline(file, line)){
        stringstream ss(line);
        string coordinate;
        vector<double> coordinates;
        int count = 0;
        while(ss >> coordinate){
            double x;
            try{
                x = stod(coordinate);
            } catch (const std::invalid_argument& ia) {
                cout << "Invalid input" << endl;
                exit(1);
            }
            if(!validate(x)){
                cout << "Invalid input" << endl;
                exit(1);
            }
            coordinates.push_back(x);
            count++;
        }
        if(n == 0){
            dimension = count;
        }
        if(count != dimension){
            cout << "Invalid input" << endl;
            exit(1);
        }
        Point p(n, dimension, coordinates);
        points.push_back(p);
        n++;
        if(n > 5000){
            cout << "Too many points" << endl;
            cout << "Please input less than 5000 points" << endl;
            exit(1);
        }
    }
    return points;
}

void plotPoints(vector<Point> points, pair<Point, Point> closestPair){
    cout << "Plotting the points and the closest pair" << endl;
    ofstream file("test/plot.py");
    file << "import matplotlib.pyplot as plt" << endl;
    file << "import numpy as np" << endl;
    file << "import math" << endl;
    file << "x = []" << endl;
    file << "y = []" << endl;
    if(points[0].getDimension() == 3){
        file << "z = []" << endl;
        for(int i = 0; i < points.size(); i++){
            if(points[i].getId() != closestPair.first.getId() && points[i].getId() != closestPair.second.getId()){
                file << "x.append(" << points[i].getCoordinate(0) << ")" << endl;
                file << "y.append(" << points[i].getCoordinate(1) << ")" << endl;
                file << "z.append(" << points[i].getCoordinate(2) << ")" << endl;
            }
        }
        file << "fig = plt.figure()" << endl;
        file << "ax = fig.add_subplot(111, projection='3d')" << endl;
        file << "ax.scatter(x, y, z)" << endl;
        file << "ax.scatter([" << closestPair.first.getCoordinate(0) << ", " << closestPair.second.getCoordinate(0) << "], [" << closestPair.first.getCoordinate(1) << ", " << closestPair.second.getCoordinate(1) << "], [" << closestPair.first.getCoordinate(2) << ", " << closestPair.second.getCoordinate(2) << "], color='red')" << endl;
    }
    if(points[0].getDimension() == 2){
        for(int i = 0; i < points.size(); i++){
            if(points[i].getId() != closestPair.first.getId() && points[i].getId() != closestPair.second.getId()){
                file << "x.append(" << points[i].getCoordinate(0) << ")" << endl;
                file << "y.append(" << points[i].getCoordinate(1) << ")" << endl;
            }
        }
        file << "plt.scatter(x, y)" << endl;
        file << "plt.scatter([" << closestPair.first.getCoordinate(0) << ", " << closestPair.second.getCoordinate(0) << "], [" << closestPair.first.getCoordinate(1) << ", " << closestPair.second.getCoordinate(1) << "], color='red')" << endl;
    }
    file << "plt.savefig('test/plot.png')" << endl;
    file.close();
    system("python test/plot.py");
    cout << "The points are plotted" << endl;
}