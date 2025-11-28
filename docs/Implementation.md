\## IMPLEMENTATION PLAN



\### Feature 1 - View palate shape and size

1\. What triggers this feature 



\*\*Whenever the frame is rendered, after every user input\*\*



2\. What input or data is needed



\*\*requires the palate member from the current customer\*\*



3\. which functions get called and what they do



\*\*getPalate() on customer, which gets its palate member and getGrid() on Palate to return the grid of chars\*\*



4\. What data gets created, modified, or displayed



\*\*2d array of chars is created possibly modified on customer construction, sent from palate to game to display\*\*



5\. What happens when the operation completes



\*\*prints data to console\*\*



\### Feature 2 - Select an ingredient to cook



1\. What triggers this feature 



\*\*User input\*\*



2\. What input or data is needed



\*\*user types name of food\*\*



3\. which functions get called and what they do



\*\*unimplimented function in game to match food name, choseFood() in game to load an instance of that food\*\*



4\. What data gets created, modified, or displayed



\*\*Game will create a new food of the type selected, and print it over palate\*\*



5\. What happens when the operation completes



\*\*display food over palate, and wait for next input\*\*





\### Feature 3 - Move around food pieces and modify the shape



1\. What triggers this feature 



\*\*User input\*\*



2\. What input or data is needed



\*\*user types any move direction\*\*



3\. which functions get called and what they do



\*\*move() on game changes the x and y of the current loaded food\*\*



4\. What data gets created, modified, or displayed



\*\*x and y of the current loaded food get modified\*\*



5\. What happens when the operation completes



\*\*display next frame\*\*





\### Feature 4 - dish up and apply food to the palate



1\. What triggers this feature 



\*\*User input\*\*



2\. What input or data is needed



\*\*user types serve dish\*\*



3\. which functions get called and what they do



\*\*serveDish() on Game, which will send a list of all cooked items to the customer using sendFood(), then clear the dish with Game.clearDish(). Then call sendFood() on Palate, which will update the grid.\*\*



4\. What data gets created, modified, or displayed



\*\*Dish will be cleared and palate of customer will be updated\*\*



5\. What happens when the operation completes



\*\*display new palate only, wait for user input\*\*



\### Feature 5 - get paid based on how good the order is



1\. What triggers this feature 



\*\*after customer has been served and user inputs to continue\*\*



2\. What input or data is needed



\*\*any key to continue\*\*



3\. which functions get called and what they do



\*\*getSatisfaction() in customer which returns the percent of the palate filled with food \* max price of all items, then dismissCustomer() and callCustomer() in game, which will clear current customer and load a new one\*\*



4\. What data gets created, modified, or displayed



\*\*Money will be modified, customer will be remored, and replaced with new customer\*\*



5\. What happens when the operation completes



\*\*wait for user input for next move\*\*



