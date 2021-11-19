# Letter Matrix Cipher
### A c++ script for encoding/decoding a playfair cipher

----

A PlayFair Cipher invloves creating a 5 x 5 matrix of the alphabet

In a PlayFair 'i' and 'j' are interchangable, for this script it is centered around 'i'

#### Matrix Example

```shell
a b c d e
f g h i k
l m n o p
q r s t u
v w x y z
```

A matrix is changed with a key, where the alphabet is added onto the end of the key and all dupe 
letters are removed before it is put into a 5 x 5 format

#### Matrix Example With Lizard as Keyword

```shell
l i z a r
d b c e f 
g h k m n
o p q s t 
u v w x z
```
Once a matrix has been created we can now encode/decode the message

Take the word 'this' for example, we first split it into character pairs

'th' 'is'

now we treat each pair as row/column and column/row pairs to get a new character pair

