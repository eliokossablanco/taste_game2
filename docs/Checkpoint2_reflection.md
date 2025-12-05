##Implimented:
-Select food and move around origin point of that food

##How it integrates
-Displays over palate and changes character displayed depending on overlay. does not directly interact yet

##Challenges
-I still had major challenges with building and testing, 
but also had to redo the way I was storing food types to be able to access it and have associated information

##What I learned
-I think I better understood how any why static functions and variables work by having to implement it in my code.
-I also learned how I am going to have to do my displaying later with the 2d array of chars

##Testing results (manual)

###Normal operation

session.chooseFood("chicken");
session.move(0,1);
session.renderFrame();

Works

###Edge case

session.move(-1,0);
session.chooseFood("bread");
session.move(3,-4);
session.renderFrame();

Works

###Boundary condition

session.chooseFood("gibberish");
session.move(2,1);
session.renderFrame();

Works

##Design decisions
-Ive changed how i want to manage moving food around the edges, I will allow moving pieces off the board, but I will have a border that will warn you if it intersects with the piece

#Questions for next checkpoint
Is it okay if I keep doing manual testing?

#Time spent
~5-6 hours
