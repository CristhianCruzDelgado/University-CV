## Introduction to cryptography

During the Second World War, the German army used the machine known as *Enigma*
to encode its messages.
Essentially, given a *seed*, the machine generated a sequence of pseudo-random numbers that was
hard to reproduce, even if the technical details of the machine were discovered.
The Allies had captured some *Enigma* machines, so they knew how
the machine worked, but the work done to break the *Enigma* codes laid
the foundations of modern cryptography.
Alan Turing took part in this work.
If you are interested in this story, watch the film
[The Imitation Game](https://en.wikipedia.org/wiki/The_Imitation_Game)
(*Descifrando Enigma* in Spanish).

Cryptology is the field of knowledge concerned with the study and design of systems that allow
secret communication between the sender of a message and one or more receivers.
Initially, the only applications of cryptology were military, but today there are many others.
For example, on multi-user computers, each user keeps their files in a form
that cannot be read by other "indiscreet" users.
To achieve this, the files are encoded (encrypted) with a key known only to their owner.
Much of the information we send over the internet also travels encoded to protect it from unwanted receivers.

There are many ways to encrypt a file.
All of them consist of transforming each character of the original file into a different
character according to a given transformation.
Two different encryption methods are described below.

### XOR encryption (exclusive or)
The
[XOR cipher](https://es.wikipedia.org/wiki/Cifrado_XOR)
requires a secret encryption/decryption key.
Each character of the file is transformed
by applying the `xor` operation with a character of the secret key.
Study the chapter
[Bitwise operators](https://www.learncpp.com/cpp-tutorial/bitwise-operators/)
of the tutorial, and remember that the (bitwise) operator in C/C++ is `^`

The character of the secret key used to transform the original character varies cyclically.
For example, if the secret key is the word `alfa` and the first words of the text are
*Informática Básica*, the first characters of the output file will be:

```
character 1  I xor a
character 2  n xor l
character 3  f xor f
character 4  o xor a
character 5  r xor a
character 6  m xor l
character 7  á xor f
character 8  t xor a
character 9  i xor a
character 9  c xor l
character 10 a xor f
character 11   xor a
character 12 B xor a
character 13 á xor l
character 14 s xor f
   ...
```

That is, the `xor` operation is applied to each character of the
input text with each character of the secret key,
taking the key cyclically (after its last character, it starts again from the first).

Before operating in this way, the secret key is processed by applying `xor` to each of its characters with the constant 128.

One advantage of this method is that it is particularly suitable for a computer,
since the exclusive or operation is performed very efficiently.
Another advantage is that decryption consists of applying exactly
the same operation to the encrypted text (with the same secret key, of course).

### Caesar cipher
As its name suggests,
[this method](https://es.wikipedia.org/wiki/Cifrado_C%C3%A9sar)
was already used in Roman times.
In this case, the encoding is as follows: if a letter of the text to encode is the N-th
letter of the alphabet, replace it with the (N + K)-th letter of the alphabet.
(Caesar used the value K = 3).
The following is a text encrypted with this method using K = 1:

```
Original text:   Navidad, Navidad, dulce navidad
Encrypted text:  Obwjebe-!Obwjebe-!evmdf!obwjebe
```

The value of K can either be fixed or requested from the user.

Obviously, decrypting the file consists of applying the inverse operation,
and in this case the value of K should be requested from the user to ensure that they are authorised to read the file.
