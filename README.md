# Dictionary

This dictionary implemented in C++ has keywords, it’s part of speech(s), and it’s definition(s). Client decides which key word they want to search and print. Provided information is the data of a dictionary. I loaded the data in vectors, and then put those vectors in a map with word as the key. I used vectors because of their dynamic size. Used maps to sort the data according to words. 

Client can input the word that they want to search and print in the following ways:

1. Client can enter one word, the keyword. When this happens, the client want to see each part of speech with each definition that is available in the dictionary.
2. Client can enter two words, the keyword with a word “distinct” along it. This means now the client wants only to see different definition of words, he does not want the same definition repeated, if same.
3. Client can enter two words, the key word with a part of speech along it. This means the client only want to see the definition of the entered keyword that has the same the part of speech as client entered. He wants to see the exact number of times as that part of speech is present in dictionary.
4. Client can enter three words, the keyword at first place, the part of speech at second place, and
“distinct” at third place. This means that client wants to see the keyword of the entered type of part of speech and whose definition should not be repeated, if same.
5. Client can enter the keyword in any order of uppercase and lowercase characters of the keyword, but he wants to see the proper keyword in the output.
6. Client can also enter those keywords, that are not in the original data. When this happens, client must be reminded that the entered word is not in the original data of the dictionary.
7. Client can also type something else as the second word, so the client must be reminded that second word can only be a part of speech or “distinct”.
8. Lastly, when client enters “!Q”, they wants the program to end. This is how I am solving the queries of the client and giving the result as desired by our beloved client.

# Output

![Picture1](https://user-images.githubusercontent.com/78123335/162883738-473b2783-2dcb-4bcd-8e3c-ddd6b59f57c4.jpg)
![Picture2](https://user-images.githubusercontent.com/78123335/162883748-095cea98-1aee-44d3-aaac-133b9e1749fd.jpg)
![Picture3](https://user-images.githubusercontent.com/78123335/162883791-abdf7115-a82a-4aee-a8f4-bcf55c929805.jpg)
![Picture4](https://user-images.githubusercontent.com/78123335/162883802-745445ac-1379-40ba-ad86-47b11efa91f3.jpg)
![Picture5](https://user-images.githubusercontent.com/78123335/162883811-dfcf3a3c-b36e-4abf-a203-09598b133504.jpg)
![Picture6](https://user-images.githubusercontent.com/78123335/162883816-1d76a31d-ccd5-4efd-a1ef-0cb02005c03e.jpg)


