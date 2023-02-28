#include "lib/header/io.hpp"
#include "lib/header/solver.hpp"
#include <chrono>
#include <numeric>

int main(){
    int dimension;
    int num;
    cout << "Enter dimension: "; cin >> dimension;
    cout << "Enter number of points: "; cin >> num;
    vector<int> bestBounds;
    vector<Point> points = randomPoints(dimension, num);
    int primeBound;
    int dummy = 0;
    int iterations;
    cout << "Enter number of iterations: "; cin >> iterations;
    pair<Point, Point> dummyPair;
    for(int k = 0; k < iterations; k++){
        // cout << "Iteration: " << k+1 << endl;
        auto primeDuration = chrono::duration<double, milli>(1000000000).count();
        for(int i = 3; i < 100; i++){
            // cout << "Bound: " << i << endl;
            auto start = chrono::high_resolution_clock::now();
            dummyPair = bruteForce(points, dummy);
            dummy = 0;
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration<double, milli>(end - start).count();
            // cout << "BruteForce: " << duration << " ms" << endl;
            auto start2 = chrono::high_resolution_clock::now();
            dummyPair = divideConquer(points, dummy, i);
            dummy = 0;
            auto end2 = chrono::high_resolution_clock::now();
            auto duration2 = chrono::duration<double, milli>(end2 - start2).count();
            // cout << "DivideConquer: " << duration2 << " ms" << endl;
            if(duration2 < duration && (duration2 - duration) < primeDuration){
                primeBound = i;
                primeDuration = duration2 - duration;
            }
            // cout << "----------------\n";
        }
        // cout << "Best :" << primeBound << endl;
        bestBounds.push_back(primeBound);
    }
    double avg = accumulate(bestBounds.begin(), bestBounds.end(), 0.0) / bestBounds.size();
    int count[10] = {0};
    for(auto i : bestBounds){
        count[i/10]++;
    }
    for(int i = 0 ; i< 10; i++){
        cout << i*10 << " - " << (i+1)*10 << ": " << count[i] << endl;
    }
    cout << "Average: " << avg << endl;
    cout << "Median: " << bestBounds[bestBounds.size()/2] << endl;
    return 0;
}