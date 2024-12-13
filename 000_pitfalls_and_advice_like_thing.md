## Things
- introducing yourself: your present, your past, then your future
    like I work here and here and make use of these skills. Before that I've worked there and there and used these skills. I'm looking forward to this and this because of this reason. 
- overall process of solving a dsa question(this does not include intro and outro stuff in the interview)
    - interviewer tells you the problems
    - you clarify the problem well enough, constraint on input, any vagueness etc. work through an example or two to make sure
    - explain brute force or the most simple approach first, then explain better approaches and their trade-off. Explain these appraoches on high level only
    - Once interviewer signals that one of the approaches is good enough, then go in depth of it. Explain it in details but without any code
    - After getting the signal that interviwer is satisfied with approach and its in depth explanation, write actual working code(not pseducode) with good practices like modular functions, good variable names
    - Once coding is done, we've to make sure the solution is correct, so
        - look for edge cases, mistakes
        - step through the code with some sample cases
        - brainstorm edge cases with interviwer with additional cases
    - then, reiterate time/space complexity of solution and code improvement chances(optimization/refactor) if given time

## Pitfalls
### 1. wrong way of solving problems
In interview, when we're explained the problem, 
- we should first clarify anything which is vague, constraints on inputs, working through a simple case etc. We can also do this as we go through the problem. This step can be omitted if everything is clear enough
- next, it is a good(and neccessary; a must) thing to first derive the approach without writing any code. So, we won't be writing any code, we'll just explain our approach.
    - Usually, people advice to first explain the brute force approach, then the optimal approach(and also in the end, after all written and coding solution, explain alternate approaches for cases in which we optimize for some other case) 
    - Here, people assume that we just have to explain the high level details of brute force approach and most optimal approach. But, this is wrong. For the optimum approach, you have to explain the solution in depth,handling all edge cases there itself(you can skip language details like python heaps have some quirk or something). Also, after you've explain the in depth solution, there shouldn't be any edge cases, any vagueness left. You can say that the meat of the problem solving is in this step itself. This is also where interviewer will signal if he/she is satisfied with your solution's correctness,edge case handling and time/space complexity requirements. If he/she does not signal anything, you should take initiative to ask them if they're satisfied.
    - Also, before going to the in-depth explanation of best approach, discuss other approaches and their trade-offs.
- In the coding step, you'll do just the coding. The only challenge you should face in this step is language quirks. If you are having any problems/doubts about your solution itself, then you've not done the previous step of deriving  and explaining approach adequately.
    - If you're having problems in the coding steps to complete the solution code even after perfectly doing the previous steps, it signals lack of practice



### 2. stressful environment
In stress, your practice will give you less than 10% returns, because
(i) your capability to solve the problems won't be 100%, so you might perform worse and it may cause despair
(ii) you might not be able to fully follow the above procedure for solving problems. So, even if you solve the problems correctly, it won't develop your mind muscle memory to do the above procedure which may lead to worse performance in interview(even though when solving problems on your own, you do great)
So don't practice/give interviews when you're in any kind of stress(travel stress, lack of sleep, work fatigue etc.)
Make sure some hours before interview are rest-like and stress free