
**Quickly test if a set of positive vectors when scaled with a positive number, can combine to create create a goal vector.**

See if you can solve it for yourself before scrolling to read my answer

<br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br />
<br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br />
  
When working with positive values, the limit is the ratio of components. 
So after finding the max and min ratios of components to components, check if goal vector is within these.
This scales to any number of components or vectors.

(i,j,k)

a * (8,2,4) + b * (1, 2, 16) = (9,4,20)

i / j

    min: 1/2

    max: 4

    goal: 9/4

    inside? True

j / k

    min 1/8
    
    max 1/2
    
    goal 1/5
    
    inside? True

i / k

    min 1/16
    
    max 2
    
    goal 9/ 20
    
    inside? True

(a = 1, b = 1)

The formula for the number of ratios is n (n-1) /2, where n is the number of components, so when n = 3 there are 3 * 2 / 2 = 3 ratios as shown.
But all vectors do not need to be checked for ratios, as only a ratio larger and smaller needs to be found.

<img width="504" alt="Screen Shot 2021-02-17 at 9 55 44 am" src="https://user-images.githubusercontent.com/69740744/108132058-2ad0a480-70aa-11eb-972d-862fe497b966.png">

Through the visualization and the formula, you can this is similar to the sum of integers, 1 + 2 + 3 ... n = n (n+1) /2

https://en.wikipedia.org/wiki/1_%2B_2_%2B_3_%2B_4_%2B_%E2%8B%AF

#visualizations

![ezgif com-video-to-gif](https://user-images.githubusercontent.com/69740744/108145884-1699a100-70c4-11eb-83d2-9d8327e8f784.gif)


<img width="566" alt="Screen Shot 2021-02-16 at 10 09 39 pm" src="https://user-images.githubusercontent.com/69740744/108055728-45723180-7048-11eb-929f-ff3e629d42a7.png">

<img width="566" alt="Screen Shot 2021-02-16 at 10 12 01 pm" src="https://user-images.githubusercontent.com/69740744/108055736-47d48b80-7048-11eb-8e3d-1a5a64f9cfde.png">




