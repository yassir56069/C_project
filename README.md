# More or Less Game

This is a simple game made in C with a simple premise. You must guess a random number between 1 and 100.  Upon guessing you will be told if your guess is more or less than the number!

## **1 And 2 Player Modes**

### 1 player mode

You get to choose between 3 difficulties, **easy, medium** and **hard**. Each difficulty has a number of tries, where;

* `Easy --> Unlimited Tries`

* `Medium --> 25 Tries`

* `Hard --> 10 Tries`

When a correct guess has been made, you've won!

### 2 player mode

You're first prompted to choose a number of rounds for the game. On each even round player 1 gets to choose the number of tries for both players. On each odd round, player 2 gets to choose the number of tries for both players. Whenever this is decided, the number of tries has to be a minimum of 10. The score is determined based on how many tries the player had left once they've managed to guess the number. The person with the highest score wins.

## **Installation**

To install the game you just have to left-click on the green code button, after which you left-click on the 'download as zip' button. Once the zip file is downloaded, you extract it at your desired installation location. To run the game, just run the `LessMore.exe` file.

![install](https://i.imgur.com/ljzHXzA.png)

if you'd like to clone the repository, run the following command in the command prompt terminal, to an appropriate folder.

```sh
git clone https://github.com/yassir56069/tp_git_yassirhoossanbuksh
```

to build the program yourself, having `gcc` installed you must run the following command in command prompt

```sh
gcc -o LessMore.exe main.c func_game.c func_util.c
```
