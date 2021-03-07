def testRatio(vectors, goalVector, component_one, component_two):

    if len(goalVector) <= 3:
      letterVector = ["i","j","k"]
      print(letterVector[component_one], "/", letterVector[component_two])

    goalRatio = goalVector[component_one] / goalVector[component_two]
    print("\n    ", goalVector[component_one], "/", goalVector[component_two], " < GOAL \n")

    lesserRatio, greaterRatio = False, False

    # test if the ratio fits within the ratio range of the vectors
    for vector in vectors:
      ratio = vector[component_one] / vector[component_two]
      print("    ", vector[component_one], "/", vector[component_two], end =" ")

      if ratio < goalRatio:
        lesserRatio = True
        print(" < lesser \n")
        if greaterRatio:
          return True # next ratio
      elif goalRatio < ratio:
        greaterRatio = True
        print(" < greater \n")
        if lesserRatio:
          return True # next ratio
      else: 
        print(" < equal \n")
        return True # next ratio

    return False

def vectorsReachGoal(vectors, goalVector):

    print("\n\n\n goalVector", goalVector, "\n vectors", vectors, "\n")  

    # moves to different components as to go through unique ratios
    for component_one in range(len(goalVector)):
        for component_two in range(component_one+1, len(goalVector)):

            if not testRatio(vectors, goalVector, component_one, component_two):
              print("vectorsReachGoal(...) == False")
              return False
             
    # passes if all ratios pass and don't return false before here
    print("vectorsReachGoal(...) == True")
    return True 

import time
start_time = time.time()

# test https://www.wolframalpha.com/input/?i=a*%281%2C2%2C3%29%2Bb*%281%2C2%2C3%29%2Bc*%281%2C2%2C3%29%2Bd*%281%2C2%2C3%29%3D%281%2C23%29
# remember that scale values can always be set to 0 https://www.wolframalpha.com/input/?i=a*%285%2C3%29%2Bb*%2815%2C4%29%2Bc*%2815%2C4%29%3D%285%2C3%29

# visualize https://www.geogebra.org

assert vectorsReachGoal( [(8,2,4),(1,2,16)], (9,4,20))
assert vectorsReachGoal( [(8,2,4),(1,2,16), (1,2,3)], (9,4,200)) == False
assert vectorsReachGoal( [(8,2,4),(1,2,16), (1,2,3)], (9,4,200)) == False
assert vectorsReachGoal( [(5,3,9),(3,5,7), (1,2,3)], (15,4,20)) == False
assert vectorsReachGoal( [(15,4,20)], (15,4,20))
assert vectorsReachGoal( [(2,2)], (3,3))
assert vectorsReachGoal( [(2,2),(3,5),(5,3)], (3,3))
assert vectorsReachGoal( [(1,1),(2,2),(3,3)], (5,5))
assert vectorsReachGoal( [(2,2),(3,3)], (1,5)) == False
assert vectorsReachGoal( [(2,2,2),(3,3,3)], (1,5,1)) == False
assert vectorsReachGoal( [(15,4),(5,3)], (5,3))

print("\n --- %s seconds ---" % (time.time() - start_time))

"""



 goalVector (9, 4, 20) 
 vectors [(8, 2, 4), (1, 2, 16)] 

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

vectorsReachGoal(...) == True



 goalVector (9, 4, 200) 
 vectors [(8, 2, 4), (1, 2, 16), (1, 2, 3)] 

i / j

     9 / 4  < GOAL 

     8 / 2  < greater 

     1 / 2  < lesser 

i / k

     9 / 200  < GOAL 

     8 / 4  < greater 

     1 / 16  < greater 

     1 / 3  < greater 

vectorsReachGoal(...) == False



 goalVector (9, 4, 200) 
 vectors [(8, 2, 4), (1, 2, 16), (1, 2, 3)] 

i / j

     9 / 4  < GOAL 

     8 / 2  < greater 

     1 / 2  < lesser 

i / k

     9 / 200  < GOAL 

     8 / 4  < greater 

     1 / 16  < greater 

     1 / 3  < greater 

vectorsReachGoal(...) == False



 goalVector (15, 4, 20) 
 vectors [(5, 3, 9), (3, 5, 7), (1, 2, 3)] 

i / j

     15 / 4  < GOAL 

     5 / 3  < lesser 

     3 / 5  < lesser 

     1 / 2  < lesser 

vectorsReachGoal(...) == False



 goalVector (15, 4, 20) 
 vectors [(15, 4, 20)] 

i / j

     15 / 4  < GOAL 

     15 / 4  < equal 

i / k

     15 / 20  < GOAL 

     15 / 20  < equal 

j / k

     4 / 20  < GOAL 

     4 / 20  < equal 

vectorsReachGoal(...) == True



 goalVector (3, 3) 
 vectors [(2, 2)] 

i / j

     3 / 3  < GOAL 

     2 / 2  < equal 

vectorsReachGoal(...) == True



 goalVector (3, 3) 
 vectors [(2, 2), (3, 5), (5, 3)] 

i / j

     3 / 3  < GOAL 

     2 / 2  < equal 

vectorsReachGoal(...) == True



 goalVector (5, 5) 
 vectors [(1, 1), (2, 2), (3, 3)] 

i / j

     5 / 5  < GOAL 

     1 / 1  < equal 

vectorsReachGoal(...) == True



 goalVector (1, 5) 
 vectors [(2, 2), (3, 3)] 

i / j

     1 / 5  < GOAL 

     2 / 2  < greater 

     3 / 3  < greater 

vectorsReachGoal(...) == False



 goalVector (1, 5, 1) 
 vectors [(2, 2, 2), (3, 3, 3)] 

i / j

     1 / 5  < GOAL 

     2 / 2  < greater 

     3 / 3  < greater 

vectorsReachGoal(...) == False



 goalVector (5, 3) 
 vectors [(15, 4), (5, 3)] 

i / j

     5 / 3  < GOAL 

     15 / 4  < greater 

     5 / 3  < equal 

vectorsReachGoal(...) == True

 --- 0.036838531494140625 seconds ---
"""
