def vectorsReachGoal(vectors, goalVector):

    # moves to different components as to go through unique ratios
    for start in range(components):
        for end in range(start+1, components):

            # for a single ratio
            goalRatio = goalVector[start] / goalVector[end]
            print(letterVector[start], "/", letterVector[end])
            print("    ", goalVector[start], "/", goalVector[end], " < GOAL \n")

            lesserRatio, greaterRatio, equalRatio = False, False, False

            for vector in vectors:
              ratio = vector[start] / vector[end]
              print("    ", vector[start], "/", vector[end], end =" ")

              if ratio < goalRatio:
                lesserRatio = True
                print(" < lesser \n")
                if greaterRatio:
                  continue
              elif goalRatio < ratio:
                greaterRatio = True
                print(" < greater \n")
                if lesserRatio:
                  continue
              elif goalRatio == ratio:
                equalRatio = True
                print(" < equal \n")
                continue

            if not lesserRatio or not greaterRatio:
              if not equalRatio:
                print("Above does't reach\n")
                return False
             

    # passes if all ratios pass and don't return before this is called
    print("Vector reaches goal")
    return True 
    

vectors = [[8,2,4], [1,2,16]]
goalVector = [9,4,20]
letterVector = ["i","j","k"]
components = len(goalVector)

print("goalVector", goalVector, "\n")
print("vectors", vectors, "\n")      

import time
start_time = time.time()
temp0 = vectorsReachGoal(vectors, goalVector)
print("\n --- %s seconds ---" % (time.time() - start_time))

print("\n\n\n Assert testing \n")
assert temp0, True

temp1 = vectorsReachGoal([[8,2,4], [1,2,16], [1,2,3]], [9,4,200])
assert temp1 == False , "Failed testing"

temp2 = vectorsReachGoal([[8,2,4], [1,2,16], [1,2,3]], [9,4,200])
assert temp2 == False , "Failed testing"

temp3 = vectorsReachGoal([[5,3,9], [3,5,7], [1,2,3]], [15,4,20])
assert temp3 == False , "Failed testing"

temp4 = vectorsReachGoal([[15,4,20]], [15,4,20])
assert temp4, "Failed testing"

"""

goalVector [9, 4, 20] 

vectors [[8, 2, 4], [1, 2, 16]] 

i / j
     9 / 4  < GOAL 

     8 / 2  < greater 

     1 / 2  < lesser 

i / k
     9 / 20  < GOAL 

     8 / 4  < greater 

     1 / 16  < lesser 

j / k
     4 / 20  < GOAL 

     2 / 4  < greater 

     2 / 16  < lesser 


 --- 0.002755880355834961 seconds ---

 vectorsReachGoal: True



 Assert testing 

i / j
     9 / 4  < GOAL 

     8 / 2  < greater 

     1 / 2  < lesser 

     1 / 2  < lesser 

i / k
     9 / 200  < GOAL 

     8 / 4  < greater 

     1 / 16  < greater 

     1 / 3  < greater 

FAILED

i / j
     9 / 4  < GOAL 

     8 / 2  < greater 

     1 / 2  < lesser 

     1 / 2  < lesser 

i / k
     9 / 200  < GOAL 

     8 / 4  < greater 

     1 / 16  < greater 

     1 / 3  < greater 

FAILED

i / j
     15 / 4  < GOAL 

     5 / 3  < lesser 

     3 / 5  < lesser 

     1 / 2  < lesser 

FAILED

i / j
     15 / 4  < GOAL 

     15 / 4  < equal 

i / k
     15 / 20  < GOAL 

     15 / 20  < equal 

j / k
     4 / 20  < GOAL 

     4 / 20  < equal 

"""
