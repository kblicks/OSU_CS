
Name: Katie Blickenstaff
ONID: blickenk
CS 162 Section 01
Assignment #2

Description: This program lets you play a game of GoFish. There are two players who have no cards in their hand at the start. 
The game is set up by first populating a normal deck of 52 cards and then shuffling the deck. Each player is dealt 7 cards
from the deck and then the human player gets to go first. Each player will take turns asking the other for a rank, and
if the opposing player has the matching rank, they must give up all the cards of that rank and transfer them to the asking player. 
The requesting player gets to go again. 
The person asking must have the rank they are asking for in their hand to be able to ask the other person for that rank. 

If there are no matching ranks in the other person's hand, then they say "Go Fish!" and the requesting player must draw a card. 
If that card matches the rank that the person is asking for, then they get to go again. Once a hand has 4 cards of the same rank,
then the player may create a book. The goal of the game is to create the most books and the person who has the most at the end will win. 

The program will then display the scores and ask the human player if they would like to go again. 

Instructions: 
1. Run the program with the command  ./go_fish true   OR ./go_fish false.  true sets the gamemode to debug and false sets it to normal
2. Look at your hand and enter a rank you would like to ask for. Enter a word such as "ace" or "Seven"
3. Continue entering ranks until both players are out of cards and the End game scores are printed 
4. Decide if you want to play again



Limitations: The command line argument must say "true" or "false" after entering go_fish. This must be in lowercase to set the appropriate gamemode