;Solution encryption

(define encrypt
	(lambda (str)
		(list->string (map encrypt-vowels (string->list str)))
))

(define encrypt-vowels
  (lambda (c)
    (cond ((or (char=? c #\a) (char=? c #\A)) #\?)
          ((or (char=? c #\e) (char=? c #\E)) #\!)
          ((or (char=? c #\o) (char=? c #\O)) #\+)
          ((or (char=? c #\u) (char=? c #\U)) #\-)
          ((or (char=? c #\i) (char=? c #\I)) #\*)
          (else c)
    )
  )
)


;Solution decryption

(define decrypt
	(lambda (str)
		(list->string (map decrypt-vowels (string->list str)))
))

(define decrypt-vowels
  (lambda (c)
    (cond ((char=? c #\?) #\a)
          ((char=? c #\!) #\e)
          ((char=? c #\+) #\o)
          ((char=? c #\-) #\u)
          ((char=? c #\*) #\i)
          (else c)
    )
  )
)
    

(encrypt "Zebra is a horse")
(decrypt (encrypt "Zebra is a horse"))
(encrypt "COMPUTER science")
(decrypt (encrypt "COMPUTER science"))