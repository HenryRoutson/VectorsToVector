
  ** Test if a set of vectors when scaled with a positive number, can combine to create create a goal vector. **
  




  When working with positive values, the limit is the ratio of components
  So after finding the max and min ratios of components to components, check if goal vector is within these.
  This scales to any number of components.
  
  (i,j,k)
  
  a * (8,2,4) + b * (1, 2, 16) = (9,4,20)

  i/j
  - min: 1/2
  - max: 4
  - goal: 9/4
  - inside? True
  
  j/k
  - min 1/8
  - max 1/2
  - goal 1/5
  - inside? True
  
  i/k
  - min 1/16
  - max 2
  - goal 9/ 20
  - inside? True
   
   (a = 1, b = 1)
   



   <img width="1394" alt="Screen Shot 2021-02-16 at 9 56 14 pm" src="https://user-images.githubusercontent.com/69740744/108053795-c8de5380-7045-11eb-9504-37e29142e5f7.png"><img width="566" alt="Screen Shot 2021-02-16 at 10 09 39 pm" src="https://user-images.githubusercontent.com/69740744/108055728-45723180-7048-11eb-929f-ff3e629d42a7.png"><img width="566" alt="Screen Shot 2021-02-16 at 10 12 01 pm" src="https://user-images.githubusercontent.com/69740744/108055736-47d48b80-7048-11eb-8e3d-1a5a64f9cfde.png">
    
    ** Now find the positive values. **
    
    
    
    
