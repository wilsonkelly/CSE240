xo;(write "hello world") 
;(newline) 
;(+ (* 3 8) 10) 
;(- 20 5)
;(+ 3 (+ 5(+ 7 (+ 9 (+ 11 13)))))
;(- (+ (* 9 4) 5) 8)
;(-(* 5(-(+ 6 12)5))22)
;(*(-(+(/ 32 4)21)(*(+ 7 2)3))9)
;3 * (4 + (((7 * 10) + (6 / 3)) / (10 + 2)))
;(*(+ 4 (/(+(* 7 10)(/ 6 3))(+ 10 2)))3)
;((((((4 + 5) * (6 + 7)) * 2) * 2) - 10) / 2) - (((3 * ((4 * 5) + (6 * 4))) / 2) + (4 * 5))
;(-(/(-(* 2(* 2 (*(+ 4 5)(+ 6 7))))10)2)(+(/(*(+(* 4 5)(* 6 4))3)2)(* 4 5)))
;(sqrt(+(expt(- 3 2) 2)(expt(- 2 5) 2)))

(define NOT-GATE (lambda(x)
  (if (= x 0) 1 0)))

(define OR-GATE (lambda(x y)
  (if (= x y 0) 0 1)))

(define AND-GATE (lambda(x y)
  (if (= x y 1) 1 0)))

;(NOT-GATE 0) ;1
;(NOT-GATE 1) ;0
;((NOT a) AND b) OR (a AND (Not b)))

(define XOR-GATE (lambda(a b)
  (OR-GATE (AND-GATE (NOT-GATE a) b) (AND-GATE (NOT-GATE b) a))))

(XOR-GATE 0 0)
(XOR-GATE 0 1)
(XOR-GATE 1 0)
(XOR-GATE 1 1)
; Expected outputs
;0
;1
;1
;0