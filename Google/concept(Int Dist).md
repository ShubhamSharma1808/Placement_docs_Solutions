Concept:- brute force nikal , thoda bda input lega 7-8 value ka tree banake possible choices ka to dikhega ki same set of values 
          repeat hota hai to yha memoization lga skte, ab ye set hai to iske liye bit masking se set of elements dekh skta
          int le -> iske 32 bit 32 element show krte hai. ab agr set and reset krna hai int & ~(1<<i) and int | (1<<i) respe.
          aise hojaega 
          - dp+bit masking is killer 
          - map ki jagah vector prefer krna
