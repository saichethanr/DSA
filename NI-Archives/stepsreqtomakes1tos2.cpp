// Question 3:
// Given a set of words, count minimum number of steps required to convert one word into another word satisfying the following conditions,
// 1. At any time, we are allowed only to change or insert or remove a single character in the word.
// 2. The resultant word obtained in step 1 should also be present in the given set of words.
// Return -1 if not possible to convert.

// Sample input 1:
// pit, kate, pat, kit, kat, kite
// Convert pit into kite
// Output 1:
// 2
// Solution: pit→kit→kite
// Another possible solution: pit → pat →kat→kate→ kite, this yields number of steps as 4 which is not better than the previous solution as we need minimum steps.

// Sample input 2:
// pit, kate, pat, kit
// Convert pit into kate
// Output 1:
// -1
// Solution: Not possible.

// Hint: Construct a graph having each word as a node and draw an edge iff those two words is derivable from each other satisfying the above two conditions. Now, apply shortest path algorithm to find the minimum length to reach from a given word to another word.
// 6 people cleared this round.