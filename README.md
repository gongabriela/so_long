# So_long: Introduction

Welcome to **so_long**, a 2D game built using the **MiniLibX** graphical library, designed for the **42** curriculum. This project is aimed at creating a simple yet challenging game where the player must navigate through a map to collect items and find an exit.

## Game Rules

The goal of **so_long** is for the player to move through a map, collect all the collectibles, and escape by choosing the shortest route to the exit. The game operates with a few key rules:

- The game uses a map description file with the `.ber` extension. The map consists of walls (`1`), empty spaces (`0`), collectibles (`C`), the exit (`E`), and the player's starting position (`P`).
- **Player Movement**:
    - The player can move up, down, left, and right using the **W, A, S, D** keys (or **ZQSD** / arrow keys, depending on preference).
    - The player cannot move through walls.
    - At every move, the program will display the current number of movements in the terminal.
- **Map Structure**:
    - The map must be rectangular and surrounded by walls.
    - It must contain at least one exit (`E`), one starting position (`P`), and at least one collectible (`C`).
    - A valid map contains no more than one exit and one starting position; any duplicates should result in an error.
- **Gameplay**:
    - The game is not in real-time, giving the player time to think through each move.
    - The program must manage window interactions smoothly, ensuring the window can be minimized, switched to, or closed without issue.
    - Pressing **ESC** or clicking the window's close button will cleanly quit the game.
- **Map Validation**:
    - The map must be validated to ensure it follows the rules: it must contain walls around its edges, and there must be a valid path between the player and the exit.
    - If there are any misconfigurations in the map, the program will display an error message and exit cleanly.

# Initiating Structs, Freeing Memory, and Handling Exits

Planning and organization are crucial for a smooth coding process. For this project, we will be saving memory addresses in pointers, and we need to have access to these allocated memory blocks at any point in our program. This will allow us to free everything properly in the case of an error or when the player chooses to exit the game. I recommend using structs and creating a free function capable of freeing all memory associated with the struct (or structs).

Be sure to initialize everything to `NULL` and check if memory has been allocated before attempting to free it, in order to avoid double-free errors!

# Parsing the map

Since your program receives a map as a parameter, we need to check if this map is valid. A valid map must follow the rules of the subject that I described on the first session.

Things you have to check:

- [ ]  if the file can be opened and read, and has .ber extension
- [ ]  if the file is empty
- [ ]  if the map is a rectangle
- [ ]  if the map is surrounded by walls
- [ ]  if the map only has the components 1,P,E,C,0 and only 1 exit and 1 player.
- [ ]  If the player can reach all collectibles and the exit.

while parsing, you can save the map in a char **, the number of rows and columns, and the number of collectibles.

Tip: to check if the player can collect all collectibles and reach the exit, use the flood fill algorithm.

# Rendering the game

Welcome to the rendering stage of **So Long**! At this point in the project, we're diving into the graphical side of things using [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx) — the lightweight graphics library provided by 42.

> ⚠️ Before you go further, it's highly recommended that you read the MiniLibX documentation to get familiar with the functions and concepts.
> 

## Initializing the Window

The first step is initializing the MiniLibX library and opening a window in your `main.c`. This sets up the rendering context that you'll use to draw your game.

```c
mlx = mlx_init();
win = mlx_new_window(mlx, width, height, "So Long");
```

## Loading Textures

All textures must be:

- Converted to **XPM** format
- Properly scaled for your system's architecture (32/64-bit)
- Stored in a `/textures` folder at the root of the project

### Functions you'll use:

- `mlx_xpm_file_to_image()` – loads XPM images into memory
- `mlx_put_image_to_window()` – displays images on the screen

## Handling Keyboard Input

To handle key presses, you'll be using the **KeySym** constants from the `X11/keysym.h` library.

Typical flow:

1. Listen for keypress events
2. Update player position
3. Re-render the map with updated state

## Final Touches and Testing

Before wrapping up, make sure to:

- **Free images** on each update to avoid memory leaks
- **Reload the game state** properly after each move
- Implement and test **the main loop**, typically using `mlx_loop()`

# Resources

https://42-cursus.gitbook.io/guide/rank-02/so_long/building-the-thing

https://harm-smits.github.io/42docs/libs/minilibx/prototypes.html

https://reactive.so/post/42-a-comprehensive-guide-to-so_long/

https://medium.com/@digitalpoolng/42-so-long-and-thanks-for-all-the-fish-building-your-first-2d-game-in-c-ccd24034bc8b
