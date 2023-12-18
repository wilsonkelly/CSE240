/* Solution */

/* Facts */
/* Question 2.1 */
department(jack, cs).
department(sam, business).

subject(jack, computer_science).
subject(jack, software_engg).
subject(sam, economics).
subject(sam, finance).

course(computer_science, "CS305").
course(computer_science, "CS332").
course(software_engg, "SE212").
course(software_engg, "SE102").
course(economics, "ECO304").
course(economics, "ECO302").
course(finance, "FIN102").
course(finance, "FIN103").

/* Rules */
/* Question 2.2 */
info(X, Y) :- 
	department(X, Y);
	subject(X, Y).

/* Question 2.3 */
schedule(X, Z) :-
	subject(X, Y),
	course(Y, Z).

/* 
Rubric:

Question 2.1:
status facts:
	(-1) minor mistake
	(-2) incorrect answer
	(-3) no facts
topic facts:
	(-1) minor mistake
	(-2) incorrect answer
	(-3) no facts
class facts:
	(-1) minor mistake
	(-2) incorrect answer
	(-3) no facts

Questions 2.2 and 2.3:
(-1) minor mistake
(-3) incorrect answer
(-5) no attempt
*/