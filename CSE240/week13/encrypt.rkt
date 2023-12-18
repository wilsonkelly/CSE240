;Your Name: Wilson Kelly
;Course: CSE 240

;string to list
(define (sTL a)
  (string->list a))

;list to string
(define (lTS a)
  (list->string a))

;encrypts characters
(define (encrypt2 a)
  (cond
    ((or (eq? a #\A)(eq? a #\a)) #\?)
    ((or (eq? a #\E)(eq? a #\e)) #\!)
    ((or (eq? a #\O)(eq? a #\o)) #\+)
    ((or (eq? a #\U)(eq? a #\u)) #\-)
    ((or (eq? a #\I)(eq? a #\i)) #\*)
    ((eq? a #\space)#\ )
    (#t a)))

;decrypts characters   
(define (decrypt2 a)
  (cond
    ((eq? a #\?)#\a)
    ((eq? a #\!)#\e)
    ((eq? a #\+)#\o)
    ((eq? a #\-)#\u)
    ((eq? a #\*)#\i)
    (#t a)))

;Takes string input, converts it to list,
;then map goes through each character in list and runs encrypt function.
;This is then converted from list to string.
(define (encrypt a)
  (lTS (map encrypt2 (sTL a))))

;same but decrypts
(define (decrypt a)
  (lTS (map decrypt2 (sTL a))))

;Test cases: 
(encrypt "Zebra is a horse") 
(decrypt (encrypt "Zebra is a horse"))
(encrypt "COMPUTER science") 
(decrypt (encrypt "COMPUTER science"))
; expected output 
"Z!br? *s ? h+rs!" 
"Zebra is a horse" 
"C+MP-T!R sc*!nc!" 
"CoMPuTeR science"