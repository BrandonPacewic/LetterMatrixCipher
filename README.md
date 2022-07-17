# Letter Matrix Cipher

A c++ script for encoding/decoding a Playfair Cipher

## What is a Playfair Cipher?

A PlayFair Cipher involves creating a 5 x 5 matrix of the alphabet.

In a PlayFair 'i' and 'j' are interchangeable, for this script it is centered around 'i'.

### Matrix Example

```Plaintext
a b c d e
f g h i k
l m n o p
q r s t u
v w x y z
```

A matrix is changed with a key, where the alphabet is added onto the end of the key and all duplicate
letters are removed before it is put into a 5 x 5 format.

### Matrix Example With Lizard as Keyword

```Plaintext
l i z a r
d b c e f 
g h k m n
o p q s t 
u v w x z
```

Once a matrix has been created we can now encode/decode the message.

Take the word 'this' for example, we first split it into character pairs.

```Plaintext
'th' 'is'
```

Now we treat each pair as row/column and column/row pairs to get a new character pair.

'th' in the lizard matrix will become 'pn' and 'is' would become 'ap'.

'This' encoded in our lizard matrix becomes.

```Plaintext
'pnap'
```

If both letters in our character pair are in the same row/column we shift them up/right or down/left depending on if we a encoding or decoding.

For example if both our keyword and the word we want to encode were banana.

Our matrix would look like this.

```Plaintext
b a n c d
e f g h i
k l m o p
q r s t u
v w x y z
```

Our letter pairs would look like this.

```Plaintext
'ba' 'na' 'na'
```

Because we are encoding we shift each character to the right if they are in the same row so our encoded letter pairs would look like this.

```Plaintext
'an' 'cn' 'cn'
```

So banana encoded with banana is

```Plaintext
'ancncn'
```

If there is a uneven number of letters we add an 'x' to complete the letter pair.

The encoded word will have a letter that does not make sense but that can be fixed when the word is decoded again and the extra 'x' can be removed.

In a similar manner if any character pair contains identical characters such as in the word.

```Plaintext
'button'
```

We replace the second character in the pair with 'x' so 'tt' becomes

```Plaintext
'tx'
```

This will sometimes create problems where it can be hard to tell if a given 'x' is really meant to be an 'x' or if it's a place holder for something else.

This is why the letter 'x' was chosen as it has the least number of words connected to it in the english language.
