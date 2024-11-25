// Skynet has grown to become the dominant force on earth and has almost completely wiped out the human race.
//  Skynet has been building robots ever since it’s inception and has been updating it’s models every year 
//  while making them better. Skynet wants to annihilate humanity completely. 
//  It plans to remove one last band of humans lead by John Connor. 
//  Skynet thinks it can destroy these humans using only two of it’s robots.
//   But Skynet doesn’t want to send two robots with the same model number lest John Connor 
//   finds out a weakness in that model and easily destroy both of them. Skynet has at its disposal N robots 
//   and to save space Skynet has stored information about pairs of robots belonging to the same model. 
//   If it doesn’t have any info stored for a particular robot then it is implied that the robot is the only one 
//   in that model. Given these constraints, in how many ways can Skynet pick two robots to destroy John Connor and 
//   his rag tag group of humans. Inputs N – Total number of robots. Each robot is assigned a number from 0 to N-1 P 
//   – Number of pairs for which Skynet has information This is followed by P pairs. Each pair has two numbers P1 
//   and P2 each where 0<=P1<=N-1 and 0<=P2<=N-1 and P1 != P2 Output Number of ways in which Skynet can select 2 
//   robots such that both the robots are different models. Example Input: 4 2 0 1 2 3 Example Output: 4 Explanation:
//    Here robots 0 and 1 are of one model, say model A. And 2 and 3 are of another model, say B. Therefore the total 
//    number of possibilities of picking 2 robots such that no two robots are of the same model are – (0, 2), (0, 3), 
//    (1, 2) and (1, 3) = 4