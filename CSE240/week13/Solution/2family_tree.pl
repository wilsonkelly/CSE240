/* Database for family tree. It consists of facts and rules. */

/* Facts */
male(kam).
male(jeb).
male(rob).
male(tio).
male(zev).
male(dom).
male(dag).
male(gio).
female(ana).
female(may).
female(sue).
female(syd).
female(pam).
female(kat).
female(fey).
female(liz).

father_of(kam, rob).
father_of(kam, syd).
father_of(jeb, tio).
father_of(jeb, pam).
father_of(rob, kat).
father_of(rob, dom).
father_of(tio, dag).
father_of(tio, fey).
father_of(zev, liz).
father_of(zev, gio).

mother_of(ana, rob).
mother_of(ana, syd).
mother_of(may, tio).
mother_of(may, pam).
mother_of(sue, kat).
mother_of(sue, dom).
mother_of(syd, dag).
mother_of(syd, fey).
mother_of(pam, liz).
mother_of(pam, gio).


/* Rules */
is_male(X) :-
 	male(X);
	father_of(X, _).
	
/* Question 1.2 */
is_female(X) :- 
	female(X);
	mother_of(X, _).
	
/* Question 1.3 */
parent_of(X, Y) :- 	
	father_of(X, Y);
	mother_of(X, Y).
	
/* Question 1.4 */
sibling_of(X, Y) :-
	parent_of(Z, X),
	parent_of(Z, Y),
	X \== Y.

/* Question 1.5 */
grandmother_of(X, Z) :-	
	mother_of(X, Y), 
	parent_of(Y, Z).

grandfather_of(X, Z) :-
	father_of(X, Y), 
	parent_of(Y, Z).

/* Question 1.6 */
descendent_of(X, Y) :- 
	parent_of(Y, X).

descendent_of(X, Y) :-
	parent_of(Y, Z),
	descendent_of(X, Z).

	/* 
Rubric:
Each Question is worth 4 0r 5 points.Please check the Word document.
(-1) for minor mistake.
(-3) for incorrect answer.
(- all points) for no attempt.
*/