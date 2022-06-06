# Wordle Clone
## Table of contents
* [App description](#app-description)
* [Additional files](#additional-files)
* [Used elements](#used-elements)

## App description	
 Wordle Clone is a console based game based on New York Times game - Wordle. The game and the whole words database is currently in English.

At the beggining player has to log into existing account or create a new one.
After that there are two game modes available: 
* free play - where player can guess words without any time restrictions;
* daily challenge - where player can play only once a day.

Both of the game modes are base on the same rules: the player guesses five-letter words. The user gets six chances, and for each unsuccessful attempt, the game informs them whether the letters used in a given try are:
* in the answer-word in the right place - the letter is being represented as the appropriate letter;
* in the answer-word, but in a different place - represented as the sign "*";
* not in the answer word - represented as the sign "-".

![obraz](https://user-images.githubusercontent.com/72342415/172215401-814448a3-7aef-4265-9ac2-9bb23cb70567.png)



  Navigating the menu and making selections is done by entering the number of the selected option available in the program menu.
  
  
## Additional files
  All of the data is stored as text files. There are two configuration files: a file containing database with words and a file containing users.


## Used elements
  The program is based on Object-Oriented Programming. It uses class inheritance mechanism. The project has been divided into files using modules - this may cause some problems with running it, since modules are fairly new addition to C++. The game also uses multithreading mechanism. Smart pointers were used in the program to implement custom singly linked list, which contains players. Open-source, header library date.h was used in the game and is included in files.
