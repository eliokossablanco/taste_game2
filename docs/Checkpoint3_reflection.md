##Implemented
-Food have unique shapes and apply over palate

##How it integrates
-Loads custom shape from list of foods using feature 2, loads them over palate

##What I learned
-to use vector 2d instead of 2d array for the inside of maps, even when they are initialized at compile time.

##Testing results (manual)
-using same tests, as there is no new user inputs

###Normal operation

Session.chooseFood("chicken");
Session.move(0,1);
Session.renderFrame();

**Works**

###Edge case

session.move(-1,0);
session.chooseFood("bread");
session.move(3,-4);
session.renderFrame();

**Works**

###Boundary condition

session.chooseFood("gibberish");
session.move(2,1);

**Broke**
Fix: made invalid shapes return false at all positions

**Works**

##Questions for next checkpoint
If I want to include a guide should I do that within the program or in the readme?

#Time spent
5 hours

-