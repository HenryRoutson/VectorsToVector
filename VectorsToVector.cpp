#include <iostream>
#include <vector>
#include <chrono>
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

    for (int i = 0; i < vectors.size(); i++) {
        vector<float> vector = vectors[i];
        float ratio = vector[component_one] / vector[component_two];
        cout << "\n    " << vector[component_one] << "/" << vector[component_two];

        if (ratio < goalRatio) {
            lesserRatio = true;
            cout << " < lesser \n";
            if (greaterRatio) { return true; }
        }
        else if (goalRatio < ratio) {
            greaterRatio = true;
            cout << " < greater \n";
            if (lesserRatio) { return true; }
        }
        else {
            cout << " < equal \n";
            return true;
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
    

    for (int component_one = 0; component_one < goalVector.size(); component_one++) {
        for (int component_two = 1+component_one; component_two < goalVector.size(); component_two++) {
            assert (component_one<component_two);

            if (testRatio(vectors,goalVector,component_one,component_two) == false) {
                cout << "\n vectorsReachGoal(...) = false \n\n\n\n\n\n";
                return false;
            }
        }
    }
    cout << "\n vectorsReachGoal(...) = true \n\n\n\n\n\n";
    return true;
}

int main(int argc, const char * argv[]) {
    
    clock_t start_time = clock();
    
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
    
    clock_t end_time1 = clock();
    clock_t result = end_time1 - start_time;
    cout << " --- " << result <<" milliseconds ---" << endl;

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





--- 0 seconds ---
Program ended with exit code: 0

*/
