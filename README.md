
# navy

The goal of this project is to recreate the very famous Battleship game, a game that is played by 2, in which
each players must guess the location of the other's boats in order to be able to map them and then destroy them.

The first commercial version of the game was Salvo, published in 1931 in the United States by the Starex company.

![Alt text](image/exemple.jpg?raw=true "Title")
## Description 📜

What are the rules:
- You must code a terminal version of this game.
- The two players are ONLY allowed to comunicate using the signals SIGUSER1 and SIGUSER2.
- The map size is 8x8.
- On each turn, you must display your positions, and then your enemy’s positions.
- At the end of the game (when all the ships of a player have been hit), you must display whether “I won” (and return 0) or “Enemy won” (and return 1).

During this project we only had the right to some functions that are here.


![Alt text](image/auth.png?raw=true "Title")


Here is a typical player's view

```bash
my positions:
 |A B C D E F G H
-+---------------
1|o 5 5 5 5 x . 3
2|. . o . . . o 3
3|o . . . . o . 3
4|. . 2 2 . . . .
5|. o . o . . . .
6|. o . . 4 4 4 4
7|. o . o . . o .
8|. . . . . . . .

enemy's positions:
 |A B C D E F G H
-+---------------
1|o . . . . o . .
2|. . x . . . o .
3|o . . . . o . .
4|. . . . . . . .
5|. x . o . . . .
6|. x . . . . . .
7|. x . x . . x .
8|. . . . . . . .
```

As in the game we spot each other thanks to the letters at the top and the numbers at the left.

The . represents the the water, these are the places where the enemy has not yet fired.

The numbers (2345) represent the boats, the number represents the length of the boat. For example if it is written 5 the boat measures 5 squares in width.

The o represent a shot in the water, it means that someone fired but did not hit a boat. So you can see where the enemy shot and where you have already shot.

The x represent a shot on a boat, it means that someone fired and hit a boat. So you can see where the enemy shot hit you and where you have already been shot.

If all your boats are sunk, then the game ends and you lose. 😞

If all the boats of your enemy are sunk, then the game ends and you won. 😃

## How to play 🎲

The maps are built like this.


```bash
2:C1:C2
3:D4:F4
4:B5:B8
5:D7:H7
```


The file passed as parameter must contain lines formatted the following way:
- LENGTH : FIRST_SQUARE : LAST_SQUARE.
- Where LENGTH is the length of the ship.
- FIRST_SQUARE and LAST_SQUARE its first and last positions.
In this file, you must have 4 ships (of lengths 2,3,4 and 5).

If the navy file is invalid, you have to quit the program and consider it as an error.

```bash
  ./navy map1.txt
```


This will pause you while giving you the pid to play 2.

![Alt text](image/pid.png?raw=true "Title")

After receiving the pid redo the same command with the pid like this.
If it works it will be written " successfully connected "

```bash
  ./navy [pid given] map2.txt
```

![Alt text](image/how1.png?raw=true "Title")


After that you will have to attack the enemy choose your squares well.
Just write the letter and number you want to attack and wait for the other to take their turn.


![Alt text](image/how2.png?raw=true "Title")


If you get the wrong box, no problem, you can correct your shot.


![Alt text](image/how3.png?raw=true "Title")


This is what an end game screen looks like.


![Alt text](image/how4.png?raw=true "Title")



## Installation 🔌

Install my_rpg

```bash
  git clone git@github.com:Pablodeibar/navy.git
  cd navy
  make
```
    
## Start playing 🎬


```bash
  ./navy map1.txt
```

You must have a map to play. You can create it yourself by taking the example of the one presented above.