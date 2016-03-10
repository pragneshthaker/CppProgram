do {
   // balance_factor(P) has not yet been updated!
	   if (N == right_child(P)) {
			 if (balance_factor(P) == 1) { // The left column in the picture
				   // ==> the temporary balance_factor(P) == 2 ==> rebalancing is required.
				   S = left_child(P); // Sibling of N
				   B = balance_factor(S);
				   if (B == -1) { // Left Right Case
					  rotate_left(S); // Reduce to Left Left Case
				   }
				   // Left Left Case
				   rotate_right(P);
				   if (B == 0) // (in the picture the small blue (0) at node 4)
					 break; // Height does not change: Leave the loop
			 }
		 
			 if (balance_factor(P) == 0) {
			   balance_factor(P) = 1; // N’s height decrease is absorbed at P.
			   break; // Leave the loop
			 }
			 balance_factor(P) = 0; // Height decreases at P
	   } 
	   
	   else { // N == left_child(P), the child whose height decreases by 1.
				 if (balance_factor(P) == -1) { // The right column in the picture
				   // ==> the temporary balance_factor(P) == -2 ==> rebalancing is required.
				   S = right_child(P); // Sibling of N
				   B = balance_factor(S);
				   
				   if (B == 1) { // Right Left Case
						rotate_right(S); // Reduce to Right Right Case
				   }
				   // Right Right Case
				   rotate_left(P);
				   if (B == 0) // (in the picture the small blue (0) at node 4)
						break; // Height does not change: Leave the loop
				 }
				 if (balance_factor(P) == 0) {
					   balance_factor(P) = -1; // N’s height decrease is absorbed at P.
					   break; // Leave the loop
				 }
				 balance_factor(P) = 0; // Height decreases at P
	   }
	   
	   N = P;
	   P = parent(N);
 } while (P != null); // Possibly up to the root
