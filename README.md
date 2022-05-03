# LRU-K
The LRU-K algoritm will be implemented in this project.
## Theoretical information
LRU-K evicts the page whose K-th most recent access is furthest in the past. For example, LRU-1 is simply LRU whereas LRU-2 evicts pages according to the time of their penultimate access. LRU-K improves greatly on LRU with regards to locality in time.  
More information: [Wiki](https://en.wikipedia.org/wiki/Page_replacement_algorithm#Variants_on_LRU), [Scientific Article](https://www.cs.cmu.edu/~christos/courses/721-resources/p297-o_neil.pdf)
## Work example(LRU-1)
The access sequence for the below example is A B C D E D F.  
![](Lruexample.png)
