# TASTE GAME

**If you are running in CLion console, do run/edit configurations then turn ON "emulate terminal in the output console"** 

## Guide

Welcome to taste game! You are opening up your brand new restaurant, and you are ready to open your doors to your first customers!
Good news is your dad gave you a generous investment of $100 to start out, unfortunately, your customers are very picky.

Each customer has their own specific Palate, represented by the grid.

### **Each customer wants their whole palate filled ideally, which will give them maximum satisfaction**

To fill their palate you will need to select ingriedients, dish them up, and then serve the plate when finished.
You can first select an ingriedient to work with by typing 'food' and then the name of a food you want to use.

* Be careful! selecting a food will charge you for it, even if you dont end up using it.

### **You can then prepare that food by doing different movement operations.**

* Cook (w) - will cook the food and move it up on the palate
* Oil (a) - will add oil to the food and move it left on the palate
* Lemon (s) - will add lemon juice to the food and move it down on the palate
* Water (d) - will add water to the food and more it right on the palate

**You want to try to position the food somewhere that isn't already filled in the palate as trying to serve food over it will create a nasty tile. Each nasty tile will deduct points from the satisfaction.**
* Attempting to serve food off the edge of the board will fill the entire palate with nasty tiles, ruining the dish.

### Once you have the food in a good position, you can type 'dish' to add the food to the dish.

Continue doing this for each item requested by the customer until you have completed the order

**Then, type 'serve' to give the dish to the customer, and get paid.**

### Getting paid:

If a customer has full satisfaction (the whole palate filled), and you give them every item they asked for, they will pay 3x the cost of ingriedients they wanted.

* They **WILL NOT** pay for ingriedients they did not ask for, so try to avoid using expensive ingiredients to fill up the palate.

**Pro tip**- You can use cheaper ingriedients to fill up the palate, especially on expensive orders, as the satisfaction increase may outweigh the cost.


## Current Status

**In progress**
* Save/Loading
* Movement pricing
* food start placement
* modify food shapes

**All main features other than Save/Loading implemented**

## FEATURES
1. **view palate shape and size of customer**
2. **select ingridients to add to meal**
3. **move and modify shape of curent food**
4. **dish up meals and apply them to the palate**
5. **get paid on how good the food is**

## BUILD INSTRUCTIONS

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Author
Elio Kossa-Blanco - CIS 25 Final Project
