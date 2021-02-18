import time
start_time = time.time()

vectors = [[8,2,4], [1,2,16]]
goalVector = [9,4,20]
components = len(goalVector)

print("goalVector", goalVector)
print("vectors", vectors)
print()

def vectorsReachGoal(vectors, goalVector):

    # moves to different components as to go through unique ratios
    for start_restriction in range(components):
        for component in range(1, components - start_restriction):

            # for a single ratio
            goalRatio = goalVector[start_restriction] / goalVector[start_restriction+component]
            print(goalVector[start_restriction], "/",goalVector[start_restriction+component], "<GOAL")

            lesserRatioSeen, greaterRatioSeen = False, False

            for vector in vectors:
              ratio = vector[start_restriction] / vector[start_restriction+component]
              print(vector[start_restriction], "/",vector[start_restriction+component])

              if ratio < goalRatio:
                lesserRatioSeen = True
                if greaterRatioSeen:
                  continue
              elif goalRatio < ratio:
                greaterRatioSeen = True
                if lesserRatioSeen:
                  continue

            print("lesser", lesserRatioSeen)
            print("greater", greaterRatioSeen)

            if not lesserRatioSeen or not greaterRatioSeen:
              return False
            print()

    # passes if all ratios pass and don't return before this is called
    return True        

print("vectorsReachGoal:",vectorsReachGoal(vectors, goalVector) )
print("--- %s seconds ---" % (time.time() - start_time))