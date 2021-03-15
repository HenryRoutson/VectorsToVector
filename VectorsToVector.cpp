#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

bool testRatio(vector< vector<float> > vectors, vector<float> goalVector, int component_one, int component_two) {

    if (goalVector.size() <= 3) {
        vector<string> letterVector = {"i","j","k"};
        cout << "\n\n" << letterVector[component_one] << "/" << letterVector[component_two];
    }

    float goalRatio = goalVector[component_one] / goalVector[component_two];
    cout << "\n\n    " << goalVector[component_one] << "/" << goalVector[component_two] << " < GOAL \n";

    bool lesserRatio = false;
    bool greaterRatio = false;

    // test if the ratio fits within the ratio range of the vectors
    for (int i = 0; i < vectors.size(); i++) {
        vector<float> vector = vectors[i];
        float ratio = vector[component_one] / vector[component_two];
        cout << "\n    " <<  vector[component_one] << "/" << vector[component_two];

        if (ratio < goalRatio) {
            lesserRatio = true;
            cout << " < lesser \n";
            if (greaterRatio) { return true; } // next ratio
        }
        else if (goalRatio < ratio) {
            greaterRatio = true;
            cout << " < greater \n";
            if (lesserRatio) { return true; } // next ratio
        }
        else {
            cout << " < equal \n";
            return true; // next ratio
        };
    }

    return false;
}

bool vectorsReachGoal(vector< vector<float> > vectors, vector<float> goalVector) {

    // printing vector
    
    cout << "\n goalVector:  {";
    for (int y = 0; y < goalVector.size(); y++) {
        cout << goalVector.at(y);
        if (y != goalVector.size()-1) {cout << ",";}
    }
    cout << "} ";
    
    cout << "\n vectors:  {";
    for (int x = 0; x < vectors.size(); x++) {
        cout << " {";
        for (int y = 0; y < vectors.at(x).size(); y++) {
            cout << vectors.at(x).at(y);
            if (y != vectors.at(x).size()-1)
                cout << ",";
        }
        cout << "} ";
        if (x != vectors.size()-1) {cout << ","; }
    }
    cout << "}";
    
    // moves to different components as to go through unique ratios
    for (int component_one = 0; component_one < goalVector.size(); component_one++) {
        for (int component_two = 1+component_one; component_two < goalVector.size(); component_two++) {
            assert (component_one<component_two);

            if (testRatio(vectors,goalVector,component_one,component_two) == false) {
                cout << "\n vectorsReachGoal(...) = false \n\n\n\n\n\n";
                return false;
            }
        }
    }
    
    // returns true if no ratios return false
    cout << "\n vectorsReachGoal(...) = true \n\n\n\n\n\n";
    return true;
}

int main(int argc, const char * argv[]) {
    
    clock_t start_time = clock();
    
    // test https://www.wolframalpha.com/input/?i=a*%281%2C2%2C3%29%2Bb*%281%2C2%2C3%29%2Bc*%281%2C2%2C3%29%2Bd*%281%2C2%2C3%29%3D%281%2C23%29
    // (remember that scale values can always be set to 0) https://www.wolframalpha.com/input/?i=a*%285%2C3%29%2Bb*%2815%2C4%29%2Bc*%2815%2C4%29%3D%285%2C3%29
    
    // visualize https://www.geogebra.org
    
    assert ( vectorsReachGoal( {{8,2,4},{1,2,16}}, {9,4,20}) );
    assert ( vectorsReachGoal( {{8,2,4},{1,2,16}, {1,2,3}}, {9,4,200}) == false );
    assert ( vectorsReachGoal( {{8,2,4},{1,2,16}, {1,2,3}}, {9,4,200}) == false );
    assert ( vectorsReachGoal( {{5,3,9},{3,5,7}, {1,2,3}}, {15,4,20}) == false );
    assert ( vectorsReachGoal( {{15,4,20}}, {15,4,20}) );
    assert ( vectorsReachGoal( {{2,2}}, {3,3} ) );
    assert ( vectorsReachGoal( {{2,2},{3,5},{5,3}}, {3,3}) );
    assert ( vectorsReachGoal( {{1,1},{2,2},{3,3}}, {5,5}) );
    assert ( vectorsReachGoal( {{2,2},{3,3}}, {1,5}) == false );
    assert ( vectorsReachGoal( {{2,2,2},{3,3,3}}, {1,5,1}) == false );
    assert ( vectorsReachGoal( {{15,4},{5,3}}, {5,3}) );
    
    cout << " --- " << (clock() - start_time) <<" milliseconds ---" << endl;

    return 0;
}

/*


goalVector:  {9,4,20}
vectors:  { {8,2,4} , {1,2,16} }

i/j

   9/4 < GOAL

   8/2 < greater

   1/2 < lesser


i/k

   9/20 < GOAL

   8/4 < greater

   1/16 < lesser


j/k

   4/20 < GOAL

   2/4 < greater

   2/16 < lesser

vectorsReachGoal(...) = true






goalVector:  {9,4,200}
vectors:  { {8,2,4} , {1,2,16} , {1,2,3} }

i/j

   9/4 < GOAL

   8/2 < greater

   1/2 < lesser


i/k

   9/200 < GOAL

   8/4 < greater

   1/16 < greater

   1/3 < greater

vectorsReachGoal(...) = false






goalVector:  {9,4,200}
vectors:  { {8,2,4} , {1,2,16} , {1,2,3} }

i/j

   9/4 < GOAL

   8/2 < greater

   1/2 < lesser


i/k

   9/200 < GOAL

   8/4 < greater

   1/16 < greater

   1/3 < greater

vectorsReachGoal(...) = false






goalVector:  {15,4,20}
vectors:  { {5,3,9} , {3,5,7} , {1,2,3} }

i/j

   15/4 < GOAL

   5/3 < lesser

   3/5 < lesser

   1/2 < lesser

vectorsReachGoal(...) = false






goalVector:  {15,4,20}
vectors:  { {15,4,20} }

i/j

   15/4 < GOAL

   15/4 < equal


i/k

   15/20 < GOAL

   15/20 < equal


j/k

   4/20 < GOAL

   4/20 < equal

vectorsReachGoal(...) = true






goalVector:  {3,3}
vectors:  { {2,2} }

i/j

   3/3 < GOAL

   2/2 < equal

vectorsReachGoal(...) = true






goalVector:  {3,3}
vectors:  { {2,2} , {3,5} , {5,3} }

i/j

   3/3 < GOAL

   2/2 < equal

vectorsReachGoal(...) = true






goalVector:  {5,5}
vectors:  { {1,1} , {2,2} , {3,3} }

i/j

   5/5 < GOAL

   1/1 < equal

vectorsReachGoal(...) = true






goalVector:  {1,5}
vectors:  { {2,2} , {3,3} }

i/j

   1/5 < GOAL

   2/2 < greater

   3/3 < greater

vectorsReachGoal(...) = false






goalVector:  {1,5,1}
vectors:  { {2,2,2} , {3,3,3} }

i/j

   1/5 < GOAL

   2/2 < greater

   3/3 < greater

vectorsReachGoal(...) = false






goalVector:  {5,3}
vectors:  { {15,4} , {5,3} }

i/j

   5/3 < GOAL

   15/4 < greater

   5/3 < equal

vectorsReachGoal(...) = true





 --- 293 milliseconds ---
Program ended with exit code: 0

*/

// run on MacBook Air M1, 16gb, 2020
// In xcode
