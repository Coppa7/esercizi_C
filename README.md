# esercizi_C
Collection of C programming exercises as preparation for the *Fondamenti di Informatica* exam.  
They mainly focus on **strings, linked lists, dynamic memory, file handling**, etc.  

Note: the exercises are solved prioritizing **speed of resolution** over efficiency.  
Some solutions may therefore be inefficient but valid, for didactic purposes.

---

### Files and Descriptions

- **Shrink.c**: Starting from a generic string, allocates a new string that contains all characters of the first one only once, in order.

- **shrink_lista.c**: Similar to `shrink.c`, but here the function `shrink` allocates a new string based on a mask (a string of 0s and 1s). Only characters corresponding to 1s are kept. Then, given a list of strings, each is replaced with its "shrunk" version, unless the reduced string starts with 'Z', in which case the corresponding node is removed.

- **amplifica_stringa.c**: Given a string and a mask (this time an array of integers). Works similarly to `shrink_lista.c`, but the mask can also contain positive numbers other than 0 and 1. A new string is allocated where each character of the original string is repeated as many times as the corresponding mask value.

- **shrink_sottosequenze.c**: Given a string (from an input file) consisting only of lowercase characters (a-z) and parentheses (assumed non-nested and already matched), the function `shrink` writes to an output file the input string with each parenthesized subsequence replaced by the most frequent character in that subsequence (ties broken arbitrarily).

- **Centra.c**: Adds a `0` in the middle of a linked list: creates a new central node if the list length is even, or replaces the central value if odd.

- **Mazzo_sbagliato.c**: Given a well-formatted file (name provided via command line), checks whether a deck of French playing cards (given in the file) is incomplete or contains duplicates.

- **CDR.c**: Given a positive integer `k`, the function allocates and returns an array of remainder classes of `k` with respect to user-provided numbers. Each remainder class stores the maximum, minimum, and count of elements belonging to it.

- **diff_max_lista.c**: Given an increasing list of positive integers, finds the difference between two elements `a` and `b` (`b - a`, with `a < b`) that occurs most frequently. If two differences have the same frequency, returns any of them.

- **lettera_min.c**: Simple program that returns (using recursion) the lexicographically smallest letter of a word.

- **minRC.c**: Given a matrix of floats, finds the first `n` values that are minimum both in their row and their column, printing their coordinates. The matrix is read from file.

- **mergestr_func.c**: A function (not a full program) that merges two arrays of strings in order.

- **gara.c**: Given a file composed of `<surname, nation>`, prints the number of participants from each nation.

- **mat_aristocrescente.c**: A matrix is "aristocrescente" if the maximum of row `i` is located in a column earlier than the maximum of row `i+1`, for all rows up to the penultimate. It is assumed no duplicates are present within a row.

- **zip.c**: Given a list of characters, creates a string containing the list characters in the form `<c>` or `<cK>`, where `K` is the number of consecutive occurrences of that character.

- **policode.c**: Given a list of persons with their "policode", allocates and creates a new list containing all persons whose policode is not compatible with ANY other. Two policodes are compatible if one is the reverse of the other (mirror) or if one is the complement of the other (since policodes are max length 9 and only contain 'D' and 'S'; for complementarity, 'S' and 'D' must be swapped).

- **percorso.c**: A 0-1 matrix represents a map, where `0` = free path and `1` = obstacle. Given a list representing a path, determines how many moves can be made before hitting an obstacle or going out of bounds, and prints the last valid position.

- **h_index.c**: Given a file containing information about a researcher (name on the first line, then publications with their citation counts), computes the Hirsch index (`h-index`).

- **code_bilanciate.c**: Counts the number of queues that contain an equal number of even and odd elements.
