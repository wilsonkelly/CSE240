; Wilson Kelly
; HW 11
; Q1 (5 points)
; Enter your code here
;(- (+ (* 9 4) 5) 8)
;(-(* 5(-(+ 6 12)5))22)
;(*(-(+(/ 32 4)21)(*(+ 7 2)3))9)
;(*(+ 4 (/(+(* 7 10)(/ 6 3))(+ 10 2)))3)
;(-(/(-(* 2(* 2 (*(+ 4 5)(+ 6 7))))10)2)(+(/(*(+(* 4 5)(* 6 4))3)2)(* 4 5)))

; Q2 (5 points)
(define (Add a b)
;Enter your code here
  (+ a b))


(Add 5 6)

; Q3 (10 points)
(define (Product x n)
; Enter your code here
  (*(Add x x)n))

(Product 3 3)

; Q4: (5 points)
;(define SquareRoot
; Enter your code here


;(SquareRoot 4)

; Q5 (10 points)
;(define DistanceBetweenTwoPoints
; Enter your code here


;(DistanceBetweenTwoPoints 2 5 3 2)

;Q6 (5 points)
(define (AddLet x y)
; Enter your code here
  (let ((a x) (b y)) (+ a b)))


(AddLet 10 3)

; Q7 (10 points)
(define (Letexpression)
; Enter your code here
  (let ((nine 9) (four 4) (five 5) (eight 8)) (-(+(* nine four)five)eight)))


(Letexpression)
