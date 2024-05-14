// Interplanetary trade:
// Hober Mallow wants to setup an inter-galactic trade which would allow trade between different planets. Each planet has its own set of currencies in which they trade. As there are too many currencies, 
// Hober decided to declare a set of M currencies (numbered from 1 to M) as the official currencies 
// that can be used to trade between planets. Two planets can trade if and only if they have a common official currency or if there is another planet
//  with which each of these planets share a common official currency. For example, let’s say planet A has currencies – 1, 3, 4, planet B has currencies 5, 6 and planet C has 6, 4.
//   It is still possible for planet A and B to trade via planet C (planet A -> C via currency 4 and then planet C ->B via currency 6 and vice versa). This type of trade can be done with more than one planets acting as intermediary as well 
//   (i.e. planet X and Y can trade via A, B, C if XA share a common currency, AB share a common currency, 
//  BC share a common currency and finally CY share some common currency). Hober observes that even with these rules there are planets which have no official currencies or planet groups which do not share any currency with other planet groups. 
//  To enable trade among all the planets he has to implement system of new currency for each of such planets which have no official or common official currencies. Implementing a new currency system costs him 1 platinum unit per planet.
//   You have to help Hober minimize the cost for enabling trade between all the planets.
// You will be given N (2 <= N <= 50) which indicates number of planets that want to be part of the inter-galactic trade. You will be given M (2 <= M <= 50) which indicates the number of official currency numbered from 1 to M. This will be followed by N lines, each consisiting of a numberCi, the number of official currencies supported by planet i, followed by C currencies which are in trade for the ith planet.
//  You have to output the number of platinum units required to enable trade across all planets.


// Example Inputs

// 5 5
// 1 2
// 2 2 3
// 2 3 4
// 2 4 5
// 1 5

#include<bits/stdc++.h> 
#include <vector>
using namespace std;
