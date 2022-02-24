 # Chess
 
 Authors:  
 [Omair Shafi](https://github.com/Omair-Shafi)  
 [Aamina Thasneem Khaleel](https://github.com/AaminaT)  
 [Quinn Nguyen](https://github.com/portal)  
 [Riley Bradt](https://github.com/rbradt)

## Project Description

Chess is a game known by all cultures and is primarily popular due to its structure and complexity. Our team enjoys a game of effective decision-making and the challenges of protecting the king. Because chess teaches the necessity of making strong moves, planning ahead, and changing perspectives to view an opponent's plan, we seek to create our own chess board game. Features we'll be adding include the saving/loading of ongoing games, the option to undo moves, and capability to play against a computer player. 

## Tools
We'll be using [PostgreSQL](https://www.postgresql.org/docs/) and [CPP Check](https://cppcheck.sourceforge.io/). We specifically chose PostgreSQL because it is an open-source SQL software and it has tools that can help save games changes (e.g., after undoing a move and saving the game, when the game is reloaded, the state of the game would contain this change). CPP Check detects bugs and focuses on detecting undefined behaviour and dangerous coding constructs. It checks variable initialization, bounds, memory, and bounds leak. It also has exception safety checking to make sure the memory is allocated and deallocated properly. 

## Input/Output
When the program is launched, there is a menu prompt with options to either start a new game against a computer, continue a previously saved game, or quit the program (subject to change). Chess games will be entirely playable through console where user input is taken to move the pieces (e.g, entering 'Re7' moves the Rook to square e7 and entering 'Rxe7' will have the Rook capture the piece on e7). After each valid move, the interface (chess board) is visually updated with pieces in their new position and any captured pieces being removed. Once a game is finished, the user will have the option to begin a new game.

## Class Diagram

![UML Class Diagram](https://i.ibb.co/n1M1Zmb/CS100-Project-UML.png)

Each class pertaining to a chess piece (**King**, **Queen**, **Rook**, **Knight**, **Bishop**, **Pawn**) inherits the **Piece** class containing isMoveValid(Move, Board*), getValue(), and getDirections(). The **Piece** class contains functions to either display available moves for a chosen piece or check if the moves entered by the user are legal. The history of moves played is handled by the **Game** class above and is achieved through keeping track of a stack of **Board** pointers. Each Board pointer has access to the members: board, numPieces, depth, and value. These members are accessed after every move to retrieve the current status of the board.

Histories of entire games are stored in **SQL_Database** whose functions include save(Game*), load(string), and loadAll().

During a game, statuses to update the board, undo a move, or make another move are directed to the **message** class and is addressed through info strings.
**message**, **Game**, and **BoardUI** all make calls to **Observer** who then updates **Listener**, an event handling class that notifies any **Observers** of state changes.
 
 > ## Phase III

For this project, we decided to go with the Observer Pattern, which sets up a notification system in which a subject class (listener) notifies other dependent classes (observers) upon a change of its state. By implementing the observer pattern, we were able to separate our game's model from the user interface for our game. In doing so, we abstracted the player from the game, allowing us to add new player types (as necessary) that will interact with the model solely through the observer pattern. This not only improved the extensibility of the program, but also circumvented the need to modify the game model for each new player type added, thus abiding by the open-closed principle. Specifically, we plan on introducing one (or more) computer player types (naïve, minimax), so the observer pattern will reduce the need for unnecessary code to implement the AI with the model.

 > You will need to schedule a check-in for the second scrum meeting with a reader (using Calendly). Your entire team must be present. This meeting will occur on week 8 but NOT during lab time.
 > * Before the meeting you should perform a sprint plan like you did in Phase II.
 > * You should also update this README file by adding the following:
 >   * What design pattern(s) did you use? For each pattern you must explain in 4-5 sentences:
 >     * Why did you pick this pattern? And what feature did you implement with it?
 >     * How did the design pattern help you write better code?
 >   * An updated class diagram that reflects the design pattern(s) you used. You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description).
 >   * Make sure your README file (and Project board) are up-to-date reflecting the current status of your project. Previous versions of the README file should still be visible through your commit history.
> 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the TA/reader during lab time. The TA/reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
