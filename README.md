# Problem #

**Quickly test if a number of scaled vectors can form a goal vector, where all scaling magnitudes and vector components are positive**

IE 

a x (i,j,k) + b x ... = (i,j,k)

See if you can solve it for yourself before scrolling to read my answer. It should be simple enough to do by hand and you don't have to solve for values.

<br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br />
<br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br />

Does this help?

![ezgif com-video-to-gif](https://user-images.githubusercontent.com/69740744/108145884-1699a100-70c4-11eb-83d2-9d8327e8f784.gif)

<br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br />
<br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br />

# Answer #
  
When working with positive values, the limit of reach is the ratio of components. 
So for each ratio, you only need to find a value greater and less than the goal value to verify it is in reach of the vectors.
This scales to any number of components or vectors and is extremely quick.
See the python file for execution with code.

a * (8,2,4) + b * (1, 2, 16) = (9,4,20)

PYTHON PRINT
START

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

vectorsReachGoal: True
--- 0.006424903869628906 seconds ---

END

(a = 1, b = 1)

https://www.wolframalpha.com/input/?i=a+*+%288%2C2%2C4%29+%2B+b+*+%281%2C+2%2C+16%29+%3D+%289%2C4%2C20%29

<br />

**Visualizations**

<img width="250" alt="Screen Shot 2021-02-16 at 10 09 39 pm" src="https://user-images.githubusercontent.com/69740744/108055728-45723180-7048-11eb-929f-ff3e629d42a7.png"><img width="250" alt="Screen Shot 2021-02-16 at 10 12 01 pm" src="https://user-images.githubusercontent.com/69740744/108055736-47d48b80-7048-11eb-8e3d-1a5a64f9cfde.png">

<br />

**Performance**

Components:

The formula for the number of ratios is n (n-1) /2, where n is the number of components, so when n = 3 there are 3 * 2 / 2 = 3 ratios as shown. 

<img width="500" alt="Screen Shot 2021-02-17 at 10 41 07 pm" src="https://user-images.githubusercontent.com/69740744/108199511-0d84f000-7115-11eb-9032-7f22313b4f3c.png">

  Through the visualization and the formula, you can this is similar to the sum of integers, 1 + 2 + 3 ... n = n (n+1) /2

https://en.wikipedia.org/wiki/1_%2B_2_%2B_3_%2B_4_%2B_%E2%8B%AFd

Vectors:

As mentioned, a global min and max don't need to be found, only values larger and smaller than the goal vector. In other words not all vectors need to be looked at.

<br />
